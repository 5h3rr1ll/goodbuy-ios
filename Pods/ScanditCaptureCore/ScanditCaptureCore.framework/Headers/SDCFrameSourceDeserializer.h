/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

@class SDCFrameSourceDeserializer;
@class SDCCameraSettings;
@protocol SDCDataCaptureModeDeserializer;
@protocol SDCFrameSourceDeserializerDelegate;
@protocol SDCFrameSource;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.1.0
 *
 * A deserializer to construct frame sources from JSON. For most use cases it is enough to use SDCCamera.cameraFromJSONString:error: which internally uses this deserializer. Using the deserializer gives the advantage of being able to listen to the deserialization events as they happen and potentially influence them. Additonally warnings can be read from the deserializer that would otherwise not be available.
 *
 * Related topics: Serialization.
 */
NS_SWIFT_NAME(FrameSourceDeserializer)
@interface SDCFrameSourceDeserializer : NSObject

/**
 * Added in version 6.1.0
 *
 * The object informed about deserialization events.
 */
@property (nonatomic, weak, nullable) id<SDCFrameSourceDeserializerDelegate> delegate;
/**
 * Added in version 6.1.0
 *
 * The warnings produced during deserialization, for example which properties were not used during deserialization.
 */
@property (nonatomic, readonly) NSArray<NSString *> *warnings;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)frameSourceDeserializerWithModeDeserializers:(NSArray<id<SDCDataCaptureModeDeserializer>> *)modeDeserializers;

/**
 * Added in version 6.1.0
 *
 * Deserializes a frame source from JSON.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable id<SDCFrameSource>)frameSourceFromJSONString:(NSString *)JSONString
                                                   error:(NSError *_Nullable *_Nullable)error;
/**
 * Added in version 6.1.0
 *
 * Takes an existing frame source and updates it by deserializing new or changed properties from JSON. See Updating from JSON for details of how updates are being done.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable id<SDCFrameSource>)updateFrameSource:(id<SDCFrameSource>)frameSource
                                  fromJSONString:(NSString *)JSONString
                                           error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.1.0
 *
 * Deserializes camera settings from JSON.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCCameraSettings *)cameraSettingsFromJSONString:(NSString *)JSONString
                                                       error:(NSError *_Nullable *_Nullable)error;
/**
 * Added in version 6.1.0
 *
 * Takes existing camera settings and updates them by deserializing new or changed properties from JSON. See Updating from JSON for details of how updates are being done.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCCameraSettings *)updateCameraSettings:(SDCCameraSettings *)settings
                                      fromJSONString:(NSString *)JSONString
                                               error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
