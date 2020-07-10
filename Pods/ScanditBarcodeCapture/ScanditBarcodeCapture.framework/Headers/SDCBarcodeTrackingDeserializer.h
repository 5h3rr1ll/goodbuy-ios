/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCDataCaptureModeDeserializer.h>

@class SDCBarcodeTracking;
@class SDCDataCaptureContext;
@class SDCBarcodeTrackingSettings;
@class SDCBarcodeTrackingBasicOverlay;
@protocol SDCBarcodeTrackingDeserializerDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.1.0
 *
 * A deserializer to construct barcode tracking from JSON. For most use cases it is enough to use SDCBarcodeTracking.barcodeTrackingFromJSONString:context:error: which internally uses this deserializer. Using the deserializer gives the advantage of being able to listen to the deserialization events as they happen and potentially influence them. Additonally warnings can be read from the deserializer that would otherwise not be available.
 *
 * Related topics: Serialization.
 */
NS_SWIFT_NAME(BarcodeTrackingDeserializer)
@interface SDCBarcodeTrackingDeserializer : NSObject <SDCDataCaptureModeDeserializer>

/**
 * Added in version 6.1.0
 *
 * The object informed about deserialization events.
 */
@property (nonatomic, weak, nullable) id<SDCBarcodeTrackingDeserializerDelegate> delegate;
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
+ (instancetype)barcodeTrackingDeserializer;

/**
 * Added in version 6.1.0
 *
 * Deserializes barcode tracking from JSON.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCBarcodeTracking *)modeFromJSONString:(NSString *)JSONString
                                        withContext:(SDCDataCaptureContext *)context
                                              error:(NSError *_Nullable *_Nullable)error;
/**
 * Added in version 6.1.0
 *
 * Takes an existing barcode tracking and updates it by deserializing new or changed properties from JSON. See Updating from JSON for details of how updates are being done.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCBarcodeTracking *)updateMode:(SDCBarcodeTracking *)barcodeTracking
                             fromJSONString:(NSString *)JSONString
                                      error:(NSError *_Nullable *_Nullable)error;

- (nullable SDCBarcodeTrackingSettings *)settingsFromJSONString:(NSString *)JSONString
                                                          error:
                                                              (NSError *_Nullable *_Nullable)error;
/**
 * Added in version 6.1.0
 *
 * Takes existing barcode tracking settings and updates them by deserializing new or changed properties from JSON. See Updating from JSON for details of how updates are being done.
 *
 * An error is set if the provided JSON does not contain required properties or contains properties of the wrong type.
 */
- (nullable SDCBarcodeTrackingSettings *)updateSettings:(SDCBarcodeTrackingSettings *)settings
                                         fromJSONString:(NSString *)JSONString
                                                  error:(NSError *_Nullable *_Nullable)error;

- (nullable SDCBarcodeTrackingBasicOverlay *)basicOverlayFromJSONString:(NSString *)JSONString
                                                               withMode:(SDCBarcodeTracking *)mode
                                                                  error:(NSError *_Nullable *_Nullable)error;
- (nullable SDCBarcodeTrackingBasicOverlay *)updateBasicOverlay:(SDCBarcodeTrackingBasicOverlay *)overlay
                                                 fromJSONString:(NSString *)JSONString
                                                          error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
