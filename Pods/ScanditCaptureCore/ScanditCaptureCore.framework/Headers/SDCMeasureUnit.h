/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <ScanditCaptureCore/SDCBase.h>

/**
 * Added in version 6.0.0
 *
 * Specifies in what units the value has been specified (fraction, device-independent pixels, pixels).
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCMeasureUnit) {
/**
     * Added in version 6.0.0
     *
     * Value is measured in pixels.
     */
    SDCMeasureUnitPixel,
/**
     * Added in version 6.0.0
     *
     * Value is measured in device-independent pixels.
     */
    SDCMeasureUnitDIP NS_SWIFT_NAME(dip),
/**
     * Added in version 6.0.0
     *
     * Value is measured as a fraction. Valid values range from 0 to 1. This can be used to specify values in relative coordinates with respect to a reference, e.g. the view width or height.
     */
    SDCMeasureUnitFraction,
} NS_SWIFT_NAME(MeasureUnit);

/**
 * Added in version 6.0.0
 *
 * An enumeration of possible ways to define a rectangular size.
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCSizingMode) {
/**
     * Added in version 6.0.0
     *
     * This value will use a SDCSizeWithUnit to determine width and the height.
     */
    SDCSizingModeWidthAndHeight,
/**
     * Added in version 6.0.0
     *
     * This value will use a SDCFloatWithUnit to determine the width and a float multiplier to determine the height.
     */
    SDCSizingModeWidthAndAspectRatio,
/**
     * Added in version 6.0.0
     *
     * This value will use a SDCFloatWithUnit to determine the height and a float multiplier to determine the width.
     */
    SDCSizingModeHeightAndAspectRatio,
} NS_SWIFT_NAME(SizingMode);

/**
 * Added in version 6.0.0
 *
 * Holds a floating-point value plus a measure unit.
 */
struct SDCFloatWithUnit {
/**
     * Added in version 6.0.0
     */
    CGFloat value;
/**
     * Added in version 6.0.0
     */
    SDCMeasureUnit unit;
} NS_SWIFT_NAME(FloatWithUnit);
typedef struct __attribute__((objc_boxable)) SDCFloatWithUnit SDCFloatWithUnit;

static inline SDCFloatWithUnit SDCFloatWithUnitMake(CGFloat value, SDCMeasureUnit unit)
    NS_SWIFT_UNAVAILABLE("Use FloatWithUnit(value:unit:)") {
    SDCFloatWithUnit result;
    result.value = value;
    result.unit = unit;
    return result;
}

SDC_EXTERN const SDCFloatWithUnit SDCFloatWithUnitZero NS_SWIFT_NAME(FloatWithUnit.zero);
SDC_EXTERN const SDCFloatWithUnit SDCFloatWithUnitNull NS_SWIFT_NAME(FloatWithUnit.null);

/**
 * Added in version 6.1.0
 */
SDC_EXTERN BOOL SDCFloatWithUnitIsNull(SDCFloatWithUnit floatWithUnit);

/**
 * Added in version 6.1.0
 */
SDC_EXTERN NSString *_Nonnull NSStringFromFloatWithUnit(SDCFloatWithUnit floatWithUnit) NS_SWIFT_NAME(getter:SDCFloatWithUnit.jsonString(self:));

/**
 * Added in version 6.0.0
 */
struct SDCSizeWithUnit {
/**
     * Added in version 6.0.0
     *
     * The width.
     */
    SDCFloatWithUnit width;
/**
     * Added in version 6.0.0
     *
     * The height.
     */
    SDCFloatWithUnit height;
} NS_SWIFT_NAME(SizeWithUnit);
typedef struct __attribute__((objc_boxable)) SDCSizeWithUnit SDCSizeWithUnit;

static inline SDCSizeWithUnit SDCSizeWithUnitMake(SDCFloatWithUnit width, SDCFloatWithUnit height)
    NS_SWIFT_UNAVAILABLE("Use SizeWithUnit(width:height:)") {
    SDCSizeWithUnit result;
    result.width = width;
    result.height = height;
    return result;
}

SDC_EXTERN const SDCSizeWithUnit SDCSizeWithUnitZero NS_SWIFT_NAME(SizeWithUnit.zero);

/**
 * Added in version 6.1.0
 */
SDC_EXTERN NSString *_Nonnull NSStringFromSizeWithUnit(SDCSizeWithUnit sizeWithUnit) NS_SWIFT_NAME(getter:SDCSizeWithUnit.jsonString(self:));

/**
 * Added in version 6.0.0
 */
struct SDCPointWithUnit {
/**
     * Added in version 6.0.0
     *
     * X coordinate of the point.
     */
    SDCFloatWithUnit x;
/**
     * Added in version 6.0.0
     *
     * Y coordinate of the point.
     */
    SDCFloatWithUnit y;
} NS_SWIFT_NAME(PointWithUnit);
typedef struct __attribute__((objc_boxable)) SDCPointWithUnit SDCPointWithUnit;

static inline SDCPointWithUnit SDCPointWithUnitMake(SDCFloatWithUnit x, SDCFloatWithUnit y)
    NS_SWIFT_UNAVAILABLE("Use PointWithUnit(x:y:)") {
    SDCPointWithUnit result;
    result.x = x;
    result.y = y;
    return result;
}

SDC_EXTERN const SDCPointWithUnit SDCPointWithUnitZero NS_SWIFT_NAME(PointWithUnit.zero);
SDC_EXTERN const SDCPointWithUnit SDCPointWithUnitNull NS_SWIFT_NAME(PointWithUnit.null);

/**
 * Added in version 6.1.0
 */
SDC_EXTERN BOOL SDCPointWithUnitIsNull(SDCPointWithUnit pointWithUnit);

/**
 * Added in version 6.1.0
 */
SDC_EXTERN NSString *_Nonnull NSStringFromPointWithUnit(SDCPointWithUnit pointWithUnit) NS_SWIFT_NAME(getter:SDCPointWithUnit.jsonString(self:));
/**
 * Added in version 6.2.0
 */
SDC_EXTERN BOOL SDCPointWithUnitFromJSONString(NSString *_Nonnull JSONString, SDCPointWithUnit *_Nonnull pointWithUnit);

/**
 * Added in version 6.0.0
 */
struct SDCRectWithUnit {
/**
     * Added in version 6.0.0
     *
     * The origin (top-left corner) of the rectangle.
     */
    SDCPointWithUnit origin;
/**
     * Added in version 6.0.0
     *
     * The size of the rectangle.
     */
    SDCSizeWithUnit size;
} NS_SWIFT_NAME(RectWithUnit);
typedef struct __attribute__((objc_boxable)) SDCRectWithUnit SDCRectWithUnit;

static inline SDCRectWithUnit SDCRectWithUnitMake(SDCPointWithUnit origin, SDCSizeWithUnit size)
    NS_SWIFT_UNAVAILABLE("Use RectWithUnit(origin:size:)") {
    SDCRectWithUnit result;
    result.origin = origin;
    result.size = size;
    return result;
}

SDC_EXTERN const SDCRectWithUnit SDCRectWithUnitZero NS_SWIFT_NAME(RectWithUnit.zero);

/**
 * Added in version 6.1.0
 */
SDC_EXTERN NSString *_Nonnull NSStringFromRectWithUnit(SDCRectWithUnit rectWithUnit) NS_SWIFT_NAME(getter:SDCRectWithUnit.jsonString(self:));

/**
 * Added in version 6.0.0
 *
 * Holds margin values (left, top, right, bottom) that can each be expressed with a different measure unit.
 */
struct SDCMarginsWithUnit {
/**
     * Added in version 6.0.0
     *
     * Left margin.
     */
    SDCFloatWithUnit left;
/**
     * Added in version 6.0.0
     *
     * Top margin.
     */
    SDCFloatWithUnit top;
/**
     * Added in version 6.0.0
     *
     * Right margin.
     */
    SDCFloatWithUnit right;
/**
     * Added in version 6.0.0
     *
     * Bottom margin.
     */
    SDCFloatWithUnit bottom;
} NS_SWIFT_NAME(MarginsWithUnit);
typedef struct __attribute__((objc_boxable)) SDCMarginsWithUnit SDCMarginsWithUnit;

static inline SDCMarginsWithUnit SDCMarginsWithUnitMake(SDCFloatWithUnit left, SDCFloatWithUnit top,
                                                        SDCFloatWithUnit right,
                                                        SDCFloatWithUnit bottom)
    NS_SWIFT_UNAVAILABLE("Use MarginsWithUnit(left:top:right:bottom:)") {
    SDCMarginsWithUnit result;
    result.left = left;
    result.top = top;
    result.right = right;
    result.bottom = bottom;
    return result;
}

/**
 * Added in version 6.1.0
 */
SDC_EXTERN NSString *_Nonnull NSStringFromMarginsWithUnit(SDCMarginsWithUnit marginsWithUnit) NS_SWIFT_NAME(getter:SDCMarginsWithUnit.jsonString(self:));

/**
 * Added in version 6.0.0
 *
 * Holds values to define a rectangular size using a dimension and an aspect ratio multiplier.
 */
struct SDCSizeWithAspect {
/**
     * Added in version 6.0.0
     *
     * The size of one dimension.
     */
    SDCFloatWithUnit size;
/**
     * Added in version 6.0.0
     *
     * The aspect ratio for the other dimension.
     */
    CGFloat aspect;
} NS_SWIFT_NAME(SizeWithAspect);
typedef struct __attribute__((objc_boxable)) SDCSizeWithAspect SDCSizeWithAspect;

static inline SDCSizeWithAspect SDCSizeWithAspectMake(SDCFloatWithUnit size, CGFloat aspect)
    NS_SWIFT_UNAVAILABLE("Use SizeWithAspect(size:aspect:)") {
    SDCSizeWithAspect result;
    result.size = size;
    result.aspect = aspect;
    return result;
}

SDC_EXTERN const SDCSizeWithAspect SDCSizeWithAspectZero NS_SWIFT_NAME(SizeWithAspect.zero);

/**
 * Added in version 6.1.0
 */
SDC_EXTERN NSString *_Nonnull NSStringFromSizeWithAspect(SDCSizeWithAspect sizeWithAspect) NS_SWIFT_NAME(getter:SDCSizeWithAspect.jsonString(self:));

