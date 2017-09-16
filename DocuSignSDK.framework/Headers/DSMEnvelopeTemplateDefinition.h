#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class DSMUserInfo;
/*!
 @class DSMEnvelopeTemplateDefinition
 */
@interface DSMEnvelopeTemplateDefinition : NSObject
/*!  @brief The unique identifier of the template. If this is not provided, DocuSign will generate a value. [optional]
 */
@property(nonatomic, copy) NSString *templateId;
/*!  @brief error TODO:Doc
 */
@property(nonatomic, copy) NSString *name;
/*!  @brief When set to **true**, this custom tab is shared. [optional]
 */
@property(nonatomic, assign) BOOL shared;
/*!  @brief error TODO:Doc
 */
@property(nonatomic, copy) NSString *password;
/*!  @brief error TODO:Doc
 */
@property(nonatomic, copy) NSString *varNewPassword;
/*!  @brief error TODO:Doc
 */
@property(nonatomic, copy) NSString *templateDescription;
/*!  @brief error TODO:Doc
 */
@property(nonatomic, copy) NSDate *lastModified;
/*!
 * @brief The DSMUserInfo class object.
 * @see DSMUserInfo
 */
@property(nonatomic, retain) DSMUserInfo *lastModifiedBy;
/*!  @brief An integer value specifying the number of document pages in the template. Omit this property if not submitting a page count. [optional]
 */
@property(nonatomic, copy) NSNumber *pageCount;
/*!  @brief error TODO:Doc
 */
@property(nonatomic, copy) NSString *uri;
/*!  @brief The name of the folder in which the template is located. [optional]
 */
@property(nonatomic, copy) NSString *folderName;
/*!  @brief The ID for the folder. [optional]
 */
@property(nonatomic, copy) NSString *folderId;
/*!  @brief The URI of the folder. [optional]
 */
@property(nonatomic, copy) NSString *folderUri;
/*!  @brief error TODO:Doc
 */
@property(nonatomic, copy) NSString *parentFolderUri;
/*!
 * @brief The DSMUserInfo class object.
 * @see DSMUserInfo.h
 */
@property(nonatomic, retain) DSMUserInfo *owner;

@end
