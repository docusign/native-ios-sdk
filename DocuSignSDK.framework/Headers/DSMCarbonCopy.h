#import "DSMRecipient.h"
/*!
 @class DSMCarbonCopy
 */
@interface DSMCarbonCopy : DSMRecipient

/*! @brief Specifies the documents that are not visible to this recipient. Document Visibility must be enabled for the account and the `enforceSignerVisibility` property must be set to **true** for the envelope to use this.\n\nWhen enforce signer visibility is enabled, documents with tabs can only be viewed by signers that have a tab on that document. Recipients that have an administrative role (Agent, Editor, or Intermediaries) or informational role (Certified Deliveries or Carbon Copies) can always see all the documents in an envelope, unless they are specifically excluded using this setting when an envelope is sent. Documents that do not have tabs are always visible to all recipients, unless they are specifically excluded using this setting when an envelope is sent. [optional].
 */
@property(nonatomic, copy) NSArray<NSString *> *excludedDocuments;
/*!  @brief Name of the recipient.
 */
@property(nonatomic, copy) NSString *name;
/*! @brief Email id of the recipient. Notification of the document to sign is sent to this email id. \n\nMaximum length: 100 characters. [optional]
 */
@property(nonatomic, copy) NSString *email;
/*! @brief TODO:Doc.
 */
@property(nonatomic, copy) NSString *emailRecipientPostSigningURL;

@end
