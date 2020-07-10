/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

@class SDCTrackedBarcode;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.0.0
 */
NS_SWIFT_NAME(BarcodeTrackingSession)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeTrackingSession : NSObject

/**
 * Added in version 6.0.0
 *
 * Newly tracked barcodes.
 */
@property (nonatomic, nonnull, readonly) NSArray<SDCTrackedBarcode *> *addedTrackedBarcodes;
/**
 * Added in version 6.0.0
 *
 * The identifiers of lost tracked barcodes that were removed.
 */
@property (nonatomic, nonnull, readonly) NSArray<NSNumber *> *removedTrackedBarcodes;
/**
 * Added in version 6.0.0
 *
 * Updated tracked barcodes (new location).
 */
@property (nonatomic, nonnull, readonly) NSArray<SDCTrackedBarcode *> *updatedTrackedBarcodes;
/**
 * Added in version 6.0.0
 *
 * A map from identifiers to tracked barcodes. It contains all currently tracked barcodes.
 */
@property (nonatomic, strong, readonly)
    NSDictionary<NSNumber *, SDCTrackedBarcode *> *trackedBarcodes;
/**
 * Added in version 6.1.0
 *
 * The identifier of the current frame sequence.
 *
 * As long as there is no interruptions of frames coming from the camera, the frameSequenceId will stay the same.
 */
@property (nonatomic, readonly) NSInteger frameSequenceId;
/**
 * Added in version 6.2.0
 *
 * Returns the JSON representation of the barcode tracking session.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
