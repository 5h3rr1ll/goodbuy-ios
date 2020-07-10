/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.2.0
 *
 * This class contains the DataCapture version getter.
 */
NS_SWIFT_NAME(DataCaptureVersion)
SDC_EXPORTED_SYMBOL
@interface SDCDataCaptureVersion : NSObject

/**
 * Added in version 6.2.0
 *
 * Returns the version of the Scandit Data Capture SDK
 */
@property (class, nonatomic, nonnull, readonly) NSString *version;

@end

NS_ASSUME_NONNULL_END
