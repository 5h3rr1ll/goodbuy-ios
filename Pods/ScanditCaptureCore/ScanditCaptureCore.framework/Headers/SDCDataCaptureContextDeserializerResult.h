/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SDCDataCaptureContext;
@class SDCDataCaptureView;

/**
 * Added in version 6.1.0
 *
 * The result of a data capture context deserialization.
 */
NS_SWIFT_NAME(DataCaptureContextDeserializerResult)
@interface SDCDataCaptureContextDeserializerResult : NSObject

/**
 * Added in version 6.1.0
 *
 * The context created or updated through the deserialization.
 */
@property (nonatomic, strong, nullable, readonly) SDCDataCaptureContext *context;
/**
 * Added in version 6.1.0
 *
 * The view potentially created or updated through the context deserialization.
 */
@property (nonatomic, strong, nullable, readonly) SDCDataCaptureView *view;
/**
 * Added in version 6.1.0
 *
 * The warnings produced during deserialization, for example which properties were not used during deserialization.
 */
@property (nonatomic, strong, nonnull, readonly) NSArray<NSString *> *warnings;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
