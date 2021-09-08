//  DSMEnvelopesManager.h
//  DocuSignSDK
#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSMSigningMode.h>
#import <DocuSignSDK/DSMEnvelopeCacheState.h>

NS_ASSUME_NONNULL_BEGIN

@class DSMRecipient;
@class DSMEnvelopeDefinition;

/*!
 @protocol DSMEnvelopesManagerOfflineSigningDelegate
 @abstract Offline signing delegate to receive events and customize signing session for recipients. Use the notifications to receive the events related to envelope offline signing, caching and syncing process. 
 @see DSMInPersonSigner DSMSigner DSMNotificationCodes
 */
@protocol DSMEnvelopesManagerOfflineSigningDelegate<NSObject>

/*!
 @discussion Inform delegate that select a recipient will show before starting offline signing.
 @use May use it to modify the recipient by switching between types before select a recipient is shown.
 @see DSMNotificationCodes
 */
- (void)willShowSelectRecipientAmongCurrentRecipients:(NSOrderedSet *)recipients offlineSigningEnvelope:(DSMEnvelopeDefinition *)envelope;

/*!
 @discussion Inform delegate that recipient will start signing envelope in offline mode.
 @use May use it to modify the recipient by switching between types before signing starts.
 @see DSMNotificationCodes
 */
- (void)recipient:(DSMRecipient *)recipient willBeginOfflineSigningEnvelope:(DSMEnvelopeDefinition *)envelope;

/*!
 @discussion Inform delegate that recipient finished signing envelope in offline mode.
 @see DSMNotificationCodes
 */
- (void)recipient:(DSMRecipient *)recipient didEndOfflineSigningEnvelope:(DSMEnvelopeDefinition *)envelope;

@end

@protocol DSMEnvelopesManagerOffineSigningSwitchRecipient<NSObject>

/*!
 @discussion present a edit recipient flow for current offline signing session with a given envelope id. This should be used from the DSMEnvelopesManagerOfflineSigningDelegate methods to ensure a valid offline signing session in progress.
 @param envelopeId id of the envelope currently in use with offline signing session
 @param animated if the presentation of edit recipient is animated or not.
 @param completion completion block to be executed after edit recipient is finished.
 */
- (void)presentEditRecipientsControllerForEnvelopeWithId:(NSString *)envelopeId
                                                animated:(BOOL)animated
                                              completion:(nullable void(^)(NSError *_Nullable error))completion;

@end

/*!
 @class DSMEnvelopesManager
 @abstract It aggregates all envelope cache & sync functionality used with offline signing envelopes generated via templates.
 @see DSMTemplatesManager
 */
@interface DSMEnvelopesManager : NSObject <DSMEnvelopesManagerOffineSigningSwitchRecipient>

/*! @discussion [optional] set a delegate to receive callback related to offline signing
 @see DSMEnvelopesManagerOfflineSigningDelegate
 */
@property (nonatomic, weak, nullable) id <DSMEnvelopesManagerOfflineSigningDelegate> offlineSigningDelegate;

/*!
 * @discussion Sync the pending envelopes on the device to create remote envelopes.
 * An envelope can be in pending Sync state when
 * a) created envelope's local InPersonSigner(s) or self-Signer have finished signing,
 *   and either has no pending local InPersonSigner(s) or only has pending remote
 *   signer(s) in next signing order.
 * b) created envelope only has pending remote signer(s) in next signing order.
 * @use When device is online and there has been sign and send Offline and pending sync to server.
 * @use Data validation or extraction for an offline completed envelope should be done before invoking the sync. Once an envelope is successfully synced, it's deleted from the cache on the device.
 * @discussion Relevant Notifications that can be used to track the progress of an envelope sync task: DSMEnvelopeSyncingStartedNotification, DSMEnvelopeSyncingSucceededNotification, DSMEnvelopeSyncingEndedNotification, DSMEnvelopeSyncingFailedNotification.
 * @see DSMNotificationCodes
 */
- (void)syncEnvelopes;

/*!
 * @discussion Cancel the sync process.
 */
- (void)cancelSync;

/*!
 * @discussion Remove a cached envelope. This call can be made when device is offline.
 * @param envelopeId An Id of the envelope to be removed.
 */
- (void)removeCachedEnvelopeWithId:(NSString *)envelopeId;

/*!
 * @discussion Return `true` if the envelope can be resumed for offline signing.
 */
- (BOOL)canResumeSigningEnvelopeWithId:(NSString *)envelopeId;

/*!
 * @discussion Resume signing with a cached envelope. This call can be made when device is offline.
 * @param presentingController controller will be presented on top of the given presentingController passed.
 * @param envelopeId An Id of the envelope to be resumed.
 * @param completion completion block to be executed after envelope signing has been resumed.
 */
- (void)resumeSigningEnvelopeWithPresentingController:(UIViewController *)presentingController
                                           envelopeId:(NSString *)envelopeId
                                           completion:(void(^)(UIViewController *_Nullable presentedController, NSError *_Nullable error))completion;

/*!
 * @discussion Retrieve all cached envelopes without the pdf documents. Envelopes can be filtered with "envelopeId". Many notifications, such as DSMEnvelopeCachedNotification, include "envelopeId" in the userInfo.  Data validation or extraction for an offline completed envelope should be done before invoking the sync. Once an envelope is successfully synced, it's deleted from the cache on the device. This call can be made when device is offline.
 * @return NSArray <DSMEnvelopeDefinition *>, array containing entire envelope definition(s). Empty array if no cached envelopes are found.
 * @see DSMEnvelopeDefinition DSMNotificationCodes DSMTemplatesManager
 */
- (NSArray *)cachedEnvelopes;

/*!
 * @discussion Retrieve envelopeIds for all cached envelopes. Compared to cachedEnvelopes, this has only envelopeId in the array. This call can be made when device is offline.
 * @return NSArray <NSString *> array containing strings representing unique envelopeId(s). Empty array if no cached envelopes are found.
 */
- (NSArray <NSString *> *)cachedEnvelopeIds;

/*!
 * @discussion Returns the cached state of an envelope. This call can be made when device is offline.
 * @param envelopeId An ID of the envelope whose status is enquired.
 * @return DSMTemplateCacheState
 * @see DSMTemplateCacheState.h
 */
- (DSMEnvelopeCacheState)cacheStateOfEnvelopeWithId:(NSString *)envelopeId;

/*!
 * @discussion Remove all cached envelopes. This call can be made when device is offline.
 */
- (void)removeCachedEnvelopes;

/*!
 * @discussion Start creating an envelope to manually add documents, recipients and tags. Client app is responsible for detecting network to present view controller.
 * @param presentingController controller will be presented on top of the given presentingController passed.
 * @param signingMode compose envelope in either online or offline mode, see DSMSigningMode
 * @param resumeWithDraft determines whether to initialize flow with a previously saved draft (if any)
 * @param animated if the presentation of sign and send be animated or not.
 * @param completion completion block to be executed after compose envelope controller has been presented.
 * @warning passing nil to a presentationController will not be able to load the offline envelope flow.
 * @discussion Relevant Notifications that can be used to track the progress of an envelope sync task: DSMEnvelopeOnlineSendFailedNotification.
 * @see DSMNotificationCodes
 */
- (void)presentComposeEnvelopeControllerWithPresentingController:(UIViewController *)presentingController
                                                     signingMode:(DSMSigningMode)signingMode
                                                 resumeWithDraft:(BOOL)resumeWithDraft
                                                        animated:(BOOL)animated
                                                      completion:(nullable void(^)(UIViewController *_Nullable presentedController))completion;

/*!
 * @discussion Creates an envelope programmatically using DSMEnvelopeBuilder.
 * @param signingMode compose envelope in either online or offline mode, see DSMSigningMode
 * @param completion completion block to be executed after envelope is successfully created.
 * @warning passing nil to a presentationController will not be able to load the offline envelope flow.
 * @see DSMEnvelopeBuilder
 */
- (void)composeEnvelopeWithEnvelopeDefinition:(DSMEnvelopeDefinition *)envelope
                                  signingMode:(DSMSigningMode)signingMode
                                   completion:(nullable void(^)(NSString *_Nullable envelopeId, NSError *error))completion;

/*!
 * @discussion Start signing a remote envelope with the given envelopeId. It presents the required modal which can be dismissed if desired with the view-controller returned with completion block.
 * Note: `envelopeId` should match the id of the remote envelope ready to sign on the account under use.
 * @param presentingController controller will be presented on top of the given presentingController passed.
 * @param envelopeId envelopeId of the remote envelope with which to start Signing process.
 * @param animated If the presentation of sign and send be animated or not.
 * @param completion Completion block to be executed after signing has been presented.
 * @warning passing nil to a presentationController will not be able to load the Signing.
 */
- (void)presentSigningWithPresentingController:(UIViewController *)presentingController
                                    envelopeId:(NSString *)envelopeId
                                      animated:(BOOL)animated
                                    completion:(void (^ _Nullable)(UIViewController *_Nullable presentedController, NSError *_Nullable error))completion;

/*!
 * @discussion Start captive/embedded signing a remote envelope with the given envelopeId. It presents the required modal which can be dismissed if desired with the view-controller returned with completion block.
 * Note: a) `envelopeId` should match the id of the remote envelope ready to sign on the account under use.
 * b) An extra API call is made to fetch `recipientUserName` & `recipientEmail` for the given `envelopeId` and `recipientClientUserId`.
 * c) In case if no unique recipient is found with given `recipientClientUserId`, `DSMSigningCancelledNotification` notification is sent with additional details.
 * Note: Captive-Signing disables the native-ui-components for the signing ceremony associated with the `DSM_SETUP_ONLINE_SIGNING_DISABLE_NATIVE_COMPONENTS` setup configuration.
 * @param presentingController controller will be presented on top of the given presentingController passed.
 * @param envelopeId envelopeId of the remote envelope with which to start Signing process.
 * @param recipientClientUserId clientUserId of the captive recipient in the envelope.
 * @param animated If the presentation of sign and send be animated or not.
 * @param completion Completion block to be executed after signing has been presented or if an error is encountered.
 * @warning passing nil to a presentationController will not be able to load the Signing.
 * @see DSMNotificationCodes.h
 */
- (void)presentCaptiveSigningWithPresentingController:(UIViewController *)presentingController
                                           envelopeId:(NSString *)envelopeId
                                recipientClientUserId:(NSString *)recipientClientUserId
                                             animated:(BOOL)animated
                                           completion:(void (^ _Nullable)(UIViewController *_Nullable presentedController, NSError *_Nullable error))completion;

/*!
 * @discussion Start captive/embedded signing a remote envelope with the given envelopeId. It presents the required modal which can be dismissed if desired with the view-controller returned with completion block.
 * Note: `envelopeId` should match the id of the remote envelope ready to sign on the account under use.
 * Note: Captive-Signing disables the native-ui-components for the signing ceremony associated with the `DSM_SETUP_ONLINE_SIGNING_DISABLE_NATIVE_COMPONENTS` setup configuration.
 * @param presentingController controller will be presented on top of the given presentingController passed.
 * @param envelopeId envelopeId of the remote envelope with which to start Signing process.
 * @param recipientUserName userName of the captive recipient in the envelope.
 * @param recipientEmail email of the captive recipient in the envelope.
 * @param recipientClientUserId clientUserId of the captive recipient in the envelope.
 * @param animated If the presentation of sign and send be animated or not.
 * @param completion Completion block to be executed after signing has been presented.
 * @warning passing nil to a presentationController will not be able to load the Signing.
*/
- (void)presentCaptiveSigningWithPresentingController:(UIViewController *)presentingController
                                           envelopeId:(NSString *)envelopeId
                                    recipientUserName:(NSString *)recipientUserName
                                       recipientEmail:(NSString *)recipientEmail
                                recipientClientUserId:(NSString *)recipientClientUserId
                                             animated:(BOOL)animated
                                           completion:(void (^ _Nullable)(UIViewController *_Nullable presentedController, NSError *_Nullable error))completion;

/*!
 * @discussion Start captive/embedded signing a remote envelope with the given envelopeId. It presents the required modal which can be dismissed if desired with the view-controller returned with completion block.
 * Note: `envelopeId` should match the id of the remote envelope ready to sign on the account under use.
 * Note: Captive-Signing disables the native-ui-components for the signing ceremony associated with the `DSM_SETUP_ONLINE_SIGNING_DISABLE_NATIVE_COMPONENTS` setup configuration.
 * @param presentingController controller will be presented on top of the given presentingController passed.
 * @param envelopeId envelopeId of the remote envelope with which to start Signing process.
 * @param recipientUserName userName of the captive recipient in the envelope.
 * @param recipientEmail email of the captive recipient in the envelope.
 * @param recipientClientUserId clientUserId of the captive recipient in the envelope.
 * @param recipientId recipientId [Optional] of the captive signer in the envelope.
 * @param animated If the presentation of sign and send be animated or not.
 * @param completion Completion block to be executed after signing has been presented.
 * @warning passing nil to a presentationController will not be able to load the Signing.
*/
- (void)presentCaptiveSigningWithPresentingController:(UIViewController *)presentingController
                                           envelopeId:(NSString *)envelopeId
                                    recipientUserName:(NSString *)recipientUserName
                                       recipientEmail:(NSString *)recipientEmail
                                recipientClientUserId:(NSString *)recipientClientUserId
                                          recipientId:(NSString *_Nullable)recipientId
                                             animated:(BOOL)animated
                                           completion:(void (^ _Nullable)(UIViewController *_Nullable presentedController, NSError *_Nullable error))completion;

/*!
* @discussion Start captive/embedded signing a remote envelope with the given embedded-signing-url. It presents
the required modal which can be dismissed if desired with the view-controller returned with the completion block. This
method can be used directly without the SDK `login` flow with `accessToken`.
* Note: Captive-Signing disables the native-ui-components for the signing ceremony associated with the
`DSM_SETUP_ONLINE_SIGNING_DISABLE_NATIVE_COMPONENTS` setup configuration.
* @param presentingController controller will be presented on top of the given presentingController passed.
* @param signingUrl embedded-envelope signing url that is used to load signing ceremony.
* @param envelopeId `envelopeId` should match the guid of the remote envelope ready to sign with the
embedded-signing-url on the account under use. This is being used for DocuSign telemetry, error tracing,
performance issues detection, etc.
* @param recipientId unique `recipientId` representing the recipient in a given envelope. This is being used for
DocuSign telemetry, error tracing, performance issue detection, etc.
* @param animated If the presentation of sign and send be animated or not.
* @param completion Completion block to be executed after signing has been presented or if an error is
encountered.
* @warning passing nil to a presentationController will not be able to load the Signing.
* @see DSMNotificationCodes.h
*/
- (void)presentCaptiveSigningWithPresentingController:(UIViewController *)presentingController
                                           signingUrl:(NSString *)signingUrl
                                           envelopeId:(NSString *)envelopeId
                                          recipientId:(NSString * _Nullable)recipientId
                                             animated:(BOOL)animated
                                           completion:(nullable void(^)(UIViewController *_Nullable presentedController, NSError *_Nullable
                                                                        error))completion;

/*!
 * @discussion Returns whether there is a current cached envelope in draft status. Once an envelope is successfully synced, it's deleted from the cache on the device. This can be used to determine whether presenting compose envelope flow should be resumed with the draft envelope. There can only be one draft cached envelope at a given time. This call can be made when device is offline.
 * @return BOOL, true if there is a cached draft envelope
 */
- (BOOL)hasCachedDraftEnvelope;

@end

NS_ASSUME_NONNULL_END
