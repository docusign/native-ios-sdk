#import <Foundation/Foundation.h>

@class DSMRecipient;
/*!
 @class DSMRecipientSignatureInformation
 */

@interface DSMRecipientSignatureInformation : NSObject
/*! 
 * @brief Specifies the user signature name. [optional]
 */
@property (nonatomic, copy) NSString *signatureName;
/*!
 * @brief signatureInitial should have a minimum 1 character and maximum 10 characters
 */
@property (nonatomic, copy) NSString *signatureInitials;
/*!
 * @brief Font styles supported for recipient signature are RageItalic, Mistral, BradleyHandITC, KaufmannBT, Freehand575 and LuciaBT
 */
@property (nonatomic, copy) NSString *fontStyle;

@end
