//  DSMNotificationCodes.h
//  DocuSignSDK
#ifndef DSMNotificationCodes_h
#define DSMNotificationCodes_h

#pragma GCC visibility push(default)

#pragma mark notification name

/*!
 * @brief Notification sent when signing is completed in online or offline mode.
 * @discussion Returned userInfo has envelopeId associated with DSMEnvelopeIdKey and signingMode associated with DSMSigningModeKey. This can be posted on a thread other than MainThread.
 * @code
   [[NSNotificationCenter defaultCenter] postNotificationName:DSMSigningCompletedNotification object:viewController userInfo:userInfo];
 */
extern NSString * const DSMSigningCompletedNotification;

/*!
 * @brief Notification sent when signing is cancelled.
 * @discussion Returned userInfo has envelopeId associated with DSMEnvelopeIdKey. This can be posted on a thread other than MainThread.
 * @code
   [[NSNotificationCenter defaultCenter] postNotificationName:DSMSigningCancelledNotification object:viewController userInfo:userInfo];
 */
extern NSString * const DSMSigningCancelledNotification;

/*!
 * @brief Notification sent when caching is enabled for a given record (envelope).
 * @discussion Returned userInfo has envelopeId associated with DSMEnvelopeIdKey key. This can be posted on a thread other than MainThread.
 * @code
 [[NSNotificationCenter defaultCenter] postNotificationName:DSMEnvelopeCachedNotification object:nil userInfo:userInfo];
 */
extern NSString * const DSMEnvelopeCachedNotification;

/*!
 * @brief Notification sent when caching is disabled for a given record (envelope).
 * @discussion Returned userInfo has envelopeId associated with DSMEnvelopeIdKey key. This can be posted on a thread other than MainThread.
 * @code
 [[NSNotificationCenter defaultCenter] postNotificationName:DSMEnvelopeUncachedNotification object:nil userInfo:userInfo];
 */
extern NSString * const DSMEnvelopeUncachedNotification;

/*!
 * @brief Notification sent when attempt to cache an envelope fails.
 * @discussion Returned userInfo has envelopeId associated with DSMEnvelopeIdKey key and error object associated with DSMErrorKey key. This can be posted on a thread other than MainThread.
 * @code
 [[NSNotificationCenter defaultCenter] postNotificationName:DSMEnvelopeCacheFailedNotification object:nil userInfo:userInfo];
 */
extern NSString * const DSMEnvelopeCacheFailedNotification;

/*!
 * @brief Notification sent when process to start syncing cached-envelopes with docusign server either finishes normally or is terminated preemptively.
 * @discussion Returnes userInfo as nil. This can be posted on a thread other than MainThread.
 * @code
 [[NSNotificationCenter defaultCenter] postNotificationName:DSMEnvelopeSyncingEndedNotification object:nil];
 */
extern NSString * const DSMEnvelopeSyncingEndedNotification;

/*!
 * @brief Notification sent when process to start syncing cached-envelopes with docusign server begins.
 * @discussion Returnes userInfo as nil. This can be posted on a thread other than MainThread.
 * @code
 [[NSNotificationCenter defaultCenter] postNotificationName:DSMEnvelopeSyncingStartedNotification object:nil];
 */
extern NSString * const DSMEnvelopeSyncingStartedNotification;

/*!
 * @brief Notification sent when process to start syncing cached-envelopes with docusign server fails because of some error.
  * @discussion Returned userInfo has envelopeId (cache uri) associated with DSMCacheURIKey key. This can be posted on a thread other than MainThread.
 * @code
 [[NSNotificationCenter defaultCenter] postNotificationName:DSMEnvelopeSyncingFailedNotification object:nil userInfo:userInfo];
 */
extern NSString * const DSMEnvelopeSyncingFailedNotification;

/*!
 * @brief Notification sent when process to sync a cached-envelope succeeds with docusign server.
 * @discussion Returned userInfo has envelopeId (cache uri) associated with DSMCacheURIKey key. This can be posted on a thread other than MainThread.
 * @code
 [[NSNotificationCenter defaultCenter] postNotificationName:DSMEnvelopeSyncingSucceededNotification object:nil userInfo:userInfo];
 */
extern NSString * const DSMEnvelopeSyncingSucceededNotification;

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
/*! @brief Notification userInfo key to represent Error of an envelope. */
extern NSString * const DSMErrorKey;
/*!
 * @brief Notification userInfo key to represent envelope signing mode (online vs offline).
 * @see DSMSigningMode.h
 */
extern NSString * const DSMSigningModeKey;

#pragma GCC visibility pop

#endif /* DSMNotificationCodes_h */
