/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCDataCaptureMode.h>

@class SDCDataCaptureContext;
@class SDCBarcodeTracking;
@class SDCBarcodeTrackingSettings;
@class SDCBarcodeTrackingSession;
@class SDCCameraSettings;

@protocol SDCFrameData;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.0.0
 *
 * The BarcodeTracking delegate is the main way for hooking into BarcodeTracking. It provides a callback that is invoked when the state of tracked barcodes changes.
 */
NS_SWIFT_NAME(BarcodeTrackingListener)
@protocol SDCBarcodeTrackingListener <NSObject>

@required

/**
 * Added in version 6.0.0
 *
 * Called for every processed frame if one or more of the following events happened:
 *
 *   1. A track is established.
 *
 *   2. A track location has changed.
 *
 *   3. A track is lost and can no longer be tracked.
 */
- (void)barcodeTracking:(nonnull SDCBarcodeTracking *)barcodeTracking
              didUpdate:(nonnull SDCBarcodeTrackingSession *)session
              frameData:(nonnull id<SDCFrameData>)frameData;

@optional

/**
 * Added in version 6.0.0
 *
 * Called when the listener starts observing the BarcodeTracking instance.
 */
- (void)didStartObservingBarcodeTracking:(nonnull SDCBarcodeTracking *)barcodeTracking;

/**
 * Added in version 6.0.0
 *
 * Called when the listener stops observing the BarcodeTracking instance.
 */
- (void)didStopObservingBarcodeTracking:(nonnull SDCBarcodeTracking *)barcodeTracking;

@end

/**
 * Added in version 6.0.0
 *
 * Data capture mode that implements MatrixScan (barcode tracking).
 *
 * Learn more on how to use barcode tracking in our Get Started With MatrixScan guide.
 *
 * This capture mode uses the barcode scanning and tracking capabilities. It cannot be used together with other capture modes that require the same capabilities, e.g. SDCBarcodeCapture or SDCLabelCapture.
 */
NS_SWIFT_NAME(BarcodeTracking)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeTracking : NSObject <SDCDataCaptureMode>

/**
 * Added in version 6.1.0
 *
 * Returns the recommended camera settings for use with barcode tracking.
 */
@property (class, nonatomic, nonnull, readonly) SDCCameraSettings *recommendedCameraSettings;
/**
 * Added in version 6.0.0
 *
 * Implemented from SDCDataCaptureMode. See SDCDataCaptureMode.context.
 */
@property (nonatomic, nullable, readonly) SDCDataCaptureContext *context;
/**
 * Added in version 6.0.0
 *
 * Implemented from SDCDataCaptureMode. See SDCDataCaptureMode.enabled.
 */
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.0.0
 *
 * Constructs a new barcode tracking mode with the provided context and settings. When the context is not nil, the capture mode is automatically added to the context.
 */
+ (instancetype)barcodeTrackingWithContext:(nullable SDCDataCaptureContext *)context
                                  settings:(nonnull SDCBarcodeTrackingSettings *)settings;

/**
 * Added in version 6.0.0
 *
 * Constructs a new barcode tracking mode with the provided JSON serialization. See Serialization for details. The capture mode is automatically added to the context.
 */
+ (nullable instancetype)barcodeTrackingFromJSONString:(nonnull NSString *)jsonString
                                               context:(nonnull SDCDataCaptureContext *)context
                                                 error:(NSError *_Nullable *_Nullable)error
    NS_SWIFT_NAME(init(jsonString:context:));

/**
 * Added in version 6.0.0
 *
 * Asynchronously applies the new settings to the barcode scanner. If the scanner is currently running, the task will complete when the next frame is processed, and will use the new settings for that frame. If the scanner is currently not running, the task will complete as soon as the settings have been stored and won’t wait until the next frame is going to be processed.
 */
- (void)applySettings:(nonnull SDCBarcodeTrackingSettings *)settings
    completionHandler:(nullable void (^)(void))completionHandler;
/**
 * Added in version 6.0.0
 *
 * Adds the listener to observe this barcode capture instance.
 *
 * If the listener is already observing the barcode tracking instance, calling this method has no effect.
 */
- (void)addListener:(nonnull id<SDCBarcodeTrackingListener>)listener NS_SWIFT_NAME(addListener(_:));
/**
 * Added in version 6.0.0
 *
 * Removes a previously added listener from this barcode tracking instance.
 *
 * If the listener is not currently observing the barcode tracking instance, calling this method has no effect.
 */
- (void)removeListener:(nonnull id<SDCBarcodeTrackingListener>)listener
    NS_SWIFT_NAME(removeListener(_:));

/**
 * Added in version 6.0.0
 *
 * Updates the mode according to a JSON serialization. See Serialization for details.
 */
- (BOOL)updateFromJSONString:(nonnull NSString *)jsonString
                       error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
