/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import "SDCBase.h"
#import "SDCViewfinder.h"
#import "SDCMeasureUnit.h"

#import <UIKit/UIColor.h>

NS_ASSUME_NONNULL_BEGIN

@class SDCSizeWithUnitAndAspect;

/**
 * Added in version 6.0.0
 *
 * Rectangular viewfinder with an embedded Scandit logo. The rectangle is always centered on the point of interest of the view.
 *
 * The rectangular viewfinder is displayed when the recognition is active and hidden when it is not.
 *
 * To use this viewfinder, create a new instance and assign it to the overlay, e.g. the barcode capture overlay by assigning to the SDCBarcodeCaptureOverlay.viewfinder property.
 */
NS_SWIFT_NAME(RectangularViewfinder)
SDC_EXPORTED_SYMBOL
@interface SDCRectangularViewfinder : NSObject <SDCViewfinder>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.0.0
 *
 * Returns a new rectangular viewfinder with default parameters.
 */
+ (nonnull instancetype)viewfinder;

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

/**
 * Added in version 6.0.0
 *
 * The color used to draw the logo and viewfinder.
 */
@property (nonatomic, strong, nonnull) UIColor *color;
/**
 * Added in version 6.0.0
 *
 * The size and sizing mode of the viewfinder.
 */
@property (nonatomic, readonly) SDCSizeWithUnitAndAspect *sizeWithUnitAndAspect;

@end

NS_ASSUME_NONNULL_END
