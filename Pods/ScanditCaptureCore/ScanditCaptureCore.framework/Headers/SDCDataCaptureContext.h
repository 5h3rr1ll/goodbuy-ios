/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

@class SDCDataCaptureContext;
@class SDCContextStatus;
@protocol SDCFrameData;
@protocol SDCFrameSource;
@protocol SDCDataCaptureMode;

/**
 * Added in version 6.0.0
 *
 * Protocol for observing/listening to mode and status changes of a data capture context.
 *
 * To observe changes of the data capture context, one or more SDCDataCaptureContextListener may be added. These listeners provide hooks into different parts of the data capture context.
 */
NS_SWIFT_NAME(DataCaptureContextListener)
@protocol SDCDataCaptureContextListener <NSObject>

@required

/**
 * Added in version 6.0.0
 *
 * Invoked when the data capture context changed the frame source. Also invoked if the frame source is reset to nil.
 */
- (void)context:(SDCDataCaptureContext *)context
    didChangeFrameSource:(nullable id<SDCFrameSource>)frameSource;

/**
 * Added in version 6.0.0
 *
 * Called when a mode got added to the context.
 */
- (void)context:(SDCDataCaptureContext *)context didAddMode:(id<SDCDataCaptureMode>)mode;

/**
 * Added in version 6.0.0
 *
 * Called when a mode got removed from the context.
 */
- (void)context:(SDCDataCaptureContext *)context didRemoveMode:(id<SDCDataCaptureMode>)mode;

/**
 * Added in version 6.0.0
 *
 * Called when a context status changed.
 */
- (void)context:(SDCDataCaptureContext *)context didChangeStatus:(SDCContextStatus *)contextStatus;

@optional

/**
 * Added in version 6.0.0
 *
 * Called when the listener has been added to the data capture context and is from now on receiving events.
 */
- (void)didStartObservingContext:(SDCDataCaptureContext *)context;

/**
 * Added in version 6.0.0
 *
 * Called when the listener has been removed from the data capture context and is no longer receiving events.
 */
- (void)didStopObservingContext:(SDCDataCaptureContext *)context;

@end

/**
 * Added in version 6.0.0
 *
 * Protocol for observing/listening to frame processing related events of a data capture context.
 *
 * To observe changes of the data capture context’s frame processing, one or more SDCDataCaptureContextFrameListener may be added. These listeners provide hooks into different parts of the data capture context.
 *
 * Frame processing only happens if at least one SDCDataCaptureMode is added.
 */
NS_SWIFT_NAME(DataCaptureContextFrameListener)
@protocol SDCDataCaptureContextFrameListener <NSObject>

@required

/**
 * Added in version 6.0.0
 *
 * Called when a frame will be processed.
 */
- (void)context:(SDCDataCaptureContext *)context willProcessFrame:(id<SDCFrameData>)frame;

/**
 * Added in version 6.0.0
 *
 * Called when a frame has been processed.
 */
- (void)context:(SDCDataCaptureContext *)context didProcessFrame:(id<SDCFrameData>)frame;

@end

/**
 * Added in version 6.0.0
 *
 * Data capture context is the main class for running data-capture related tasks. The context manages one or more capture modes, such as SDCBarcodeCapture, or SDCLabelCapture that perform the recognition. The context itself acts as a scheduler, but does not provide any interfaces for configuring data capture capabilities. Configuration and result handling is handled by the data capture modes directly.
 *
 * Each data capture context has exactly one frame source (typically a built-in camera). The frame source delivers the frames on which the capture modes should perform recognition on. When a new capture context is created, it’s frame source is nil and must be initialized for recognition to work.
 *
 * Typically a SDCDataCaptureView is used to visualize the ongoing data capture process on screen together with one or more overlays. However it’s also possible to use the data capture context without a view to perform off-screen processing.
 *
 * Related topics: Get Started With Barcode Scanning, Get Started With MatrixScan, Core Concepts of the Scandit Data Capture SDK.
 */
NS_SWIFT_NAME(DataCaptureContext)
SDC_EXPORTED_SYMBOL
@interface SDCDataCaptureContext : NSObject

/**
 * Added in version 6.0.0
 *
 * Readonly attribute to get the current frame source. To change the frame source use setFrameSource:completionHandler:.
 */
@property (nonatomic, nullable, readonly) id<SDCFrameSource> frameSource;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.0.0
 *
 * Constructs a data capture context with the provided license key.
 *
 * @remark Due to resource constraints, only one data capture context instance can be used at a given point in time. Each call to contextForLicenseKey: disposes previously created data capture contexts, as if dispose were called. Disposed contexts cannot be used for recognition anymore.
 */
+ (instancetype)contextForLicenseKey:(nonnull NSString *)licenseKey
    NS_SWIFT_NAME(init(licenseKey:));

/**
 * Added in version 6.1.0
 *
 * Constructs a data capture context with the provided license key and an optional external id. See contextForLicenseKey: for details.
 *
 * The external ID is a customer defined identifier that is verified in the license key. This is an optional feature for resellers of the Scandit Data Capture SDK.
 *
 * See contextForLicenseKey: for details about the context instantiation.
 */
+ (instancetype)contextForLicenseKey:(nonnull NSString *)licenseKey
                          externalID:(nullable NSString *)externalID
    NS_SWIFT_NAME(init(licenseKey:externalID:));

/**
 * Added in version 6.0.0
 *
 * Constructs a data capture context with the provided license key and an optional device name.
 *
 * The device name allows to optionally identify the device with a user-provided name. This name is then associated with the unique identifier of the device and displayed in the online dashboard.
 *
 * See contextForLicenseKey: for details about the context instantiation.
 */
+ (instancetype)contextForLicenseKey:(nonnull NSString *)licenseKey
                          deviceName:(nullable NSString *)deviceName
    NS_SWIFT_NAME(init(licenseKey:deviceName:));

/**
 * Added in version 6.1.0
 *
 * Constructs a data capture context with the provided license key, an optional external id and an optional device name.
 *
 * The external ID is a customer defined identifier that is verified in the license key. This is an optional feature for resellers of the Scandit Data Capture SDK.
 *
 * The device name allows to identify the device with a user-provided name. This name is then associated with the unique identifier of the device and displayed in the online dashboard.
 *
 * See contextForLicenseKey: for details about the context instantiation.
 */
+ (instancetype)contextForLicenseKey:(nonnull NSString *)licenseKey
                          externalID:(nullable NSString *)externalID
                          deviceName:(nullable NSString *)deviceName
    NS_SWIFT_NAME(init(licenseKey:externalID:deviceName:));

+ (instancetype)contextForLicenseKey:(nonnull NSString *)licenseKey
                          externalID:(nullable NSString *)externalID
                          deviceName:(nullable NSString *)deviceName
                       frameworkName:(nullable NSString *)frameworkName
    NS_SWIFT_NAME(init(licenseKey:externalID:deviceName:frameworkName:));

/**
 * Added in version 6.0.0
 *
 * Adds the listener to this data capture context. Context listeners receive events when new data capture modes are added, or the frame source changes.
 *
 * In case the same listener is already observing this instance, calling this method will not add the listener again. The listener is stored using a weak reference and must thus be retained by the caller for it to not go out of scope.
 */
- (void)addListener:(nonnull id<SDCDataCaptureContextListener>)listener
    NS_SWIFT_NAME(addListener(_:));
/**
 * Added in version 6.0.0
 *
 * Removes a previously added listener from this data capture context.
 *
 * In case the listener is not currently observing this instance, calling this method has no effect.
 */
- (void)removeListener:(nonnull id<SDCDataCaptureContextListener>)listener
    NS_SWIFT_NAME(removeListener(_:));

/**
 * Added in version 6.0.0
 *
 * Adds the frame listener to this data capture context. Frame listeners receive events when frames are about to be processed or have been processed by the data capture context.
 *
 * In case the same listener is already observing this instance, calling this method will not add the listener again. The listener is stored using a weak reference and must thus be retained by the caller for it to not go out of scope.
 */
- (void)addFrameListener:(nullable id<SDCDataCaptureContextFrameListener>)listener
    NS_SWIFT_NAME(addFrameListener(_:));
/**
 * Added in version 6.0.0
 *
 * Removes a previously added frame listener from this data capture context.
 *
 * In case the listener is not currently observing this instance, calling this method has no effect.
 */
- (void)removeFrameListener:(nullable id<SDCDataCaptureContextFrameListener>)listener
    NS_SWIFT_NAME(removeFrameListener(_:));

/**
 * Added in version 6.0.0
 *
 * Set the frame source of this data capture context.
 *
 * Frame sources produce frames to be processed by the data capture context. The user typically doesn’t create their own frame sources, but use one of the frame sources provided by the Scandit Data Capture SDK. Typical frame sources are web cams, or built-in cameras of a mobile device.
 *
 * Setting the frame source to nil will effectively stop recognition of this capture context.
 *
 * When the frame source changes, SDCDataCaptureContextListener.context:didChangeFrameSource: will be invoked on all registered listeners.
 */
- (void)setFrameSource:(nullable id<SDCFrameSource>)frameSource
     completionHandler:(nullable void (^)(void))completionHandler;

/**
 * Added in version 6.0.0
 *
 * Adds the specified data capture mode to this capture context. Please note that it is not possible to add a mode associated with a context to a different context. If the mode is already associated with this context, this call has no effect.
 *
 * Multiple data capture modes can be associated with the same context. However, there are restrictions on which data capture modes can be used together. These restrictions are expressed in terms of capabilities that the capture modes require, .e.g. barcode scanning, tracking. No two capture modes that require the same capabilities can be used with the same data capture context. When conflicting requirements are detected, the data capture context will not process any frames and report an error.
 *
 * Decide how to propagate error in case of failure.
 */
- (void)addMode:(nonnull id<SDCDataCaptureMode>)mode NS_SWIFT_NAME(addMode(_:));
/**
 * Added in version 6.0.0
 *
 * Removes the mode from this capture context. If the capture mode is currently not associated to the context, this call has no effect.
 */
- (void)removeMode:(nonnull id<SDCDataCaptureMode>)mode NS_SWIFT_NAME(removeMode(_:));

/**
 * Added in version 6.0.0
 *
 * Removes all modes from this capture context. If there currently are no captures modes associated to the context, this call has no effect. It is only allowed to remove capture modes from the context when either the frame source is nil, or the frame source is off (SDCFrameSource.currentState is SDCFrameSourceStateOff).
 */
- (void)removeAllModes;

/**
 * Added in version 6.0.0
 *
 * Disposes/releases this data capture context. This frees most associated resources and can be used to save some memory. Disposed/released contexts cannot be used for recognition anymore, trying will result in a ContextStatus with error code 1025. Data capture modes and listeners remain untouched.
 *
 * This method may be called multiple times on the same context. Further calls have no effect.
 */
- (void)dispose;

@end

NS_ASSUME_NONNULL_END
