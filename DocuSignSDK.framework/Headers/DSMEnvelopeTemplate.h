#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "DSMEnvelopeHelperProtocol.h"

@class DSMDocument;
@class DSMEnvelopeTemplateDefinition;
@class DSMRecipients;
@class DSMNotification;
@class DSMCustomFields;
@class DSMEmailSettings;

/*!
 @class DSMEnvelopeTemplate
 */
@interface DSMEnvelopeTemplate : NSObject <DSMEnvelopeHelperProtocol>

/* When set to DSMDisclosureSettingShownToRecipients, the disclosure is shown to
 recipients in accordance with the account’s Electronic Record and Signature Disclosure 
 frequency setting. When set to DSMDisclosureSettingNotShownToRecipients, the Electronic 
 Record and Signature Disclosure is not shown to any envelope recipients. 
 If the `disclosureSetting` property is set to DSMDisclosureSettingUseAccountDisclosureSetting (default),
 then the account's normal disclosure setting is used and the value of the `disclosureSetting` property 
 is not returned in responses when getting envelope information.
 */
typedef enum {
    DSMDisclosureSettingUseAccountDisclosureSetting, // default
    DSMDisclosureSettingShownToRecipients,
    DSMDisclosureSettingNotShownToRecipients,
} DSMDisclosureSetting;
/*!
 * @brief The DSMEnvelopeTemplateDefinition class object.
 * @see DSMEnvelopeTemplateDefinition.h
 */
@property (nonatomic, retain) DSMEnvelopeTemplateDefinition *envelopeTemplateDefinition;
/*!
 * @brief The DSMDocument class object, details on the documents in the template.
 * @see DSMDocument.h
 */
@property (nonatomic, copy) NSArray<DSMDocument *> *documents;
/*!
 * @brief The DSMDocument class object, combined pdf of all documents in template.
 * @see DSMDocument.h
 */
@property (nonatomic, retain) DSMDocument *combinedDocument;
/*!
 * @brief The DSMRecipients class object, list of recipients on template.
 * @see DSMRecipients.h
 */
@property (nonatomic, retain) DSMRecipients *recipients;
/*!
 * @brief The DSMRecipients class object, list of recipients on template.
 * @see DSMRecipients.h
 */
@property (nonatomic, retain) DSMNotification *notification;
@property (nonatomic, retain) DSMCustomFields *customFields;
@property (nonatomic, retain) DSMEmailSettings *emailSettings;
/*!
 * @brief Used to identify an envelope. The id is a sender-generated value and is valid in the DocuSign system for 7 days. It is recommended that a transaction ID is used for offline signing to ensure that an envelope is not sent multiple times. The `transactionId` property can be used determine if an envelope status (i.e. was created or not) for cases where an internet connection was lost before the envelope status could be returned. [optional]
 */
@property (nonatomic, copy) NSString *transactionId;
/*!
 * @brief Indicates the envelope status. Valid values are:\n\n* sent - The envelope is sent to the recipients. \n* created - The envelope is saved as a draft and can be modified and sent later. [optional]
 */
@property (nonatomic, copy) NSString *status;
/*!
 * @brief  Contains a URI for an endpoint that you can use to retrieve the documents. [optional]
 */
@property (nonatomic, copy) NSString *documentsUri;
/*!
 * @brief Contains a URI for an endpoint that you can use to retrieve the recipients. [optional]
 */
@property (nonatomic, copy) NSString *recipientsUri;
/*!
 * @brief When set to **true**, the envelope is queued for processing and the value of the `status` property is set to 'Processing'. Additionally, get status calls return 'Processing' until completed. [optional]
 */
@property (nonatomic, assign) BOOL asynchronous;
/*!
 * @brief Contains a URI for an endpoint that you can use to retrieve the envelope or envelopes. [optional]
 */
@property (nonatomic, copy) NSString *envelopeUri;
/*!
 * @brief Specifies the subject of the email that is sent to all recipients.\n\nSee [ML:Template Email Subject Merge Fields] for information about adding merge field information to the email subject. [optional]
 */
@property (nonatomic, copy) NSString *emailSubject;
/*!
 * @brief TODO:Doc
 */
@property (nonatomic, copy) NSString *emailBlurb;
/*!
 * @brief The envelope ID of the envelope.
 */
@property (nonatomic, copy) NSString *envelopeId;
/*!
 * @brief Specifies the physical location where the signing takes place. It can have two enumeration values; InPerson and Online. The default value is Online. [optional]
 */
@property (nonatomic, copy) NSString *signingLocation;
/*!
 * @brief Contains a URI for an endpoint that you can use to retrieve the custom fields. [optional]
 */
@property (nonatomic, copy) NSString *customFieldsUri;
/*!
 * @brief When set to **true**, Envelope ID Stamping is enabled. [optional]
 */
@property (nonatomic, assign) BOOL envelopeIdStamping;
/*!
 * @brief Specifies the Authoritative copy feature. If set to true the Authoritative copy feature is enabled. [optional]
 */
@property (nonatomic, assign) BOOL authoritativeCopy;
/*!
 * @brief Contains a URI for an endpoint that you can use to retrieve the notifications. [optional]
 */
@property (nonatomic, copy) NSString *notificationUri;
/*!
 * @brief When set to **true**, documents with tabs can only be viewed by signers that have a tab on that document. Recipients that have an administrative role (Agent, Editor, or Intermediaries) or informational role (Certified Deliveries or Carbon Copies) can always see all the documents in an envelope, unless they are specifically excluded using this setting when an envelope is sent. Documents that do not have tabs are always visible to all recipients, unless they are specifically excluded using this setting when an envelope is sent.\n\nYour account must have Document Visibility enabled to use this. [optional]
 */
@property (nonatomic, assign) BOOL enforceSignerVisibility;
/*!
 * @brief When set to **true**, the signer is allowed to print the document and sign it on paper. [optional]
 */
@property (nonatomic, assign) BOOL enableWetSign;
/*!
 * @brief When set to **true**, Document Markup is enabled for envelope. Account must have Document Markup enabled to use this [optional]
 */
@property (nonatomic, assign) BOOL allowMarkup;
/*!
 * @brief TODO:Doc
 */
@property (nonatomic, assign) BOOL allowReassign;
/*!
 * @brief Indicates the date and time the item was created. [optional]
 */
@property (nonatomic, copy) NSDate *createdDateTime;
/*!
 * @brief The date and time the item was last modified. [optional]
 */
@property (nonatomic, copy) NSDate *lastModifiedDateTime;
/*!
 * @brief For DocuSign use only. [optional]
 */
@property (nonatomic, copy) NSDate *deliveredDateTime;
/*!
 * @brief The date and time the envelope was sent. [optional]
 */
@property (nonatomic, copy) NSDate *sentDateTime;
/*!
 * @brief Specifies the date and time this item was completed. [optional]
 */
@property (nonatomic, copy) NSDate *completedDateTime;
/*!
 * @brief The date and time the envelope or template was voided. [optional]
 */
@property (nonatomic, copy) NSDate *voidedDateTime;
/*!
 * @brief The date and time the envelope or template was cached.
 */
@property (nonatomic, copy) NSDate *cachedDateTime;
/*!
 * @brief The reason the envelope or template was voided. [optional]
 */
@property (nonatomic, copy) NSString *voidedReason;
/*!
 * @brief Specifies the data and time the item was deleted. [optional]
 */
@property (nonatomic, copy) NSDate *deletedDateTime;
/*!
 * @brief The date and time the recipient declined the document. [optional]
 */
@property (nonatomic, copy) NSDate *declinedDateTime;
/*!
 * @brief The data and time the status changed. [optional]
 */
@property (nonatomic, copy) NSDate *statusChangedDateTime;
/*!
 * @brief Contains a URI for an endpoint that you can use to retrieve combined document.
 */
@property (nonatomic, copy) NSString *documentsCombinedUri;
/*!
 * @brief Retrieves a URI for an endpoint that allows you to easily retrieve certificate information. [optional]
 */
@property (nonatomic, copy) NSString *certificateUri;
/*!
 * @brief Contains a URI for an endpoint which you can use to retrieve the templates. [optional]
 */
@property (nonatomic, copy) NSString *templatesUri;
/*! 
 * @brief When set to **true**, prevents senders from changing the contents of `emailBlurb` and `emailSubject` properties for the envelope. \n\nAdditionally, this prevents users from making changes to the contents of `emailBlurb` and `emailSubject` properties when correcting envelopes. \n\nHowever, if the `messageLock` node is set to true**** and the `emailSubject` property is empty, senders and correctors are able to add a subject to the envelope. [optional]
 */
@property (nonatomic, assign) BOOL messageLock;
/*!
 * @brief When set to **true**, prevents senders from changing, correcting, or deleting the recipient information for the envelope. [optional]
 */
@property (nonatomic, assign) BOOL recipientsLock;
/*!
  @brief TODO
 */
@property (nonatomic, assign) DSMDisclosureSetting disclosureSetting;
/*!
 * @brief TODO
 */
@property (nonatomic, copy) NSString *purgeState;
/*!
 * @brief When set to **true**, indicates that this module is enabled on the account. [optional]
 */
@property (nonatomic, assign) BOOL is21CFRPart11;
/*!
 * @brief TODO
 */
@property (nonatomic, assign) BOOL autoNavigation;
/*!
 * @brief TODO
 */
@property (nonatomic, assign) BOOL isSignatureProviderEnvelope;
/*!
 * @brief TODO
 */
@property (nonatomic, copy) NSString *brandId;
/*!
 * @brief TODO
 */
@property (nonatomic, assign) BOOL brandLock;
/*!
 * @brief TODO
 */
@property (nonatomic) NSInteger currentRoutingOrder;

@end
