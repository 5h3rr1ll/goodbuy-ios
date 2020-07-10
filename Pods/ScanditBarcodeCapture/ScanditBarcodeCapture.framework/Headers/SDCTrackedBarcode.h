/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCQuadrilateral.h>

@class SDCBarcode;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.0.0
 *
 * A barcode tracked over the course of multiple frames.
 *
 * The state of a SDCTrackedBarcode can be observed using a SDCBarcodeTrackingListener.
 *
 * The SDCBarcodeTrackingListener.barcodeTracking:didUpdate:frameData: callback will be invoked every time a new frame is processed and at least one of the following events took place:
 *
 *   1. A track is established.
 *
 *   2. A track location has changed.
 *
 *   3. A track is lost and can no longer be tracked.
 */
NS_SWIFT_NAME(TrackedBarcode)
SDC_EXPORTED_SYMBOL
@interface SDCTrackedBarcode : NSObject

/**
 * Added in version 6.0.0
 *
 * The time (in seconds) it will take the tracked barcode to move to the predictedLocation. This value can be used to animate the predicted change of location of the tracked barcode.
 */
@property (nonatomic, readonly) NSTimeInterval deltaTime;
/**
 * Added in version 6.0.0
 *
 * The location where the tracked barcode is predicted to be in deltaTime.
 *
 * @warning In case the feature is not licensed, a quadrilateral with all corners set to 0, 0 is returned.
 */
@property (nonatomic, readonly) SDCQuadrilateral predictedLocation;
/**
 * Added in version 6.0.0
 *
 * YES if it’s safe to animate from the current state to the next. As there are state transitions that do not guarantee a stable ordering of the location’s corners you should always check this property before animating a location change.
 */
@property (nonatomic, readonly) BOOL shouldAnimateFromPreviousToNextState;
/**
 * Added in version 6.0.0
 *
 * The unique identifier for the tracked barcode. The identifier is unique for each barcode. The same identifier may be reused once the barcode is lost for another barcode.
 */
@property (nonatomic, readonly) NSInteger identifier;
/**
 * Added in version 6.0.0
 *
 * The barcode associated to this track.
 */
@property (nonatomic, nonnull, readonly) SDCBarcode *barcode;
/**
 * Added in version 6.2.0
 *
 * Returns the JSON representation of the tracked barcode.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
