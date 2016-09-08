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

// Begin generated code
// See generate.py
typedef CF_ENUM(CFIndex, CFMeasurementFormatterUnit) {
    kCFMeasurementFormatterUnitAcceleration_GForce, // ICU 53
    kCFMeasurementFormatterUnitAcceleration_MeterPerSecondSquared, // ICU 54
    kCFMeasurementFormatterUnitAngle_ArcMinute, // ICU 53
    kCFMeasurementFormatterUnitAngle_ArcSecond, // ICU 53
    kCFMeasurementFormatterUnitAngle_Degree, // ICU 53
    kCFMeasurementFormatterUnitAngle_Radian, // ICU 54
    kCFMeasurementFormatterUnitAngle_Revolution, // ICU 56 (draft)
    kCFMeasurementFormatterUnitArea_Acre, // ICU 53
    kCFMeasurementFormatterUnitArea_Hectare, // ICU 53
    kCFMeasurementFormatterUnitArea_SquareCentimeter, // ICU 54
    kCFMeasurementFormatterUnitArea_SquareFoot, // ICU 53
    kCFMeasurementFormatterUnitArea_SquareInch, // ICU 54
    kCFMeasurementFormatterUnitArea_SquareKilometer, // ICU 53
    kCFMeasurementFormatterUnitArea_SquareMeter, // ICU 53
    kCFMeasurementFormatterUnitArea_SquareMile, // ICU 53
    kCFMeasurementFormatterUnitArea_SquareYard, // ICU 54
    kCFMeasurementFormatterUnitConcentr_Karat, // ICU 54
    kCFMeasurementFormatterUnitConcentr_MilligramPerDeciliter, // ICU 57 (draft)
    kCFMeasurementFormatterUnitConcentr_MillimolePerLiter, // ICU 57 (draft)
    kCFMeasurementFormatterUnitConcentr_PartPerMillion, // ICU 57 (draft)
    kCFMeasurementFormatterUnitConsumption_LiterPer100Kilometers, // ICU 56 (draft)
    kCFMeasurementFormatterUnitConsumption_LiterPerKilometer, // ICU 54
    kCFMeasurementFormatterUnitConsumption_MilePerGallon, // ICU 54
    kCFMeasurementFormatterUnitConsumption_MilePerGallonImperial, // ICU 57 (draft)
    kCFMeasurementFormatterUnitDigital_Bit, // ICU 54
    kCFMeasurementFormatterUnitDigital_Byte, // ICU 54
    kCFMeasurementFormatterUnitDigital_Gigabit, // ICU 54
    kCFMeasurementFormatterUnitDigital_Gigabyte, // ICU 54
    kCFMeasurementFormatterUnitDigital_Kilobit, // ICU 54
    kCFMeasurementFormatterUnitDigital_Kilobyte, // ICU 54
    kCFMeasurementFormatterUnitDigital_Megabit, // ICU 54
    kCFMeasurementFormatterUnitDigital_Megabyte, // ICU 54
    kCFMeasurementFormatterUnitDigital_Terabit, // ICU 54
    kCFMeasurementFormatterUnitDigital_Terabyte, // ICU 54
    kCFMeasurementFormatterUnitDuration_Century, // ICU 56 (draft)
    kCFMeasurementFormatterUnitDuration_Day, // ICU 53
    kCFMeasurementFormatterUnitDuration_Hour, // ICU 53
    kCFMeasurementFormatterUnitDuration_Microsecond, // ICU 54
    kCFMeasurementFormatterUnitDuration_Millisecond, // ICU 53
    kCFMeasurementFormatterUnitDuration_Minute, // ICU 53
    kCFMeasurementFormatterUnitDuration_Month, // ICU 53
    kCFMeasurementFormatterUnitDuration_Nanosecond, // ICU 54
    kCFMeasurementFormatterUnitDuration_Second, // ICU 53
    kCFMeasurementFormatterUnitDuration_Week, // ICU 53
    kCFMeasurementFormatterUnitDuration_Year, // ICU 53
    kCFMeasurementFormatterUnitElectric_Ampere, // ICU 54
    kCFMeasurementFormatterUnitElectric_Milliampere, // ICU 54
    kCFMeasurementFormatterUnitElectric_Ohm, // ICU 54
    kCFMeasurementFormatterUnitElectric_Volt, // ICU 54
    kCFMeasurementFormatterUnitEnergy_Calorie, // ICU 54
    kCFMeasurementFormatterUnitEnergy_Foodcalorie, // ICU 54
    kCFMeasurementFormatterUnitEnergy_Joule, // ICU 54
    kCFMeasurementFormatterUnitEnergy_Kilocalorie, // ICU 54
    kCFMeasurementFormatterUnitEnergy_Kilojoule, // ICU 54
    kCFMeasurementFormatterUnitEnergy_KilowattHour, // ICU 54
    kCFMeasurementFormatterUnitFrequency_Gigahertz, // ICU 54
    kCFMeasurementFormatterUnitFrequency_Hertz, // ICU 54
    kCFMeasurementFormatterUnitFrequency_Kilohertz, // ICU 54
    kCFMeasurementFormatterUnitFrequency_Megahertz, // ICU 54
    kCFMeasurementFormatterUnitLength_AstronomicalUnit, // ICU 54
    kCFMeasurementFormatterUnitLength_Centimeter, // ICU 53
    kCFMeasurementFormatterUnitLength_Decimeter, // ICU 54
    kCFMeasurementFormatterUnitLength_Fathom, // ICU 54
    kCFMeasurementFormatterUnitLength_Foot, // ICU 53
    kCFMeasurementFormatterUnitLength_Furlong, // ICU 54
    kCFMeasurementFormatterUnitLength_Inch, // ICU 53
    kCFMeasurementFormatterUnitLength_Kilometer, // ICU 53
    kCFMeasurementFormatterUnitLength_LightYear, // ICU 53
    kCFMeasurementFormatterUnitLength_Meter, // ICU 53
    kCFMeasurementFormatterUnitLength_Micrometer, // ICU 54
    kCFMeasurementFormatterUnitLength_Mile, // ICU 53
    kCFMeasurementFormatterUnitLength_MileScandinavian, // ICU 56 (draft)
    kCFMeasurementFormatterUnitLength_Millimeter, // ICU 53
    kCFMeasurementFormatterUnitLength_Nanometer, // ICU 54
    kCFMeasurementFormatterUnitLength_NauticalMile, // ICU 54
    kCFMeasurementFormatterUnitLength_Parsec, // ICU 54
    kCFMeasurementFormatterUnitLength_Picometer, // ICU 53
    kCFMeasurementFormatterUnitLength_Yard, // ICU 53
    kCFMeasurementFormatterUnitLight_Lux, // ICU 54
    kCFMeasurementFormatterUnitMass_Carat, // ICU 54
    kCFMeasurementFormatterUnitMass_Gram, // ICU 53
    kCFMeasurementFormatterUnitMass_Kilogram, // ICU 53
    kCFMeasurementFormatterUnitMass_MetricTon, // ICU 54
    kCFMeasurementFormatterUnitMass_Microgram, // ICU 54
    kCFMeasurementFormatterUnitMass_Milligram, // ICU 54
    kCFMeasurementFormatterUnitMass_Ounce, // ICU 53
    kCFMeasurementFormatterUnitMass_OunceTroy, // ICU 54
    kCFMeasurementFormatterUnitMass_Pound, // ICU 53
    kCFMeasurementFormatterUnitMass_Stone, // ICU 54
    kCFMeasurementFormatterUnitMass_Ton, // ICU 54
    kCFMeasurementFormatterUnitPower_Gigawatt, // ICU 54
    kCFMeasurementFormatterUnitPower_Horsepower, // ICU 53
    kCFMeasurementFormatterUnitPower_Kilowatt, // ICU 53
    kCFMeasurementFormatterUnitPower_Megawatt, // ICU 54
    kCFMeasurementFormatterUnitPower_Milliwatt, // ICU 54
    kCFMeasurementFormatterUnitPower_Watt, // ICU 53
    kCFMeasurementFormatterUnitPressure_Hectopascal, // ICU 53
    kCFMeasurementFormatterUnitPressure_InchHg, // ICU 53
    kCFMeasurementFormatterUnitPressure_Millibar, // ICU 53
    kCFMeasurementFormatterUnitPressure_MillimeterOfMercury, // ICU 54
    kCFMeasurementFormatterUnitPressure_PoundPerSquareInch, // ICU 54
    kCFMeasurementFormatterUnitSpeed_KilometerPerHour, // ICU 53
    kCFMeasurementFormatterUnitSpeed_Knot, // ICU 56 (draft)
    kCFMeasurementFormatterUnitSpeed_MeterPerSecond, // ICU 53
    kCFMeasurementFormatterUnitSpeed_MilePerHour, // ICU 53
    kCFMeasurementFormatterUnitTemperature_Celsius, // ICU 53
    kCFMeasurementFormatterUnitTemperature_Fahrenheit, // ICU 53
    kCFMeasurementFormatterUnitTemperature_Generic, // ICU 56 (draft)
    kCFMeasurementFormatterUnitTemperature_Kelvin, // ICU 54
    kCFMeasurementFormatterUnitVolume_AcreFoot, // ICU 54
    kCFMeasurementFormatterUnitVolume_Bushel, // ICU 54
    kCFMeasurementFormatterUnitVolume_Centiliter, // ICU 54
    kCFMeasurementFormatterUnitVolume_CubicCentimeter, // ICU 54
    kCFMeasurementFormatterUnitVolume_CubicFoot, // ICU 54
    kCFMeasurementFormatterUnitVolume_CubicInch, // ICU 54
    kCFMeasurementFormatterUnitVolume_CubicKilometer, // ICU 53
    kCFMeasurementFormatterUnitVolume_CubicMeter, // ICU 54
    kCFMeasurementFormatterUnitVolume_CubicMile, // ICU 53
    kCFMeasurementFormatterUnitVolume_CubicYard, // ICU 54
    kCFMeasurementFormatterUnitVolume_Cup, // ICU 54
    kCFMeasurementFormatterUnitVolume_CupMetric, // ICU 56 (draft)
    kCFMeasurementFormatterUnitVolume_Deciliter, // ICU 54
    kCFMeasurementFormatterUnitVolume_FluidOunce, // ICU 54
    kCFMeasurementFormatterUnitVolume_Gallon, // ICU 54
    kCFMeasurementFormatterUnitVolume_GallonImperial, // ICU 57 (draft)
    kCFMeasurementFormatterUnitVolume_Hectoliter, // ICU 54
    kCFMeasurementFormatterUnitVolume_Liter, // ICU 53
    kCFMeasurementFormatterUnitVolume_Megaliter, // ICU 54
    kCFMeasurementFormatterUnitVolume_Milliliter, // ICU 54
    kCFMeasurementFormatterUnitVolume_Pint, // ICU 54
    kCFMeasurementFormatterUnitVolume_PintMetric, // ICU 56 (draft)
    kCFMeasurementFormatterUnitVolume_Quart, // ICU 54
    kCFMeasurementFormatterUnitVolume_Tablespoon, // ICU 54
    kCFMeasurementFormatterUnitVolume_Teaspoon, // ICU 54
};
// End generated code

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
