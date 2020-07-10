/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

@class SDCBarcode;
@class SDCLocalizedOnlyBarcode;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.0.0
 *
 * The capture session is responsible for determining the list of relevant barcodes by filtering out duplicates. This filtering of duplicates is completely time-based and doesn’t use any information about the location of the barcode. For location-based tracking over multiple frames, you may be better off using SDCBarcodeTracking. By default, all the codes scanned in a frame are always reported. It is possible to filter out codes recently scanned by changing SDCBarcodeCaptureSettings.codeDuplicateFilter.
 *
 * When the barcode capture mode is disabled, the session’s duplicate filter is reset.
 *
 * The capture session should only be accessed from within the callbacks to which it is provided as an argument. It is not safe to be accessed from anywhere else since it may be concurrently modified. However, the barcodes returned by the session can be used outside the callbacks.
 */
NS_SWIFT_NAME(BarcodeCaptureSession)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeCaptureSession : NSObject

/**
 * Added in version 6.0.0
 *
 * List of codes that were newly recognized in the last processed frame.
 */
@property (nonatomic, nonnull, readonly) NSArray<SDCBarcode *> *newlyRecognizedBarcodes;
/**
 * Added in version 6.0.0
 *
 * List of codes that were newly localized (but not recognized) in the last processed frame.
 */
@property (nonatomic, nonnull, readonly) NSArray<SDCLocalizedOnlyBarcode *> *newlyLocalizedBarcodes;
/**
 * Added in version 6.1.0
 *
 * The identifier of the current frame sequence.
 *
 * As long as there is no interruptions of frames coming from the camera, the frameSequenceId will stay the same.
 */
@property (nonatomic, readonly) NSInteger frameSequenceId;
/**
 * Added in version 6.1.0
 *
 * Returns the JSON representation of the barcode capture session.
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.0.0
 *
 * Resets the barcode capture session, effectively clearing the history of scanned codes. This affects duplicate filtering: when calling reset every frame has the same effect as setting the SDCBarcodeCaptureSettings.codeDuplicateFilter to 0.
 */
- (void)reset;

@end

NS_ASSUME_NONNULL_END
