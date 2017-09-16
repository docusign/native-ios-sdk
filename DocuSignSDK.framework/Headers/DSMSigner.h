#import "DSMRecipient.h"

@class DSMTabs;
@class DSMRecipientSignatureInformation;
/*!
 @class DSMSigner
 */
@interface DSMSigner : DSMRecipient

/*!
 * @brief The DSMRecipientSignatureInformation class object.
 * @see DSMRecipientSignatureInformation.h
 */
@property(nonatomic, retain) DSMRecipientSignatureInformation *signatureInfo;
/*!
* @brief TODO:Doc
*/
@property(nonatomic, assign) BOOL defaultRecipient;
/*!
 * @brief The DSMTabs class object.
 * @see DSMTabs.h
 */
@property(nonatomic, retain) DSMTabs *tabs;
/*!
* @brief When set to **true**, specifies that the signer must sign in all locations. [optional]
*/
@property(nonatomic, assign) BOOL signInEachLocation;
/*!
 * @brief Sets the type of signer certificate required for signing. If left blank, no certificate is required. Only one type of certificate can be set for a signer. The possible values are:\n\n* docusign_express – Requires a DocuSign Express certificate.\n* safe – Requires a SAFE-BioPharma certificate.\n* open_trust – Requires an OpenTrust certificate. \n\n**Important**: There are certain rules and restrictions that must be followed when requiring OpenTrust digital signatures. See [ML:OpenTrust Rules and Restrictions] for more information. [optional]
 */
@property(nonatomic, copy) NSString *requireSignerCertificate;
/*!
 * @brief When set to **true**, the signer must print, sign, and upload or fax the signed documents to DocuSign. [optional]
 */
@property(nonatomic, assign) BOOL requireSignOnPaper;
/*!
 * @brief When set to **true**, specifies that the signer can perform the signing ceremony offline. [optional]
 */
@property(nonatomic, assign) BOOL canSignOffline;
/*!
 * @brief When set to **true**, this signer is a bulk recipient and the recipient information is contained in a bulk recipient file. \n\nNote that when this is true the email and name for the recipient becomes bulk@recipient.com and \"Bulk Recipient\". These fields can not be changed for the bulk recipient. [optional]
 */
@property(nonatomic, assign) BOOL isBulkRecipient;
/*!
 * @brief Contains a URI for an endpoint that allows you to easily retrieve bulk recipient information. [optional]
 */
@property(nonatomic, copy) NSString *bulkRecipientsUri;
/*!
 * @brief TODO:Doc
 */
@property(nonatomic, copy) NSString *recipientSuppliesTabs;
/*!
 * @brief Specifies the documents that are not visible to this recipient. Document Visibility must be enabled for the account and the `enforceSignerVisibility` property must be set to **true** for the envelope to use this.\n\nWhen enforce signer visibility is enabled, documents with tabs can only be viewed by signers that have a tab on that document. Recipients that have an administrative role (Agent, Editor, or Intermediaries) or informational role (Certified Deliveries or Carbon Copies) can always see all the documents in an envelope, unless they are specifically excluded using this setting when an envelope is sent. Documents that do not have tabs are always visible to all recipients, unless they are specifically excluded using this setting when an envelope is sent. [optional]
 */
@property(nonatomic, copy) NSArray<NSString *> *excludedDocuments;
/*!
 * @brief Name of the recipient.
 */
@property(nonatomic, copy) NSString *name;
/*!
 * @brief Email id of the recipient. Notification of the document to sign is sent to this email id. \n\nMaximum length: 100 characters. [optional] 
 */
@property(nonatomic, copy) NSString *email;
/*!
 * @brief TODO:Doc
 */
@property(nonatomic, copy) NSString *emailRecipientPostSigningURL;

@end
