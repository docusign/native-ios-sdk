#import <Foundation/Foundation.h>

@interface NSString (DSMAdditions)

+ (NSString *)dsm_base64StringFromData:(NSData *)data length:(NSInteger)length;
- (NSString *)dsm_truncateAndEllipseStringToLength:(NSInteger)length;
- (NSString *)dsm_stringByReplacingURLEncoding;
- (BOOL)dsm_isValidUUID;
+ (BOOL)dsm_isEmptyOrNil:(NSString *)input;

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

@end

