#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSESObject.h>

/**
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen
 * Do not edit the class manually.
 */



@protocol DSESTemplateMatch
@end

@interface DSESTemplateMatch : DSESObject

/*  [optional]
 */
@property(nonatomic) NSString* matchPercentage;
/*  [optional]
 */
@property(nonatomic) NSString* documentStartPage;
/*  [optional]
 */
@property(nonatomic) NSString* documentEndPage;

@end