/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 * Added in version 6.0.0
 *
 * Protocol for viewfinders. Viewfinders are restricted to the set of viewfinders provided by the Scandit Data Capture SDK, it is not possible for customers to conform to this protocol and provide custom viewfinder implementations. This protocol does not expose any methods or properties, it just serves as a tag for different viewfinder styles.
 */
NS_SWIFT_NAME(Viewfinder)
@protocol SDCViewfinder <NSObject>
@end
