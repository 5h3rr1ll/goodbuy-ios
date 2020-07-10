/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

@class SDCFrameSourceDeserializer;
@class SDCCameraSettings;
@class SDCJSONValue;
@protocol SDCFrameSource;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.1.0
 *
 * The listener for the frame source deserializer.
 */
NS_SWIFT_NAME(FrameSourceDeserializerDelegate)
@protocol SDCFrameSourceDeserializerDelegate <NSObject>

/**
 * Added in version 6.1.0
 *
 * Called before the deserialization of the frame source started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)frameSourceDeserializer:(SDCFrameSourceDeserializer *)deserializer
    didStartDeserializingFrameSource:(id<SDCFrameSource>)frameSource
                       fromJSONValue:(SDCJSONValue *)JSONValue;
/**
 * Added in version 6.1.0
 *
 * Called when the deserialization of the frame source finished. This is the point to do additional deserialization.
 */
- (void)frameSourceDeserializer:(SDCFrameSourceDeserializer *)deserializer
    didFinishDeserializingFrameSource:(id<SDCFrameSource>)frameSource
                        fromJSONValue:(SDCJSONValue *)JSONValue;

/**
 * Added in version 6.1.0
 *
 * Called before the deserialization of the camera settings started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)frameSourceDeserializer:(SDCFrameSourceDeserializer *)deserializer
    didStartDeserializingCameraSettings:(SDCCameraSettings *)settings
                          fromJSONValue:(SDCJSONValue *)JSONValue;
/**
 * Added in version 6.1.0
 *
 * Called when the deserialization of the camera settings finished. This is the point to do additional deserialization.
 */
- (void)frameSourceDeserializer:(SDCFrameSourceDeserializer *)deserializer
    didFinishDeserializingCameraSettings:(SDCCameraSettings *)settings
                           fromJSONValue:(SDCJSONValue *)JSONValue;

@end

NS_ASSUME_NONNULL_END
