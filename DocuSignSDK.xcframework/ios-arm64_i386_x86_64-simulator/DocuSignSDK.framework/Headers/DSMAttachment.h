#import <Foundation/Foundation.h>

/*!
 @class DSMAttachment
 */
@interface DSMAttachment : NSObject
/*!  @brief TODO:Doc
 */
@property (nonatomic, copy) NSString *label;
/*!  @brief Specifies the type of the attachment for the recipient. [optional]
 */
@property (nonatomic, copy) NSString *attachmentType;

@end

