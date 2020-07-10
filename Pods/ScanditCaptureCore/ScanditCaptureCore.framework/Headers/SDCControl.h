/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 * Added in version 6.0.0
 *
 * Protocol for custom controls on top of the data capture view. Controls are restricted to the set of controls provided by the Scandit Data Capture SDK, it is not possible for customers to conform to this protocol and provide custom control implementations. This protocol does not expose any methods or properties, it just serves as a tag for different controls.
 */
NS_SWIFT_NAME(Control)
@protocol SDCControl <NSObject>

@end
