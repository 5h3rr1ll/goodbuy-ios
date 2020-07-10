/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SDCDataCaptureView;
@class SDCDataCaptureViewDeserializer;
@class SDCJSONValue;

/**
 * Added in version 6.1.0
 *
 * The listener for the data capture view deserializer.
 */
NS_SWIFT_NAME(DataCaptureViewDeserializerDelegate)
@protocol SDCDataCaptureViewDeserializerDelegate <NSObject>

/**
 * Added in version 6.1.0
 *
 * Called before the deserialization of the view started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)viewDeserializer:(SDCDataCaptureViewDeserializer *)deserializer
    didStartDeserializingView:(SDCDataCaptureView *)view
                fromJSONValue:(SDCJSONValue *)JSONValue;
/**
 * Added in version 6.1.0
 *
 * Called when the deserialization of the view finished. This is the point to do additional deserialization.
 */
- (void)viewDeserializer:(SDCDataCaptureViewDeserializer *)deserializer
    didFinishDeserializingView:(SDCDataCaptureView *)view
                 fromJSONValue:(SDCJSONValue *)JSONValue;

@end

NS_ASSUME_NONNULL_END
