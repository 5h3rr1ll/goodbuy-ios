/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

@class SDCVibration;
@class SDCSound;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.0.0
 *
 * A feedback consisting of a sound and vibration, for example to be provided by a device when a code has been successfully scanned.
 */
NS_SWIFT_NAME(Feedback)
SDC_EXPORTED_SYMBOL
@interface SDCFeedback : NSObject

/**
 * Added in version 6.0.0
 *
 * The default feedback consisting of a default sound and a default vibration.
 */
@property (class, nonatomic, readonly) SDCFeedback *defaultFeedback;

/**
 * Added in version 6.0.0
 *
 * Creates a Feedback that emits the given vibration and plays the given sound.
 */
- (instancetype)initWithVibration:(nullable SDCVibration *)vibration
                            sound:(nullable SDCSound *)sound;

/**
 * Added in version 6.0.0
 *
 * The vibration to be emitted when a feedback is required. If nil, no vibration is emitted. This property is further influenced by the device’s ring mode: the device may not vibrate even if this property is properly set to a non-nil instance.
 */
@property (nonatomic, nullable, readonly) SDCVibration *vibration;
/**
 * Added in version 6.0.0
 *
 * The sound to be played when a feedback is required. If nil, no sound is played. Depending on the device’s ring mode and/or volume settings, no sound may be played even if this property is properly set to a non-nil instance.
 */
@property (nonatomic, nullable, readonly) SDCSound *sound;

/**
 * Added in version 6.0.0
 *
 * Emits the feedback defined by this object. This method is further influenced by the device’s ring mode and/or volume settings - check sound and vibration for more details.
 */
- (void)emit;

@end

NS_ASSUME_NONNULL_END
