#import "DSMRecipient.h"

@class DSMTabs;
@class DSMRecipientSignatureInformation;

/*!
 @class DSMInPersonSigner
 */
@interface DSMInPersonSigner : DSMRecipient
/*!
 * @brief Specifies the name of the signing host. It is a required element for In Person Signers recipient Type. \nMaximum Length: 100 characters. [optional]
 */
@property(nonatomic, copy) NSString *hostName;
/*!
 * @brief TODO:Doc
 */
@property(nonatomic, copy) NSString *hostEmail;
/*!
 * @brief Required. The full legal name of a signer for the envelope. \n\nMaximum Length: 100 characters. [optional]
 */
@property(nonatomic, copy) NSString *signerName;
/*!
 * @brief The email address for an InPersonSigner recipient Type. \n\nMaximum Length: 100 characters. [optional]
 */
@property(nonatomic, copy) NSString *signerEmail;
/*!
 * @brief The DSMRecipientSignatureInformation class object.
 * @see DSMRecipientSignatureInformation.h
 */
@property(nonatomic, copy) DSMRecipientSignatureInformation *signatureInfo;
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
 * @brief TODO:Doc
 */
@property(nonatomic, copy) NSString *requireSignerCertificate;
/*!
 * @brief TODO:Doc
 */
@property(nonatomic, assign) BOOL requireSignOnPaper;
/*!
 * @brief When set to **true**, specifies that the signer can perform the signing ceremony offline. [optional]
 */
@property(nonatomic, assign) BOOL canSignOffline;
/*!
 * @brief TODO:Doc
 */
@property(nonatomic, copy) NSString *recipientSuppliesTabs;
/*!
 * @brief TODO:Doc
 */
@property(nonatomic, copy) NSString *inPersonSigningType;

@end
