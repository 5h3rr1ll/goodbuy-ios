/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#include <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SDCDataCaptureContext;
@protocol SDCFrameData;

/**
 * Added in version 6.0.0
 *
 * SDCDataCaptureMode is the protocol implemented by all data capture modes. A data capture mode encapsulates a specific way of capturing data, such as barcode capture, barcode tracking, text capture, or label capture. Each capture mode can be individually enabled and disabled to switch between different ways of capturing data.
 *
 * Capture modes are restricted to the set of data captures modes provided by the Scandit Data Capture SDK. It is not available for implementing custom data capture modes.
 *
 * Capture modes need to be associated with a data capture context after they have been created using SDCDataCaptureContext.addMode:. This is done automatically when using any of the factory methods such as SDCBarcodeCapture.barcodeCaptureWithContext:settings:, SDCBarcodeTracking.barcodeTrackingWithContext:settings:, SDCTextCapture.textCaptureWithContext:settings: or SDCLabelCapture.labelCaptureWithContext:settings: and specifying a context. If no context is specified for the factory methods, the mode has to be manually added. Modes can be removed again using SDCDataCaptureContext.removeMode:.
 *
 * Multiple data capture modes can be associated with the same context. However, there are restrictions on which data capture modes can be used together. These restrictions are expressed in terms of capabilities that the capture modes require, for example barcode scanning and barcode tracking both require the capability to scan barcodes. No two capture modes that require the same capabilities can be used with the same data capture context. When conflicting requirements are detected, the data capture context will not process any frames and report a context status error with code 1028.
 *
 * Usage Sample
 *
 * Because the SDCDataCaptureMode cannot be instantiated directly, the example below uses the SDCBarcodeCapture to illustrate a typical usage of capture modes. Other capture modes will work very similarly. The typical steps are:
 *
 *   1. Configure the capture mode by first creating settings.
 *
 *   2. Instantiate the capture mode and associate with the context and the settings.
 *
 *   3. Registering a mode-specific listener (not shown).
 *
 * Todo
 *
 * add this to the sample
 *
 *   4. Enabling recognition by setting the enabled property to YES.
 *
 * add this to the sample
 *
 * @code
 * let settings = BarcodeCaptureSettings()
 * settings.set(symbology: .qr, enabled: true)
 * let barcodeCapture = BarcodeCapture(context: context, settings: settings)
 * // Capture modes are enabled by default. The next line is not strictly necessary and
 * // is only listed to make you aware of the possibility to enable/disable modes.
 * barcodeCapture.isEnabled = true
 * @endcode
 */
NS_SWIFT_NAME(DataCaptureMode)
@protocol SDCDataCaptureMode <NSObject>

/**
 * Added in version 6.0.0
 *
 * YES if this data capture mode is enabled, NO if not. Only enabled capture modes are processing frames.
 *
 * Changing this property from NO to YES causes this data capture mode to start processing frames.
 *
 * Changing this property from YES to NO causes this data capture mode to stop processing frames. The effect is immediate: no more frames will be processed after the change. However, if a frame is currently being processed, this frame will be completely processed and deliver any results/callbacks to the registered listeners. When changing this property from one of the listener callbacks that is called as a result of processing the frame, no more frames will be processed after that.
 *
 * Note that this property only affects the data capture and does not affect the SDCFrameSource’s state.
 *
 * By default, this property is YES.
 */
@property (nonatomic, assign, getter=isEnabled) BOOL enabled NS_SWIFT_NAME(isEnabled);

/**
 * Added in version 6.0.0
 *
 * The context this data capture mode is attached to. When the data capture mode is currently not attached to a context, nil is returned.
 */
@property (nonatomic, nullable, readonly) SDCDataCaptureContext *context;

@end

NS_ASSUME_NONNULL_END
