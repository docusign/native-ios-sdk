#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSESObject.h>

/**
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen
 * Do not edit the class manually.
 */



@protocol DSESAttachment
@end

@interface DSESAttachment : DSESObject

/*  [optional]
 */
@property(nonatomic) NSString* label;
/* Specifies the type of the attachment for the recipient. [optional]
 */
@property(nonatomic) NSString* attachmentType;

@end