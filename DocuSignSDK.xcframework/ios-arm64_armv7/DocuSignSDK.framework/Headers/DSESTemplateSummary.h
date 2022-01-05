#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSESObject.h>

/**
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen
 * Do not edit the class manually.
 */

#import <DocuSignSDK/DSESTemplateMatch.h>


@protocol DSESTemplateSummary
@end

@interface DSESTemplateSummary : DSESObject

/* The unique identifier of the template. If this is not provided, DocuSign will generate a value. [optional]
 */
@property(nonatomic) NSString* templateId;
/*  [optional]
 */
@property(nonatomic) NSString* name;
/* Specifies the document ID number that the tab is placed on. This must refer to an existing Document's ID attribute. [optional]
 */
@property(nonatomic) NSString* documentId;
/*  [optional]
 */
@property(nonatomic) NSString* documentName;
/* Reserved: TBD [optional]
 */
@property(nonatomic) NSString* applied;

@property(nonatomic) DSESTemplateMatch* templateMatch;
/*  [optional]
 */
@property(nonatomic) NSString* uri;

@end