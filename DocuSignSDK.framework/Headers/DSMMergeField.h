#import <Foundation/Foundation.h>

/*!
 @class DSMMergeField
 */
@interface DSMMergeField : NSObject
/*!
 * @brief TODO:Doc
 */
@property (nonatomic, copy) NSString *configurationType;
/*!
 * @brief Sets the object associated with the custom tab. Currently this is the Salesforce Object. [optional]
 */
@property (nonatomic, copy) NSString *path;
/*!
 * @brief When wet to true, the information entered in the tab automatically updates the related Salesforce data when an envelope is completed. [optional]
 */
@property (nonatomic, copy) NSNumber *row;
/*!
 * @brief When set to **true**, the sender can modify the value of the custom tab during the sending process. [optional]
 */
@property (nonatomic, assign) BOOL writeBack;
/*!
 * @brief TODO:Doc
 */
@property (nonatomic, assign) BOOL allowSenderToEdit;

@end
