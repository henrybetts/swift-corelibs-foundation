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
#else
    import SwiftFoundation
    import SwiftXCTest
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
        
        let mf = MeasurementFormatter()
        mf.locale = Locale(identifier: "en_US")
        
        XCTAssertEqual(mf.string(from: Measurement(value: 12.0, unit: UnitAcceleration.gravity)), "12 G")
        XCTAssertEqual(mf.string(from: Measurement(value: 12.0, unit: UnitAcceleration.metersPerSecondSquared)), "12 m/s²")
        
    }
    

}
