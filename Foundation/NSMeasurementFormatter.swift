// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2016 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

import CoreFoundation

// Begin generated code
// See generate.py
#if os(OSX) || os(iOS)
private let kCFMeasurementFormatterUnitAcceleration_GForce = CFMeasurementFormatterUnit.acceleration_GForce
private let kCFMeasurementFormatterUnitAcceleration_MeterPerSecondSquared = CFMeasurementFormatterUnit.acceleration_MeterPerSecondSquared
private let kCFMeasurementFormatterUnitAngle_ArcMinute = CFMeasurementFormatterUnit.angle_ArcMinute
private let kCFMeasurementFormatterUnitAngle_ArcSecond = CFMeasurementFormatterUnit.angle_ArcSecond
private let kCFMeasurementFormatterUnitAngle_Degree = CFMeasurementFormatterUnit.angle_Degree
private let kCFMeasurementFormatterUnitAngle_Radian = CFMeasurementFormatterUnit.angle_Radian
private let kCFMeasurementFormatterUnitAngle_Revolution = CFMeasurementFormatterUnit.angle_Revolution
private let kCFMeasurementFormatterUnitArea_Acre = CFMeasurementFormatterUnit.area_Acre
private let kCFMeasurementFormatterUnitArea_Hectare = CFMeasurementFormatterUnit.area_Hectare
private let kCFMeasurementFormatterUnitArea_SquareCentimeter = CFMeasurementFormatterUnit.area_SquareCentimeter
private let kCFMeasurementFormatterUnitArea_SquareFoot = CFMeasurementFormatterUnit.area_SquareFoot
private let kCFMeasurementFormatterUnitArea_SquareInch = CFMeasurementFormatterUnit.area_SquareInch
private let kCFMeasurementFormatterUnitArea_SquareKilometer = CFMeasurementFormatterUnit.area_SquareKilometer
private let kCFMeasurementFormatterUnitArea_SquareMeter = CFMeasurementFormatterUnit.area_SquareMeter
private let kCFMeasurementFormatterUnitArea_SquareMile = CFMeasurementFormatterUnit.area_SquareMile
private let kCFMeasurementFormatterUnitArea_SquareYard = CFMeasurementFormatterUnit.area_SquareYard
private let kCFMeasurementFormatterUnitConcentr_Karat = CFMeasurementFormatterUnit.concentr_Karat
private let kCFMeasurementFormatterUnitConcentr_MilligramPerDeciliter = CFMeasurementFormatterUnit.concentr_MilligramPerDeciliter
private let kCFMeasurementFormatterUnitConcentr_MillimolePerLiter = CFMeasurementFormatterUnit.concentr_MillimolePerLiter
private let kCFMeasurementFormatterUnitConcentr_PartPerMillion = CFMeasurementFormatterUnit.concentr_PartPerMillion
private let kCFMeasurementFormatterUnitConsumption_LiterPer100Kilometers = CFMeasurementFormatterUnit.consumption_LiterPer100Kilometers
private let kCFMeasurementFormatterUnitConsumption_LiterPerKilometer = CFMeasurementFormatterUnit.consumption_LiterPerKilometer
private let kCFMeasurementFormatterUnitConsumption_MilePerGallon = CFMeasurementFormatterUnit.consumption_MilePerGallon
private let kCFMeasurementFormatterUnitConsumption_MilePerGallonImperial = CFMeasurementFormatterUnit.consumption_MilePerGallonImperial
private let kCFMeasurementFormatterUnitDigital_Bit = CFMeasurementFormatterUnit.digital_Bit
private let kCFMeasurementFormatterUnitDigital_Byte = CFMeasurementFormatterUnit.digital_Byte
private let kCFMeasurementFormatterUnitDigital_Gigabit = CFMeasurementFormatterUnit.digital_Gigabit
private let kCFMeasurementFormatterUnitDigital_Gigabyte = CFMeasurementFormatterUnit.digital_Gigabyte
private let kCFMeasurementFormatterUnitDigital_Kilobit = CFMeasurementFormatterUnit.digital_Kilobit
private let kCFMeasurementFormatterUnitDigital_Kilobyte = CFMeasurementFormatterUnit.digital_Kilobyte
private let kCFMeasurementFormatterUnitDigital_Megabit = CFMeasurementFormatterUnit.digital_Megabit
private let kCFMeasurementFormatterUnitDigital_Megabyte = CFMeasurementFormatterUnit.digital_Megabyte
private let kCFMeasurementFormatterUnitDigital_Terabit = CFMeasurementFormatterUnit.digital_Terabit
private let kCFMeasurementFormatterUnitDigital_Terabyte = CFMeasurementFormatterUnit.digital_Terabyte
private let kCFMeasurementFormatterUnitDuration_Century = CFMeasurementFormatterUnit.duration_Century
private let kCFMeasurementFormatterUnitDuration_Day = CFMeasurementFormatterUnit.duration_Day
private let kCFMeasurementFormatterUnitDuration_Hour = CFMeasurementFormatterUnit.duration_Hour
private let kCFMeasurementFormatterUnitDuration_Microsecond = CFMeasurementFormatterUnit.duration_Microsecond
private let kCFMeasurementFormatterUnitDuration_Millisecond = CFMeasurementFormatterUnit.duration_Millisecond
private let kCFMeasurementFormatterUnitDuration_Minute = CFMeasurementFormatterUnit.duration_Minute
private let kCFMeasurementFormatterUnitDuration_Month = CFMeasurementFormatterUnit.duration_Month
private let kCFMeasurementFormatterUnitDuration_Nanosecond = CFMeasurementFormatterUnit.duration_Nanosecond
private let kCFMeasurementFormatterUnitDuration_Second = CFMeasurementFormatterUnit.duration_Second
private let kCFMeasurementFormatterUnitDuration_Week = CFMeasurementFormatterUnit.duration_Week
private let kCFMeasurementFormatterUnitDuration_Year = CFMeasurementFormatterUnit.duration_Year
private let kCFMeasurementFormatterUnitElectric_Ampere = CFMeasurementFormatterUnit.electric_Ampere
private let kCFMeasurementFormatterUnitElectric_Milliampere = CFMeasurementFormatterUnit.electric_Milliampere
private let kCFMeasurementFormatterUnitElectric_Ohm = CFMeasurementFormatterUnit.electric_Ohm
private let kCFMeasurementFormatterUnitElectric_Volt = CFMeasurementFormatterUnit.electric_Volt
private let kCFMeasurementFormatterUnitEnergy_Calorie = CFMeasurementFormatterUnit.energy_Calorie
private let kCFMeasurementFormatterUnitEnergy_Foodcalorie = CFMeasurementFormatterUnit.energy_Foodcalorie
private let kCFMeasurementFormatterUnitEnergy_Joule = CFMeasurementFormatterUnit.energy_Joule
private let kCFMeasurementFormatterUnitEnergy_Kilocalorie = CFMeasurementFormatterUnit.energy_Kilocalorie
private let kCFMeasurementFormatterUnitEnergy_Kilojoule = CFMeasurementFormatterUnit.energy_Kilojoule
private let kCFMeasurementFormatterUnitEnergy_KilowattHour = CFMeasurementFormatterUnit.energy_KilowattHour
private let kCFMeasurementFormatterUnitFrequency_Gigahertz = CFMeasurementFormatterUnit.frequency_Gigahertz
private let kCFMeasurementFormatterUnitFrequency_Hertz = CFMeasurementFormatterUnit.frequency_Hertz
private let kCFMeasurementFormatterUnitFrequency_Kilohertz = CFMeasurementFormatterUnit.frequency_Kilohertz
private let kCFMeasurementFormatterUnitFrequency_Megahertz = CFMeasurementFormatterUnit.frequency_Megahertz
private let kCFMeasurementFormatterUnitLength_AstronomicalUnit = CFMeasurementFormatterUnit.length_AstronomicalUnit
private let kCFMeasurementFormatterUnitLength_Centimeter = CFMeasurementFormatterUnit.length_Centimeter
private let kCFMeasurementFormatterUnitLength_Decimeter = CFMeasurementFormatterUnit.length_Decimeter
private let kCFMeasurementFormatterUnitLength_Fathom = CFMeasurementFormatterUnit.length_Fathom
private let kCFMeasurementFormatterUnitLength_Foot = CFMeasurementFormatterUnit.length_Foot
private let kCFMeasurementFormatterUnitLength_Furlong = CFMeasurementFormatterUnit.length_Furlong
private let kCFMeasurementFormatterUnitLength_Inch = CFMeasurementFormatterUnit.length_Inch
private let kCFMeasurementFormatterUnitLength_Kilometer = CFMeasurementFormatterUnit.length_Kilometer
private let kCFMeasurementFormatterUnitLength_LightYear = CFMeasurementFormatterUnit.length_LightYear
private let kCFMeasurementFormatterUnitLength_Meter = CFMeasurementFormatterUnit.length_Meter
private let kCFMeasurementFormatterUnitLength_Micrometer = CFMeasurementFormatterUnit.length_Micrometer
private let kCFMeasurementFormatterUnitLength_Mile = CFMeasurementFormatterUnit.length_Mile
private let kCFMeasurementFormatterUnitLength_MileScandinavian = CFMeasurementFormatterUnit.length_MileScandinavian
private let kCFMeasurementFormatterUnitLength_Millimeter = CFMeasurementFormatterUnit.length_Millimeter
private let kCFMeasurementFormatterUnitLength_Nanometer = CFMeasurementFormatterUnit.length_Nanometer
private let kCFMeasurementFormatterUnitLength_NauticalMile = CFMeasurementFormatterUnit.length_NauticalMile
private let kCFMeasurementFormatterUnitLength_Parsec = CFMeasurementFormatterUnit.length_Parsec
private let kCFMeasurementFormatterUnitLength_Picometer = CFMeasurementFormatterUnit.length_Picometer
private let kCFMeasurementFormatterUnitLength_Yard = CFMeasurementFormatterUnit.length_Yard
private let kCFMeasurementFormatterUnitLight_Lux = CFMeasurementFormatterUnit.light_Lux
private let kCFMeasurementFormatterUnitMass_Carat = CFMeasurementFormatterUnit.mass_Carat
private let kCFMeasurementFormatterUnitMass_Gram = CFMeasurementFormatterUnit.mass_Gram
private let kCFMeasurementFormatterUnitMass_Kilogram = CFMeasurementFormatterUnit.mass_Kilogram
private let kCFMeasurementFormatterUnitMass_MetricTon = CFMeasurementFormatterUnit.mass_MetricTon
private let kCFMeasurementFormatterUnitMass_Microgram = CFMeasurementFormatterUnit.mass_Microgram
private let kCFMeasurementFormatterUnitMass_Milligram = CFMeasurementFormatterUnit.mass_Milligram
private let kCFMeasurementFormatterUnitMass_Ounce = CFMeasurementFormatterUnit.mass_Ounce
private let kCFMeasurementFormatterUnitMass_OunceTroy = CFMeasurementFormatterUnit.mass_OunceTroy
private let kCFMeasurementFormatterUnitMass_Pound = CFMeasurementFormatterUnit.mass_Pound
private let kCFMeasurementFormatterUnitMass_Stone = CFMeasurementFormatterUnit.mass_Stone
private let kCFMeasurementFormatterUnitMass_Ton = CFMeasurementFormatterUnit.mass_Ton
private let kCFMeasurementFormatterUnitPower_Gigawatt = CFMeasurementFormatterUnit.power_Gigawatt
private let kCFMeasurementFormatterUnitPower_Horsepower = CFMeasurementFormatterUnit.power_Horsepower
private let kCFMeasurementFormatterUnitPower_Kilowatt = CFMeasurementFormatterUnit.power_Kilowatt
private let kCFMeasurementFormatterUnitPower_Megawatt = CFMeasurementFormatterUnit.power_Megawatt
private let kCFMeasurementFormatterUnitPower_Milliwatt = CFMeasurementFormatterUnit.power_Milliwatt
private let kCFMeasurementFormatterUnitPower_Watt = CFMeasurementFormatterUnit.power_Watt
private let kCFMeasurementFormatterUnitPressure_Hectopascal = CFMeasurementFormatterUnit.pressure_Hectopascal
private let kCFMeasurementFormatterUnitPressure_InchHg = CFMeasurementFormatterUnit.pressure_InchHg
private let kCFMeasurementFormatterUnitPressure_Millibar = CFMeasurementFormatterUnit.pressure_Millibar
private let kCFMeasurementFormatterUnitPressure_MillimeterOfMercury = CFMeasurementFormatterUnit.pressure_MillimeterOfMercury
private let kCFMeasurementFormatterUnitPressure_PoundPerSquareInch = CFMeasurementFormatterUnit.pressure_PoundPerSquareInch
private let kCFMeasurementFormatterUnitSpeed_KilometerPerHour = CFMeasurementFormatterUnit.speed_KilometerPerHour
private let kCFMeasurementFormatterUnitSpeed_Knot = CFMeasurementFormatterUnit.speed_Knot
private let kCFMeasurementFormatterUnitSpeed_MeterPerSecond = CFMeasurementFormatterUnit.speed_MeterPerSecond
private let kCFMeasurementFormatterUnitSpeed_MilePerHour = CFMeasurementFormatterUnit.speed_MilePerHour
private let kCFMeasurementFormatterUnitTemperature_Celsius = CFMeasurementFormatterUnit.temperature_Celsius
private let kCFMeasurementFormatterUnitTemperature_Fahrenheit = CFMeasurementFormatterUnit.temperature_Fahrenheit
private let kCFMeasurementFormatterUnitTemperature_Generic = CFMeasurementFormatterUnit.temperature_Generic
private let kCFMeasurementFormatterUnitTemperature_Kelvin = CFMeasurementFormatterUnit.temperature_Kelvin
private let kCFMeasurementFormatterUnitVolume_AcreFoot = CFMeasurementFormatterUnit.volume_AcreFoot
private let kCFMeasurementFormatterUnitVolume_Bushel = CFMeasurementFormatterUnit.volume_Bushel
private let kCFMeasurementFormatterUnitVolume_Centiliter = CFMeasurementFormatterUnit.volume_Centiliter
private let kCFMeasurementFormatterUnitVolume_CubicCentimeter = CFMeasurementFormatterUnit.volume_CubicCentimeter
private let kCFMeasurementFormatterUnitVolume_CubicFoot = CFMeasurementFormatterUnit.volume_CubicFoot
private let kCFMeasurementFormatterUnitVolume_CubicInch = CFMeasurementFormatterUnit.volume_CubicInch
private let kCFMeasurementFormatterUnitVolume_CubicKilometer = CFMeasurementFormatterUnit.volume_CubicKilometer
private let kCFMeasurementFormatterUnitVolume_CubicMeter = CFMeasurementFormatterUnit.volume_CubicMeter
private let kCFMeasurementFormatterUnitVolume_CubicMile = CFMeasurementFormatterUnit.volume_CubicMile
private let kCFMeasurementFormatterUnitVolume_CubicYard = CFMeasurementFormatterUnit.volume_CubicYard
private let kCFMeasurementFormatterUnitVolume_Cup = CFMeasurementFormatterUnit.volume_Cup
private let kCFMeasurementFormatterUnitVolume_CupMetric = CFMeasurementFormatterUnit.volume_CupMetric
private let kCFMeasurementFormatterUnitVolume_Deciliter = CFMeasurementFormatterUnit.volume_Deciliter
private let kCFMeasurementFormatterUnitVolume_FluidOunce = CFMeasurementFormatterUnit.volume_FluidOunce
private let kCFMeasurementFormatterUnitVolume_Gallon = CFMeasurementFormatterUnit.volume_Gallon
private let kCFMeasurementFormatterUnitVolume_GallonImperial = CFMeasurementFormatterUnit.volume_GallonImperial
private let kCFMeasurementFormatterUnitVolume_Hectoliter = CFMeasurementFormatterUnit.volume_Hectoliter
private let kCFMeasurementFormatterUnitVolume_Liter = CFMeasurementFormatterUnit.volume_Liter
private let kCFMeasurementFormatterUnitVolume_Megaliter = CFMeasurementFormatterUnit.volume_Megaliter
private let kCFMeasurementFormatterUnitVolume_Milliliter = CFMeasurementFormatterUnit.volume_Milliliter
private let kCFMeasurementFormatterUnitVolume_Pint = CFMeasurementFormatterUnit.volume_Pint
private let kCFMeasurementFormatterUnitVolume_PintMetric = CFMeasurementFormatterUnit.volume_PintMetric
private let kCFMeasurementFormatterUnitVolume_Quart = CFMeasurementFormatterUnit.volume_Quart
private let kCFMeasurementFormatterUnitVolume_Tablespoon = CFMeasurementFormatterUnit.volume_Tablespoon
private let kCFMeasurementFormatterUnitVolume_Teaspoon = CFMeasurementFormatterUnit.volume_Teaspoon
#endif
// End generated code

extension MeasurementFormatter {
    public struct UnitOptions : OptionSet {
        public private(set) var rawValue: UInt
        public init(rawValue: UInt) { self.rawValue = rawValue }
        
        
        public static let providedUnit = UnitOptions(rawValue: 1 << 0)
        
        public static let naturalScale = UnitOptions(rawValue: 1 << 1)
        
        public static let temperatureWithoutUnit = UnitOptions(rawValue: 1 << 2)
    }
}

open class MeasurementFormatter : Formatter, NSSecureCoding {
    
    private var __cfFormatter: CFMeasurementFormatter? = nil
    private var _cfFormatter: CFMeasurementFormatter {
        
        if (__cfFormatter == nil){
            
            let cfStyle: CFMeasurementFormatterStyle
            switch unitStyle {
            case .long:
                cfStyle = .wide
            case .medium:
                cfStyle = .short
            case .short:
                cfStyle = .narrow
            }
            
            __cfFormatter = CFMeasurementFormatterCreate(kCFAllocatorDefault, locale._cfObject, cfStyle, numberFormatter._cfFormatter)
            
        }
        
        return __cfFormatter!
        
    }
    
    private func reset(){
        __cfFormatter = nil
    }
    
    /*
     This property can be set to ensure that the formatter behaves in a way the developer expects, even if it is not standard according to the preferences of the user's locale. If not specified, unitOptions defaults to localizing according to the preferences of the locale.
     
     Ex:
     
     By default, if unitOptions is set to the empty set, the formatter will do the following:
     - kilocalories may be formatted as "C" instead of "kcal" depending on the locale.
     - kilometersPerHour may be formatted as "miles per hour" for US and UK locales but "kilometers per hour" for other locales.
     
     However, if NSMeasurementFormatterUnitOptionsProvidedUnit is set, the formatter will do the following:
     - kilocalories would be formatted as "kcal" in the language of the locale, even if the locale prefers "C".
     - kilometersPerHour would be formatted as "kilometers per hour" for US and UK locales even though the preference is for "miles per hour."
     
     Note that NSMeasurementFormatter will handle converting measurement objects to the preferred units in a particular locale.  For instance, if provided a measurement object in kilometers and the set locale is en_US, the formatter will implicitly convert the measurement object to miles and return the formatted string as the equivalent measurement in miles.
     
     */
    open var unitOptions: MeasurementFormatter.UnitOptions = []
    
    
    /*
     If not specified, unitStyle is set to NSFormattingUnitStyleMedium.
     */
    open var unitStyle: Formatter.UnitStyle = .medium {
        didSet{
            reset()
        }
    }
    
    
    /*
     If not specified, locale is set to the user's current locale.
     */
    /*@NSCopying*/ open var locale: Locale! = Locale.current {
        didSet{
            reset()
        }
    }
    
    
    /*
     If not specified, the number formatter is set up with NSNumberFormatterDecimalStyle.
     */
    private var _numberFormatter: NumberFormatter? = nil
    open var numberFormatter: NumberFormatter! {
        get{
            if let obj = _numberFormatter{
                return obj
            }else{
                let obj = NumberFormatter()
                obj.numberStyle = .decimal
                _numberFormatter = obj
                reset()
                return obj
            }
        }
        set{
            _numberFormatter = newValue
            reset()
        }
    }
    
    private func cfUnit(from unit: Unit) -> CFMeasurementFormatterUnit?{
        
        if unit is UnitAcceleration {
            
            switch unit.symbol {
            case UnitAcceleration.Symbol.gravity:
                return kCFMeasurementFormatterUnitAcceleration_GForce
            case UnitAcceleration.Symbol.metersPerSecondSquared:
                return kCFMeasurementFormatterUnitAcceleration_MeterPerSecondSquared
            default:
                return nil
            }
            
        }else if unit is UnitAngle {
            
        }else if unit is UnitArea {
            
        }else if unit is UnitConcentrationMass {
            
        }else if unit is UnitDispersion {
            
        }else if unit is UnitDuration {
            
        }else if unit is UnitElectricCharge {
            
        }else if unit is UnitElectricCurrent {
            
        }else if unit is UnitElectricPotentialDifference {
            
        }else if unit is UnitElectricResistance {
            
        }else if unit is UnitEnergy {
            
        }else if unit is UnitFrequency {
            
        }else if unit is UnitFuelEfficiency {
            
        }else if unit is UnitIlluminance {
            
        }else if unit is UnitLength {
            
        }else if unit is UnitMass {
            
        }else if unit is UnitPower {
            
        }else if unit is UnitPressure {
            
        }else if unit is UnitSpeed {
            
        }else if unit is UnitTemperature {
            
        }else if unit is UnitVolume {
            
        }

        return nil

    }
    
    
    open func string<UnitType: Unit>(from measurement: Measurement<UnitType>) -> String {
        
        if let cfUnit = cfUnit(from: measurement.unit) {
            
            if let string = CFMeasurementFormatterCreateString(kCFAllocatorDefault, _cfFormatter, measurement.value, cfUnit) {
                
                return string._swiftObject
                
            }
            
        }
        
        //if localization fails, return formatted number + symbol
        guard let numberString = numberFormatter.string(from: NSNumber(value: measurement.value)) else { return "" }
        return numberString + measurement.unit.symbol
        
    }
    
    
    /*
     @param An NSUnit
     @return A formatted string representing the localized form of the unit without a value attached to it.  This method will return [unit symbol] if the provided unit cannot be localized.
     */
    open func string(from unit: Unit) -> String { NSUnimplemented() }
    
    public override init() {
        super.init()
    }
    
    public required init?(coder aDecoder: NSCoder) { NSUnimplemented() }
    open override func encode(with aCoder: NSCoder) { NSUnimplemented() }
    public static var supportsSecureCoding: Bool { return true }
}
