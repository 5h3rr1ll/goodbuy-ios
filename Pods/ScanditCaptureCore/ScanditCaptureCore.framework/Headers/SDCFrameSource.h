/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>

#import "SDCFrameData.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.0.0
 *
 * The different states a frame source can be in.
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCFrameSourceState) {
/**
     * Added in version 6.0.0
     *
     * The frame source is off and not producing frames.
     */
    SDCFrameSourceStateOff,
/**
     * Added in version 6.0.0
     *
     * The frame source is on and producing frames.
     */
    SDCFrameSourceStateOn,
/**
     * Added in version 6.0.0
     *
     * The frame source is currently starting (moving from SDCFrameSourceStateOff to state SDCFrameSourceStateOn). This value cannot be set directly but is returned by SDCFrameSource.currentState to indicate that the frame source is currently starting.
     */
    SDCFrameSourceStateStarting,
/**
     * Added in version 6.0.0
     *
     * The frame source is currently stopping (moving from SDCFrameSourceStateOn to state SDCFrameSourceStateOff). This value cannot be set directly but is returned by SDCFrameSource.currentState to indicate that the frame source is currently stopping.
     */
    SDCFrameSourceStateStopping
} NS_SWIFT_NAME(FrameSourceState);

/**
 * Added in version 6.1.0
 */
SDC_EXTERN NSString *_Nonnull NSStringFromFrameSourceState(SDCFrameSourceState state) NS_SWIFT_NAME(getter:SDCFrameSourceState.jsonString(self:));
/**
 * Added in version 6.1.0
 */
SDC_EXTERN BOOL SDCFrameSourceStateFromJSONString(NSString *_Nonnull JSONString, SDCFrameSourceState *_Nonnull frameSourceState);

@protocol SDCFrameSource;

/**
 * Added in version 6.0.0
 */
NS_SWIFT_NAME(FrameSourceListener)
@protocol SDCFrameSourceListener <NSObject>

@required

/**
 * Added in version 6.0.0
 */
- (void)frameSource:(id<SDCFrameSource>)source didChangeState:(SDCFrameSourceState)newState;

/**
 * Added in version 6.0.0
 *
 * Event that is emitted whenever a new frame is available. Consumers of this frame source can listen to this event to receive the frames produced by the frame source. The frames are reference counted, if the consumers require access to the frames past the lifetime of the callback, they need to increment the reference count of the frame by one and release it once they are done processing it.
 */
- (void)frameSource:(id<SDCFrameSource>)source didOutputFrame:(id<SDCFrameData>)frame;

@optional

/**
 * Added in version 6.0.0
 */
- (void)didStartObservingFrameSource:(id<SDCFrameSource>)source;

/**
 * Added in version 6.0.0
 */
- (void)didStopObservingFrameSource:(id<SDCFrameSource>)source;

@end

/**
 * Added in version 6.0.0
 *
 * Protocol for producers of frames. Typically this protocol is used through SDCCamera which gives access to the built-in camera on iOS. For more sophisticated use cases this protocol can be implemented by programmers to support other sources of frames, such as external cameras with proprietary APIs.
 *
 * @remark The SDCFrameSource protocol is currently restricted to frame sources included in the Scandit Data Capture SDK and cannot be used to implement custom frame sources.
 */
NS_SWIFT_NAME(FrameSource)
@protocol SDCFrameSource <NSObject>

/**
 * Added in version 6.0.0
 *
 * Sets the desired state of the frame source
 *
 * Possible values are SDCFrameSourceStateOn/SDCFrameSourceStateOff. The frame source’s state needs to be switched to SDCFrameSourceStateOn for it to produce frames.
 *
 * It is not allowed to set the desired state to SDCFrameSourceStateStarting/SDCFrameSourceStateStopping. These values are only used to report ongoing state transitions.
 *
 * In case the desired state is equal to the current state, calling this method has no effect. Otherwise, a call to this method initiates a state transition from the current state to the desired state.
 *
 * The state transition is asynchronous, meaning that it may not complete immediately for certain frame source implementations. When a state transition is ongoing, further changes to the desired state are delayed until the state transition completes. Only the last of the desired states will be processed; previous requested state transitions will be cancelled.
 *
 * The completion handler is invoked when the state transition finishes. YES is passed to the completion handler in case the state transition is successful, NO if it either was cancelled or the state transition failed.
 */
- (void)switchToDesiredState:(SDCFrameSourceState)state
           completionHandler:(nullable void (^)(BOOL))completionHandler;

/**
 * Added in version 6.0.0
 *
 * Readonly attribute for accessing the desired state. Possible states are SDCFrameSourceStateOn, SDCFrameSourceStateOff.
 */
@property (nonatomic, readonly) SDCFrameSourceState desiredState;
/**
 * Added in version 6.0.0
 *
 * Readonly attribute for accessing the current state. Possible states are SDCFrameSourceStateOn, SDCFrameSourceStateOff, SDCFrameSourceStateStarting, SDCFrameSourceStateStopping.
 *
 * The current state cannot be changed directly, but is modified by switchToDesiredState:completionHandler:.
 */
@property (nonatomic, readonly) SDCFrameSourceState currentState;

/**
 * Added in version 6.0.0
 *
 * Adds the listener to this frame source.
 *
 * In case the same listener is already observing this instance, calling this method will not add the listener again. The listener is stored using a weak reference and must thus be retained by the caller for it to not go out of scope.
 */
- (void)addListener:(nonnull id<SDCFrameSourceListener>)listener NS_SWIFT_NAME(addListener(_:));
/**
 * Added in version 6.0.0
 *
 * Removes a previously added listener from this frame source.
 *
 * In case the listener is not currently observing this instance, calling this method has no effect.
 */
- (void)removeListener:(nonnull id<SDCFrameSourceListener>)listener
    NS_SWIFT_NAME(removeListener(_:));

@end

NS_ASSUME_NONNULL_END
