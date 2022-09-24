#import <DocuSignSDK/DSESObject.h>
#import <DocuSignSDK/DSESRecipientSignatureInformation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DSESRecipientSignaturesInformation : DSESObject

/* Array of the user signatures.
 */
@property(nonatomic) NSArray<DSESRecipientSignatureInformation>* userSignatures;

@end

NS_ASSUME_NONNULL_END
