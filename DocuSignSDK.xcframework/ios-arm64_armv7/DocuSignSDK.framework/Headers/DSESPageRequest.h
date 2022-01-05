#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSESObject.h>

/**
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen
 * Do not edit the class manually.
 */



@protocol DSESPageRequest
@end

@interface DSESPageRequest : DSESObject

/* Sets the direction the page image is rotated. The possible settings are: left or right [optional]
 */
@property(nonatomic) NSString* rotate;
/*  [optional]
 */
@property(nonatomic) NSString* password;

@end