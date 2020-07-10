/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 * Added in version 6.0.0
 *
 * Enumeration for different directions.
 */
typedef NS_CLOSED_ENUM(NSUInteger, SDCDirection) {
/**
     * Added in version 6.0.0
     *
     * Direction left to right.
     */
    SDCDirectionLeftToRight,
/**
     * Added in version 6.0.0
     *
     * Direction right to left.
     */
    SDCDirectionRightToLeft,
/**
     * Added in version 6.0.0
     *
     * Direction horizontal.
     */
    SDCDirectionHorizontal,
/**
     * Added in version 6.0.0
     *
     * Direction top to bottom.
     */
    SDCDirectionTopToBottom,
/**
     * Added in version 6.0.0
     *
     * Direction bottom to top.
     */
    SDCDirectionBottomToTop,
/**
     * Added in version 6.0.0
     *
     * Direction vertical.
     */
    SDCDirectionVertical,
/**
     * Added in version 6.0.0
     *
     * No direction.
     */
    SDCDirectionNone
} NS_SWIFT_NAME(Direction);

