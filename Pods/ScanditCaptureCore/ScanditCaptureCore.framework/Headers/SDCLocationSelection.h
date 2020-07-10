/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCMeasureUnit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.0.0
 *
 * Protocol for location selection. Location selections implement a specific strategy how a data object (like a barcode or text) is selected out of multiple visible ones by for example only selecting objects inside a certain area or objects that intersect a certain area. See Scan Area Guide for an in-depth explanation of location selection. Implementations are provided by SDCRadiusLocationSelection and SDCRectangularLocationSelection.
 *
 * Location selection implementations are restricted to the set of location selections provided by the Scandit Data Capture SDK, it is not possible to conform to this protocol with a custom implementations of location selection. This protocol does not expose any methods or properties, it just serves as a unifying type for different selection strategies.
 */
NS_SWIFT_NAME(LocationSelection)
@protocol SDCLocationSelection <NSObject>
@end

/**
 * Added in version 6.0.0
 *
 * Location selection for selecting codes inside a circle with the given radius, centered on the point of interest. Any object that touches the circle is returned, objects that do not intersect the circle are filtered out. See Scan Area Guide for an in depth explanation of location selection.
 */
NS_SWIFT_NAME(RadiusLocationSelection)
SDC_EXPORTED_SYMBOL
@interface SDCRadiusLocationSelection : NSObject <SDCLocationSelection>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.0.0
 *
 * Creates a new radius location selection instance with the specified radius.
 */
+ (instancetype)locationSelectionWithRadius:(SDCFloatWithUnit)radius;

/**
 * Added in version 6.0.0
 *
 * The radius of the circle. When using fractional coordinates, the radius is measured relative to the view’s width.
 */
@property (nonatomic, readonly) SDCFloatWithUnit radius;

@end

@class SDCSizeWithUnitAndAspect;

/**
 * Added in version 6.0.0
 *
 * Location selection for selecting codes inside a rectangle centered on the point of interest. Any object that is fully inside the rectangle is returned, objects that are partially or entirely outside of the rectangle are filtered out. See Scan Area Guide for an in-depth explanation of location selection.
 */
NS_SWIFT_NAME(RectangularLocationSelection)
SDC_EXPORTED_SYMBOL
@interface SDCRectangularLocationSelection : NSObject <SDCLocationSelection>
/**
 * Added in version 6.0.0
 *
 * The size and sizing mode of the location selection.
 */
@property (nonatomic, readonly) SDCSizeWithUnitAndAspect *sizeWithUnitAndAspect;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.0.0
 *
 * Creates a new rectangular location selection instance with the specified horizontal and vertical size. When the unit is relative (unit in either x or y is SDCMeasureUnitFraction) the size is computed relative to the view size minus the scan area margins.
 */
+ (instancetype)locationSelectionWithSize:(SDCSizeWithUnit)size;
/**
 * Added in version 6.0.0
 *
 * Creates a new rectangular location selection instance with the specified width and computes the height based on the provided height/width aspect ratio. When the unit is relative (SDCMeasureUnitFraction), the width is computed relative to the view size minus the scan area margins.
 */
+ (instancetype)locationSelectionWithWidth:(SDCFloatWithUnit)width
                               aspectRatio:(CGFloat)heightToWidthAspectRatio;
/**
 * Added in version 6.0.0
 *
 * Creates a new rectangular location selection instance with the specified height and computes the width based on the provided width/height aspect ratio.  When the unit is relative (SDCMeasureUnitFraction), the height is computed relative to the view size minus the scan area margins.
 */
+ (instancetype)locationSelectionWithHeight:(SDCFloatWithUnit)height
                                aspectRatio:(CGFloat)widthToHeightAspectRatio;

@end

NS_ASSUME_NONNULL_END
