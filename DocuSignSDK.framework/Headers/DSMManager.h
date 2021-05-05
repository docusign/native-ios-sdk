//  DSMManager.h
//  DocuSignSDK
#import <Foundation/Foundation.h>
#import "DSMSetupConstants.h"
#import "DSMLoggingLevel.h"

NS_ASSUME_NONNULL_BEGIN

@class DSMAccountInfo;

/*!
 @class DSMManager
 @abstract It contains helper class methods to setup, login and clear credentials upon logout.
 @discussion setupWithConfiguration provides customization options to adjust global settings for DocuSignSDK.
 @see DSMTemplatesManager.h
 */
@interface DSMManager : NSObject

/*! @brief name
 */
+ (NSString *)name;

/*! @brief buildVersion
 */
+ (NSString *)buildVersion;

/*!
 @method setup
 @brief Set up managed context and additional modules. It's recommended to invoke `setup` during application launch.
 */
+ (void)setup;

/*!
 @method setLoggingLevel
 @brief setup logging level.
 @param level level of Logging required
 @see DSMLoggingLevel.h
 */
+ (void)setLoggingLevel:(DSMLoggingLevel)level;

/*!
 @method setupWithConfiguration
 @brief setup with configuration to override the default behaviors.
 Example:
     NSMutableDictionary<NSString *, NSString *> *configuration = [[DSMManager defaultConfigurations] mutableCopy];
     [configuration setValue:DSM_SETUP_TRUE_VALUE forKey:DSM_SETUP_OFFLINE_SIGNING_HIDE_ALERTS_KEY];
     [configuration setValue:DSM_SETUP_TRUE_VALUE forKey:DSM_SETUP_DISABLE_CONTACTS_USAGE_KEY];
     [configuration setValue:@(DSMTabComparisonStrictMatch) forKey:DSM_SETUP_TAB_DEFAULTS_COMPARISON]
     [DSMManager setupWithConfiguration:configuration];
 @see DSMSetupConstants.h
 */
+ (void)setupWithConfiguration:(NSDictionary <NSString *, id> *)configuration;

/*!
@method setConfigurationValue
@brief Update a configured value associated with a key.
Example:
    [DSMManager setConfigurationValue:@(DSMTabComparisonStrictMatch) key:DSM_SETUP_TAB_DEFAULTS_COMPARISON];
@see DSMSetupConstants.h
*/
+ (void)setConfigurationValue:(id)value key:(NSString *)key;

/*!
 @method configuredValueForSetupKey
 @brief query saved configuration value for a given key. If no custom configuration found, it will return the default value for given configuration key. @see defaultConfigurations
 */
+ (BOOL)configuredValueForSetupKey:(NSString *)key;

/*!
 @method configuredValueForSetupKeyTabDefaultsComparison
 @brief query saved configuration value for DSM_SETUP_TAB_DEFAULTS_COMPARISON key. If no configuration found, it will return the default value as DSMTabComparisonStrictMatch. @see defaultConfigurations
 */
+ (DSMTabComparison)configuredValueForSetupKeyTabDefaultsComparison;

/*!
 @method configuredValueForSetupKeyAPITimeout
 @brief query saved configuration value for DSM_SETUP_DEFAULT_API_TIMEOUT key.
 If no configuration found, it will return the default value as set with DSM_SETUP_API_TIMEOUT_DEFAULT_VALUE (= 120 seconds).
 If custom configuration is found, it will clamp the value between DSM_SETUP_API_TIMEOUT_MIN_VALUE (= 30 seconds) and DSM_SETUP_API_TIMEOUT_MAX_VALUE (= 1200 seconds).
 */
+ (NSInteger)configuredValueForSetupKeyAPITimeout;

/*!
 @brief default configurations
 */
+ (NSDictionary<NSString *, id> *)defaultConfigurations;

/*!
 @method loginWithAccessToken
 @brief Sets up DocuSign user account for SDK usage in OAuth case.
 @param accessToken  DocuSign oAuthToken (JWT)
 @param accountId  DocuSign accountId of the user using SDK for sign and send
 @param userId  DocuSign userId of the user using SDK for sign and send
 @param userName  DocuSign username of the user using SDK for sign and send
 @param email  DocuSign registered email Id of the user using SDK for sign and send
 @param host  DocuSign host where user is signed up with DocuSign (e.g. "https://demo.docusign.net/restapi")
 @param integratorKey DocuSign integratorKey for the client application
 @param completion block to be executed after user account is setup
 @see DSMAccountInfo.h
 */
+ (void)loginWithAccessToken:(NSString *)accessToken
                   accountId:(NSString *)accountId
                      userId:(NSString *)userId
                    userName:(NSString *)userName
                       email:(NSString *)email
                        host:(NSURL *)host
               integratorKey:(NSString *)integratorKey
                  completion:(void(^)(DSMAccountInfo *_Nullable accountInfo, NSError *_Nullable error))completion;

/*!
 @method loginWithEmail
 @brief [Deprecated] Sets up DocuSign user account for SDK usage. Only supported login mode is online. Further details on auth update can be found at: https://developers.docusign.com/platform/auth/migrate/
 @param email  DocuSign username (email) of the user using SDK for sign and send
 @param password  DocuSign password of the user using SDK for sign and send
 @param integratorKey DocuSign integratorKey for the client application
 @param host DocuSign host where user is signed up with DocuSign (e.g. "https://demo.docusign.net/restapi")
 @param completion block to be executed after user account is setup
 @see DSMAccountInfo.h
 */
+ (void)loginWithEmail:(NSString *)email
              password:(NSString *)password
         integratorKey:(NSString *)integratorKey
                  host:(NSURL *)host
            completion:(void(^)(DSMAccountInfo *_Nullable accountInfo, NSError *_Nullable error))completion
    DEPRECATED_MSG_ATTRIBUTE("use loginWithAccessToken:accountId:userId:userName:email:host:integratorKey:completion");

/*!
 @method loginWithApiPassword
 @brief [Deprecated] Sets up DocuSign user account for SDK usage in OAuth case.  Further details on auth update can be found at: https://developers.docusign.com/platform/auth/migrate/
 @param apiPassword  DocuSign apiPassword
 @param accountId  DocuSign accountId of the user using SDK for sign and send
 @param userId  DocuSign userId of the user using SDK for sign and send
 @param userName  DocuSign username of the user using SDK for sign and send
 @param email  DocuSign registered email Id of the user using SDK for sign and send
 @param host  DocuSign host where user is signed up with DocuSign (e.g. "https://demo.docusign.net/restapi")
 @param integratorKey DocuSign integratorKey for the client application
 @param completion block to be executed after user account is setup
 @see DSMAccountInfo.h
 */
+ (void)loginWithApiPassword:(NSString *)apiPassword
                   accountId:(NSString *)accountId
                      userId:(NSString *)userId
                    userName:(NSString *)userName
                       email:(NSString *)email
                        host:(NSURL *)host
               integratorKey:(NSString *)integratorKey
                  completion:(void(^)(DSMAccountInfo *_Nullable accountInfo, NSError *_Nullable error))completion
    DEPRECATED_MSG_ATTRIBUTE("use loginWithAccessToken:accountId:userId:userName:email:host:integratorKey:completion");

/*!
 @method fetchSettingsWithAccountInfo
 @brief Fetch additional data for a given account that includes account & user settings with consumer disclosure.
 */
+ (void)fetchSettingsWithAccountInfo:(DSMAccountInfo *)accountInfo
                          completion:(void (^)(DSMAccountInfo *_Nullable accountInfo, NSError *_Nullable error))completion;

/*!
 @method logout
 @abstract logout and clean/clear all local storage and user data. Note: Invoking this method will also remove any of the offline signed envelopes.
 @result boolean representing success with logout
 @see DSMEnvelopesManager to manage cached envelopes
 @see DSMTemplatesManager to manage cached templates
 */
+ (BOOL)logout;

/*!
 @method isSessionActiveWithEmail
 @brief Returns whether there is an active user authentication session.
 @param email DocuSign username (email) of the user using SDK for sign and send
 @param password DocuSign password of the user using SDK for sign and send
 @param integratorKey DocuSign integratorKey for the client application
 @param host DocuSign host where user is signed up with DocuSign (e.g. "https://demo.docusign.net/restapi")
 @return Whether there is an active user authentication session
*/
+ (BOOL)isSessionActiveWithEmail:(NSString *)email
                        password:(NSString *)password
                   integratorKey:(NSString *)integratorKey
                            host:(NSURL *)host;

@end

NS_ASSUME_NONNULL_END
