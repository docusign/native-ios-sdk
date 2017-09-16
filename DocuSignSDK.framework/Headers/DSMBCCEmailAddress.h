#import <Foundation/Foundation.h>

/*!
 @class DSMBCCEmailAddress
 */
@interface DSMBCCEmailAddress : NSObject
/*!  @brief Only users with canManageAccount setting can use this option. An array of up to 5 email addresses the envelope is sent to as a BCC email. \n \nExample: If your account has BCC for Email Archive set up for the email address 'archive@mycompany.com' and you send an envelope using the BCC Email Override to send a BCC email to 'salesarchive@mycompany.com', then a copy of the envelope is only sent to the 'salesarchive@mycompany.com' email address. [optional]
 */
@property (nonatomic, copy) NSString *bccEmailAddressId;
/*!  @brief Specifies the BCC email address. DocuSign verifies that the email format is correct, but does not verify that the email is active.Using this overrides the BCC for Email Archive information setting for this envelope.\n\nMaximum of length: 100 characters. [optional]
 */
@property (nonatomic, copy) NSString *email;

@end
