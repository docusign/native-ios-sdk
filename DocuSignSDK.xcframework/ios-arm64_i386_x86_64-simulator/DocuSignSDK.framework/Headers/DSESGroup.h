#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSESObject.h>

/**
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen
 * Do not edit the class manually.
 */

#import <DocuSignSDK/DSESErrorDetails.h>
#import <DocuSignSDK/DSESUserInfo.h>


@protocol DSESGroup
@end

@interface DSESGroup : DSESObject

/* The DocuSign group ID for the group. [optional]
 */
@property(nonatomic) NSString* groupId;
/* The name of the group. [optional]
 */
@property(nonatomic) NSString* groupName;
/* The ID of the permission profile associated with the group. [optional]
 */
@property(nonatomic) NSString* permissionProfileId;
/* The group type. [optional]
 */
@property(nonatomic) NSString* groupType;
/*  [optional]
 */
@property(nonatomic) NSArray<DSESUserInfo>* users;

@property(nonatomic) DSESErrorDetails* errorDetails;

@end