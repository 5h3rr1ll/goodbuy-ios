/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.0.0
 *
 * A vibration, to be emitted for example when a code has been successfully scanned.
 */
NS_SWIFT_NAME(Vibration)
SDC_EXPORTED_SYMBOL
@interface SDCVibration : NSObject

/**
 * Added in version 6.0.0
 *
 * The default vibration for a successful scan.
 */
@property (class, nonatomic, readonly) SDCVibration *defaultVibration;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
