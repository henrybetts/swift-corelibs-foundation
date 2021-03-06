# Implementation Status

This document lays out the structure of the Foundation project, and provides the current implementation status of each major feature.

Foundation is divided into groups of related functionality. These groups are currently laid out in the Xcode project, even though they are in a flat structure on disk.

As Foundation is a work in progress, not all methods and functionality are present. When implementations are completed, this list should be updated to reflect the current state of the library.

#### Table Key

##### Implementation Status
* _N/A_: This entity is internal or private and implemented ad hoc; there are no guidelines in place to suggest what completion might look like
* _Unimplemented_: This entity exists, but all functions and methods are `NSUnimplemented()`
* _Incomplete_: Implementation of this entity has begun, but critical sections have been left `NSUnimplemented()`
* _Mostly Complete_: All critical sections of this entity have been implemented, but some methods might remain `NSUnimplemented()`
* _Complete_: No methods are left `NSUnimplemented()` (though this is not a guarantee that work is complete -- there may be methods that need overriding or extra work)

##### Test Coverage
* _N/A_: This entity is internal and public tests are inappropriate, or it is an entity for which testing does not make sense
* _None_: There are no unit tests specific to this entity; even if it is used indirectly in other unit tests, we should have tests targeting this entity in isolation
* _Incomplete_: Unit tests exist for this entity, but there are critical paths that are not being tested
* _Substantial_: Most, if not all, of this entity's critical paths are being tested

There is no _Complete_ status for test coverage because there are always additional tests to be implemented. Even entities with _Substantial_ coverage are missing tests (e.g. `NSCoding` conformance, `NSCopying` conformance, `description`s, etc.)

### Entities

* **Runtime**: The basis for interoperability.
    The classes and methods in this group provide an interface for interoperability between C code and Swift. They also provide common layers used throughout the framework such as the root class `NSObject`.

    | Entity Name             | Status          | Test Coverage | Notes                                                                       |
    |-------------------------|-----------------|---------------|-----------------------------------------------------------------------------|
    | `NSEnumerator`          | Complete        | None          |                                                                             |
    | `NSGetSizeAndAlignment` | Complete        | None          |                                                                             |
    | `NSStringFromClass`     | Mostly Complete | None          | Only top-level Swift classes are supported                                  |
    | `NSClassFromString`     | Mostly Complete | None          | Only top-level Swift classes are supported; mangled names are not supported |
    | `NSObject`              | Complete        | None          |                                                                             |
    | `NSSwiftRuntime`        | N/A             | N/A           | For internal use only                                                       |
    | `Boxing`                | N/A             | N/A           | For internal use only                                                       |


* **URL**: Networking primitives

    The classes in this group provide functionality for manipulating URLs and paths via a common model object. The group also has classes for creating and receiving network connections.

    | Entity Name                  | Status          | Test Coverage | Notes                                                                                                              |
    |------------------------------|-----------------|---------------|--------------------------------------------------------------------------------------------------------------------|
    | `URLAuthenticationChallenge` | Unimplemented   | None          |                                                                                                                    |
    | `URLCache`                   | Unimplemented   | None          |                                                                                                                    |
    | `URLCredential`              | Mostly Complete | Incomplete    | `NSCoding` and `NSCopying` remain unimplemented                                                                    |
    | `URLCredentialStorage`       | Unimplemented   | None          |                                                                                                                    |
    | `NSURLError*`                | Complete        | N/A           |                                                                                                                    |
    | `URLProtectionSpace`         | Unimplemented   | None          |                                                                                                                    |
    | `URLProtocol`                | Unimplemented   | None          |                                                                                                                    |
    | `URLProtocolClient`          | Unimplemented   | None          |                                                                                                                    |
    | `NSURLRequest`               | Mostly Complete | Incomplete    | `NSCoding` remains unimplemented                                                                                   |
    | `NSMutableURLRequest`        | Mostly Complete | Incomplete    | `NSCoding` remains unimplemented                                                                                   |
    | `URLResponse`                | Mostly Complete | Incomplete    | `NSCoding` remains unimplemented                                                                                   |
    | `NSHTTPURLResponse`          | Mostly Complete | Substantial   | `NSCoding` remains unimplemented                                                                                   |
    | `NSURL`                      | Mostly Complete | Substantial   | `NSCoding` with non-keyed-coding archivers, `checkResourceIsReachable()`, and resource values remain unimplemented |
    | `NSURLQueryItem`             | Mostly Complete | N/A           | `NSCoding` remains unimplemented                                                                                   |
    | `URLResourceKey`             | Complete        | N/A           |                                                                                                                    |
    | `URLFileResourceType`        | Complete        | N/A           |                                                                                                                    |
    | `URL`                        | Complete        | Incomplete    |                                                                                                                    |
    | `URLResourceValues`          | Complete        | N/A           |                                                                                                                    |
    | `URLComponents`              | Complete        | Incomplete    |                                                                                                                    |
    | `URLRequest`                 | Complete        | None          |                                                                                                                    |
    | `HTTPCookie`                 | Complete        | Incomplete    |                                                                                                                    |
    | `HTTPCookiePropertyKey`      | Complete        | N/A           |                                                                                                                    |
    | `HTTPCookieStorage`          | Unimplemented   | None          |                                                                                                                    |
    | `Host`                       | Complete        | None          |                                                                                                                    |
    | `Configuration`              | N/A             | N/A           | For internal use only                                                                                              |
    | `EasyHandle`                 | N/A             | N/A           | For internal use only                                                                                              |
    | `HTTPBodySource`             | N/A             | N/A           | For internal use only                                                                                              |
    | `HTTPMessage`                | N/A             | N/A           | For internal use only                                                                                              |
    | `libcurlHelpers`             | N/A             | N/A           | For internal use only                                                                                              |
    | `MultiHandle`                | N/A             | N/A           | For internal use only                                                                                              |
    | `URLSession`                 | Mostly Complete | Incomplete    | `shared`, invalidation, resetting, flushing, getting tasks, and others remain unimplemented                        |
    | `URLSessionConfiguration`    | Mostly Complete | Incomplete    | `ephemeral` and `background(withIdentifier:)` remain unimplemented                                                 |
    | `URLSessionDelegate`         | Complete        | N/A           |                                                                                                                    |
    | `URLSessionTask`             | Mostly Complete | Incomplete    | `NSCopying`, `cancel()`, `error`, `createTransferState(url:)` with streams, and others remain unimplemented        |
    | `URLSessionDataTask`         | Complete        | Incomplete    |                                                                                                                    |
    | `URLSessionUploadTask`       | Complete        | None          |                                                                                                                    |
    | `URLSessionDownloadTask`     | Incomplete      | Incomplete    | `cancel(byProducingResumeData:)` remains unimplemented                                                             |
    | `URLSessionStreamTask`       | Unimplemented   | None          |                                                                                                                    |
    | `TaskRegistry`               | N/A             | N/A           | For internal use only                                                                                              |
    | `TransferState`              | N/A             | N/A           | For internal use only                                                                                              |


* **Formatters**: Locale and language-correct formatted values.

    This group contains the is the base `NSFormatter` class and its subclasses. These formatters can be used for dates, numbers, sizes, energy, and many other types.

    | Entity Name                     | Status          | Test Coverage | Notes                                                                                     |
    |---------------------------------|-----------------|---------------|-------------------------------------------------------------------------------------------|
    | `DateComponentFormatter`        | Unimplemented   | None          |                                                                                           |
    | `DateIntervalFormatter`         | Unimplemented   | None          |                                                                                           |
    | `EnergyFormatter`               | Unimplemented   | None          |                                                                                           |
    | `LengthFormatter`               | Unimplemented   | None          |                                                                                           |
    | `MassFormatter`                 | Unimplemented   | None          |                                                                                           |
    | `NumberFormatter`               | Mostly Complete | Substantial   | `objectValue(_:range:)` remains unimplemented                                             |
    | `PersonNameComponentsFormatter` | Unimplemented   | None          |                                                                                           |
    | `ByteCountFormatter`            | Unimplemented   | Incomplete    |                                                                                           |
    | `DateFormatter`                 | Mostly Complete | Incomplete    | `objectValue(_:range:)` and `setLocalizedDateFormatFromTemplate(_:)` remain unimplemented |
    | `Formatter`                     | Complete        | N/A           |                                                                                           |
    | `MeasurementFormatter`          | Unimplemented   | None          |                                                                                           |

* **Predicates**: Base functionality for building queries.

    This is the base class and subclasses for `NSPredicate` and `NSExpression`.

    | Entity Name             | Status        | Test Coverage | Notes                                                                              |
    |-------------------------|---------------|---------------|------------------------------------------------------------------------------------|
    | `NSExpression`          | Unimplemented | N/A           |                                                                                    |
    | `NSComparisonPredicate` | Unimplemented | N/A           |                                                                                    |
    | `NSCompoundPredicate`   | Complete      | Substantial   |                                                                                    |
    | `NSPredicate`           | Incomplete    | Incomplete    | Only boolean and block evaluations are implemented; all else remains unimplemented |

* **Serialization**: Serialization and deserialization functionality.

    The classes in this group perform tasks like parsing and writing JSON, property lists and binary archives.

    | Entity Name                 | Status          | Test Coverage | Notes                                                                         |
    |-----------------------------|-----------------|---------------|-------------------------------------------------------------------------------|
    | `NSJSONSerialization`       | Mostly Complete | Substantial   | `jsonObject(with:options:)` remains unimplemented                             |
    | `NSKeyedArchiver`           | Mostly Complete | Substantial   | `init()` and `encodedData` remain unimplemented                               |
    | `NSKeyedCoderOldStyleArray` | N/A             | N/A           | For internal use only                                                         |
    | `NSKeyedUnarchiver`         | Mostly Complete | Substantial   | `decodingFailurePolicy.set` remains unimplemented                             |
    | `NSKeyedArchiverHelpers`    | N/A             | N/A           | For internal use only                                                         |
    | `NSCoder`                   | Incomplete      | N/A           | Decoding methods which require a concrete implementation remain unimplemented |
    | `PropertyListSerialization` | Mostly Complete | Incomplete    | `propertyList(with:options:format:)` remains unimplemented                    |

* **XML**: A group of classes for parsing and representing XML documents and elements.

    The classes provided in this group are responsible for parsing and validating XML. They should be an interface for representing libxml2 in a more object-oriented manner.

    | Entity Name   | Status          | Test Coverage | Notes                                                                                                                                 |
    |---------------|-----------------|---------------|---------------------------------------------------------------------------------------------------------------------------------------|
    | `XMLDocument` | Mostly Complete | Substantial   | `init()`, `replacementClass(for:)`, and `object(byApplyingXSLT...)` remain unimplemented                                              |
    | `XMLDTD`      | Mostly Complete | Substantial   | `init()` remains unimplemented                                                                                                        |
    | `XMLDTDNode`  | Complete        | Incomplete    |                                                                                                                                       |
    | `XMLElement`  | Incomplete      | Incomplete    | `init(xmlString:)`, `elements(forLocalName:uri:)`, `attribute(forLocalName:uri:)`, namespace support, and others remain unimplemented |
    | `XMLNode`     | Incomplete      | Incomplete    | `localName(forName:)`, `prefix(forName:)`, `predefinedNamespace(forPrefix:)`, and others remain unimplemented                         |
    | `XMLParser`   | Complete        | Incomplete    |                                                                                                                                       |

* **Collections**: A group of classes to contain objects.

    The classes provided in this group provide basic collections. The primary role for these classes is to provide an interface layer between the CoreFoundation implementations and the standard library implementations. Additionally, they have useful extras like serialization support. There are also additional collection types that the standard library does not support.

     > _Note_: See [Known Issues](Issues.md) for more information about bridging between Foundation collection types and Swift standard library collection types.

    | Entity Name           | Status          | Test Coverage | Notes                                                                                                                                                               |
    |-----------------------|-----------------|---------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|
    | `NSOrderedSet`        | Mostly Complete | Substantial   | `NSCoding` with non-keyed-coding archivers, `NS[Mutable]Copying`, and `array` & `set` (and associated indexing methods) remain unimplemented                        |
    | `NSMutableOrderedSet` | Mostly Complete | Substantial   | `NSCoding` and `sortRange(_:options:, usingComparator:)` with non-empty options remain unimplemented                                                                |
    | `NSCFArray`           | N/A             | N/A           | For internal use only                                                                                                                                               |
    | `NSIndexSet`          | Mostly Complete | Incomplete    | `NSCoding`, `NSCopying`, and concurrent `enumerateWithOptions(_:range:paramType:returnType:block:)` remain unimplemented                                            |
    | `NSMutableIndexSet`   | Mostly Complete | Incomplete    | `shiftIndexesStarting(at:by:)` remains unimplemented                                                                                                                |
    | `IndexSet`            | Complete        | Incomplete    |                                                                                                                                                                     |
    | `NSIndexPath`         | Mostly Complete | None          | `NSCoding`, `NSCopying`, `getIndexes(_:)` remain unimplemented                                                                                                      |
    | `IndexPath`           | Complete        | Incomplete    |                                                                                                                                                                     |
    | `NSArray`             | Mostly Complete | Substantial   | Reading/writing to files/URLs, concurrent `enumerateObjects(at:options:using:)`, and `sortedArray(from:options:usingComparator:)` with options remain unimplemented |
    | `NSMutableArray`      | Mostly Complete | Substantial   | `exchangeObject(at:withObjectAt:)` and `replaceObjects(in:withObjectsFromArray:)` remain unimplemented for types other than `NSMutableArray`                        |
    | `NSDictionary`        | Mostly Complete | Incomplete    | `NSCoding` with non-keyed-coding archivers, `descriptionInStringsFileFormat`, `sharedKeySet(forKeys:)`, and reading/writing to files/URLs remain unimplemented      |
    | `NSMutableDictionary` | Mostly Complete | Incomplete    | `descriptionInStringsFileFormat`, `sharedKeySet(forKeys:)`, and reading/writing to files/URLs remain unimplemented                                                  |
    | `NSCFDictionary`      | N/A             | N/A           | For internal use only                                                                                                                                               |
    | `NSSet`               | Mostly Complete | Incomplete    | `description(withLocale:)` and `customMirror` remain unimplemented                                                                                                  |
    | `NSMutableSet`        | Mostly Complete | Incomplete    | `init?(coder:)` remains unimplemented                                                                                                                               |
    | `NSCountedSet`        | Mostly Complete | Incomplete    | `init?(coder:)` remains unimplemented                                                                                                                               |
    | `NSCFSet`             | N/A             | N/A           | For internal use only                                                                                                                                               |
    | `NSCache`             | Complete        | None          |                                                                                                                                                                     |
    | `NSSortDescriptor`    | Unimplemented   | None          |                                                                                                                                                                     |

* **RunLoop**: Timers, streams and run loops.

    The classes in this group provide support for scheduling work and acting upon input from external sources.

    | Entity Name      | Status          | Test Coverage | Notes                                                                         |
    |------------------|-----------------|---------------|-------------------------------------------------------------------------------|
    | `Port`           | Unimplemented   | None          |                                                                               |
    | `MessagePort`    | Unimplemented   | None          |                                                                               |
    | `SocketPort`     | Unimplemented   | None          |                                                                               |
    | `PortMessage`    | Unimplemented   | None          |                                                                               |
    | `RunLoop`        | Mostly Complete | Incomplete    | `add(_: Port, forMode:)` and `remove(_: Port, forMode:)` remain unimplemented |
    | `NSStream`       | Mostly Complete | Substantial   |                                                                               |
    | `Stream`         | Unimplemented   | Substantial   | Methods which require a concrete implementation remain unimplemented          |
    | `InputStream`    | Mostly Complete | Substantial   | `getBuffer(_:length:)` remains unimplemented                                  |
    | `NSOutputStream` | Complete        | Substantial   |                                                                               |
    | `Timer`          | Complete        | Substantial   |                                                                               |

* **String**: A set of classes for scanning, manipulating and storing string values.

    The NSString implementation is present to provide an interface layer between CoreFoundation and Swift, but it also adds additional functionality on top of the Swift standard library String type. Other classes in this group provide mechanisms to scan, match regular expressions, store attributes in run arrays attached to strings, and represent sets of characters.

    > _Note_: See [Known Issues](Issues.md) for more information about bridging between the Foundation NSString types and Swift standard library String type.

    | Entity Name                 | Status          | Test Coverage | Notes                                                                                                                                                            |
    |-----------------------------|-----------------|---------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------|
    | `RegularExpression`         | Mostly Complete | Substantial   | `NSCoding` remains unimplemented                                                                                                                                 |
    | `Scanner`                   | Mostly Complete | Incomplete    | `scanHex<T: _FloatLike>(_:locale:locationToScanFrom:to:)` and `localizedScannerWithString(_:)` remain unimplemented                                              |
    | `TextCheckingResult`        | Mostly Complete | Incomplete    | `NSCoding`, `NSCopying`, `resultType`, and `range(at:)` remain unimplemented                                                                                     |
    | `NSAttributedString`        | Incomplete      | Incomplete    | `NSCoding`, `NS[Mutable]Copying`, `attributedSubstring(from:)`, `isEqual(to:)`, `init(NSAttributedString:)`, and `enumerateAttributes(...)` remain unimplemented |
    | `NSMutableAttributedString` | Unimplemented   | Incomplete    | Only `addAttribute(_:value:range:)` is implemented                                                                                                               |
    | `NSCharacterSet`            | Mostly Complete | Incomplete    | `NSCoding` remains unimplemented                                                                                                                                 |
    | `NSMutableCharacterSet`     | Mostly Complete | None          | Decoding remains unimplemented                                                                                                                                   |
    | `NSCFCharacterSet`          | N/A             | N/A           | For internal use only                                                                                                                                            |
    | `CharacterSet`              | Complete        | Incomplete    |                                                                                                                                                                  |
    | `NSString`                  | Mostly Complete | Substantial   | `init(contentsOf:usedEncoding:)`, `init(contentsOfFile:usedEncoding:)`, `enumerateSubstrings(in:options:using:)` remain unimplemented                            |
    | `NSStringEncodings`         | Complete        | N/A           | Contains definitions of string encodings                                                                                                                         |
    | `NSCFString`                | N/A             | N/A           | For internal use only                                                                                                                                            |
    | `NSStringAPI`               | N/A             | N/A           | Exposes `NSString` APIs on `String`                                                                                                                              |
    | `ExtraStringAPIs`           | Complete        | N/A           | Random access for `String.UTF16View`, only when Foundation is imported; decouples the Swift core from a UTF16 representation.                                    |

* **Number**: A set of classes and methods for representing numeric values and structures.

    | Entity Name                       | Status          | Test Coverage | Notes                                                                         |
    |-----------------------------------|-----------------|---------------|-------------------------------------------------------------------------------|
    | `NSRange`                         | Mostly Complete | Incomplete    | `NSCoding` from non-keyed-coding archivers remains unimplemented              |
    | `Decimal`                         | Unimplemented   | None          |                                                                               |
    | `NSDecimalNumber`                 | Unimplemented   | None          |                                                                               |
    | `NSDecimalNumberHandler`          | Unimplemented   | None          |                                                                               |
    | `CGPoint`                         | Complete        | Substantial   |                                                                               |
    | `CGSize`                          | Complete        | Substantial   |                                                                               |
    | `CGRect`                          | Complete        | Substantial   |                                                                               |
    | `NSEdgeInsets`                    | Mostly Complete | None          | `NSCoding` from non-keyed-coding archivers remains unimplemented              |
    | `NSGeometry`                      | Mostly Complete | Substantial   | `NSIntegralRectWithOptions` `.AlignRectFlipped` support remains unimplemented |
    | `CGFloat`                         | Complete        | Substantial   |                                                                               |
    | `AffineTransform`                 | Complete        | None          |                                                                               |
    | `NSAffineTransform`               | Mostly Complete | Substnatial   | `NSCoding` remains unimplemented                                              |
    | `NSNumber`                        | Complete        | Incomplete    |                                                                               |
    | `NSConcreteValue`                 | N/A             | N/A           | For internal use only                                                         |
    | `NSSpecialValue`                  | N/A             | N/A           | For internal use only                                                         |
    | `NSValue`                         | Complete        | Substantial   |                                                                               |
    | `NSMeasurement`                   | Unimplemented   | None          |                                                                               |
    | `Measurement`                     | Complete        | None          |                                                                               |
    | `UnitConverter`                   | Complete        | Incomplete    |                                                                               |
    | `UnitConverterLinear`             | Complete        | Incomplete    |                                                                               |
    | `Unit`                            | Complete        | None          |                                                                               |
    | `Dimension`                       | Complete        | None          |                                                                               |
    | `UnitAcceleration`                | Complete        | None          |                                                                               |
    | `UnitAngle`                       | Complete        | None          |                                                                               |
    | `UnitArea`                        | Complete        | None          |                                                                               |
    | `UnitConcentrationMass`           | Complete        | None          |                                                                               |
    | `UnitDispersion`                  | Complete        | None          |                                                                               |
    | `UnitDuration`                    | Complete        | None          |                                                                               |
    | `UnitElectricCharge`              | Complete        | None          |                                                                               |
    | `UnitElectricCurrent`             | Complete        | None          |                                                                               |
    | `UnitElectricPotentialDifference` | Complete        | None          |                                                                               |
    | `UnitElectricResistance`          | Complete        | None          |                                                                               |
    | `UnitEnergy`                      | Complete        | None          |                                                                               |
    | `UnitFrequency`                   | Complete        | None          |                                                                               |
    | `UnitFuelEfficiency`              | Complete        | None          |                                                                               |
    | `UnitLength`                      | Complete        | None          |                                                                               |
    | `UnitIlluminance`                 | Complete        | None          |                                                                               |
    | `UnitMass`                        | Complete        | None          |                                                                               |
    | `UnitPower`                       | Complete        | None          |                                                                               |
    | `UnitPressure`                    | Complete        | None          |                                                                               |
    | `UnitSpeed`                       | Complete        | None          |                                                                               |
    | `UnitTemperature`                 | Complete        | None          |                                                                               |
    | `UnitVolume`                      | Complete        | None          |                                                                               |

* **UserDefaults**: A mechanism for storing values to persist as user settings and local.

    | Entity Name    | Statues         | Test Coverage | Notes                                                                                                                         |
    |----------------|-----------------|---------------|-------------------------------------------------------------------------------------------------------------------------------|
    | `UserDefaults` | Incomplete      | None          | `dictionaryRepresentation()`, domain support, and forced objects remain unimplemented. Unit tests are currently commented out |
    | `NSLocale`     | Mostly Complete | Incomplete    | `NSCoding` from non-keyed-coding archivers remains unimplemented. Only unit test asserts locale key constant names            |
    | `Locale`       | Complete        | Incomplete    | Only unit test asserts value copying                                                                                          |

* **OS**: Mechanisms for interacting with the operating system on a file system level as well as process and thread level

    | Entity Name      | Status          | Test Coverage | Notes                                                                                                                     |
    |------------------|-----------------|---------------|---------------------------------------------------------------------------------------------------------------------------|
    | `FileHandle`     | Mostly Complete | Incomplete    | `NSCoding`, `nullDevice`, and background operations remain unimplemented                                                  |
    | `Pipe`           | Complete        | Incomplete    |                                                                                                                           |
    | `FileManager`    | Incomplete      | Incomplete    | URL searches, relationship lookups, item copying, cross-device moving, recursive linking, and others remain unimplemented |
    | `Task`           | Mostly Complete | Substantial   | `interrupt()`, `terminate()`, `suspend()`, `resume()`, and `terminationReason` remain unimplemented                       |
    | `Bundle`         | Mostly Complete | Incomplete    | `allBundles`, `init(for:)`, `unload()`, `classNamed()`, and `principalClass` remain unimplemented                         |
    | `ProcessInfo`    | Complete        | Substantial   |                                                                                                                           |
    | `Thread`         | Incomplete      | Incomplete    | `isMainThread`, `mainThread`, `name`, `callStackReturnAddresses`, and `callStackSymbols` remain unimplemented             |
    | `Operation`      | Complete        | Incomplete    |                                                                                                                           |
    | `BlockOperation` | Complete        | Incomplete    |                                                                                                                           |
    | `OperationQueue` | Complete        | Incomplete    |                                                                                                                           |
    | `Lock`           | Mostly Complete | None          | `lock(before:)` remains unimplemented                                                                                     |
    | `ConditionLock`  | Complete        | None          |                                                                                                                           |
    | `RecursiveLock`  | Mostly Complete | None          | `lock(before:)` remains unimplemented                                                                                     |
    | `Condition`      | Complete        | None          |                                                                                                                           |

* **DateTime**: Classes for representing dates, timezones, and calendars.

    | Entity Name        | Status          | Test Coverage | Notes                                                                                                                           |
    |--------------------|-----------------|---------------|---------------------------------------------------------------------------------------------------------------------------------|
    | `NSCalendar`       | Mostly Complete | None          | `NSCoding` from non-keyed-coding archivers, `autoupdatingCurrent`, and `enumerateDates` remain unimplemented                    |
    | `NSDateComponents` | Mostly Complete | None          | `NSCoding` from non-keyed-coding archivers remains unimplemented                                                                |
    | `Calendar`         | Complete        | Incomplete    |                                                                                                                                 |
    | `DateComponents`   | Complete        | Incomplete    |                                                                                                                                 |
    | `NSDate`           | Mostly Complete | Incomplete    | Encoding to non-keyed-coding archivers and `timeIntervalSinceReferenceDate` remain unimplemented                                |
    | `NSDateInterval`   | Complete        | None          |                                                                                                                                 |
    | `DateInterval`     | Complete        | None          |                                                                                                                                 |
    | `Date`             | Complete        | Incomplete    |                                                                                                                                 |
    | `NSTimeZone`       | Mostly Complete | Incomplete    | `local` and setting `abbreviationDictionary` remain unimplemented |
    | `TimeZone`         | Complete        | Incomplete    |                                                                                                                                 |

* **Notifications**: Classes for loosely coupling events from a set of many observers.

    | Entity Name          | Status          | Test Coverage | Notes                                                      |
    |----------------------|-----------------|---------------|------------------------------------------------------------|
    | `NSNotification`     | Complete        | N/A           |                                                            |
    | `NotificationCenter` | Mostly Complete | Substantial   | Adding observers to non-`nil` queues remains unimplemented |
    | `Notification`       | Complete        | N/A           |                                                            |
    | `NotificationQueue`  | Complete        | Substantial   |                                                            |

* **Model**: Representations for abstract model elements like null, data, and errors.

    | Entity Name              | Status          | Test Coverage | Notes                             |
    |--------------------------|-----------------|---------------|-----------------------------------|
    | `NSNull`                 | Complete        | Substantial   |                                   |
    | `NSData`                 | Complete        | Substantial   |                                   |
    | `NSMutableData`          | Complete        | Substantial   |                                   |
    | `Data`                   | Complete        | Substantial   |                                   |
    | `NSProgress`             | Unimplemented   | None          |                                   |
    | `NSError`                | Complete        | None          |                                   |
    | `NSUUID`                 | Complete        | Substantial   |                                   |
    | `UUID`                   | Complete        | None          |                                   |
    | `NSPersonNameComponents` | Mostly Complete | None          | `NSCopying` remains unimplemented |
    | `PersonNameComponents`   | Complete        | None          |                                   |
