#import <Foundation/Foundation.h>

@interface DSMFolder : NSObject

/*!
 * @brief TODO
 */
@property(nonatomic, copy) NSString *ownerUserName;
/*!
 * @brief TODO
 */
@property(nonatomic, copy) NSString *ownerEmail;
/*!
 * @brief TODO
 */
@property(nonatomic, copy) NSString *ownerUserId;
/*!
 * @brief TODO
 */
@property(nonatomic, copy) NSString *type;
/*!
 * @brief TODO
 */
@property(nonatomic, copy) NSString *name;
/*!
 * @brief TODO
 */
@property(nonatomic, copy) NSString *uri;
/*!
 * @brief TODO
 */
@property(nonatomic, copy) NSString *parentFolderId;
/*!
 * @brief TODO
 */
@property(nonatomic, copy) NSString *parentFolderUri;
/*!
 * @brief TODO
 */
@property(nonatomic, copy) NSString *folderId;
/*!
 * @brief A collection of folder objects returned in a response. [optional]
 */
@property(nonatomic, copy) NSArray<DSMFolder *> *folders;

@end
