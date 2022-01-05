#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSESObject.h>

/**
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen
 * Do not edit the class manually.
 */



@protocol DSESMergeField
@end

@interface DSESMergeField : DSESObject

/*  [optional]
 */
@property(nonatomic) NSString* configurationType;
/* Sets the object associated with the custom tab. Currently this is the Salesforce Object. [optional]
 */
@property(nonatomic) NSString* path;
/* When wet to true, the information entered in the tab automatically updates the related Salesforce data when an envelope is completed. [optional]
 */
@property(nonatomic) NSString* writeBack;
/* When set to **true**, the sender can modify the value of the custom tab during the sending process. [optional]
 */
@property(nonatomic) NSString* allowSenderToEdit;
/* IOS-13142 Addition by DSM. Swagger has it missing, and it's part of API JSON. [optional]
 */
@property(nonatomic) NSString* row;

@end