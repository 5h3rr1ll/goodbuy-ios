/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

/**
 * Added in version 6.0.0
 *
 * Enumeration of possible channel types.
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCChannel) {
/**
     * Added in version 6.0.0
     *
     * Luminance (Y) or gray-scale channel
     */
    SDCChannelY,
/**
     * Added in version 6.0.0
     */
    SDCChannelU,
/**
     * Added in version 6.0.0
     */
    SDCChannelV,
/**
     * Added in version 6.0.0
     *
     * Red channel
     */
    SDCChannelR,
/**
     * Added in version 6.0.0
     *
     * Green channel
     */
    SDCChannelG,
/**
     * Added in version 6.0.0
     *
     * Blue channel
     */
    SDCChannelB,
/**
     * Added in version 6.0.0
     *
     * Alpha channel
     */
    SDCChannelA
} NS_SWIFT_NAME(Channel);

/**
 * Added in version 6.0.0
 *
 * An individual image plane as part of an image buffer. The image plane data may or may not be interleaved with other image planes.
 */
NS_SWIFT_NAME(ImagePlane)
SDC_EXPORTED_SYMBOL
@interface SDCImagePlane : NSObject

/**
 * Added in version 6.0.0
 *
 * The bytes used by this image plane. For interleaved image planes, parts of the bytes exposed this property may not be part of this plane and belong to other planes. For example, for an SDCImageBuffer with red, green and blue planes using an interleaved layout, only every third byte belongs to the red image plane.
 *
 * The life-time of the data is tied to the life-time of the SDCImageBuffer, which for image buffers belonging to frame data is bound to the life-time of the SDCFrameData instance.
 */
@property (nonatomic, nonnull, readonly) uint8_t const *data;
/**
 * Added in version 6.0.0
 */
@property (nonatomic, readonly) SDCChannel channel;
/**
 * Added in version 6.0.0
 *
 * The amount of subsampling (in pixels in X-direction). For image plane with the exception of U and V planes, the subsampling in both x and y will be 1 (meaning no subsampling). A subsampling of 2 indicates that two horizontally adjacent  pixels share the same pixel data.
 */
@property (nonatomic, readonly) NSUInteger subsamplingX;
/**
 * Added in version 6.0.0
 *
 * The amount of subsampling (in pixels in Y-direction). For image plane with the exception of U and V planes, the subsampling in both x and y will be 1 (meaning no subsampling). A subsampling of 2 indicates that two vertically adjacent pixels share the same pixel data.
 */
@property (nonatomic, readonly) NSUInteger subsamplingY;
/**
 * Added in version 6.0.0
 *
 * The number of bytes of a row of pixels. For example, an RGB image will typically have a row stride of 3 * width, with potential padding at the end to match mulitples of 4.
 */
@property (nonatomic, readonly) NSUInteger rowStride;
/**
 * Added in version 6.0.0
 *
 * Number of bytes between two adjacent pixels part of the same image plane. In case of subsampling, this value is the number of bytes per pixel as if there were no subsampling. For example, for a non-interleaved U plane subsampled at 2, the element stride is 1.
 */
@property (nonatomic, readonly) NSUInteger pixelStride;

@end

@class UIImage;

/**
 * Added in version 6.0.0
 *
 * An image buffer consists of one or more images planes that describe how the memory is laid out. Instances of this class don’t own the data, rather the data is owned by another class (typically a SDCFrameData instance).
 *
 * platform specific convenience functionality to convert from native image/frame types to image buffer.
 */
NS_SWIFT_NAME(ImageBuffer)
SDC_EXPORTED_SYMBOL
@interface SDCImageBuffer : NSObject

/**
 * Added in version 6.0.0
 *
 * List of planes that this image buffer holds. The data used by these image planes may or may not be part of the same block of memory.
 */
@property (nonatomic, nonnull, readonly) NSArray<SDCImagePlane *> *planes;
/**
 * Added in version 6.0.0
 *
 * Width of the image buffer in pixels (non-subsampled).
 */
@property (nonatomic, readonly) NSUInteger width;
/**
 * Added in version 6.0.0
 *
 * Height of the image buffer in pixels (non-subsampled).
 */
@property (nonatomic, readonly) NSUInteger height;
/**
 * Added in version 6.1.0
 *
 * Converts the video frame to a UIImage that can be visualized in the UI, or stored on disk.
 *
 * The returned image has the same dimensions as the video frame.
 */
- (nullable UIImage *)toUIImage;

@end

/**
 * Added in version 6.0.0
 *
 * Interface for holding frame data from one or more sources (cameras). The concrete type is tied to the frame source that produces the frames.
 *
 * The frame data contains one or more image buffers, each of which may have different sizes. Each frame data is guaranteed to have at least one image buffer. Only frame sources that combine the input of multiple frame sources will have more than one image buffer. The images buffers can have different sizes.
 *
 * A frame contains the pixel data as well as layout of one particular frame. Frames are immutable and reference counted, so they can be shared by multiple consumers. The frame is returned to the pool (recycled) when all consumers release the frame.
 */
NS_SWIFT_NAME(FrameData)
@protocol SDCFrameData <NSObject>

/**
 * Added in version 6.0.0
 *
 * The image buffers contained in this frame data.
 */
@property (nonatomic, nonnull, readonly) NSArray<SDCImageBuffer *> *imageBuffers;

@end
