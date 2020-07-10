/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIColor.h>
#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCViewfinder.h>
#import <ScanditCaptureCore/SDCMeasureUnit.h>
#import <ScanditCaptureCore/SDCSizeWithUnitAndAspect.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.0.0
 *
 * Spotlight viewfinder with an embedded Scandit logo. The spotlight is always centered on the point of interest of the view.
 *
 * The spotlight viewfinder is always displayed but the color of the border around the spotlight changes depending on whether the data capture mode is enabled or not.
 *
 * To use this viewfinder, create a new instance and assign it to the overlay, e.g. the barcode capture overlay by assigning to the SDCBarcodeCaptureOverlay.viewfinder property.
 */
NS_SWIFT_NAME(SpotlightViewfinder)
SDC_EXPORTED_SYMBOL
@interface SDCSpotlightViewfinder : NSObject <SDCViewfinder>

/**
 * Added in version 6.0.0
 *
 * The color used to draw the spotlight border when the data capture mode is enabled.
 */
@property (nonatomic, strong, nonnull) UIColor *enabledBorderColor;
/**
 * Added in version 6.0.0
 *
 * The color used to draw the spotlight border when the data capture mode is disabled.
 */
@property (nonatomic, strong, nonnull) UIColor *disabledBorderColor;
/**
 * Added in version 6.0.0
 *
 * The color used to draw the darkened area surrounding the spotlight.
 */
@property (nonatomic, strong, nonnull) UIColor *backgroundColor;
/**
 * Added in version 6.0.0
 *
 * The size and sizing mode of the viewfinder.
 */
@property (nonatomic, readonly) SDCSizeWithUnitAndAspect *sizeWithUnitAndAspect;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 * Added in version 6.0.0
 *
 * Returns a new spotlight viewfinder with default parameters.
 */
+ (nonnull instancetype)viewfinder NS_SWIFT_NAME(init());

/**
 * Added in version 6.0.0
 *
 * Sets the horizontal and vertical size of the viewfinder to the provided value. When the unit is relative (unit in either x or y is SDCMeasureUnitFraction) the size is computed relative to the view size minus the scan area margins.
 */
- (void)setSize:(SDCSizeWithUnit)size;
/**
 * Added in version 6.0.0
 *
 * Sets the width of the viewfinder and compute height automatically based on the provided height/width aspect ratio. When the unit is relative (SDCMeasureUnitFraction), the width is computed relative to the view size minus the scan area margins.
 */
- (void)setWidth:(SDCFloatWithUnit)width aspectRatio:(CGFloat)heightToWidthAspectRatio;
/**
 * Added in version 6.0.0
 *
 * Sets the height of the viewfinder and compute width automatically based on the provided width/height aspect ratio. When the unit is relative (SDCMeasureUnitFraction), the height is computed relative to the view size minus the scan area margins.
 */
- (void)setHeight:(SDCFloatWithUnit)height aspectRatio:(CGFloat)widthToHeightAspectRatio;

@end

NS_ASSUME_NONNULL_END
