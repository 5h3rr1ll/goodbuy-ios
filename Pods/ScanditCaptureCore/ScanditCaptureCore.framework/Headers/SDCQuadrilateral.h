/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

/**
 * Added in version 6.0.0
 *
 * Polygon represented by 4 corners.
 */
struct SDCQuadrilateral {
/**
     * Added in version 6.0.0
     */
    CGPoint topLeft;
/**
     * Added in version 6.0.0
     */
    CGPoint topRight;
/**
     * Added in version 6.0.0
     */
    CGPoint bottomRight;
/**
     * Added in version 6.0.0
     */
    CGPoint bottomLeft;
} NS_SWIFT_NAME(Quadrilateral);
typedef struct __attribute__((objc_boxable)) SDCQuadrilateral SDCQuadrilateral;

/**
 * Added in version 6.1.0
 */
SDC_EXTERN NSString *_Nonnull NSStringFromQuadrilateral(SDCQuadrilateral quadrilateral) NS_SWIFT_NAME(getter:SDCQuadrilateral.jsonString(self:));
/**
 * Added in version 6.1.0
 */
SDC_EXTERN BOOL SDCQuadrilateralFromJSONString(NSString *_Nonnull JSONString, SDCQuadrilateral *_Nonnull quadrilateral);

