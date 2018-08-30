#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class DSMEditor, DSMAgent, DSMInPersonSigner, DSMSigner, DSMCarbonCopy, DSMCertifiedDelivery, DSMIntermediary, DSMRecipient;
/*!
 @class DSMRecipients
 */
@interface DSMRecipients : NSObject
/*!
 * @brief A complex type containing information about the Signer recipient. [optional]
 * @see DSMSigner.h
 */
@property(nonatomic, copy) NSArray<DSMSigner *> *signers;
/*!
 * @brief A complex type defining the management and access rights of a recipient assigned assigned as an agent on the document. [optional]
 * @see DSMAgent.h
 */
@property(nonatomic, copy) NSArray<DSMAgent *> *agents;
/*!
 * @brief A complex type defining the management and access rights of a recipient assigned assigned as an editor on the document. [optional]
 * @see DSMEditor.h
 */
@property(nonatomic, copy) NSArray<DSMEditor *> *editors;
/*!
 * @brief Identifies a recipient that can, but is not required to, add name and email information for recipients at the same or subsequent level in the routing order (until subsequent Agents, Editors or Intermediaries recipient types are added). [optional]
 * @see DSMIntermediary.h
 */
@property(nonatomic, copy) NSArray<DSMIntermediary *> *intermediaries;
/*!
 * @brief A complex type containing information about recipients who should receive a copy of the envelope, but does not need to sign it. [optional]
 * @see DSMCarbonCopy.h
 */
@property(nonatomic, copy) NSArray<DSMCarbonCopy *> *carbonCopies;
/*!
 * @brief  A complex type containing information on a recipient the must receive the completed documents for the envelope to be completed, but the recipient does not need to sign, initial, date, or add information to any of the documents. [optional]
 * @see DSMCertifiedDelivery.h
 */
@property(nonatomic, copy) NSArray<DSMCertifiedDelivery *> *certifiedDeliveries;
/*!
 * @brief Specifies a signer that is in the same physical location as a DocuSign user who will act as a Signing Host for the transaction. The recipient added is the Signing Host and new separate Signer Name field appears after Sign in person is selected. [optional]
 * @see DSMInPersonSigner.h
 */
@property(nonatomic, copy) NSArray<DSMInPersonSigner *> *inPersonSigners;
/*!
 * @brief recipients count
 */
@property(nonatomic, copy) NSNumber *recipientCount;
/*!
 * @brief Current routing order (recipient routing who is current signer)
 */
@property(nonatomic, copy) NSNumber *currentRoutingOrder;
//TODO:Doc move to categories
/*!
 * @discussion Gives list of all recipients.
 * @return NSArray
 */
- (NSArray *)allRecipientArrays;
/*!
 * @discussion Gives list of all recipients.
 * @return NSArray
 */
- (NSArray *)allRecipients;
/*!
 * @discussion Gives list of all recipients. TODO:Doc
 * @return NSArray
 */
- (NSArray *)allSigners;
/*!
* @discussion Gives list of all signers.
* @return NSArray
*/
- (NSArray *)allSignersIncludingNeedsToView;
/*!
 * @discussion Gives list of all inperson signers.
 * @return NSArray
 */
- (NSArray *)allSignersAndInpersonSigners;
/*!
 * @discussion If any of the current signers have declined. TODO:Doc
 * @return BOOL
 */
- (BOOL)anyCurrentRecipientsHaveDeclined;
/*!
 * @discussion Returns true if all the recipients have completed (signing or decliend).
 * @return BOOL
 */
- (BOOL)allRecipientsHaveCompletedOrDeclined;
/*!
 * @discussion Return a recipient with given recipient Id.
 */
- (DSMRecipient *)recipientWithId:(NSString *)recipientId;
/*!
 * @discussion Return a recipient with given recipient RoleName.
 */
- (DSMRecipient *)recipientWithRoleName:(NSString *)recipientRoleName;

/*!
 * @discussion Removes a recipient from corresponding recipients array.
 */
- (void)removeRecipient:(DSMRecipient *)recipient;

#pragma mark - Recipient Switching (Native)
/*!
 * @discussion return a signer created from inPersonSigner object data.
 * @param inPersonSigner in person signer object
 * @param name name of remote signer
 * @param email email of remote signer
 * @see DSMSigner.h DSMInPersonSigner.h
 */
- (void)signerFromInPersonSigner:(DSMInPersonSigner *)inPersonSigner name:(NSString *)name email:(NSString *)email;
/*!
 * @discussion return an inPersonSigner created from signer object data.
 * @param signer signer object
 * @param hostName name of host for in person signer
 * @param hostEmail email of host for in person signer
 * @param signerName name of in person signer
 * @param signerEmail email of in person signer
 * @see DSMSigner.h DSMInPersonSigner.h
 */
- (void)inPersonSignerFromSigner:(DSMSigner *)signer hostName:(NSString *)hostName hostEmail:(NSString *)hostEmail signerName:(NSString *)signerName signerEmail:(NSString *)signerEmail;

@end
