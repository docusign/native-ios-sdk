#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class DSMUserInfo;
@class DSMAttachment;
@class DSMRecipientEmailNotification;
@class DSMSignature;
@class DSMOfflineAttributes;

typedef NS_ENUM(NSUInteger, DSMRecipientType);
/*!
 @class DSMRecipient
 */
@interface DSMRecipient : NSObject
/*!
* @brief recipientType type of the recipient(siner, inpersonsinger,...)
* @see DSMRecipientType.h
*/
@property(nonatomic) DSMRecipientType recipientType;
/*!
 * @brief When set to **true** and the feature is enabled in the sender's account, the signing recipient is required to draw signatures and initials at each signature/initial tab ( instead of adopting a signature/initial style or only drawing a signature/initial once). [optional]
 */
@property(nonatomic, copy) NSString *signingGroupId;
/*!
 * @brief The display name for the signing group. \n\nMaximum Length: 100 characters. [optional]
 */
@property(nonatomic, copy) NSString *signingGroupName;
/*!
 * @brief A complex type that contains information about users in the signing group. [optional]
 * @see DSMUserInfo.h
 */
@property(nonatomic, copy) NSArray<DSMUserInfo *> *signingGroupUsers;
/*!
 * @brief Unique for the recipient. It is used by the tab element to indicate which recipient is to sign the Document. [optional]
 */
@property(nonatomic, copy) NSString *recipientId;
/*!
 * @brief  TODO:Doc
 */
@property(nonatomic, copy) NSString *recipientIdGuid;
/*!
 * @brief If a value is provided, the recipient must enter the value as the access code to view and sign the envelope. \n\nMaximum Length: 50 characters and must conform to account’s access code format setting.\n\nIf blank, but the signer `accessCode` property is set in the envelope, then that value is used.\n\nIf blank and the signer `accessCode` property is not set, then access code is not required. [optional]
 */
@property(nonatomic, copy) NSString *accessCode;
/*!
 * @brief This Optional attribute indicates that the access code will be added to the email sent to the recipient; this nullifies the Security measure of Access Code on the recipient. [optional]
 */
@property(nonatomic, copy) NSString *addAccessCodeToEmail;
/*!
 * @brief When set to **true**, the recipient is required to use the specified ID check method (including Phone and SMS authentication) to validate their identity. [optional] 
 */
@property(nonatomic, assign) BOOL requireIdLookup;
/*!
 * @brief Specifies authentication check by name. The names used here must be the same as the authentication type names used by the account (these name can also be found in the web console sending interface in the Identify list for a recipient,) This overrides any default authentication setting.\n\n*Example*: Your account has ID Check and SMS Authentication available and in the web console Identify list these appear as 'ID Check $' and 'SMS Auth $'. To use ID check in an envelope, the idCheckConfigurationName should be 'ID Check '. If you wanted to use SMS, it would be 'SMS Auth $' and you would need to add you would need to add phone number information to the `smsAuthentication` node. [optional]
 */
@property(nonatomic, copy) NSString *idCheckConfigurationName;
//@property(nonatomic, copy) NSArray<DSESocialAuthentication> *socialAuthentications;
//@property(nonatomic, copy) DSRecipientPhoneAuthentication *phoneAuthentication;
//@property(nonatomic, copy) DSRecipientSAMLAuthentication *samlAuthentication;
//@property(nonatomic, copy) DSRecipientSMSAuthentication *smsAuthentication;
/*!
 * @brief TODO:Doc
 */
@property(nonatomic, copy) NSString *userId;
/*!
 * @brief Specifies whether the recipient is embedded or remote. \n\nIf the `clientUserId` property is not null then the recipient is embedded. Note that if the `ClientUserId` property is set and either `SignerMustHaveAccount` or `SignerMustLoginToSign` property of the account settings is set to  **true**, an error is generated on sending.ng. \n\nMaximum length: 100 characters. [optional]
 */
@property(nonatomic, copy) NSString *clientUserId;
/*!
 * @brief Specifies a sender provided valid URL string for redirecting an embedded recipient. When using this option, the embedded recipient still receives an email from DocuSign, just as a remote recipient would. When the document link in the email is clicked the recipient is redirected, through DocuSign, to the supplied URL to complete their actions. When routing to the URL, the sender’s system (the server responding to the URL) must request a recipient token to launch a signing session. \n\nIf set to `SIGN_AT_DOCUSIGN`, the recipient is directed to an embedded signing or viewing process directly at DocuSign. The signing or viewing action is initiated by the DocuSign system and the transaction activity and Certificate of Completion records will reflect this. In all other ways the process is identical to an embedded signing or viewing operation that is launched by any partner.\n\nIt is important to remember that in a typical embedded workflow the authentication of an embedded recipient is the responsibility of the sending application, DocuSign expects that senders will follow their own process for establishing the recipient’s identity. In this workflow the recipient goes through the sending application before the embedded signing or viewing process in initiated. However, when the sending application sets `EmbeddedRecipientStartURL=SIGN_AT_DOCUSIGN`, the recipient goes directly to the embedded signing or viewing process bypassing the sending application and any authentication steps the sending application would use. In this case, DocuSign recommends that you use one of the normal DocuSign authentication features (Access Code, Phone Authentication, SMS Authentication, etc.) to verify the identity of the recipient.\n\nIf the `clientUserId` property is NOT set, and the `embeddedRecipientStartURL` is set, DocuSign will ignore the redirect URL and launch the standard signing process for the email recipient. Information can be appended to the embedded recipient start URL using merge fields. The available merge fields items are: envelopeId, recipientId, recipientName, recipientEmail, and customFields. The `customFields` property must be set fort the recipient or envelope. The merge fields are enclosed in double brackets. \n\n*Example*: \n\n`http://senderHost/[[mergeField1]]/ beginSigningSession? [[mergeField2]]&[[mergeField3]]` [optional]
 */
@property(nonatomic, copy) NSString *embeddedRecipientStartURL;
/*!
 * @brief An optional array of strings that allows the sender to provide custom data about the recipient. This information is returned in the envelope status but otherwise not used by DocuSign. Each customField string can be a maximum of 100 characters. [optional]
 */
@property(nonatomic, copy) NSArray<NSString *> *customFields;
/*!
 * @brief Specifies the routing order of the recipient in the envelope. [optional]
 */
@property(nonatomic, copy) NSNumber *routingOrder;
//@property(nonatomic, copy) DSIdCheckInformationInput *idCheckInformationInput;
/*!
 * @brief TODO:Doc
 */
@property(nonatomic, copy) NSArray<DSMAttachment *> *recipientAttachments;
/*!
 * @brief Specifies a note that is unique to this recipient. This note is sent to the recipient via the signing email. The note displays in the signing UI near the upper left corner of the document on the signing screen.\n\nMaximum Length: 1000 characters. [optional]
 */
@property(nonatomic, copy) NSString *note;
/*!
 * @brief Optional element. Specifies the role name associated with the recipient.<br/><br/>This is required when working with template recipients. [optional]
 */
@property(nonatomic, copy) NSString *roleName;
/*!
 * @brief Indicates the envelope status. Valid values are:\n\n* sent - The envelope is sent to the recipients. \n* created - The envelope is saved as a draft and can be modified and sent later. [optional]
 */
@property(nonatomic, copy) NSString *status;
/*!
 * @brief Reserved: For DocuSign use only. [optional]
 */
@property(nonatomic, copy) NSDate *signedDateTime;
/*!
 * @brief Reserved: For DocuSign use only. [optional]
 */
@property(nonatomic, copy) NSDate *deliveredDateTime;
/*!
 * @brief The date and time the recipient declined the document. [optional]
 */
@property(nonatomic, copy) NSDate *declinedDateTime;
/*!
 * @brief The date and time the envelope was sent. [optional]
 */
@property(nonatomic, copy) NSDate *sentDateTime;
/*!
 * @brief The reason the recipient declined the document. [optional]
 */
@property(nonatomic, copy) NSString *declinedReason;
/*!
 * @brief Reserved: For DocuSign use only. [optional]
 */
@property(nonatomic, copy) NSString *deliveryMethod;
/*!
 * @brief Reserved: [optional]
 */
@property(nonatomic, copy) NSString *faxNumber;
/*!
 * @brief When set to **true**, the sender cannot change any attributes of the recipient. Used only when working with template recipients. [optional]
 */
@property(nonatomic, assign) BOOL templateLocked;
/*!
 * @brief  When set to **true**, the sender may not remove the recipient. Used only when working with template recipients. [optional]
 */
@property(nonatomic, assign) BOOL templateRequired;
//@property(nonatomic, copy) DSRecipientEmailNotification *emailNotification;
/*!
 * @brief When set to **true** and the envelope recipient creates a DocuSign account after signing, the Manage Account Email Notification settings are used as the default settings for the recipient's account. [optional]
 */
@property(nonatomic, assign) BOOL inheritEmailNotificationConfiguration;
//@property(nonatomic, copy) DSErrorDetails *errorDetails;
//@property(nonatomic, copy) DSAuthenticationStatus *recipientAuthenticationStatus;
/*!
 * @brief Total tab count
 */
@property(nonatomic, copy) NSNumber *totalTabCount;
/*!
 * @brief TODO:Doc
 * @see DSMRecipientEmailNotification.h
 */
@property (nonatomic, retain) DSMRecipientEmailNotification *emailNotification;
/*!
 * @brief TODO:Doc
 * @see DSMOfflineAttributes.h
 */
@property(nonatomic, retain) DSMOfflineAttributes *offlineAttributes;
/*!
 * @brief TODO:Doc
 * @see DSMSignature.h
 */
@property (nonatomic, retain) DSMSignature *signature;
//TODO:Doc Move to categories
/*!
 * @discussion Recipient status sent or delivered.
 * @return BOOL
 */
- (BOOL)isSentOrDelivered;
/*!
 * @discussion Returns true if recipient status is completed or declined or signed.
 * @return BOOL
 */
- (BOOL)hasCompletedOrDeclined;
/*!
 * @discussion Returns true if signer is a digital certificate Signer.
 * @return BOOL
 */
- (BOOL)isDigitalCertificateSigner;
/*!
 * @discussion Returns true if recipient maches with given userID.
 * @return BOOL
 */
- (BOOL)matchesUserWithUserID:(NSString *)userID;

@end

@interface DSMRecipient (NativeSigning)
/*!
 * @discussion Returns Signer name.
 * @return NSString
 */
-(NSString *)dsm_name;

@end
