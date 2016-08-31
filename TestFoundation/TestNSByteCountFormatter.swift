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



class TestNSByteCountFormatter : XCTestCase {
    
    static var allTests: [(String, (TestNSByteCountFormatter) -> () throws -> Void)] {
        return [
            ("test_DefaultValues", test_DefaultValues),
            ("test_zero", test_zero),
            ("test_singular", test_singular),
            ("test_decimal", test_decimal),
            ("test_binary", test_binary),
            ("test_allowedUnits", test_allowedUnits),
            ("test_components", test_components),
            ("test_fractionDigits", test_fractionDigits),
            ("test_negative", test_negative),
            ("test_large", test_large)
        ]
    }
    
    func test_DefaultValues() {
        let formatter = ByteCountFormatter()
        XCTAssertEqual(formatter.allowedUnits, ByteCountFormatter.Units.useDefault)
        XCTAssertEqual(formatter.countStyle, ByteCountFormatter.CountStyle.file)
        XCTAssertEqual(formatter.allowsNonnumericFormatting, true)
        XCTAssertEqual(formatter.includesUnit, true)
        XCTAssertEqual(formatter.includesCount, true)
        XCTAssertEqual(formatter.includesActualByteCount, false)
        XCTAssertEqual(formatter.isAdaptive, true)
        XCTAssertEqual(formatter.zeroPadsFractionDigits, false)
        XCTAssertEqual(formatter.formattingContext, Formatter.Context.unknown)
    }
    
    func test_zero() {
        
        let fm = ByteCountFormatter()
        XCTAssertEqual(fm.string(fromByteCount: 0), "Zero KB")
        
        fm.allowedUnits = .useBytes
        XCTAssertEqual(fm.string(fromByteCount: 0), "Zero bytes")
        
        fm.allowsNonnumericFormatting = false
        XCTAssertEqual(fm.string(fromByteCount: 0), "0 bytes")
        
        
    }
    
    func test_singular() {
        
        let fm = ByteCountFormatter()
        XCTAssertEqual(fm.string(fromByteCount: 1), "1 byte")
        
    }
    
    func test_decimal() {
        
        let fm = ByteCountFormatter()
        XCTAssertEqual(fm.string(fromByteCount: 10), "10 bytes")
        XCTAssertEqual(fm.string(fromByteCount: 10000), "10 KB")
        XCTAssertEqual(fm.string(fromByteCount: 10000000), "10 MB")
        XCTAssertEqual(fm.string(fromByteCount: 10000000000), "10 GB")
        XCTAssertEqual(fm.string(fromByteCount: 10000000000000), "10 TB")
        
    }
    
    func test_binary() {
        
        let fm = ByteCountFormatter()
        fm.countStyle = .memory
        
        XCTAssertEqual(fm.string(fromByteCount: 1024*1024*10), "10 MB")
        
    }
    
    func test_allowedUnits() {
        
        let fm = ByteCountFormatter()
        
        fm.allowedUnits = .useAll
        XCTAssertEqual(fm.string(fromByteCount: 50000000), "50 MB")
        
        fm.allowedUnits = .useGB
        XCTAssertEqual(fm.string(fromByteCount: 50000000), "0.05 GB")
        
        fm.allowedUnits = [.useGB, .useMB]
        XCTAssertEqual(fm.string(fromByteCount: 50000000), "50 MB")
        
        fm.allowedUnits = [.useKB, .useGB]
        XCTAssertEqual(fm.string(fromByteCount: 50000000), "50,000 KB")
        
    }
    
    func test_components() {
        
        let fm = ByteCountFormatter()
        fm.includesActualByteCount = true
        
        XCTAssertEqual(fm.string(fromByteCount: 10), "10 bytes")
        XCTAssertEqual(fm.string(fromByteCount: 10000), "10 KB (10,000 bytes)")
        
        fm.includesUnit = false
        XCTAssertEqual(fm.string(fromByteCount: 10), "10")
        
        fm.includesUnit = true
        fm.includesCount = false
        XCTAssertEqual(fm.string(fromByteCount: 10000), "KB")
        
        fm.includesCount = false
        fm.includesUnit = false
        XCTAssertEqual(fm.string(fromByteCount: 10000), "")
        
    }
    
    func test_fractionDigits() {
        
        let fm = ByteCountFormatter()
        
        XCTAssertEqual(fm.string(fromByteCount: 12345), "12 KB")
        XCTAssertEqual(fm.string(fromByteCount: 12345000), "12.3 MB")
        XCTAssertEqual(fm.string(fromByteCount: 12345000000), "12.35 GB")
        
        fm.isAdaptive = false
        XCTAssertEqual(fm.string(fromByteCount: 12345), "12.35 KB")
        
        fm.zeroPadsFractionDigits = true
        XCTAssertEqual(fm.string(fromByteCount: 12000), "12.00 KB")
        
    }
    
    func test_negative() {
        
        let fm = ByteCountFormatter()
        XCTAssertEqual(fm.string(fromByteCount: -1000), "-1 KB")
        
    }
    
    func test_large() {

        let fm = ByteCountFormatter()

        XCTAssertEqual(fm.string(for: NSNumber(value: 1.52e+19)), "15.2 EB")
        XCTAssertEqual(fm.string(for: NSNumber(value: 1.52e+25)), "15.2 YB")

    }
    
}
