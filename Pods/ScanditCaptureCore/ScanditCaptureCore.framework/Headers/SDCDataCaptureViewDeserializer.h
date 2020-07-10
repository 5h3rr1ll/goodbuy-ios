/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCDataCaptureView.h>

NS_ASSUME_NONNULL_BEGIN

@class SDCDataCaptureViewDeserializerHelper;
@protocol SDCDataCaptureViewDeserializerDelegate;
@protocol SDCDataCaptureModeDeserializer;

/**
 * Added in version 6.1.0
 *
 * A deserializer to construct frame sources from JSON. For most use cases it is enough to use SDCCamera.cameraFromJSONString:error: which internally uses this deserializer. Using the deserializer gives the advantage of being able to listen to the deserialization events as they happen and potentially influence them. Additonally warnings can be read from the deserializer that would otherwise not be available.
 *
 * Related topics: Serialization.
 */
NS_SWIFT_NAME(DataCaptureViewDeserializer)
@interface SDCDataCaptureViewDeserializer : NSObject

/**
 * Added in version 6.1.0
 *
 * The object informed about deserialization events.
 */
@property (nonatomic, weak, nullable) id<SDCDataCaptureViewDeserializerDelegate> delegate;
/**
 * Added in version 6.1.0
 *
 * The warnings produced during deserialization, for example which properties were not used during deserialization.
 */
@property (nonatomic, readonly) NSArray<NSString *> *warnings;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

+ (instancetype)dataCaptureViewDeserializerWithDeserializerModes:
    (NSArray<id<SDCDataCaptureModeDeserializer>> *)modeDeserializers
    NS_SWIFT_NAME(init(modeDeserializers:));

/**
 * Added in version 6.1.0
 *
 * Deserializes a data capture view from JSON.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCDataCaptureView *)viewFromJSONString:(NSString *)JSONString
                                        withContext:(SDCDataCaptureContext *)context
                                              error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.1.0
 *
 * Takes an existing data capture view and updates it by deserializing new or changed properties from JSON. See Updating from JSON for details of how updates are being done.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCDataCaptureView *)updateView:(SDCDataCaptureView *)view
                             fromJSONString:(NSString *)JSONString
                                      error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
