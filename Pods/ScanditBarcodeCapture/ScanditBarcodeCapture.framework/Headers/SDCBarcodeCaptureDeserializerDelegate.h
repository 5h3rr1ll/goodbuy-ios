/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

@class SDCBarcodeCaptureDeserializer;
@class SDCBarcodeCapture;
@class SDCBarcodeCaptureSettings;
@class SDCBarcodeCaptureOverlay;
@class SDCJSONValue;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.1.0
 *
 * The listener for the barcode capture deserializer.
 */
NS_SWIFT_NAME(BarcodeCaptureDeserializerDelegate)
@protocol SDCBarcodeCaptureDeserializerDelegate <NSObject>

/**
 * Added in version 6.1.0
 *
 * Called before the deserialization of barcode capture started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)barcodeCaptureDeserializer:(SDCBarcodeCaptureDeserializer *)deserializer
         didStartDeserializingMode:(SDCBarcodeCapture *)mode
                     fromJSONValue:(SDCJSONValue *)JSONValue;
/**
 * Added in version 6.1.0
 *
 * Called when the deserialization of barcode capture finished. This is the point to do additional deserialization.
 */
- (void)barcodeCaptureDeserializer:(SDCBarcodeCaptureDeserializer *)deserializer
        didFinishDeserializingMode:(SDCBarcodeCapture *)mode
                     fromJSONValue:(SDCJSONValue *)JSONValue;

/**
 * Added in version 6.1.0
 *
 * Called before the deserialization of the barcode capture settings started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)barcodeCaptureDeserializer:(SDCBarcodeCaptureDeserializer *)deserializer
     didStartDeserializingSettings:(SDCBarcodeCaptureSettings *)settings
                     fromJSONValue:(SDCJSONValue *)JSONValue;
/**
 * Added in version 6.1.0
 *
 * Called when the deserialization of the barcode capture settings finished. This is the point to do additional deserialization.
 */
- (void)barcodeCaptureDeserializer:(SDCBarcodeCaptureDeserializer *)deserializer
    didFinishDeserializingSettings:(SDCBarcodeCaptureSettings *)settings
                     fromJSONValue:(SDCJSONValue *)JSONValue;

/**
 * Added in version 6.1.0
 *
 * Called before the deserialization of the barcode capture overlay started. This is the point to overwrite defaults before the deserialization is performed.
 */
- (void)barcodeCaptureDeserializer:(SDCBarcodeCaptureDeserializer *)deserializer
      didStartDeserializingOverlay:(SDCBarcodeCaptureOverlay *)overlay
                     fromJSONValue:(SDCJSONValue *)JSONValue;
/**
 * Added in version 6.1.0
 *
 * Called when the deserialization of the barcode capture overlay finished. This is the point to do additional deserialization.
 */
- (void)barcodeCaptureDeserializer:(SDCBarcodeCaptureDeserializer *)deserializer
     didFinishDeserializingOverlay:(SDCBarcodeCaptureOverlay *)overlay
                     fromJSONValue:(SDCJSONValue *)JSONValue;

@end

NS_ASSUME_NONNULL_END
