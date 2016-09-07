// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

#if !defined(__COREFOUNDATION_CFMEASUREMENTFORMATTER__)
#define __COREFOUNDATION_CFMEASUREMENTFORMATTER__ 1

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFLocale.h>
#include <CoreFoundation/CFNumberFormatter.h>
#include <CoreFoundation/CFArray.h>

CF_IMPLICIT_BRIDGING_ENABLED
CF_EXTERN_C_BEGIN

typedef struct CF_BRIDGED_MUTABLE_TYPE(id) __CFMeasurementFormatter *CFMeasurementFormatterRef;

CF_EXPORT
CFTypeID CFMeasurementFormatterGetTypeID(void);

typedef CF_ENUM(CFIndex, CFMeasurementFormatterStyle) {
    kCFMeasurementFormatterStyleWide = 0,
    kCFMeasurementFormatterStyleShort = 1,
    kCFMeasurementFormatterStyleNarrow = 2,
    kCFMeasurementFormatterStyleNumeric = 3
};

typedef CF_ENUM(CFIndex, CFMeasurementFormatterUnit) {
    kCFMeasurementFormatterUnitAcceleration_GForce = (0 << 8)+0,
    kCFMeasurementFormatterUnitAcceleration_MeterPerSecondSquared = (0 << 8)+1
};

typedef struct {
    double value;
    CFMeasurementFormatterUnit unit;
} CFMeasurementFormatterMeasure;

CF_EXPORT
CFMeasurementFormatterRef CFMeasurementFormatterCreate(CFAllocatorRef allocator, CFLocaleRef locale, CFMeasurementFormatterStyle style, CFNumberFormatterRef numberFormatter);
/* Returns a CFMeasurementFormatter, localized to the given locale, which will format measurements to the given style. A CFNumberFormatter can be passed to customize the way in which numbers are formatted, otherwise, to use the default formatter, pass NULL. */

CF_EXPORT
CFStringRef CFMeasurementFormatterCreateString(CFAllocatorRef allocator, CFMeasurementFormatterRef formatter, double value, CFMeasurementFormatterUnit unit);
/* Returns a localized string representation of the given measurement value and unit */

CF_EXPORT
CFStringRef CFMeasurementFormatterCreateStringFromMeasures(CFAllocatorRef allocator, CFMeasurementFormatterRef formatter, CFArrayRef measures);
/* Unimplemented. Returns a localized string representation of a list of measures, each represented by a CFMeasurementFormatterMeasure object. e.g: "1 hour, 30 mins" */

CF_EXPORT
CFStringRef CFMeasurementFormatterCreateUnitString(CFAllocatorRef allocator, CFMeasurementFormatterRef formatter, CFMeasurementFormatterUnit unit);
/* Unimplemented. Returns a localized string representation of the given unit */

CF_EXTERN_C_END
CF_IMPLICIT_BRIDGING_DISABLED

#endif /* ! __COREFOUNDATION_CFMEASUREMENTFORMATTER__ */
