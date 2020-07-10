/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

@class SDCBarcodeTrackingDeserializer;
@class SDCBarcodeTracking;
@class SDCBarcodeTrackingSettings;
@class SDCBarcodeTrackingBasicOverlay;
@class SDCJSONValue;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.1.0
 *
 * The listener for the barcode capture deserializer.
 */
NS_SWIFT_NAME(BarcodeTrackingDeserializerDelegate)
@protocol SDCBarcodeTrackingDeserializerDelegate <NSObject>

/**
 * Added in version 6.1.0
 *
 * Called before the deserialization of barcode tracking started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)barcodeTrackingDeserializer:(SDCBarcodeTrackingDeserializer *)deserializer
          didStartDeserializingMode:(SDCBarcodeTracking *)mode
                      fromJSONValue:(SDCJSONValue *)JSONValue;
/**
 * Added in version 6.1.0
 *
 * Called when the deserialization of barcode tracking finished. This is the point to do additional deserialization.
 */
- (void)barcodeTrackingDeserializer:(SDCBarcodeTrackingDeserializer *)deserializer
         didFinishDeserializingMode:(SDCBarcodeTracking *)mode
                      fromJSONValue:(SDCJSONValue *)JSONValue;

/**
 * Added in version 6.1.0
 *
 * Called before the deserialization of the barcode tracking settings started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)barcodeTrackingDeserializer:(SDCBarcodeTrackingDeserializer *)deserializer
      didStartDeserializingSettings:(SDCBarcodeTrackingSettings *)settings
                      fromJSONValue:(SDCJSONValue *)JSONValue;
/**
 * Added in version 6.1.0
 *
 * Called when the deserialization of the barcode tracking settings finished. This is the point to do additional deserialization.
 */
- (void)barcodeTrackingDeserializer:(SDCBarcodeTrackingDeserializer *)deserializer
     didFinishDeserializingSettings:(SDCBarcodeTrackingSettings *)settings
                      fromJSONValue:(SDCJSONValue *)JSONValue;

/**
 * Added in version 6.1.0
 *
 * Called before the deserialization of the barcode tracking basic overlay started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)barcodeTrackingDeserializer:(SDCBarcodeTrackingDeserializer *)deserializer
    didStartDeserializingBasicOverlay:(SDCBarcodeTrackingBasicOverlay *)overlay
                        fromJSONValue:(SDCJSONValue *)JSONValue;
/**
 * Added in version 6.1.0
 *
 * Called when the deserialization of the barcode tracking basic overlay finished. This is the point to do additional deserialization.
 */
- (void)barcodeTrackingDeserializer:(SDCBarcodeTrackingDeserializer *)deserializer
    didFinishDeserializingBasicOverlay:(SDCBarcodeTrackingBasicOverlay *)overlay
                         fromJSONValue:(SDCJSONValue *)JSONValue;

@end

NS_ASSUME_NONNULL_END
