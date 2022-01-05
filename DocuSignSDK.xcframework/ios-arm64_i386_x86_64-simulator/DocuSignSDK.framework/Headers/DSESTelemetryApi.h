#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSESErrorDetails.h>
#import <DocuSignSDK/DSESObject.h>
#import <DocuSignSDK/DSESApiClient.h>
#import <DocuSignSDK/DSESTelemetryEventsResponse.h>
#import <DocuSignSDK/DSESTelemetryEvents.h>

@interface DSESTelemetryApi : NSObject

@property(nonatomic, assign) DSESApiClient *apiClient;

- (instancetype)initWithApiClient:(DSESApiClient *)apiClient;
- (void)addHeader:(NSString*)value forKey:(NSString*)key;
- (unsigned long)requestQueueSize;
+ (DSESTelemetryApi *)apiWithHeader:(NSString*)headerValue key:(NSString*)key;
+ (DSESTelemetryApi *) sharedAPI;

/// Gets the user account settings for a specified user.
/// Retrieves a list of the account settings and email notification information for the specified user.\n\nThe response returns the account setting name/value information and the email notification settings for the specified user. For more information about the different user settings, see the [ML:userSettings list].
/// return DSESUserSettingsInformation*

- (NSNumber *)createTelemetryEvents:(DSESTelemetryEvents *)telemetryEvents
                  completionHandler: (void (^)(DSESTelemetryEventsResponse* output, NSError* error))completionBlock;

@end

