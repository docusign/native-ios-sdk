#import "DSMEnvelopesManager.h"

@class DSESRecipients;
@class DSMEnvelopeDownloadConfiguration;
@class DSMEnvelopeDefinition;

NS_ASSUME_NONNULL_BEGIN

@interface DSMEnvelopesManager (Additions)

- (void)presentSigningWithPresentingController:(UIViewController *)presentingController
                                    envelopeId:(NSString *)envelopeId
                                    templateId:(NSString *)templateId
                                      animated:(BOOL)animated
                                    completion:(void (^ _Nullable)(UIViewController *, NSError *))completion;

- (void)presentSigningWithPresentingController:(UIViewController *)presentingController
                                    envelopeId:(NSString *)envelopeId
                                      animated:(BOOL)animated
                                    recipients:(DSESRecipients *)recipients
                                    completion:(void (^ _Nullable)(UIViewController *, NSError *))completion;

/*
 * Parameters such as `clientUserId`, `email`, `userName`, `recipientId`, `authenticationMethod`, `returnUrl` are associated with the captive-signer that is part of the sent envelope.
 * [Captive/Embedded Signing API Reference](https://developers.docusign.com/esign-rest-api/guides/concepts/embedding)
 */
- (void)presentCaptiveSigningWithPresentingController:(UIViewController *)presentingController
                                           envelopeId:(NSString *)envelopeId
                                             userName:(NSString *)userName
                                                email:(NSString *)email
                                         clientUserId:(NSString *)clientUserId
                                          recipientId:(NSString *)recipientId
                                            returnUrl:(NSString *)returnUrl
                                 authenticationMethod:(NSString *)authenticationMethod
                                             animated:(BOOL)animated
                                           completion:(void (^ _Nullable)(UIViewController *, NSError *))completion;

/*
* Parameter `clientUserId` is associated with the captive-signer that is part of the sent envelope.
* [Captive/Embedded Signing API Reference](https://developers.docusign.com/esign-rest-api/guides/concepts/embedding)
*/
- (void)presentCaptiveSigningWithPresentingController:(UIViewController *)presentingController
                                           envelopeId:(NSString *)envelopeId
                                         clientUserId:(NSString *)clientUserId
                                             animated:(BOOL)animated
                                           completion:(void (^ _Nullable)(UIViewController *, NSError *))completion;

/*!
 * @discussion Cache (download) an envelope for a given envelopeId with the pdf documents. `DSMEnvelopeCachedNotification` is sent when envelope is cached successfully. Note: Any previously cached version of envelope with the same envelopeId will be removed and any progress for completed signers would be lost.
 * @param envelopeId Id of envelope to download
 * @param downloadConfiguration [optional] download configuration for setting advance options
 * @param completion completion block
 * @see DSMEnvelopeDownloadConfiguration DSMEnvelopeDefinition DSMNotificationCodes
 */
- (void)downloadEnvelopeWithId:(NSString *)envelopeId downloadConfiguration:(nullable DSMEnvelopeDownloadConfiguration *)downloadConfiguration completion:(void (^ _Nullable)(NSString *_Nullable, NSError *_Nullable))completion;

/*!
 * @discussion Cache (download) an envelope for a given envelopeId with the pdf documents. `DSMEnvelopeCachedNotification` is sent when envelope is cached successfully. Note: Any previously cached version of envelope with the same envelopeId will be removed and any progress for completed signers would be lost.
 * @param envelopeId Id of envelope to download
 * @param completion completion block
 * @see DSMEnvelopeDefinition DSMNotificationCodes
 */
- (void)downloadEnvelopeWithId:(NSString *)envelopeId completion:(void (^ _Nullable)(NSString *_Nullable, NSError *_Nullable))completion;

/*!
 * @discussion Retrieve cached envelope for a given envelopeId with the pdf documents.
 * @return DSMEnvelopeDefinition * object containing entire envelope definition including the documents
 * @see DSMEnvelopesManager DSMEnvelopeDefinition DSMNotificationCodes
 */
- (nullable DSMEnvelopeDefinition *)downloadedEnvelopeWithId:(NSString *)envelopeId;

@end

NS_ASSUME_NONNULL_END
