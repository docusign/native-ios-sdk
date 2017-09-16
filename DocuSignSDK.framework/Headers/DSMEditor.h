#import "DSMRecipient.h"

/*!
 @class DSMEditor
 */
@interface DSMEditor : DSMRecipient

/*! @brief Name of the recipient.
 */
@property(nonatomic, copy) NSString *name;
/*! @brief Email id of the recipient. Notification of the document to sign is sent to this email id. \n\nMaximum length: 100 characters. [optional]
 */
@property(nonatomic, copy) NSString *email;
/*! @brief TODO:Doc
 */
@property(nonatomic, copy) NSString *emailRecipientPostSigningURL;

@end
