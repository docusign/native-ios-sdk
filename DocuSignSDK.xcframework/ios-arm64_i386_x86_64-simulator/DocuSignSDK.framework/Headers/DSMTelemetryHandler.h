#import <Foundation/Foundation.h>

@interface DSMTelemetryHandler : NSObject

/// Fetches all events in core Data
+ (NSArray *)getAllTelemetryEvents;

/// Fetches first batch of telemetry events. A batch consists of 30 events.
/// @return An array of DSMCDTelemetryEvent
+ (NSArray *)getFirstBatchTelemetryEvents;

/// Caches Telemetry events.
/// Telemetry is disabled by overriding the default behaviour using `DSM_SETUP_ENABLE_TELEMETRY` setup configuration on `DSMManager`, events and logs won't be captured by the SDK.
/// @param eventName name of the event
/// @param category event category
/// @param properties a dictionary with additional information to cache.
/// @param completionBlock a completion block
+ (void)cacheTelemetryEventWithName:(NSString *)eventName
                           category:(NSString *)category
                         properties:(NSDictionary <NSString *, NSString*>*)properties
                         completion:(void(^)(NSError *error))completionBlock;

/// Caches Telemetry events.
/// Telemetry is disabled by overriding the default behaviour using `DSM_SETUP_ENABLE_TELEMETRY` setup configuration on `DSMManager`, events and logs won't be captured by the SDK.
/// @param eventName name of the event
/// @param category event category
/// @param eventType event type
/// @param applicationName application name
/// @param properties a dictionary with additional information to cache.
/// @param completionBlock a completion block
+ (void)cacheTelemetryEventWithName:(NSString *)eventName
                           category:(NSString *)category
                          eventType:(NSString *)eventType
                    applicationName:(NSString *)applicationName
                         properties:(NSDictionary <NSString *, NSString*>*)properties
                         completion:(void(^)(NSError *error))completionBlock;

/// Caches Telemetry events.
/// Telemetry is disabled by overriding the default behaviour using `DSM_SETUP_ENABLE_TELEMETRY` setup configuration on `DSMManager`, events and logs won't be captured by the SDK.
/// @param eventName name of the event
/// @param category event category
/// @param envelopeId envelope Id of the envelope
/// @param clientUserId client user Id associated with the recipient in envelope
/// @param signingMode signing mode used
/// @param isCaptive is signing captive (embedded)
/// @param timeTrackKey time-track key associated for given event
/// @param properties a dictionary with additional information to cache.
/// @param completionBlock a completion block
+ (void)cacheTelemetryEventWithName:(NSString *)eventName
                           category:(NSString *)category
                         envelopeId:(NSString *)envelopeId
                       clientUserId:(NSString *)clientUserId
                        signingMode:(NSString *)signingMode
                          isCaptive:(BOOL)isCaptive
                       timeTrackKey:(NSString *)timeTrackKey
                        reasonShort:(NSString *)reasonShort
                         properties:(NSDictionary <NSString *, NSString*>*)properties
                         completion:(void(^)(NSError *error))completionBlock;


/// Removes Telemetry events from cache based on the specified Ids
/// @param eventIds a unique Id, especially a traceToken on `DSMCDTelemetryEvent`
+ (BOOL)deleteTelemetryEventsWithIds:(NSArray *)eventIds;


/// Truncates all existing events in Cache. Typically used when user logout from the SDK.
+ (void)clearTelemetryEvents;

/// Fetches the Telemetry endpoint based on current host url
+ (NSString *)getTelemetryHostUrlStringForProd;

+ (NSArray *)testEnvironments;
+ (NSDictionary *)prodEnvironments;

#pragma mark - Whitelisted Events

+ (void)cacheAuthenticationEventWithSuccess;
+ (void)cacheAuthenticationEventFailureWithHost:(NSString *)hostUrl
                                    errorReason:(NSString *)errorReason;

// Online Signing events
+ (void)cacheOnlineTapWebLinkEventWithURL:(NSString *)url
                                     type:(NSString *)typeOfLink
                               envelopeId:(NSString *)envelopeId;
+ (void)cacheOnlineSigningErrorWithMessage:(NSString *)message
                                envelopeId:(NSString *)envelopeId;
+ (void)cacheOnlineNativeSigningComponentEventWithComponent:(NSString *)component
                                                 envelopeId:(NSString *)envelopeId;

#pragma mark - Debug Events

+ (void)debugLog:(NSString *)log envelopeId:(NSString *)envelopeId;

@end

