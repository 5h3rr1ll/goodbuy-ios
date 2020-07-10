/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#include <Foundation/Foundation.h>
#include <CoreGraphics/CoreGraphics.h>
#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.0.0
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCVideoResolution) {
/**
     * Added in version 6.0.0
     *
     * Resolution is 1280x720.
     */
    SDCVideoResolutionHD NS_SWIFT_NAME(hd) = 0,
/**
     * Added in version 6.0.0
     *
     * Resolution is 1920x1080.
     */
    SDCVideoResolutionFullHD = 1,
/**
     * Added in version 6.0.0
     *
     * In contrast to SDCVideoResolutionFullHD, and SDCVideoResolutionHD, SDCVideoResolutionAuto will select the resolution based on hardware capabilities and/or scan-performance considerations. The chosen resolution may change in future versions of the software.
     */
    SDCVideoResolutionAuto = 2,
/**
     * Added in version 6.0.0
     *
     * Resolution is 3840x2160.
     */
    SDCVideoResolutionUHD4K NS_SWIFT_NAME(uhd4k) = 3,
} NS_SWIFT_NAME(VideoResolution);

/**
 * Added in version 6.1.0
 */
SDC_EXTERN NSString *_Nonnull NSStringFromVideoResolution(SDCVideoResolution videoResolution) NS_SWIFT_NAME(getter:SDCVideoResolution.jsonString(self:));
/**
 * Added in version 6.1.0
 */
SDC_EXTERN BOOL SDCVideoResolutionFromJSONString(NSString *_Nonnull JSONString, SDCVideoResolution *_Nonnull videoResolution);

/**
 * Added in version 6.0.0
 *
 * Enumeration of possible focus ranges to use. This can be used to restrict the auto-focus system to only consider objects in a certain range to focus on.
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCFocusRange) {
/**
     * Added in version 6.0.0
     *
     * Use the full focus range supported by the camera.
     */
    SDCFocusRangeFull,
/**
     * Added in version 6.0.0
     *
     * Only focus on objects that are far from the camera.
     */
    SDCFocusRangeFar,
/**
     * Added in version 6.0.0
     *
     * Only focus on objects that are near to the camera.
     */
    SDCFocusRangeNear,
} NS_SWIFT_NAME(FocusRange);

/**
 * Added in version 6.1.0
 */
SDC_EXTERN NSString *_Nonnull NSStringFromFocusRange(SDCFocusRange focusRange) NS_SWIFT_NAME(getter:SDCFocusRange.jsonString(self:));
/**
 * Added in version 6.1.0
 */
SDC_EXTERN BOOL SDCFocusRangeFromJSONString(NSString *_Nonnull JSONString, SDCFocusRange *_Nonnull focusRange);

SDC_EXTERN const CGFloat SDCCurrentZoomFactor NS_SWIFT_NAME(CurrentZoomFactor);

/**
 * Added in version 6.0.0
 *
 * Holds camera-specific settings such as preferred resolution, maximum frame rate etc. The defaults are chosen such that they work for a wide variety of use cases. You may apply custom settings to further optimize scan performance for your particular use case. There is typically no need to customize the camera settings beyond changing the preferred resolution.
 *
 * @remark This class is not thread safe.
 *
 * Holds camera related settings such as preview resolution and maximum frame rate to use.
 *
 * Expose exposure and focus options.
 */
NS_SWIFT_NAME(CameraSettings)
SDC_EXPORTED_SYMBOL
@interface SDCCameraSettings : NSObject

/**
 * Added in version 6.0.0
 *
 * Creates new default camera settings. maxFrameRate is set to 30, zoomFactor is set to 1 and preferredResolution is set to SDCVideoResolutionAuto.
 */
- (instancetype)init;
/**
 * Added in version 6.0.0
 *
 * Creates a copy of the provided settings.
 */
- (instancetype)initWithSettings:(nonnull SDCCameraSettings *)settings;
/**
 * Added in version 6.2.0
 *
 * Set camera property to the provided value. Use this method to set properties that are not yet part of a stable API. Properties set through this method may or may not be used or change in a future release.
 */
- (void)setValue:(nonnull id)value forProperty:(nonnull NSString *)property;
/**
 * Added in version 6.2.0
 *
 * Retrieves the value of a previously set camera property. In case the property does not exist, nil is returned.
 */
- (nullable id)valueForProperty:(nonnull NSString *)property;

/**
 * Added in version 6.0.0
 *
 * The preferred resolution to use for the camera. The camera will use the resolution that is closests to the resolution preference. For example, if only lower resolutions than the preferred resolution are available, the highest available resolution will be used.
 *
 * The resolution chosen by the camera only takes the preferredResolution into account, it does not consider the resolution limit of your license key. When the device selects a resolution that is larger than what you have licensed, the data capture context will report a license status error.
 *
 * The default value is SDCVideoResolutionAuto.
 */
@property (nonatomic, assign) SDCVideoResolution preferredResolution;
/**
 * Added in version 6.0.0
 *
 * The maximum frame rate to use for the camera. If the value is higher than the maximum available frame rate of the device, it will be set to the device’s maximum.
 *
 * The default value is 30 Hz.
 */
@property (nonatomic, assign) CGFloat maxFrameRate;
/**
 * Added in version 6.0.0
 *
 * The zoom factor to use for the camera. This value is a multiplier, a value of 1.0 means no zoom, while a value of 2.0 doubles the size of the image, but halves the field of view.
 *
 * Values less than 1.0 are treated as 1.0. Values greater than the maximum available zoom factor are clamped to the maximum accepted value.
 *
 * If the zoom factor should not change, CurrentZoomFactor should be used.
 *
 * define CurrentZoomFactor and create link to it.
 *
 * The default zoom factor is 1.0.
 */
@property (nonatomic, assign) CGFloat zoomFactor;
/**
 * Added in version 6.0.0
 *
 * The focus range to primarily use, if supported by the device.
 */
@property (nonatomic, assign) SDCFocusRange focusRange;

@end

NS_ASSUME_NONNULL_END
