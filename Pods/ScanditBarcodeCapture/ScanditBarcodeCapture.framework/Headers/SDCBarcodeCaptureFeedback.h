/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>
@class SDCFeedback;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.0.0
 *
 * Determines what feedback (vibration, sound) should be emitted when reading barcodes.
 * The feedback is specified for each SDCBarcodeCapture instance separately and can be changed
 * through the feedback property by either modifying an existing
 * instance of this class, or by assigning a new one.
 *
 * As of now, this class only allows to configure the feedback that gets emitted when a barcode is read successfully, through the success property.
 *
 * See documentation on the SDCBarcodeCapture.feedback property for usage samples.
 */
NS_SWIFT_NAME(BarcodeCaptureFeedback)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeCaptureFeedback : NSObject

/**
 * Added in version 6.0.0
 *
 * Returns a barcode capture feedback with default configuration:
 *
 *   • default beep sound is loaded,
 *
 *   • beeping for the success event is enabled,
 *
 *   • vibration for the success event is enabled.
 */
@property (class, nonatomic, readonly) SDCBarcodeCaptureFeedback *defaultFeedback;

/**
 * Added in version 6.0.0
 *
 * A feedback for a success event.
 */
@property (nonatomic, strong, nonnull) SDCFeedback *success;

+ (nullable instancetype)barcodeCaptureFeedbackFromJSONString:(nonnull NSString *)jsonString
                                                        error:(NSError *_Nullable *_Nullable)error;
@end

NS_ASSUME_NONNULL_END
