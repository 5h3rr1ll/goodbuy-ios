/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <UIKit/UIKit.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCDataCaptureOverlay.h>
#import <ScanditCaptureCore/SDCAnchor.h>
#import <ScanditCaptureCore/SDCMeasureUnit.h>

@class SDCBarcodeTracking;
@class SDCDataCaptureView;
@class SDCTrackedBarcode;
@class SDCBarcodeTrackingAdvancedOverlay;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.0.0
 */
NS_SWIFT_NAME(BarcodeTrackingAdvancedOverlayDelegate)
@protocol SDCBarcodeTrackingAdvancedOverlayDelegate <NSObject>

- (nullable UIView *)barcodeTrackingAdvancedOverlay:
                         (nonnull SDCBarcodeTrackingAdvancedOverlay *)overlay
                              viewForTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

/**
 * Added in version 6.0.0
 *
 * Anchor point that should be used for the view corresponding to the given SDCTrackedBarcode.
 * This method will be called after barcodeTrackingAdvancedOverlay:viewForTrackedBarcode: and before barcodeTrackingAdvancedOverlay:offsetForTrackedBarcode:.
 * Called from the main thread.
 * Beware that this anchor can be overridden with SDCBarcodeTrackingAdvancedOverlay.setAnchor:forTrackedBarcode: method.
 * This method will only be called for new tracked barcodes that do not have an anchor yet, e.g. an anchor set by a call to SDCBarcodeTrackingAdvancedOverlay.setAnchor:forTrackedBarcode:.
 */
- (SDCAnchor)barcodeTrackingAdvancedOverlay:(nonnull SDCBarcodeTrackingAdvancedOverlay *)overlay
                    anchorForTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

/**
 * Added in version 6.0.0
 *
 * Offset to be set to the view corresponding to the given SDCTrackedBarcode. The offset is relative to the anchor point of the tracked barcode.
 * This method will be called after barcodeTrackingAdvancedOverlay:viewForTrackedBarcode: and barcodeTrackingAdvancedOverlay:anchorForTrackedBarcode:.
 * Called from the main thread.
 * Beware that this offset can be overridden with SDCBarcodeTrackingAdvancedOverlay.setOffset:forTrackedBarcode: method.
 * This method will only be called for new tracked barcodes that do not have an offset yet, e.g. an offset set by a call to SDCBarcodeTrackingAdvancedOverlay.setOffset:forTrackedBarcode:.
 */
- (SDCPointWithUnit)barcodeTrackingAdvancedOverlay:
                        (nonnull SDCBarcodeTrackingAdvancedOverlay *)overlay
                           offsetForTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

@end

/**
 * Added in version 6.0.0
 *
 * An overlay for SDCDataCaptureView that allows anchoring a single user-provided View to each tracked barcode.
 *
 * The provided view is visible on the top of the camera preview as long as its tracked barcode is and for all this time retains its relative position to it. This is useful when an additional information should be provided to tracked barcodes in real time. For instance, a user may overlay the price of an item or its expiry date for each corresponding barcode.
 *
 * To display the views, this overlay must be attached to a SDCDataCaptureView. This may be done either by creating it with overlayWithBarcodeTracking:forDataCaptureView: with a non-null view parameter or by passing this overlay to SDCDataCaptureView.addOverlay:.
 *
 * A user of this class may configure what view is displayed for the given barcode and the relative position between the two by implementing SDCBarcodeTrackingAdvancedOverlayDelegate or by calling setView:forTrackedBarcode:, setAnchor:forTrackedBarcode: or setOffset:forTrackedBarcode:.
 *
 * For additional information about using this overlay, refer to Get Started With MatrixScan and Add AR Overlays in MatrixScan.
 */
NS_CLASS_AVAILABLE_IOS(10_0)
NS_SWIFT_NAME(BarcodeTrackingAdvancedOverlay)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeTrackingAdvancedOverlay : UIView <SDCDataCaptureOverlay>

/**
 * Added in version 6.0.0
 */
@property (nonatomic, weak, nullable) id<SDCBarcodeTrackingAdvancedOverlayDelegate> delegate;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)decoder NS_UNAVAILABLE;

/**
 * Added in version 6.0.0
 *
 * Constructs a new barcode tracking advanced overlay for the barcode tracking instance. The overlay is automatically added to the view.
 */
+ (instancetype)overlayWithBarcodeTracking:(nonnull SDCBarcodeTracking *)barcodeTracking
                        forDataCaptureView:(nullable SDCDataCaptureView *)view
    NS_SWIFT_NAME(init(barcodeTracking:view:));

/**
 * Added in version 6.0.0
 *
 * The method can be called to change the view drawn for the given tracked barcode. Setting the view to nil will unset the view from the tracked barcode and will effectively remove it from the overlay.
 * This method is thread-safe, it can be called from any thread.
 * The view set via this method will take precedence over the one set via SDCBarcodeTrackingAdvancedOverlayDelegate.barcodeTrackingAdvancedOverlay:viewForTrackedBarcode:: in case a view is set before SDCBarcodeTrackingAdvancedOverlayDelegate.barcodeTrackingAdvancedOverlay:viewForTrackedBarcode: got called, no call to SDCBarcodeTrackingAdvancedOverlayDelegate.barcodeTrackingAdvancedOverlay:viewForTrackedBarcode: will happen.
 */
- (void)setView:(nullable UIView *)view
    forTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;
/**
 * Added in version 6.0.0
 *
 * The method can be called to change the anchor point for the view associated with the given tracked barcode. This method is thread-safe, it can be called from any thread.
 * The anchor set via this method will take precedence over the one set via SDCBarcodeTrackingAdvancedOverlayDelegate.barcodeTrackingAdvancedOverlay:anchorForTrackedBarcode:: in case a view is set before SDCBarcodeTrackingAdvancedOverlayDelegate.barcodeTrackingAdvancedOverlay:anchorForTrackedBarcode: got called, no call to SDCBarcodeTrackingAdvancedOverlayDelegate.barcodeTrackingAdvancedOverlay:anchorForTrackedBarcode: will happen.
 */
- (void)setAnchor:(SDCAnchor)anchor forTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;
/**
 * Added in version 6.0.0
 *
 * The method can be called to change the offset for the view associated with the given tracked barcode. This method is thread-safe, it can be called from any thread.
 * The offset set via this method will take precedence over the one set via SDCBarcodeTrackingAdvancedOverlayDelegate.barcodeTrackingAdvancedOverlay:offsetForTrackedBarcode:: in case a view is set before SDCBarcodeTrackingAdvancedOverlayDelegate.barcodeTrackingAdvancedOverlay:offsetForTrackedBarcode: got called, no call to SDCBarcodeTrackingAdvancedOverlayDelegate.barcodeTrackingAdvancedOverlay:offsetForTrackedBarcode: will happen.
 * If the SDCMeasureUnit of the offset is SDCMeasureUnitFraction, the offset is calculated relative to view’s dimensions.
 */
- (void)setOffset:(SDCPointWithUnit)offset
    forTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;
/**
 * Added in version 6.0.0
 *
 * Clears all the views for the currently tracked barcodes from this overlay.
 * This method is thread-safe, it can be called from any thread.
 */
- (void)clearTrackedBarcodeViews;

@end

NS_ASSUME_NONNULL_END
