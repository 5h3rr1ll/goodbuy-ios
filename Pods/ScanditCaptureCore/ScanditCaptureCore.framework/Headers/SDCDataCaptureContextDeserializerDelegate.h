/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@class SDCDataCaptureContext;
@class SDCDataCaptureContextDeserializer;
@class SDCJSONValue;

/**
 * Added in version 6.1.0
 *
 * The listener for the frame source deserializer.
 */
NS_SWIFT_NAME(DataCaptureContextDeserializerDelegate)
@protocol SDCDataCaptureContextDeserializerDelegate <NSObject>

/**
 * Added in version 6.1.0
 *
 * Called before the deserialization of the context started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)contextDeserializer:(SDCDataCaptureContextDeserializer *)deserializer
    didStartDeserializingContext:(SDCDataCaptureContext *)context
                   fromJSONValue:(SDCJSONValue *)JSONValue;
/**
 * Added in version 6.1.0
 *
 * Called when the deserialization of the context finished. This is the point to do additional deserialization.
 */
- (void)contextDeserializer:(SDCDataCaptureContextDeserializer *)deserializer
    didFinishDeserializingContext:(SDCDataCaptureContext *)context
                    fromJSONValue:(SDCJSONValue *)JSONValue;

@end

NS_ASSUME_NONNULL_END
