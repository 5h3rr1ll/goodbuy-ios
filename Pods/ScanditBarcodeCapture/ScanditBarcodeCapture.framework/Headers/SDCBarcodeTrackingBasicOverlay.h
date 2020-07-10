/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCDataCaptureOverlay.h>

@class SDCBarcodeTracking;
@class SDCBrush;
@class SDCTrackedBarcode;
@class SDCBarcodeTrackingBasicOverlay;
@class SDCDataCaptureView;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.0.0
 */
NS_SWIFT_NAME(BarcodeTrackingBasicOverlayDelegate)
@protocol SDCBarcodeTrackingBasicOverlayDelegate <NSObject>

/**
 * Added in version 6.0.0
 *
 * Callback method that can be used to set a SDCBrush for a tracked barcode. It is called when a new tracked barcode appears. Called from the rendering thread.
 * If the callback returns nil, then no visualization will be drawn for the tracked barcode. Additionally, tapping on the barcode will have no effect - the action defined by barcodeTrackingBasicOverlay:didTapTrackedBarcode: callback will not be performed.
 */
- (nullable SDCBrush *)barcodeTrackingBasicOverlay:(nonnull SDCBarcodeTrackingBasicOverlay *)overlay
                            brushForTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

/**
 * Added in version 6.0.0
 *
 * Callback method that can be used to define an action that should be performed once a tracked barcode is tapped. Called from the main thread.
 *
 * If you are adding a UIGestureRecognizer to the data capture view, ensure that the cancelsTouchesInView property is set to NO as otherwise tap gestures will be cancelled instead of successfully completing.
 */
- (void)barcodeTrackingBasicOverlay:(nonnull SDCBarcodeTrackingBasicOverlay *)overlay
               didTapTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

@end

/**
 * Added in version 6.0.0
 *
 * An overlay for SDCDataCaptureView that shows a simple augmentation over each tracked barcode.
 *
 * To display the augmentations, this overlay must be attached to a SDCDataCaptureView. This may be done either by creating it with overlayWithBarcodeTracking:forDataCaptureView: with a non-null view parameter or by passing this overlay to SDCDataCaptureView.addOverlay:.
 *
 * A user of this class may configure the appearance of the augmentations by implementing  SDCBarcodeTrackingBasicOverlayDelegate or by calling setBrush:forTrackedBarcode:.
 *
 * For additional information about using this overlay, refer to Get Started With MatrixScan.
 */
NS_SWIFT_NAME(BarcodeTrackingBasicOverlay)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeTrackingBasicOverlay : NSObject <SDCDataCaptureOverlay>

/**
 * Added in version 6.0.0
 *
 * The delegate which is called whenever a new TrackedBarcode is newly tracked or newly recognized.
 */
@property (nonatomic, weak, nullable) id<SDCBarcodeTrackingBasicOverlayDelegate> delegate;
/**
 * Added in version 6.0.0
 *
 * The default brush applied to recognized tracked barcodes. This is the brush used if SDCBarcodeTrackingBasicOverlayDelegate is not implemented.
 * Setting this brush to nil hides all tracked barcodes, unless setBrush:forTrackedBarcode: is called.
 */
@property (nonatomic, strong, nullable) SDCBrush *defaultBrush;

/**
 * Added in version 6.0.0
 *
 * When set to YES, this overlay will visualize the active scan area used for BarcodeTracking. This is useful to check margins defined on the SDCDataCaptureView are set correctly. This property is meant for debugging during development and is not intended for use in production.
 *
 * By default this property is NO.
 */
@property (nonatomic, assign) BOOL shouldShowScanAreaGuides;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.0.0
 *
 * Constructs a new barcode tracking basic overlay for the barcode tracking instance. For the overlay to be displayed on screen, it must be added to a SDCDataCaptureView.
 */
+ (instancetype)overlayWithBarcodeTracking:(nonnull SDCBarcodeTracking *)barcodeTracking;
/**
 * Added in version 6.0.0
 *
 * Constructs a new barcode tracking basic overlay for the barcode tracking instance. The overlay is automatically added to the view.
 */
+ (instancetype)overlayWithBarcodeTracking:(nonnull SDCBarcodeTracking *)barcodeTracking
                        forDataCaptureView:(nullable SDCDataCaptureView *)view
    NS_SWIFT_NAME(init(barcodeTracking:view:));
;

+ (nullable instancetype)barcodeTrackingBasicOverlayFromJSONString:(nonnull NSString *)jsonString
                                                              mode:
                                                                  (nonnull SDCBarcodeTracking *)mode
                                                             error:(NSError **)error
    NS_SWIFT_NAME(init(jsonString:barcodeCapture:));

/**
 * Added in version 6.0.0
 *
 * Updates the overlay according to a JSON serialization. See Serialization for details.
 */
- (BOOL)updateFromJSONString:(nonnull NSString *)jsonString error:(NSError **)error;

/**
 * Added in version 6.0.0
 *
 * The method can be called to change the visualization style of a tracked barcode. This method is thread-safe, it can be called from any thread.
 * If the brush is nil, then no visualization will be drawn for the tracked barcode. Additionally, tapping on the barcode will have no effect - the action defined by SDCBarcodeTrackingBasicOverlayDelegate.barcodeTrackingBasicOverlay:didTapTrackedBarcode: callback will not be performed.
 */
- (void)setBrush:(nullable SDCBrush *)brush
    forTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

/**
 * Added in version 6.0.0
 *
 * Clears all currently displayed visualizations for the tracked barcodes.
 *
 * This only applies to the currently tracked barcodes, the visualizations for the new ones will still appear.
 */
- (void)clearTrackedBarcodeBrushes;

@end

NS_ASSUME_NONNULL_END
