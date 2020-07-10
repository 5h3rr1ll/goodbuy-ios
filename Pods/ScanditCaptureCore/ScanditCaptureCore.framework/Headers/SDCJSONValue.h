/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCMeasureUnit.h>

@class SDCBrush;
@class SDCSizeWithUnitAndAspect;

NS_ASSUME_NONNULL_BEGIN

/**
 * Added in version 6.0.0
 *
 * JSON representation for use with the Scandit Data Capture SDK. It provides a lot of convenience functions for deserialization of base classes. It also tracks the usage of properties to be able to later report those that were not used for deserialization (potentially because they were misspelled or are outdated).
 */
NS_SWIFT_NAME(JSONValue)
SDC_EXPORTED_SYMBOL
@interface SDCJSONValue : NSObject

/**
 * Added in version 6.1.0
 *
 * Whether this JSON value was used during deserialization.
 */
@property (nonatomic, assign, getter=isUsed) BOOL used;
/**
 * Added in version 6.1.0
 *
 * The path from the root to this JSON value.
 */
@property (nonatomic, strong, readonly) NSString *absolutePath;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Added in version 6.1.0
 *
 * Returns a new JSON Value for the given json string. An exception is thrown if the string is not a valid JSON representation.
 */
+ (instancetype)JSONValueWithString:(nonnull NSString *)string;

/**
 * Added in version 6.1.0
 *
 * Returns the string representation of the JSON value.
 */
- (nonnull NSString *)jsonString;

/**
 * Added in version 6.1.0
 *
 * Returns the value as a boolean. An exception is thrown if the conversion is not possible.
 */
- (BOOL)asBOOL;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given key as a boolean. An exception is thrown if this JSON Value is not an object, it does not contain a value for the given key or the value for the given key is not a boolean.
 */
- (BOOL)BOOLForKey:(nonnull NSString *)key;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given key as a boolean. The default value is returned if there is no value for the given key. An exception is thrown if this JSON Value is not an object or the value for the given key is not a boolean.
 */
- (BOOL)BOOLForKey:(nonnull NSString *)key default:(BOOL)defaultValue;

/**
 * Added in version 6.1.0
 *
 * Returns the value as an integer. An exception is thrown if the conversion is not possible.
 */
- (NSInteger)asInteger;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given key as an integer. An exception is thrown if this JSON Value is not an object, it does not contain a value for the given key or the value for the given key is not an integer.
 */
- (NSInteger)integerForKey:(nonnull NSString *)key;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given key as an integer. The default value is returned if there is no value for the given key. An exception is thrown if this JSON Value is not an object or the value for the given key is not an integer.
 */
- (NSInteger)integerForKey:(nonnull NSString *)key default:(NSInteger)defaultValue;

/**
 * Added in version 6.1.0
 *
 * Returns the value as a float. An exception is thrown if the conversion is not possible.
 */
- (CGFloat)asCGFloat;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given key as a float. An exception is thrown if this JSON Value is not an object, it does not contain a value for the given key or the value for the given key is not a float.
 */
- (CGFloat)CGFloatForKey:(nonnull NSString *)key;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given key as a float. The default value is returned if there is no value for the given key. An exception is thrown if this JSON Value is not an object or the value for the given key is not a float.
 */
- (CGFloat)CGFloatForKey:(nonnull NSString *)key default:(CGFloat)defaultValue;

/**
 * Added in version 6.1.0
 *
 * Returns the value as a string. An exception is thrown if the conversion is not possible.
 */
- (nonnull NSString *)asString;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given key as a string. An exception is thrown if this JSON Value is not an object, it does not contain a value for the given key or the value for the given key is not a string.
 */
- (nonnull NSString *)stringForKey:(nonnull NSString *)key;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given key as a string. The default value is returned if there is no value for the given key. An exception is thrown if this JSON Value is not an object or the value for the given key is not a string.
 */
- (nonnull NSString *)stringForKey:(nonnull NSString *)key default:(nonnull NSString *)defaultValue;

/**
 * Added in version 6.1.0
 *
 * Returns the value as a color. An exception is thrown if the conversion is not possible.
 */
- (nonnull UIColor *)asColor;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given key as a color. An exception is thrown if this JSON Value is not an object, it does not contain a value for the given key or the value for the given key is not a color.
 */
- (nonnull UIColor *)colorForKey:(nonnull NSString *)key;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given key as a color. The default value is returned if there is no value for the given key. An exception is thrown if this JSON Value is not an object or the value for the given key is not a color.
 */
- (nonnull UIColor *)colorForKey:(nonnull NSString *)key default:(nonnull UIColor *)defaultValue;

/**
 * Added in version 6.1.0
 *
 * Returns the value as a SDCBrush. An exception is thrown if the conversion is not possible.
 */
- (nonnull SDCBrush *)asBrush;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given key as a SDCBrush. An exception is thrown if this JSON Value is not an object, it does not contain a value for the given key or the value for the given key is not a SDCBrush.
 */
- (nonnull SDCBrush *)brushForKey:(nonnull NSString *)key;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given key as a SDCBrush. The default value is returned if there is no value for the given key. An exception is thrown if this JSON Value is not an object or the value for the given key is not a SDCBrush.
 */
- (nullable SDCBrush *)brushForKey:(nonnull NSString *)key
                           default:(nullable SDCBrush *)defaultValue;

/**
 * Added in version 6.1.0
 *
 * Returns the value as a SDCFloatWithUnit. An exception is thrown if the conversion is not possible.
 */
- (SDCFloatWithUnit)asFloatWithUnit;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given key as a SDCFloatWithUnit. An exception is thrown if this JSON Value is not an object, it does not contain a value for the given key or the value for the given key is not a SDCFloatWithUnit.
 */
- (SDCFloatWithUnit)floatWithUnitForKey:(nonnull NSString *)key;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given key as a SDCFloatWithUnit. The default value is returned if there is no value for the given key. An exception is thrown if this JSON Value is not an object or the value for the given key is not a SDCFloatWithUnit.
 */
- (SDCFloatWithUnit)floatWithUnitForKey:(nonnull NSString *)key
                                default:(SDCFloatWithUnit)defaultValue;

/**
 * Added in version 6.1.0
 *
 * Returns the value as a SDCPointWithUnit. An exception is thrown if the conversion is not possible.
 */
- (SDCPointWithUnit)asPointWithUnit;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given key as a SDCPointWithUnit. An exception is thrown if this JSON Value is not an object, it does not contain a value for the given key or the value for the given key is not a SDCPointWithUnit.
 */
- (SDCPointWithUnit)pointWithUnitForKey:(nonnull NSString *)key;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given key as a SDCPointWithUnit. The default value is returned if there is no value for the given key. An exception is thrown if this JSON Value is not an object or the value for the given key is not a SDCPointWithUnit.
 */
- (SDCPointWithUnit)pointWithUnitForKey:(nonnull NSString *)key
                                default:(SDCPointWithUnit)defaultValue;

/**
 * Added in version 6.1.0
 *
 * Returns the value as a SDCMarginsWithUnit. An exception is thrown if the conversion is not possible.
 */
- (SDCMarginsWithUnit)asMarginsWithUnit;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given key as a SDCMarginsWithUnit. An exception is thrown if this JSON Value is not an object, it does not contain a value for the given key or the value for the given key is not a SDCMarginsWithUnit.
 */
- (SDCMarginsWithUnit)marginsWithUnitForKey:(nonnull NSString *)key;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given key as a SDCMarginsWithUnit. The default value is returned if there is no value for the given key. An exception is thrown if this JSON Value is not an object or the value for the given key is not a SDCMarginsWithUnit.
 */
- (SDCMarginsWithUnit)marginsWithUnitForKey:(nonnull NSString *)key
                                    default:(SDCMarginsWithUnit)defaultValue;

/**
 * Added in version 6.1.0
 *
 * Returns the value if it is an array. An exception is thrown if the conversion is not possible.
 */
- (nonnull SDCJSONValue *)asArray;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given key as an array. An exception is thrown if this JSON Value is not an object, it does not contain a value for the given key or the value for the given key is not an array.
 */
- (nonnull SDCJSONValue *)arrayForKey:(nonnull NSString *)key;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given key as an array. The default value is returned if there is no value for the given key. An exception is thrown if this JSON Value is not an object or the value for the given key is not an array.
 */
- (nullable SDCJSONValue *)arrayForKey:(nonnull NSString *)key
                               default:(nullable SDCJSONValue *)defaultValue;
/**
 * Added in version 6.1.0
 *
 * The size of the array. An exception is thrown if this JSON value is not an array.
 */
- (NSUInteger)count;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given index. An exception is thrown if this JSON Value is not an array or the given index is out of bounds.
 */
- (nonnull SDCJSONValue *)JSONValueAtIndex:(NSUInteger)index;

/**
 * Added in version 6.1.0
 *
 * Returns the value if it is an object. An exception is thrown if the conversion is not possible.
 */
- (nonnull SDCJSONValue *)asObject;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given key as an object. An exception is thrown if this JSON Value is not an object, it does not contain a value for the given key or the value for the given key is not an object.
 */
- (nonnull SDCJSONValue *)objectForKey:(nonnull NSString *)key;
/**
 * Added in version 6.1.0
 *
 * Returns the value for the given key as an object. The default value is returned if there is no value for the given key. An exception is thrown if this JSON Value is not an object or the value for the given key is not an object.
 */
- (nullable SDCJSONValue *)objectForKey:(nonnull NSString *)key
                                default:(nullable SDCJSONValue *)defaultValue;
/**
 * Added in version 6.1.0
 *
 * Returns whether a value for the given key exists. An exception is thrown if this JSON Value is not an object.
 *
 * Added in version 6.1.0
 *
 * Returns the value for the given key. An exception is thrown if this JSON Value is not an object or it does not contain a value for the given key.
 */
- (BOOL)containsKey:(nonnull NSString *)key;

@end

NS_ASSUME_NONNULL_END
