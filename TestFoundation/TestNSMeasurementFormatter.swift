// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2016 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

#if DEPLOYMENT_RUNTIME_OBJC || os(Linux)
    import Foundation
    import XCTest
    import CoreFoundation
#else
    import SwiftFoundation
    import SwiftXCTest
    import CoreFoundation
#endif



class TestMeasurementFormatter: XCTestCase {
    
    static var allTests: [(String, (TestMeasurementFormatter) -> () throws -> Void)] {
        return [
            ("test_construct", test_construct),
            ("test_format", test_format)
        ]
    }
    
    func test_construct(){
        
        let mf = MeasurementFormatter()
        
        XCTAssertEqual(mf.unitOptions, [])
        XCTAssertEqual(mf.unitStyle, Formatter.UnitStyle.medium)
        XCTAssertEqual(mf.locale, Locale.current)
        XCTAssertNotNil(mf.numberFormatter)
        XCTAssertEqual(mf.numberFormatter.numberStyle, NumberFormatter.Style.decimal)
        
        
    }
 
    func test_format(){

        struct UnitData{
            let unit: Unit
            let version: Int32
            let symbol: String
            let short: String
            let medium: String
            let long: String
            init(_ unit:Unit, _ version:Int32, _ symbol:String, _ short:String, _ medium:String, _ long:String) {
                self.unit = unit
                self.version = version
                self.symbol = symbol
                self.short = short
                self.medium = medium
                self.long = long
            }
        }
        
        let data = [
            
            //          Unit, ICU version, symbol, ICU narrow, ICU short, ICU wide
            
            UnitData(UnitAcceleration.gravity, 53, "12g", "12Gs", "12 G", "12 g-force"),
            UnitData(UnitAcceleration.metersPerSecondSquared, 54, "12m/s²", "12m/s²", "12 m/s²", "12 meters per second squared")
        ]
        
        
        let locale = Locale(identifier: "en_US")
        
        let short = MeasurementFormatter()
        short.unitStyle = .short
        short.locale = locale
        
        let medium = MeasurementFormatter()
        medium.unitStyle = .medium
        medium.locale = locale
        
        let long = MeasurementFormatter()
        long.unitStyle = .long
        long.locale = locale
        
        for unitData in data {
            
            let measurement = Measurement(value: 12, unit: unitData.unit)
            
            if (kCFMeasurementFormatterIsAvailable && unitData.version <= U_ICU_VERSION_MAJOR_NUM){
                
                XCTAssertEqual(short.string(from: measurement), unitData.short, "Testing short style")
                XCTAssertEqual(medium.string(from: measurement), unitData.medium, "Testing medium style")
                XCTAssertEqual(long.string(from: measurement), unitData.long, "Testing long style")
                
            }else{
                
                XCTAssertEqual(short.string(from: measurement), unitData.symbol, "Testing built-in symbol (ICU unavailable)")
                
            }
            
        }
        
    }
    

}
