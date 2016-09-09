// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

extern "C"{
#include <CoreFoundation/CFMeasurementFormatter.h>
#include <CoreFoundation/ForFoundationOnly.h>
#include "CFInternal.h"
//#include "CFICULogging.h"
}

#include <unicode/measfmt.h>
#include <unicode/measunit.h>
#include <unicode/measure.h>
#include <unicode/uvernum.h>

#define BUFFER_SIZE 768

#if U_ICU_VERSION_MAJOR_NUM >= 53
const bool kCFMeasurementFormatterIsAvailable = true;
#else
const bool kCFMeasurementFormatterIsAvailable = false;
#endif

const CFIndex kCFMeasurementFormatterICUVersion = U_ICU_VERSION_MAJOR_NUM;

struct __CFMeasurementFormatter {
    CFRuntimeBase _base;
    MeasureFormat* _mf;
    
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
    if (formatter->_mf) delete formatter->_mf;
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
    
#if U_ICU_VERSION_MAJOR_NUM >= 53
    
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
    
    UMeasureFormatWidth ustyle;
    switch (style) {
        case kCFMeasurementFormatterStyleNumeric: ustyle = UMEASFMT_WIDTH_NUMERIC; break;
        case kCFMeasurementFormatterStyleNarrow: ustyle = UMEASFMT_WIDTH_NARROW; break;
        case kCFMeasurementFormatterStyleShort: ustyle = UMEASFMT_WIDTH_SHORT; break;
        case kCFMeasurementFormatterStyleWide: ustyle = UMEASFMT_WIDTH_WIDE; break;
            
        default:
            //CFAssert(0, __kCFLogAssertion, "%s(): unknown style %d", __PRETTY_FUNCTION__, style);
            ustyle = UMEASFMT_WIDTH_WIDE;
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
    
    memory->_mf = new MeasureFormat(Locale(cstr), ustyle, (NumberFormat*)uNumberFormat, status);
    //memory->_mf = __cficu_umeasfmt_open(cstr, ustyle, uNumberFormat, &status);
    if (U_FAILURE(status)){
        if (uNumberFormat) unum_close(uNumberFormat);
        CFRelease(memory);
        return NULL;
    }
    
    return (CFMeasurementFormatterRef)memory;
    
#else
    return NULL;
#endif
    
}

// Begin generated code
// See generate.py
MeasureUnit* _CFMeasurementFormatterCreateUnit(CFMeasurementFormatterUnit unit, UErrorCode &status) {
    switch (unit) {
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitAcceleration_GForce:
            return MeasureUnit::createGForce(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitAcceleration_MeterPerSecondSquared:
            return MeasureUnit::createMeterPerSecondSquared(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitAngle_ArcMinute:
            return MeasureUnit::createArcMinute(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitAngle_ArcSecond:
            return MeasureUnit::createArcSecond(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitAngle_Degree:
            return MeasureUnit::createDegree(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitAngle_Radian:
            return MeasureUnit::createRadian(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 56
        case kCFMeasurementFormatterUnitAngle_Revolution:
            return MeasureUnit::createRevolutionAngle(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitArea_Acre:
            return MeasureUnit::createAcre(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitArea_Hectare:
            return MeasureUnit::createHectare(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitArea_SquareCentimeter:
            return MeasureUnit::createSquareCentimeter(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitArea_SquareFoot:
            return MeasureUnit::createSquareFoot(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitArea_SquareInch:
            return MeasureUnit::createSquareInch(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitArea_SquareKilometer:
            return MeasureUnit::createSquareKilometer(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitArea_SquareMeter:
            return MeasureUnit::createSquareMeter(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitArea_SquareMile:
            return MeasureUnit::createSquareMile(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitArea_SquareYard:
            return MeasureUnit::createSquareYard(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitConcentr_Karat:
            return MeasureUnit::createKarat(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 57
        case kCFMeasurementFormatterUnitConcentr_MilligramPerDeciliter:
            return MeasureUnit::createMilligramPerDeciliter(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 57
        case kCFMeasurementFormatterUnitConcentr_MillimolePerLiter:
            return MeasureUnit::createMillimolePerLiter(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 57
        case kCFMeasurementFormatterUnitConcentr_PartPerMillion:
            return MeasureUnit::createPartPerMillion(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 56
        case kCFMeasurementFormatterUnitConsumption_LiterPer100Kilometers:
            return MeasureUnit::createLiterPer100Kilometers(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitConsumption_LiterPerKilometer:
            return MeasureUnit::createLiterPerKilometer(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitConsumption_MilePerGallon:
            return MeasureUnit::createMilePerGallon(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 57
        case kCFMeasurementFormatterUnitConsumption_MilePerGallonImperial:
            return MeasureUnit::createMilePerGallonImperial(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitDigital_Bit:
            return MeasureUnit::createBit(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitDigital_Byte:
            return MeasureUnit::createByte(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitDigital_Gigabit:
            return MeasureUnit::createGigabit(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitDigital_Gigabyte:
            return MeasureUnit::createGigabyte(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitDigital_Kilobit:
            return MeasureUnit::createKilobit(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitDigital_Kilobyte:
            return MeasureUnit::createKilobyte(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitDigital_Megabit:
            return MeasureUnit::createMegabit(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitDigital_Megabyte:
            return MeasureUnit::createMegabyte(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitDigital_Terabit:
            return MeasureUnit::createTerabit(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitDigital_Terabyte:
            return MeasureUnit::createTerabyte(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 56
        case kCFMeasurementFormatterUnitDuration_Century:
            return MeasureUnit::createCentury(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitDuration_Day:
            return MeasureUnit::createDay(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitDuration_Hour:
            return MeasureUnit::createHour(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitDuration_Microsecond:
            return MeasureUnit::createMicrosecond(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitDuration_Millisecond:
            return MeasureUnit::createMillisecond(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitDuration_Minute:
            return MeasureUnit::createMinute(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitDuration_Month:
            return MeasureUnit::createMonth(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitDuration_Nanosecond:
            return MeasureUnit::createNanosecond(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitDuration_Second:
            return MeasureUnit::createSecond(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitDuration_Week:
            return MeasureUnit::createWeek(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitDuration_Year:
            return MeasureUnit::createYear(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitElectric_Ampere:
            return MeasureUnit::createAmpere(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitElectric_Milliampere:
            return MeasureUnit::createMilliampere(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitElectric_Ohm:
            return MeasureUnit::createOhm(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitElectric_Volt:
            return MeasureUnit::createVolt(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitEnergy_Calorie:
            return MeasureUnit::createCalorie(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitEnergy_Foodcalorie:
            return MeasureUnit::createFoodcalorie(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitEnergy_Joule:
            return MeasureUnit::createJoule(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitEnergy_Kilocalorie:
            return MeasureUnit::createKilocalorie(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitEnergy_Kilojoule:
            return MeasureUnit::createKilojoule(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitEnergy_KilowattHour:
            return MeasureUnit::createKilowattHour(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitFrequency_Gigahertz:
            return MeasureUnit::createGigahertz(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitFrequency_Hertz:
            return MeasureUnit::createHertz(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitFrequency_Kilohertz:
            return MeasureUnit::createKilohertz(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitFrequency_Megahertz:
            return MeasureUnit::createMegahertz(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitLength_AstronomicalUnit:
            return MeasureUnit::createAstronomicalUnit(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitLength_Centimeter:
            return MeasureUnit::createCentimeter(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitLength_Decimeter:
            return MeasureUnit::createDecimeter(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitLength_Fathom:
            return MeasureUnit::createFathom(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitLength_Foot:
            return MeasureUnit::createFoot(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitLength_Furlong:
            return MeasureUnit::createFurlong(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitLength_Inch:
            return MeasureUnit::createInch(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitLength_Kilometer:
            return MeasureUnit::createKilometer(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitLength_LightYear:
            return MeasureUnit::createLightYear(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitLength_Meter:
            return MeasureUnit::createMeter(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitLength_Micrometer:
            return MeasureUnit::createMicrometer(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitLength_Mile:
            return MeasureUnit::createMile(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 56
        case kCFMeasurementFormatterUnitLength_MileScandinavian:
            return MeasureUnit::createMileScandinavian(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitLength_Millimeter:
            return MeasureUnit::createMillimeter(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitLength_Nanometer:
            return MeasureUnit::createNanometer(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitLength_NauticalMile:
            return MeasureUnit::createNauticalMile(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitLength_Parsec:
            return MeasureUnit::createParsec(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitLength_Picometer:
            return MeasureUnit::createPicometer(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitLength_Yard:
            return MeasureUnit::createYard(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitLight_Lux:
            return MeasureUnit::createLux(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitMass_Carat:
            return MeasureUnit::createCarat(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitMass_Gram:
            return MeasureUnit::createGram(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitMass_Kilogram:
            return MeasureUnit::createKilogram(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitMass_MetricTon:
            return MeasureUnit::createMetricTon(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitMass_Microgram:
            return MeasureUnit::createMicrogram(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitMass_Milligram:
            return MeasureUnit::createMilligram(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitMass_Ounce:
            return MeasureUnit::createOunce(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitMass_OunceTroy:
            return MeasureUnit::createOunceTroy(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitMass_Pound:
            return MeasureUnit::createPound(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitMass_Stone:
            return MeasureUnit::createStone(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitMass_Ton:
            return MeasureUnit::createTon(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitPower_Gigawatt:
            return MeasureUnit::createGigawatt(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitPower_Horsepower:
            return MeasureUnit::createHorsepower(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitPower_Kilowatt:
            return MeasureUnit::createKilowatt(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitPower_Megawatt:
            return MeasureUnit::createMegawatt(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitPower_Milliwatt:
            return MeasureUnit::createMilliwatt(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitPower_Watt:
            return MeasureUnit::createWatt(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitPressure_Hectopascal:
            return MeasureUnit::createHectopascal(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitPressure_InchHg:
            return MeasureUnit::createInchHg(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitPressure_Millibar:
            return MeasureUnit::createMillibar(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitPressure_MillimeterOfMercury:
            return MeasureUnit::createMillimeterOfMercury(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitPressure_PoundPerSquareInch:
            return MeasureUnit::createPoundPerSquareInch(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitSpeed_KilometerPerHour:
            return MeasureUnit::createKilometerPerHour(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 56
        case kCFMeasurementFormatterUnitSpeed_Knot:
            return MeasureUnit::createKnot(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitSpeed_MeterPerSecond:
            return MeasureUnit::createMeterPerSecond(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitSpeed_MilePerHour:
            return MeasureUnit::createMilePerHour(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitTemperature_Celsius:
            return MeasureUnit::createCelsius(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitTemperature_Fahrenheit:
            return MeasureUnit::createFahrenheit(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 56
        case kCFMeasurementFormatterUnitTemperature_Generic:
            return MeasureUnit::createGenericTemperature(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitTemperature_Kelvin:
            return MeasureUnit::createKelvin(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitVolume_AcreFoot:
            return MeasureUnit::createAcreFoot(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitVolume_Bushel:
            return MeasureUnit::createBushel(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitVolume_Centiliter:
            return MeasureUnit::createCentiliter(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitVolume_CubicCentimeter:
            return MeasureUnit::createCubicCentimeter(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitVolume_CubicFoot:
            return MeasureUnit::createCubicFoot(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitVolume_CubicInch:
            return MeasureUnit::createCubicInch(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitVolume_CubicKilometer:
            return MeasureUnit::createCubicKilometer(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitVolume_CubicMeter:
            return MeasureUnit::createCubicMeter(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitVolume_CubicMile:
            return MeasureUnit::createCubicMile(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitVolume_CubicYard:
            return MeasureUnit::createCubicYard(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitVolume_Cup:
            return MeasureUnit::createCup(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 56
        case kCFMeasurementFormatterUnitVolume_CupMetric:
            return MeasureUnit::createCupMetric(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitVolume_Deciliter:
            return MeasureUnit::createDeciliter(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitVolume_FluidOunce:
            return MeasureUnit::createFluidOunce(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitVolume_Gallon:
            return MeasureUnit::createGallon(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 57
        case kCFMeasurementFormatterUnitVolume_GallonImperial:
            return MeasureUnit::createGallonImperial(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitVolume_Hectoliter:
            return MeasureUnit::createHectoliter(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 53
        case kCFMeasurementFormatterUnitVolume_Liter:
            return MeasureUnit::createLiter(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitVolume_Megaliter:
            return MeasureUnit::createMegaliter(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitVolume_Milliliter:
            return MeasureUnit::createMilliliter(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitVolume_Pint:
            return MeasureUnit::createPint(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 56
        case kCFMeasurementFormatterUnitVolume_PintMetric:
            return MeasureUnit::createPintMetric(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitVolume_Quart:
            return MeasureUnit::createQuart(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitVolume_Tablespoon:
            return MeasureUnit::createTablespoon(status);
#endif
#if U_ICU_VERSION_MAJOR_NUM >= 54
        case kCFMeasurementFormatterUnitVolume_Teaspoon:
            return MeasureUnit::createTeaspoon(status);
#endif
        default: return NULL;
    }
}
// End generated code

CFStringRef CFMeasurementFormatterCreateString(CFAllocatorRef allocator, CFMeasurementFormatterRef formatter, double value, CFMeasurementFormatterUnit unit){
    
#if U_ICU_VERSION_MAJOR_NUM >= 53
    
    if (allocator == NULL) allocator = __CFGetDefaultAllocator();
    __CFGenericValidateType(allocator, CFAllocatorGetTypeID());
    __CFGenericValidateType(formatter, CFMeasurementFormatterGetTypeID());
    
    UErrorCode status = U_ZERO_ERROR;
    
    MeasureUnit* measunit = _CFMeasurementFormatterCreateUnit(unit, status);
    if (measunit == NULL){
        //unit not available
        return NULL;
    }
    
    LocalPointer<Measure> meas(new Measure(value, measunit, status));
    if (U_FAILURE(status)){
        return NULL;
    }
    
    Formattable fmt;
    fmt.adoptObject(meas.orphan());
    
    
    UnicodeString string;
    formatter->_mf->format(fmt, string, status);
    
    if (U_FAILURE(status)){
        return NULL;
    }
    
    CFIndex length = string.length();
    UChar* ustr = (UChar *)CFAllocatorAllocate(kCFAllocatorSystemDefault, sizeof(UChar) * length, 0);
    string.extract(ustr, length, status);
    
    CFStringRef result;
    
    if (U_SUCCESS(status)) {
        result = CFStringCreateWithCharacters(allocator, ustr, length);
    }
    
    CFAllocatorDeallocate(kCFAllocatorSystemDefault, ustr);
    return result;
    
#else
    return NULL;
#endif
    
}

CFStringRef CFMeasurementFormatterCreateStringFromMeasures(CFAllocatorRef allocator, CFMeasurementFormatterRef formatter, CFArrayRef measures){
    return NULL;
}

CFStringRef CFMeasurementFormatterCreateUnitString(CFAllocatorRef allocator, CFMeasurementFormatterRef formatter, CFMeasurementFormatterUnit unit){
    return NULL;
}

#undef BUFFER_SIZE
