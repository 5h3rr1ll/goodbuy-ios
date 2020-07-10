/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

/**
 * Added in version 6.0.0
 *
 * An enumeration of possible anchoring points in a geometric object such as CGRect or quadrilaterals. Values of this enumeration are typically used to determine where elements are placed on the screen. For example, it is used to place the logo on screen.
 */
NS_SWIFT_NAME(Anchor)
typedef NS_CLOSED_ENUM(NSUInteger, SDCAnchor) {
/**
     * Added in version 6.0.0
     *
     * This value will use the top left corner as the anchor point.
     */
    SDCAnchorTopLeft,
/**
     * Added in version 6.0.0
     *
     * This value will will use the center of the top edge as the anchor point.
     */
    SDCAnchorTopCenter,
/**
     * Added in version 6.0.0
     *
     * This value will use the top right corner as the anchor point.
     */
    SDCAnchorTopRight,
/**
     * Added in version 6.0.0
     *
     * This value will use the center left corner as the anchor point.
     */
    SDCAnchorCenterLeft,
/**
     * Added in version 6.0.0
     *
     * This value will use the center as the anchor point.
     */
    SDCAnchorCenter,
/**
     * Added in version 6.0.0
     *
     * This value will use the center of the right edge as the anchor point.
     */
    SDCAnchorCenterRight,
/**
     * Added in version 6.0.0
     *
     * This value will use the bottom left corner as the anchor point.
     */
    SDCAnchorBottomLeft,
/**
     * Added in version 6.0.0
     *
     * This value will use the center of the bottom edge as the anchor point.
     */
    SDCAnchorBottomCenter,
/**
     * Added in version 6.0.0
     *
     * This value will use the bottom right corner as the anchor point.
     */
    SDCAnchorBottomRight,
} NS_SWIFT_NAME(Anchor);

/**
 * Added in version 6.1.0
 */
SDC_EXTERN NSString *_Nonnull NSStringFromAnchor(SDCAnchor anchor) NS_SWIFT_NAME(getter:SDCAnchor.jsonString(self:));
/**
 * Added in version 6.1.0
 */
SDC_EXTERN BOOL SDCAnchorFromJSONString(NSString *_Nonnull JSONString, SDCAnchor *_Nonnull anchor);

