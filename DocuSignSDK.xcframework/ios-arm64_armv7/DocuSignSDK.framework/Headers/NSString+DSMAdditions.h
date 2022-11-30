#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (DSMAdditions)

+ (NSString *)dsm_base64StringFromData:(NSData *)data length:(NSInteger)length;
- (NSString *)dsm_truncateAndEllipseStringToLength:(NSInteger)length;
- (NSString *)dsm_stringByReplacingURLEncoding;
- (BOOL)dsm_isValidUUID;
+ (BOOL)dsm_isEmptyOrNil:(NSString *)input;

- (NSString *)withPrefix:(NSString *)prefix;

@end

@interface NSString (DSMUUID)

+ (NSString *)dsm_UUIDString;

@end

@interface NSString (DSMComparison)

- (BOOL)dsm_caseAndDiacriticInsensitivelyMatches:(NSString *)aString;
- (BOOL)dsm_caseInsensitivelyMatches:(NSString *)aString;
- (NSString *)dsm_uniqueStringByAppendingNumberAmongstStrings:(NSArray *)otherStrings;

@end

@interface NSString (DSMTrimming)

- (NSString *)dsm_stringByTrimmingWhitespaceAndNewlines;

@end

@interface NSString (DSMBoolean)

+ (instancetype)dsm_stringWithBool:(BOOL)boolValue;
+ (instancetype)dsm_stringWithErrorCode:(NSInteger)errorCode withErrorReason:(NSString *)errorReason;
@end

@interface NSString (DSMAttributed)

- (NSAttributedString * _Nullable)dsm_attributedStringFromText:(NSString *)fullString
                                              substringsToBold:(NSArray <NSString *> *)substringsToBold;

- (NSArray <NSValue *> * _Nullable)dsm_findRangesOfSubstring:(NSString *)substring
                                      withRegexPatternString:(NSString *)regexPatternString;

- (NSAttributedString * _Nullable)dsm_boldifyStringForRanges:(NSArray <NSValue *> *)rangesToBold
                                                    boldFont:(UIFont *)boldFont;

@end

@interface NSString (DSMSignature)

+ (NSString *)dsm_initialsWithName:(NSString *)name;

@end

NS_ASSUME_NONNULL_END
