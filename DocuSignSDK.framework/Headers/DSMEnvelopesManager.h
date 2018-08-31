//  DSMEnvelopesManager.h
//  DocuSignSDK
#import <Foundation/Foundation.h>

@class DSMRecipient;
@class DSMEnvelopeDefinition;

/*!
 @protocol DSMEnvelopesManagerOfflineSigningDelegate
 @abstract Offline signing delegate to receive events and customize signing session.
 @see DSMInPersonSigner DSMSigner
 */
@protocol DSMEnvelopesManagerOfflineSigningDelegate<NSObject>

/*!
 @discussion Inform delegate that select a recipient will show before starting offline signing.
 @use May use it to modify the recipient by switching between types before select a recipient is shown
 @see DSMNotificationCodes
 */
- (void)willShowSelectRecipientAmongCurrentRecipients:(NSOrderedSet *)recipients offlineSigningEnvelope:(DSMEnvelopeDefinition *)envelope;

/*!
 @discussion Inform delegate that recipient will start signing envelope in offline mode.
 @use May use it to modify the recipient by switching between types before signing starts
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
                                              completion:(void(^)(NSError *error))completion;

@end

/*!
 @class DSMEnvelopesManager
 @abstract It aggregates all envelope cache & sync functionality used with offline signing envelopes generated via templates.
 @see DSMTemplatesManager
 */
@interface DSMEnvelopesManager : NSObject <DSMEnvelopesManagerOffineSigningSwitchRecipient>

@property (nonatomic, weak/*, nullable*/) id <DSMEnvelopesManagerOfflineSigningDelegate> offlineSigningDelegate;

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
 * @discussion Remove a cached envelope.
 * @param envelopeId An Id of the envelope to be removed.
 */
- (void)removeCachedEnvelopeWithId:(NSString *)envelopeId;

/*!
 * @discussion Retrive all cached envelopes. Envelopes can be filtered with "envelopeId". Many notifications, such as DSMEnvelopeCachedNotification, include "envelopeId" in the userInfo.  Data validation or extraction for an offline completed envelope should be done before invoking the sync. Once an envelope is successfully synced, it's deleted from the cache on the device.
 * @return NSArray <DSMEnvelopeDefinition *>, array containing entire envelope definition(s)
 * @see DSMEnvelopeDefinition DSMNotificationCodes DSMTemplatesManager
 */
- (NSArray *)cachedEnvelopes;

/*!
 * @discussion Retrive envelopeIds for all cached envelopes. Compared to cachedEnvelopes, this has only envelopeId in the array.
 * @return NSArray <NSString *> array containing strings representing unique envelopeId(s)
 */
- (NSArray <NSString *> *)cachedEnvelopeIds;

/*!
 * @discussion Remove all cached envelopes.
 */
- (void)removeCachedEnvelopes;

@end
