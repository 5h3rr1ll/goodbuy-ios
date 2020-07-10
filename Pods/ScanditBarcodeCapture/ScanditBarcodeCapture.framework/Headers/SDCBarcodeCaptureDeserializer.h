/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCDataCaptureModeDeserializer.h>

@class SDCBarcodeCapture;
@class SDCDataCaptureContext;
@class SDCBarcodeCaptureSettings;
@class SDCBarcodeCaptureOverlay;
@protocol SDCBarcodeCaptureDeserializerDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.1.0
 *
 * A deserializer to construct barcode capture from JSON. For most use cases it is enough to use SDCBarcodeCapture.barcodeCaptureFromJSONString:context:error: which internally uses this deserializer. Using the deserializer gives the advantage of being able to listen to the deserialization events as they happen and potentially influence them. Additonally warnings can be read from the deserializer that would otherwise not be available.
 *
 * Related topics: Serialization.
 */
NS_SWIFT_NAME(BarcodeCaptureDeserializer)
@interface SDCBarcodeCaptureDeserializer : NSObject <SDCDataCaptureModeDeserializer>

/**
 * Added in version 6.1.0
 *
 * The object informed about deserialization events.
 */
@property (nonatomic, weak, nullable) id<SDCBarcodeCaptureDeserializerDelegate> delegate;
/**
 * Added in version 6.1.0
 *
 * The warnings produced during deserialization, for example which properties were not used during deserialization.
 */
@property (nonatomic, readonly) NSArray<NSString *> *warnings;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.1.0
 *
 * Creates a new deserializer object.
 */
+ (instancetype)barcodeCaptureDeserializer;

/**
 * Added in version 6.1.0
 *
 * Deserializes barcode capture from JSON.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCBarcodeCapture *)modeFromJSONString:(NSString *)JSONString
                                       withContext:(SDCDataCaptureContext *)context
                                             error:(NSError *_Nullable *_Nullable)error;
/**
 * Added in version 6.1.0
 *
 * Takes an existing barcode capture and updates it by deserializing new or changed properties from JSON. See Updating from JSON for details of how updates are being done.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCBarcodeCapture *)updateMode:(SDCBarcodeCapture *)barcodeCapture
                            fromJSONString:(NSString *)JSONString
                                     error:(NSError *_Nullable *_Nullable)error;

- (nullable SDCBarcodeCaptureSettings *)settingsFromJSONString:(NSString *)JSONString
                                                         error:(NSError *_Nullable *_Nullable)error;
/**
 * Added in version 6.1.0
 *
 * Takes existing barcode capture settings and updates them by deserializing new or changed properties from JSON. See Updating from JSON for details of how updates are being done.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCBarcodeCaptureSettings *)updateSettings:(SDCBarcodeCaptureSettings *)settings
                                        fromJSONString:(NSString *)JSONString
                                                 error:(NSError *_Nullable *_Nullable)error;

/**
 * Added in version 6.1.0
 *
 * Deserializes a barcode capture overlay from JSON.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCBarcodeCaptureOverlay *)overlayFromJSONString:(NSString *)JSONString
                                                    withMode:(SDCBarcodeCapture *)mode
                                                       error:(NSError *_Nullable *_Nullable)error;
/**
 * Added in version 6.1.0
 *
 * Takes an existing barcode capture overlay and updates it by deserializing new or changed properties from JSON. See Updating from JSON for details of how updates are being done.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCBarcodeCaptureOverlay *)updateOverlay:(SDCBarcodeCaptureOverlay *)overlay
                                      fromJSONString:(NSString *)JSONString
                                               error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
