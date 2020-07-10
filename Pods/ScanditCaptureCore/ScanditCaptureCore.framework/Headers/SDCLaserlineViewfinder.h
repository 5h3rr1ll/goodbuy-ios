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

/**
 * Added in version 6.0.0
 *
 * A horizontal laser line with a Scandit logo underneath. Toggles color depending on the capture mode enabled property. The laserline is centered on the data capture view’s point of interest.
 *
 * To use this viewfinder, create a new instance and assign it to the overlay, e.g. the barcode capture overlay by assigning to the SDCBarcodeCaptureOverlay.viewfinder property.
 */
NS_SWIFT_NAME(LaserlineViewfinder)
SDC_EXPORTED_SYMBOL
@interface SDCLaserlineViewfinder : NSObject <SDCViewfinder>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.0.0
 *
 * Returns a new laserline viewfinder with default parameters.
 */
+ (nonnull instancetype)viewfinder;

/**
 * Added in version 6.0.0
 *
 * The width of the laser line. The laser line is centered on the point of interest of the view.  When specifying the width with relative units, the width is measured relative to the view’s width minus the horizontal scan area margins.
 */
@property (nonatomic, assign) SDCFloatWithUnit width;

/**
 * Added in version 6.0.0
 *
 * The color to be used when recognition is enabled/active.
 */
@property (nonatomic, strong, nonnull) UIColor *enabledColor;
/**
 * Added in version 6.0.0
 *
 * The color to be used when recognition is disabled/inactive.
 */
@property (nonatomic, strong, nonnull) UIColor *disabledColor;

@end

NS_ASSUME_NONNULL_END
