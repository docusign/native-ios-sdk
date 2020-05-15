# How to use AccountInfo for offline login when the device has no network connectivity 

At times, client apps don't have network connectivity and the flow to use templates or envelopes in offline mode is blocked until user is logged in with SDK. This section has details on how to enable client app to login with DocuSign Mobile SDK when the device is offline  

Solution using `apiPassword`: `DSMManager` login method `loginWithUserId` should be used first while online to get valid login information returned via `accountInfo` parameter of completion block. Once a successful online login is done, client code should persist the `accountInfo`, and use persisted `apiPassword` to do offline SDK login when device has no network connectivity. 

## Implementation Details

### Existing Login methods availabe with the `DSMManager`

* `loginWithAccessToken` is the recommended solution for online and offline login  
** As per current SDK implementation, in order to use `loginWithAccessToken`, OAuth2 Code Grant should be implemented to receive `accessToken` to be used for `online` or `offline` SDK login.
** Link to DocuSign ESign REST API Guide using OAuth2 Code Grant: https://developers.docusign.com/esign-rest-api/guides/authentication/oauth2-code-grant
* `loginWithUserId` is online only login method that goes through the legacy authentication API using `username` and `password` combination
* `loginWithAPIPassword` is online and offline login method that goes through the legacy authentication API using `apiPassword` retrieved via `loginWithUserId` method
** Link to online documentation: https://developers.docusign.com/esign-rest-api/reference/Authentication/Authentication/login


`DSMAccountInfo` object is retuned with the completion `completion:^(DSMAccountInfo *accountInfo, NSError *error)` for following login methods exposed in `DSMManager`:
* `loginWithUserId:password:integratorKey:host:completion:`
* `loginWithAccessToken:accountId:userId:userName:email:host:integratorKey:networkMode:completion:`
* `loginWithAPIPassword:accountId:userId:userName:email:host:integratorKey:networkMode:completion:`


### Using `DSMAccountInfo`

`DSMAccountInfo` composition:

* `accountId`
* `accountName`
* `apiPassword` nil when `accessToken` is used
* `authenticationMethod`
* `email`
* `host`
* `integratorKey`
* `accessToken` nil when `apiPassword` is used
* `userId`
* `userName`

When a successful login is done when online, `accountInfo` can be persisted securly in the client app for future use. Apple's Keychain Services (https://developer.apple.com/documentation/security/keychain_services) can be used for securely persisting sensitive information. If the network is unavailable, client app may use `loginWithAccessToken` or `loginWithAPIPassword` to continue the login process when device is offline. All of the offline functionality will be available when offline login is done. Some of the online methods would result in errors, and to resolve those, client app is required to use the online login methods to proceed with online functionalities.

### Note: Avoid logging and exposing any of the sensitive data returned with `DSMAccountInfo` object. 

