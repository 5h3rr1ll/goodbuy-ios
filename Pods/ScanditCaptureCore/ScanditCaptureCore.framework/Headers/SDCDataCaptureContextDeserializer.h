/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SDCDataCaptureContextDeserializerDelegate;
@protocol SDCDataCaptureModeDeserializer;

@class SDCDataCaptureContext;
@class SDCDataCaptureView;
@class SDCFrameSourceDeserializer;
@class SDCDataCaptureViewDeserializer;
@class SDCDataCaptureContextDeserializerResult;

/**
 * Added in version 6.1.0
 *
 * A deserializer to construct data capture contexts from JSON. To properly deserialize an entire context a SDCFrameSourceDeserializer and x need to be provided.
 *
 * Related topics: Serialization.
 */
NS_SWIFT_NAME(DataCaptureContextDeserializer)
@interface SDCDataCaptureContextDeserializer : NSObject

/**
 * Added in version 6.1.0
 *
 * The object informed about deserialization events.
 */
@property (nonatomic, weak, nullable) id<SDCDataCaptureContextDeserializerDelegate> delegate;
/**
 * Added in version 6.1.0
 *
 * Avoids dependencies on other threads during contextFromJSONString:error: and updateContext:view:fromJSON:error:. This flag is not set by default which means the mentioned methods can have dependencies on other threads, the dependencies are as follows:
 *
 *   • When the context specifies a capture mode array (even an empty one), the deserialization needs to synchronize with the context thread.
 *
 *   • When the view specifies an overlay array (even an empty one), the deserialization needs to synchronize with the context thread.
 *
 * These dependencies are necessary to ensure the consistency of the deserialization across multiple calls. In certain situations they can cause issues though because the context thread is waiting for another thread that is trying to execute a deserialization, resulting in a deadlock. This flag was introduced to allow to circumvent deadlocks in such cases.
 *
 * If this flag is true, the deserializer can only be used with one context at a time and has to have created said context. Specifically this means the lifecycle is as follows:
 *
 *   • avoidThreadDependencies is set to true.
 *
 *   • The deserializer’s contextFromJSONString:error: is used to create a context.
 *
 *   • The deserializer’s updateContext:view:fromJSON:error: is used zero or more times but only with the context previously created through the deserializer.
 *
 *   • Every adding or removing of capture modes from this context is done through updateContext:view:fromJSON:error: (other changes like properties of capture modes etc. can be done through other ways).
 *
 * It is possible to repeat this lifecycle over and over with different contexts, but it is essential that all calls involving a context are in sequence. It is not possible to create context A, update context A, create context B and then update context A again.
 *
 * Just as without this flag the deserializer is not thread-safe and because of the above lifecycle all calls (not just the ones for the same context) have to be called on the same thread.
 */
@property (nonatomic, assign) BOOL avoidThreadDependencies;

+ (instancetype)contextDeserializerWithFrameSourceDeserializer:(SDCFrameSourceDeserializer *)frameSourceDeserializer
                                              viewDeserializer:(SDCDataCaptureViewDeserializer *)viewDeserializer
                                             modeDeserializers:(NSArray<id<SDCDataCaptureModeDeserializer>> *)modeDeserializers
    NS_SWIFT_NAME(init(frameSourceDeserializer:viewDeserializer:modeDeserializers:));

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (nullable SDCDataCaptureContextDeserializerResult *)contextFromJSONString:(NSString *)jsonString
                                                                      error:(NSError *_Nullable *_Nullable)error;

- (nullable SDCDataCaptureContextDeserializerResult *)updateContext:(SDCDataCaptureContext *)context
                                                               view:(nullable SDCDataCaptureView *)view
                                                           fromJSON:(NSString *)jsonString
                                                              error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
