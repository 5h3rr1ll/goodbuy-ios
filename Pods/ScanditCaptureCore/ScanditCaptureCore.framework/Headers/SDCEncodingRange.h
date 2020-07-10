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
 * Defines the encoding of a range of bytes.
 */
NS_SWIFT_NAME(EncodingRange)
SDC_EXPORTED_SYMBOL
@interface SDCEncodingRange : NSObject

/**
 * Added in version 6.0.0
 *
 * Charset encoding name as defined by IANA.
 */
@property (nonatomic, nonnull, readonly) NSString *ianaName;
/**
 * Added in version 6.0.0
 *
 * Start index of this encoding range.
 */
@property (nonatomic, readonly) NSUInteger startIndex;
/**
 * Added in version 6.0.0
 *
 * End index (first index after the last) of this encoding range.
 */
@property (nonatomic, readonly) NSUInteger endIndex;

/**
 * Added in version 6.1.0
 */
@property (nonatomic, nonnull, readonly) NSString *JSONString;

@end

NS_ASSUME_NONNULL_END
