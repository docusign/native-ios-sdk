//  DSMEnvelopeHelperProtocol.h
//  DocuSignSDK
#import "DSMRecipientType.h"

@class DSMRecipient;
@class DSMRecipients;
@class DSMDocument;
@class DSMTab;

NS_ASSUME_NONNULL_BEGIN

// Implements commonly used functions for DSEnvelope (in DS app).
@protocol DSMEnvelopeHelperProtocol <NSObject>

@required
/*!
 * @brief Maintains the currentRouting Order (Currently signing recipient routing order) for a envelope being signed.
 * @see DSMEnvelopeTemplate.h
 */
@property (nonatomic) NSInteger currentRoutingOrder;
/*!
 * @discussion Gives list of docuemnts for a Template.
 * @return NSOrderedSet ( NSArray<DSMDocument *> *documents;)
 * @see DSMDocument.h
 */
- (NSOrderedSet *)allDocuments;
/*!
 * @discussion Gives list of InPerson and Remote Signers.
 * @return NSOrderedSet
 * @see DSMSigner.h and DSMInPersonSigner.h
 */
- (NSOrderedSet *)allSigners;
/*!
 * @discussion Gives list of inclomplete local signers.
 * @return NSOrderedSet
 * @see DSMSigner.h and DSMInPersonSigner.h
 */
- (NSOrderedSet *)incompleteLocalSigners;
/*!
 * @discussion Gives recipient details for a given recipeitnId.
 * @return DSMRecipient
 * @see DSMRecipient.h
 */
- (DSMRecipient *)recipientWithId:(NSString *)recipientID;
/*!
 * @discussion Gives recipients list of given DSMRecipientType.
 * @return NSOrderedSet
 * @see DSMRecipientType.h
 */
- (NSOrderedSet *)recipientsOfType:(DSMRecipientType)recipientType;
/*!
 * @discussion If envelope is signed by atleast one remote signer/inperson signer in current session.
 * @return BOOL
 */
- (BOOL)isRemoteEnvelopeSignedByAtLeastOneSignerInCurrentSession;

- (NSOrderedSet *)allOfflineRecipientsInCurrentRoutingOrder;
- (DSMRecipients *)unsignedRecipients;
- (BOOL)isLocallyOriginatedEnvelope;
- (BOOL)isAvailableRemotely;
- (BOOL)isCreatedFromTemplate;

- (NSSet *)allTags;
- (NSSet *)tagsForDocument:(DSMDocument * _Nullable)document;
- (NSSet *)tagsForSigner:(DSMRecipient * _Nullable)signer;

- (BOOL)isSelfSign;

- (void)setSubjectIfNeeded;

@end

NS_ASSUME_NONNULL_END
