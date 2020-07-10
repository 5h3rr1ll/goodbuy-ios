/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.0.0
 *
 * A capture mode overlay is the UI counterpart of capture modes and visualizes the recognition process in the graphical user interface. Overlays highlight objects such as identified barcodes on top of the preview. Overlays may add UI elements to guide the user, such as view finders.
 *
 * Capture mode overlays are added to a SDCDataCaptureView through SDCDataCaptureView.addOverlay: and removed again through SDCDataCaptureView.removeOverlay:. Overlays are associated to the data capture modes they require when they are constructed.
 *
 * Overlays are restricted to the set of overlays provided by the Scandit Data Capture SDK, it is not possible for customers to conform to this protocol and provide custom overlays. This protocol does not expose any methods or properties, it just serves as a tag for different overlays.
 */
NS_SWIFT_NAME(DataCaptureOverlay)
@protocol SDCDataCaptureOverlay <NSObject>

@end

NS_ASSUME_NONNULL_END
