// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

#include <CoreFoundation/CFMeasurementFormatter.h>
#include <CoreFoundation/ForFoundationOnly.h>
#include "CFInternal.h"
#include "CFICULogging.h"

#define BUFFER_SIZE 768

struct __CFMeasurementFormatter {
    CFRuntimeBase _base;
    UAMeasureFormat* _mf;
    
    //retain these if we want to provide getters for them
    //CFLocaleRef _locale;
    //CFMeasurementFormatterStyle _style;
    //CFNumberFormatterRef _nf;
};

static CFStringRef __CFMeasurementFormatterCopyDescription(CFTypeRef cf) {
    CFMeasurementFormatterRef formatter = (CFMeasurementFormatterRef)cf;
    return CFStringCreateWithFormat(CFGetAllocator(formatter), NULL, CFSTR("<CFMeasurementFormatter %p [%p]>"), cf, CFGetAllocator(formatter));
}

static void __CFMeasurementFormatterDeallocate(CFTypeRef cf) {
    CFMeasurementFormatterRef formatter = (CFMeasurementFormatterRef)cf;
    if (formatter->_mf) __cficu_umeasfmt_close(formatter->_mf);
}

static CFTypeID __kCFMeasurementFormatterTypeID = _kCFRuntimeNotATypeID;

static const CFRuntimeClass __CFMeasurementFormatterClass = {
    0,
    "CFMeasurementFormatter",
    NULL,	// init
    NULL,	// copy
    __CFMeasurementFormatterDeallocate,
    NULL,
    NULL,
    NULL,	//
    __CFMeasurementFormatterCopyDescription
};

CFTypeID CFMeasurementFormatterGetTypeID(void) {
    static dispatch_once_t initOnce = 0;
    dispatch_once(&initOnce, ^{ __kCFMeasurementFormatterTypeID = _CFRuntimeRegisterClass(&__CFMeasurementFormatterClass); });
    return __kCFMeasurementFormatterTypeID;
}

CFMeasurementFormatterRef CFMeasurementFormatterCreate(CFAllocatorRef allocator, CFLocaleRef locale, CFMeasurementFormatterStyle style, CFNumberFormatterRef numberFormatter) {
    
    struct __CFMeasurementFormatter *memory;
    uint32_t size = sizeof(struct __CFMeasurementFormatter) - sizeof(CFRuntimeBase);
    if (allocator == NULL) allocator = __CFGetDefaultAllocator();
    __CFGenericValidateType(allocator, CFAllocatorGetTypeID());
    __CFGenericValidateType(locale, CFLocaleGetTypeID());
    memory = (struct __CFMeasurementFormatter *)_CFRuntimeCreateInstance(allocator, CFMeasurementFormatterGetTypeID(), size, NULL);
    if (NULL == memory) {
        return NULL;
    }
    
    memory->_mf = NULL;
    
    if (locale == NULL) locale = CFLocaleGetSystem();
    
    UAMeasureFormatWidth ustyle;
    switch (style) {
        case kCFMeasurementFormatterStyleNumeric: ustyle = UAMEASFMT_WIDTH_NUMERIC; break;
        case kCFMeasurementFormatterStyleNarrow: ustyle = UAMEASFMT_WIDTH_NARROW; break;
        case kCFMeasurementFormatterStyleShort: ustyle = UAMEASFMT_WIDTH_SHORT; break;
        case kCFMeasurementFormatterStyleWide: ustyle = UAMEASFMT_WIDTH_WIDE; break;

        default:
            CFAssert(0, __kCFLogAssertion, "%s(): unknown style %d", __PRETTY_FUNCTION__, style);
            ustyle = UAMEASFMT_WIDTH_WIDE;
            break;
    }
    
    CFStringRef localeName = locale ? CFLocaleGetIdentifier(locale) : CFSTR("");
    char buffer[BUFFER_SIZE];
    const char *cstr = CFStringGetCStringPtr(localeName, kCFStringEncodingASCII);
    if (NULL == cstr) {
        if (CFStringGetCString(localeName, buffer, BUFFER_SIZE, kCFStringEncodingASCII)) cstr = buffer;
    }
    if (NULL == cstr) {
        CFRelease(memory);
        return NULL;
    }
    
    UErrorCode status = U_ZERO_ERROR;
    
    UNumberFormat* uNumberFormat = NULL;
    if (numberFormatter){
        uNumberFormat = (UNumberFormat*)_CFNumberFormatterGetFormatter(numberFormatter);
        
        //MeasureFormat seems to dealloc the NumberFormat object which is a problem, since CFNumberFormatter is also expecting to release it. Make a copy:
        uNumberFormat = unum_clone(uNumberFormat, &status);
        if (U_FAILURE(status)){
            CFRelease(memory);
            return NULL;
        }
        
    }
    
    memory->_mf = __cficu_umeasfmt_open(cstr, ustyle, uNumberFormat, &status);
    if (U_FAILURE(status)){
        if (uNumberFormat) unum_close(uNumberFormat);
        CFRelease(memory);
        return NULL;
    }
    
    return (CFMeasurementFormatterRef)memory;
}

bool _CFMeasurementFormatterConvertUnit(CFMeasurementFormatterUnit in, UAMeasureUnit *out){
    
    //this should probably use a large switch statement, in case the ICU values change
    *out = in;
    return true;
    
}

CFStringRef CFMeasurementFormatterCreateString(CFAllocatorRef allocator, CFMeasurementFormatterRef formatter, double value, CFMeasurementFormatterUnit unit){
    
    if (allocator == NULL) allocator = __CFGetDefaultAllocator();
    __CFGenericValidateType(allocator, CFAllocatorGetTypeID());
    __CFGenericValidateType(formatter, CFMeasurementFormatterGetTypeID());
    
    UChar *ustr = NULL, ubuffer[BUFFER_SIZE];
    UErrorCode status = U_ZERO_ERROR;
    CFIndex used;
    
    UAMeasureUnit umeasunit;
    if (!_CFMeasurementFormatterConvertUnit(unit, &umeasunit)){
        //invalid argument
        return NULL;
    }
    
    used = __cficu_umeasfmt_format(formatter->_mf, value, umeasunit, ubuffer, BUFFER_SIZE, &status);
    if (status == U_BUFFER_OVERFLOW_ERROR){
        ustr = (UChar *)CFAllocatorAllocate(kCFAllocatorSystemDefault, sizeof(UChar) * used, 0);
        status = U_ZERO_ERROR;
        used = __cficu_umeasfmt_format(formatter->_mf, value, umeasunit, ustr, used, &status);
    }

    CFStringRef string = NULL;
    
    if (U_SUCCESS(status)) {
        UniChar *bufferToUse = ustr ? (UniChar *)ustr : (UniChar *)ubuffer;
        string = CFStringCreateWithCharacters(allocator, bufferToUse, used);
    }

    if (ustr) CFAllocatorDeallocate(kCFAllocatorSystemDefault, ustr);
    return string;

}

CFStringRef CFMeasurementFormatterCreateStringFromMeasures(CFAllocatorRef allocator, CFMeasurementFormatterRef formatter, CFArrayRef measures){
    return NULL;
}

CFStringRef CFMeasurementFormatterCreateUnitString(CFAllocatorRef allocator, CFMeasurementFormatterRef formatter, CFMeasurementFormatterUnit unit){
    return NULL;
}

#undef BUFFER_SIZE

