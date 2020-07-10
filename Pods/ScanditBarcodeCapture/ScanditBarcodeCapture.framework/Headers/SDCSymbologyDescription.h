/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCSymbology.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.0.0
 */
struct SDCRange {
/**
     * Added in version 6.0.0
     *
     * Minimum of the range.
     */
    NSInteger minimum;
/**
     * Added in version 6.0.0
     *
     * Maximum of the range.
     */
    NSInteger maximum;
/**
     * Added in version 6.0.0
     *
     * Step of the range.
     */
    NSInteger step;
};
typedef struct __attribute__((objc_boxable)) SDCRange SDCRange;

/**
 * Added in version 6.0.0
 *
 * Checks if a given range is fixed.
 */
SDC_EXTERN BOOL SDCRangeIsFixed(SDCRange range) NS_SWIFT_NAME(getter:SDCRange.isFixed(self:));

/**
 * Added in version 6.0.0
 *
 * Description specific to a particular barcode symbology.
 */
NS_SWIFT_NAME(SymbologyDescription)
SDC_EXPORTED_SYMBOL
@interface SDCSymbologyDescription : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.0.0
 *
 * Gets the symbology for a given identifier.
 *
 * Deprecated since version 6.1.0: Use symbologyDescriptionFromIdentifier: and symbology instead.
 */
+ (SDCSymbology)symbologyFromIdentifier:(nonnull NSString *)identifier;
+ (nonnull SDCSymbologyDescription *)symbologyDescriptionFromIdentifier:
    (nonnull NSString *)identifier;

/**
 * Added in version 6.0.0
 *
 * Creates a new symbology description for a given barcode symbology.
 */
- (instancetype)initWithSymbology:(SDCSymbology)symbology NS_DESIGNATED_INITIALIZER;

/**
 * Added in version 6.0.0
 *
 * Identifier of the symbology associated with this description.
 */
@property (nonatomic, nonnull, readonly) NSString *identifier;
/**
 * Added in version 6.0.0
 *
 * The human readable name of the symbology associated with this description.
 */
@property (nonatomic, nonnull, readonly) NSString *readableName;
/**
 * Added in version 6.0.0
 *
 * Determines whether the symbology associated with this description is available.
 */
@property (nonatomic, readonly) BOOL isAvailable;
/**
 * Added in version 6.0.0
 *
 * Determines whether decoding of color-inverted (bright on dark) codes for the symbology associated with this description is available.
 */
@property (nonatomic, readonly) BOOL isColorInvertible;
/**
 * Added in version 6.0.0
 *
 * The supported active symbol count range for the symbology associated with this description.
 */
@property (nonatomic, readonly) SDCRange activeSymbolCountRange;
/**
 * Added in version 6.0.0
 *
 * The default symbol count range for the symbology associated with this description.
 */
@property (nonatomic, readonly) SDCRange defaultSymbolCountRange;
/**
 * Added in version 6.0.0
 *
 * A list of extensions supported by the symbology associated with this description.
 */
@property (nonatomic, nonnull, readonly) NSSet<NSString *> *supportedExtensions;
/**
 * Added in version 6.1.0
 *
 * The symbology associated with this description.
 */
@property (nonatomic, readonly) SDCSymbology symbology;
/**
 * Added in version 6.0.0
 *
 * Gets a description of each available barcode symbology.
 */
@property (class, nonatomic, nonnull, readonly)
    NSArray<SDCSymbologyDescription *> *allSymbologyDescriptions NS_SWIFT_NAME(all);
/**
 * Added in version 6.1.0
 *
 * Returns the JSON representation of the symbology description.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

@end

NS_ASSUME_NONNULL_END
