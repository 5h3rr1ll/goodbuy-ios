/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <UIKit/UIView.h>

#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.0.0
 *
 * Brushes define how objects are drawn on screen and allow to change their fill and stroke color as well as the stroke width. They are, for example, used to change the styling of barcode locations, or other objects drawn on top of the video preview. Brushes are immutable. Once created none of the members can be modified.
 */
NS_SWIFT_NAME(Brush)
SDC_EXPORTED_SYMBOL
@interface SDCBrush : NSObject

/**
 * Added in version 6.1.0
 *
 * Creates a new brush where both fill and stroke colors are set to fully transparent black. The stroke width is set to zero.
 */
@property (class, nonatomic, readonly) SDCBrush *transparentBrush;

/**
 * Added in version 6.0.0
 *
 * Creates a new default brush. Both fill and stroke color are set to fully transparent black. The stroke width is set to zero.
 */
- (instancetype)init;

/**
 * Added in version 6.0.0
 *
 * Creates a new brush with provided fill, stroke colors and stroke width.
 */
- (instancetype)initWithFillColor:(nonnull UIColor *)fillColor
                      strokeColor:(nonnull UIColor *)strokeColor
                      strokeWidth:(CGFloat)strokeWidth NS_DESIGNATED_INITIALIZER;

/**
 * Added in version 6.2.0
 */
+ (nullable instancetype)brushFromJSONString:(nonnull NSString *)JSONString

    NS_SWIFT_NAME(init(jsonString:));

/**
 * Added in version 6.0.0
 *
 * The fill color used to draw the object.
 */
@property (nonatomic, nonnull, readonly) UIColor *fillColor;
/**
 * Added in version 6.0.0
 *
 * The stroke color used to draw the object.
 */
@property (nonatomic, nonnull, readonly) UIColor *strokeColor;
/**
 * Added in version 6.0.0
 *
 * The width in device-independent pixels used to render the stroke.
 */
@property (nonatomic, readonly) CGFloat strokeWidth;

@end

NS_ASSUME_NONNULL_END
