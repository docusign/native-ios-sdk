#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSMAuthenticationMethod.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 * @class AccountInfo containing the sensitive login information returned after login is successful.
 * @brief  DSMAccountInfo object is retuned with the completion `completion:^(DSMAccountInfo *accountInfo, NSError *error)` for following login methods exposed in `DSMManager`:
 * - `loginWithAccessToken:accountId:userId:userName:email:host:integratorKey:completion:`
 * - `loginWithAPIPassword:accountId:userId:userName:email:host:integratorKey:completion:`
 * - `loginWithUserId:password:integratorKey:host:completion:`
 *
 * When a successful login is done when online, `accountInfo` can be persisted securely in the client app for future use.
 * For example, Apple's Keychain Services can be used for securely persisting sensitive information.
 * If the network is unavailable, client app may use `loginWithAccessToken` or `loginWithAPIPassword` to continue the login process when device is offline.
 * All of the offline functionality will be available when offline login is done.
 * Any of the online functionality would result in errors, and SDK would need login call to be made again to proceed with online functionality.
 *
 * Note: Don't log and expose any of the sensitive data returned with the `DSMAccountInfo` object.
 * @see DSMManager.h
 */
@interface DSMAccountInfo : NSObject

/*! @brief accountId [sensitive data]
 */
@property (nonatomic) NSString *accountId;

/*! @brief accountName
 */
@property (nonatomic) NSString *accountName;

/*! @brief apiPassword  [sensitive data]
 */
@property (nonatomic) NSString *apiPassword;

/*! @brief accessToken  [sensitive data]
 */
@property (nonatomic) NSString *accessToken;

/*! @brief authenticationMethod
 * @see DSMAuthenticationMethod.h
 */
@property (nonatomic) DSMAuthenticationMethod authenticationMethod;

/*! @brief email  [sensitive data]
 */
@property (nonatomic) NSString *email;

/*! @brief host
 */
@property (nonatomic) NSURL *host;

/*! @brief integratorKey  [sensitive data]
 */
@property (nonatomic) NSString *integratorKey;

/*! @brief userId  [sensitive data]
 */
@property (nonatomic) NSString *userId;

/*! @brief userName
 */
@property (nonatomic) NSString *userName;

@end

NS_ASSUME_NONNULL_END
