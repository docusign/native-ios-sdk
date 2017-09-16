//  DSMManager.h
//  DocuSignSDK
#import <Foundation/Foundation.h>

#import "DSMLoggingLevel.h"

@interface DSMManager : NSObject

+ (NSString *)name;

+ (NSString *)buildVersion;

/*!
 * @discussion Sets up managed context. should eb called from application:​did​Finish​Launching​With​Options:
 * @code
  - (BOOL)application:(UIApplication *)application
 didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
 ...
 [DSMManager setup];
 ...
 }
 * @param templateId An ID of the template whose status is enquired.
 * @return DSMTemplateCacheState
 * @see DSMTemplateCacheState.h
 */
+ (void)setup;

/*!
 * @discussion setup logging level.
 * @param level level of Logging required.
 * @see DSMLoggingLevel.h
 */
+ (void)setLoggingLevel:(DSMLoggingLevel)level;

/*!
 * @discussion Sets up DocuSign user account for SDK usage.
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
 * @discussion Sets up DocuSign user account for SDK usage in OAuth case(this is currently only for Docusign Client App).
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
 * @discussion Sets up DocuSign user account for SDK usage in OAuth case(this is currently only for Docusign Client App).
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
 * @discussion clean/clear all local storage and user data - called when user logs out.
 */
+ (BOOL)clearCredentialsAndCachedTemplates;

@end
