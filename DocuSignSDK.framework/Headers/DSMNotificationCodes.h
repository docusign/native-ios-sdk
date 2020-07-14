//  DSMNotificationCodes.h
//  DocuSignSDK
#ifndef DSMNotificationCodes_h
#define DSMNotificationCodes_h

#pragma GCC visibility push(default)

#pragma mark notification name

/*!
 * @brief Notification sent when envelope signing is completed in online or offline mode by all current signers.
 * @discussion Returned userInfo contains signingMode associated with DSMSigningModeKey and templateId associated with DSMTemplateIdkey. Returned userInfo also contains envelopeId associated with DSMEnvelopeIdKey only when online signing; during offline signing, envelopeId for signed envelope is sent with DSMEnvelopeCachedNotification.
 * Conforming to DSMEnvelopesManagerOfflineSigningDelegate allows client apps to receive callback events associated with recipient selection or individual recipient events for start and finish offline signing.
 * This can be posted on a thread other than MainThread.
 * [[NSNotificationCenter defaultCenter] postNotificationName:DSMSigningCompletedNotification object:viewController userInfo:userInfo];
 * @see DSMEnvelopesManager.h
 * @see DSMEnvelopesManagerOfflineSigningDelegate
 */
extern NSString * const DSMSigningCompletedNotification;

/*!
 * @brief Notification sent when signing is cancelled.
 * @discussion Returned userInfo has envelopeId associated with DSMEnvelopeIdKey. This can be posted on a thread other than MainThread.
 * [[NSNotificationCenter defaultCenter] postNotificationName:DSMSigningCancelledNotification object:viewController userInfo:userInfo];
 */
extern NSString * const DSMSigningCancelledNotification;

/*!
 * @brief Notification sent when composing online envelope fails.
 * @discussion Returned userInfo has envelopeId associated with DSMEnvelopeIdKey. This can be posted on a thread other than MainThread.
 * [[NSNotificationCenter defaultCenter] postNotificationName:DSMEnvelopeOnlineSendFailedNotification object:nil userInfo:userInfo];
 */
extern NSString * const DSMEnvelopeOnlineSendFailedNotification;
/*!
 * @brief Notification sent when caching is enabled for a given record (envelope).
 * @discussion Returned userInfo contains envelopeId associated with DSMEnvelopeIdKey, templateId associated with DSMTemplateIdKey. This can be posted on a thread other than MainThread.
 * [[NSNotificationCenter defaultCenter] postNotificationName:DSMEnvelopeCachedNotification object:nil userInfo:userInfo];
 * Note: Enabling setup configuration `DSM_SETUP_ENABLE_OFFLINE_SIGNING_SAVE_ENVELOPE_PROGRESS_KEY` would result in this notification being sent every time a local offline envelope is saved after local signer finishes signing.
 */
extern NSString * const DSMEnvelopeCachedNotification;

/*!
 * @brief Notification sent when caching is disabled for a given record (envelope).
 * @discussion Returned userInfo has envelopeId associated with DSMEnvelopeIdKey key. This can be posted on a thread other than MainThread.
 * [[NSNotificationCenter defaultCenter] postNotificationName:DSMEnvelopeUncachedNotification object:nil userInfo:userInfo];
 */
extern NSString * const DSMEnvelopeUncachedNotification;

/*!
 * @brief Notification sent when attempt to cache an envelope fails.
 * @discussion Returned userInfo has envelopeId associated with DSMEnvelopeIdKey key and error object associated with DSMErrorKey key. This can be posted on a thread other than MainThread.
 * [[NSNotificationCenter defaultCenter] postNotificationName:DSMEnvelopeCacheFailedNotification object:nil userInfo:userInfo];
 */
extern NSString * const DSMEnvelopeCacheFailedNotification;

/*!
 * @brief Notification sent when process to start syncing cached-envelopes with docusign server either finishes normally or is terminated preemptively.
 * @discussion Returns userInfo as nil. This can be posted on a thread other than MainThread.
 * [[NSNotificationCenter defaultCenter] postNotificationName:DSMEnvelopeSyncingEndedNotification object:nil];
 */
extern NSString * const DSMEnvelopeSyncingEndedNotification;

/*!
 * @brief Notification sent when process to start syncing cached-envelopes with docusign server begins.
 * @discussion Returns userInfo with envelopes pending sync details. This can be posted on a thread other than MainThread. Each of the entries contains the dictionary of {DSMEnvelopeIdKey: envelopeId, DSMTemplateIdKey: templateId, DSMTransactionIdKey: transactionId} representing an envelope instance.
 * [[NSNotificationCenter defaultCenter] postNotificationName:DSMEnvelopeSyncingStartedNotification object:nil];
 */
extern NSString * const DSMEnvelopeSyncingStartedNotification;

/*!
 * @brief Notification sent when process to start syncing cached-envelopes with docusign server fails because of some error.
 * @discussion Returned userInfo has envelopeId (cache uri) associated with DSMCacheURIKey key. This can be posted on a thread other than MainThread.
 * [[NSNotificationCenter defaultCenter] postNotificationName:DSMEnvelopeSyncingFailedNotification object:nil userInfo:userInfo];
 */
extern NSString * const DSMEnvelopeSyncingFailedNotification;

/*!
 * @brief Notification sent when process to sync a cached-envelope succeeds with docusign server.
 * @discussion Returned userInfo contains: envelopeId associated with DSMEnvelopeIdKey, cache uri associated with DSMCacheURIKey and templateId associated with DSMTemplateIdKey. This can be posted on a thread other than MainThread.
 * [[NSNotificationCenter defaultCenter] postNotificationName:DSMEnvelopeSyncingSucceededNotification object:nil userInfo:userInfo];
 */
extern NSString * const DSMEnvelopeSyncingSucceededNotification;

/*!
 * @brief Notification sent when envelope is created from template has invalid tab defaults for readonly & required tabs.
 * @discussion Templates may have tabs which are set as Readonly (i.e. locked, signer can't modify the value during signing) AND Required (i.e. tab must have valid value when signing is finished). If Required AND Readonly tab(s) found with nil value in template and no tab-defaults value associated with tab-label(s), DSMFoundReadonlyAndRequiredTabsWithInvalidDefaultsNotification notification will be posted to notify listeners when such template configuration error(s) are detected for envelope-tabs.
 * Optional SDK configuration available: DSM_SETUP_OFFLINE_SIGNING_CONVERT_INVALID_READONLY_REQUIRED_TEXTTABS_TO_EDITABLE
 * @see DSMSetupConstants.h
 * [[NSNotificationCenter defaultCenter] postNotificationName:DSMFoundReadonlyAndRequiredTabsWithInvalidDefaultsNotification object:nil userInfo:userInfo];
 */
extern NSString * const DSMFoundReadonlyAndRequiredTabsWithInvalidDefaultsNotification;

/*!
 * @brief Notification sent when errors are detected with the offline envelope being persisted to coredata for progress save.
 * @discussion Offline envelope is saved after it's created for offline signing and once a local signer finishes signing or a local signer choose to pause signing to be resumed later. Use the envelopeId to uniquely identify the envelope.
 */
extern NSString * const DSMOfflineEnvelopeSaveErrorNotification;

/*!
 * @brief Notification sent when errors are detected with the template configuration during offline envelope signing.
 * @discussion This notification is sent in addition to other specific notifications such as DSMEnvelopeSyncingFailedNotification, DSMEnvelopeCacheFailedNotification and is meant to cover cases related to configuration errors in the template or signed envelope.
 * It's highly recommended to subscribe, log and handle this notification when DSM_SETUP_OFFLINE_SIGNING_HIDE_ALERTS_KEY is used to supress the UI alerts during offline signing.
 * Notification will be sent irrespective of the optional SDK configuration DSM_SETUP_OFFLINE_SIGNING_HIDE_ALERTS_KEY value being set as true or false.
 * UserInfo contains the error object with details on the cause, for example, a) duplicate recipients found with template recipients data or b) invalid formola tab configuration detected in template during offline envelope signing. Optionally, "AdditionalDetails" key points to details related to specific tab resulting in validation errors during offline signing.
 * @see DSMSetupConstants.h
 * [[NSNotificationCenter defaultCenter] postNotificationName:DSMOfflineEnvelopeSigningErrorNotification object:nil userInfo:userInfo];
 */
extern NSString * const DSMOfflineEnvelopeSigningErrorNotification;

/*!
 * @brief Notification sent when errors are detected with the additional data fetch or deletion for a given account.
 * @discussion UserInfo contains the error object with details on the cause, for example, a) key(s): value(s) that failed to fetch or delete with a given error code. Optionally, "AdditionalDetails" key points to details related to severity of the error.
 */
extern NSString * const DSMAdditionalAccountDataFetchOrDeleteErrorNotification;

#pragma mark Envelope Cache Status
/*! @brief Envelope status represending successful caching; this status is sent with various Notification userInfo. */
extern NSString * const DSMCacheDidAddStatus;
/*! @brief Envelope status represending successful update of the cache status; this status is sent with various Notification userInfo. */
extern NSString * const DSMCacheDidUpdateStatus;
/*! @brief Envelope status represending successful uncaching of already cached envelope; this status is sent with various Notification userInfo. */
extern NSString * const DSMCacheDidRemoveStatus;
/*! @brief Envelope status represending failure during caching; this status is sent with various Notification userInfo. */
extern NSString * const DSMCacheDidFailStatus;

#pragma mark Notification Keys
/*! @brief Notification userInfo key to represent CacheURI (recordId) of an envelope. */
extern NSString * const DSMCacheURIKey;
/*! @brief Notification userInfo key to represent EnvelopeId (also recordId) of an envelope. */
extern NSString * const DSMEnvelopeIdKey;
/*! @brief Notification userInfo key to represent TemplateId of a template. */
extern NSString * const DSMTemplateIdKey;
/*! @brief Notification userInfo key to represent TransactionId of an envelope. TransactionIds are only used for offline envelopes which are created on the device using a template or pdf documents. */
extern NSString * const DSMTransactionIdKey;
/*! @brief Notification userInfo key to represent Error of an envelope. */
extern NSString * const DSMErrorKey;
/*!
 * @brief Notification userInfo key to represent envelope signing mode (online vs offline).
 * @see DSMSigningMode
 */
extern NSString * const DSMSigningModeKey;

#pragma GCC visibility pop

#endif /* DSMNotificationCodes_h */
