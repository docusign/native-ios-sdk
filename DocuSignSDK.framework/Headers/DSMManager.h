//  DSMManager.h
//  DocuSignSDK
#import <Foundation/Foundation.h>
#import "DSMSetupConstants.h"
#import "DSMLoggingLevel.h"

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
 * @brief Sets up managed context. should be called from application:​did​Finish​Launching​With​Options:
 */
+ (void)setup;

/*!
 * @brief setup logging level.
 * @param level level of Logging required.
 * @see DSMLoggingLevel.h
 */
+ (void)setLoggingLevel:(DSMLoggingLevel)level;

/*!
 * @brief setup with configuration to override the default behaviors.
 *
 * Example:
 *     NSMutableDictionary<NSString *, NSString *> *configuration = [[DSMManager defaultConfigurations] mutableCopy];
 *     [configuration setValue:DSM_SETUP_TRUE_VALUE forKey:DSM_SETUP_OFFLINE_SIGNING_HIDE_ALERTS_KEY];
 *     [configuration setValue:DSM_SETUP_TRUE_VALUE forKey:DSM_SETUP_DISABLE_CONTACTS_USAGE_KEY];
 *     [DSMManager setupWithConfiguration:configuration];
 *
 * @see DSMSetupConstants.h
 */
+ (void)setupWithConfiguration:(NSDictionary <NSString *, NSString *> *)configuration;

/*!
 * @brief query saved configuration value for a given key. If no custom configuration found, it will return the default value for given configuration key. @see defaultConfigurations
 */
+ (BOOL)configuredValueForSetupKey:(NSString *)key;

/*!
 * @brief default configurations
 */
+ (NSDictionary<NSString *, NSString *> *)defaultConfigurations;

/*!
 * @brief Sets up DocuSign user account for SDK usage.
 * @param userName  DocuSign username of the user using SDK for sign and send.
 * @param password  DocuSign pasword of the user using SDK for sign and send.
 * @param integratorKey DocuSign integratorKey for the client application.
 * @param url DocuSign host where user is signed up with DocuSign (e.g. "https://demo.docusign.net/restapi").
 * @param completionBlock to be executed after user account is setup.
 */
+ (void)loginWithUserId:(NSString *)userName
               password:(NSString *)password
          integratorKey:(NSString *)integratorKey
                   host:(NSURL *)url
        completionBlock:(void(^)(NSError *))completionBlock;

/*!
 * @brief Sets up DocuSign user account for SDK usage in OAuth case(this is currently only for Docusign Client App).
 * @param accessToken  DocuSign oAuthToken.
 * @param accountId  DocuSign accountId of the user using SDK for sign and send.
 * @param userId  DocuSign userId of the user using SDK for sign and send.
 * @param userName  DocuSign username of the user using SDK for sign and send.
 * @param email  DocuSign registered emaildId of the user using SDK for sign and send.
 * @param host  DocuSign host where user is signed up with DocuSign (e.g. "https://demo.docusign.net/restapi").
 * @param integratorKey DocuSign integratorKey for the client application.
 * @param completionBlock to be executed after user account is setup.
 */
+ (void)loginWithAccessToken:(NSString *)accessToken
                   accountId:(NSString *)accountId
                      userId:(NSString *)userId
                    userName:(NSString *)userName
                       email:(NSString *)email
                        host:(NSURL *)host
               integratorKey:(NSString *)integratorKey
                  completion:(void(^)(NSError *error))completionBlock;

/*!
 * @brief Sets up DocuSign user account for SDK usage in OAuth case(this is currently only for Docusign Client App).
 * @param apiPassword  DocuSign apiPassword.
 * @param accountId  DocuSign accountId of the user using SDK for sign and send.
 * @param userId  DocuSign userId of the user using SDK for sign and send.
 * @param userName  DocuSign username of the user using SDK for sign and send.
 * @param email  DocuSign registered emaildId of the user using SDK for sign and send.
 * @param host  DocuSign host where user is signed up with DocuSign (e.g. "https://demo.docusign.net/restapi").
 * @param integratorKey DocuSign integratorKey for the client application.
 * @param completionBlock to be executed after user account is setup.
 */
+ (void)loginWithApiPassword:(NSString *)apiPassword
                   accountId:(NSString *)accountId
                      userId:(NSString *)userId
                    userName:(NSString *)userName
                       email:(NSString *)email
                        host:(NSURL *)host
               integratorKey:(NSString *)integratorKey
                  completion:(void(^)(NSError *error))completionBlock;

/*!
 * @brief clean/clear all local storage and user data - called when user logs out.
 * Note: Invoking this method will also remove any of the offline signed envelopes.
 * @see DSMEnvelopesManager to manage cached envelopes
 * @see DSMTemplatesManager to manage cached templates
 */
+ (BOOL)clearCredentialsAndCachedTemplates;

@end
