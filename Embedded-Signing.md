
# DocuSign iOS SDK - Embedded Signing

## Embedded Signing with SDK

[Embedded or Captive Signing](https://developers.docusign.com/docs/esign-rest-api/esign101/concepts/embedding/) enables users to view and sign documents within the app using generated signing URLs for each of the envelope. To present the signing request in the app UI, the logged in SDK user must be the document sender and have access to the sent envelope to retrieve the signing URL. Additional details are available on [eSign concepts page](https://developers.docusign.com/docs/esign-rest-api/esign101/concepts/embedding/) and [eSign API guide](https://developers.docusign.com/docs/esign-rest-api/how-to/request-signature-in-app-embedded/) for Embedded Signing. 

In addition to the guide below, [`Swift UI` based sample app](./docusign-sdk-sample-swiftui/README.md) also contains all the required steps. [TGK Swift Sample app](https://github.com/docusign/sample-app-tgk-financial-ios) also has code samples to perform authentication and Embedded Signing. 

In order to use Embedded Signing without authentication, refer to [this section](https://github.com/docusign/native-ios-sdk/blob/master/Embedded-Signing.md#embedded-signing-without-sdk-authentication) below.

### A. User Authentication 

[DSMManager](https://github.com/docusign/native-ios-sdk/blob/master/DocuSignSDK.framework/Headers/DSMManager.h) has multiple ways to login with SDK, the following method is the recommended interface to use once the client-app has a valid access token -- additional details on how to [get an access token](https://developers.docusign.com/platform/auth). Once authenticated, [`userinfo`](https://developers.docusign.com/platform/auth/reference/user-info/) can be used to fetch additional properties such as `userId`, `username`, etc required for login.

```
/*!
 @method loginWithAccessToken
 @brief Sets up DocuSign user account for SDK usage in OAuth case.
 @param accessToken  DocuSign oAuthToken
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
```

Sample swift code to perform setup and login.

```
// Invoke sdk setup with custom configurations
var configurations = DSMManager.defaultConfigurations()
configurations[DSM_SETUP_POWERED_BY_DOCUSIGN_ENABLED] = DSM_SETUP_FALSE_VALUE
DSMManager.setup(withConfiguration: configurations)

// Login with DocuSign SDK using accessToken
let demoHostUrl = URL(string: "https://demo.docusign.net/restapi")
let accessToken = ? // AccessToken as fetched with auth API
DSMManager.login(withAccessToken: accessToken, 
                 accountId: "", 
                 userId: "", 
                 userName: "John Wood", 
                 email: "john.wood@dsxtr.com", 
                 host: demoHostUrl, 
                 integratorKey: "") { accountInfo, error in
                     if let error = error {
                        // handle and log sdk login error
                        ...
                        return
                     }
                     // login is successful, process `accountInfo` as needed
                     ...
            }
```

### B. Retriving signing URL and C. Presenting signing request 

Native SDK has the following method to do both retrieve the signing URL and load captive signing session for an authenticated sender account. It also makes an extra API call to fetch recipient information such as `userName` and `email`. 

```
/*!
 * @discussion Start captive/embedded signing a remote envelope with the given envelopeId. It presents the required modal which can be dismissed if desired with the view-controller returned with completion block.
 * Note: a) `envelopeId` should match the id of the remote envelope ready to sign on the account under use.
 * b) An extra API call is made to fetch `recipientUserName` & `recipientEmail` for the given `envelopeId` and `recipientClientUserId`.
 * c) In case if no unique recipient is found with given `recipientClientUserId`, `DSMSigningCancelledNotification` notification is sent with additional details.
 * @param presentingController controller will be presented on top of the given presentingController passed.
 * @param envelopeId envelopeId of the remote envelope with which to start Signing process.
 * @param recipientClientUserId clientUserId of the captive recipient in the envelope.
 * @param animated If the presentation of sign and send be animated or not.
 * @param completion Completion block to be executed after signing has been presented or if an error is encountered.
 * @warning passing nil to a presentationController will not be able to load the Signing.
 * @see DSMNotificationCodes.h
 */
- (void)presentCaptiveSigningWithPresentingController:(UIViewController *)presentingController
                                           envelopeId:(NSString *)envelopeId
                                recipientClientUserId:(NSString *)recipientClientUserId
                                             animated:(BOOL)animated
                                           completion:(void (^ _Nullable)(UIViewController *_Nullable presentedController, NSError *_Nullable error))completion;
```

Additionally, the following interface is available if the integrated app already has recipient details. Using this method would avoid making additional API call.

```
/*!
 * @discussion Start captive/embedded signing a remote envelope with the given envelopeId. It presents the required modal which can be dismissed if desired with the view-controller returned with completion block.
 * Note: `envelopeId` should match the id of the remote envelope ready to sign on the account under use.
 * @param presentingController controller will be presented on top of the given presentingController passed.
 * @param envelopeId envelopeId of the remote envelope with which to start Signing process.
 * @param recipientUserName userName of the captive recipient in the envelope.
 * @param recipientEmail email of the captive recipient in the envelope.
 * @param recipientClientUserId clientUserId of the captive recipient in the envelope.
 * @param animated If the presentation of sign and send be animated or not.
 * @param completion Completion block to be executed after signing has been presented.
 * @warning passing nil to a presentationController will not be able to load the Signing.
*/
- (void)presentCaptiveSigningWithPresentingController:(UIViewController *)presentingController
                                           envelopeId:(NSString *)envelopeId
                                    recipientUserName:(NSString *)recipientUserName
                                       recipientEmail:(NSString *)recipientEmail
                                recipientClientUserId:(NSString *)recipientClientUserId
                                             animated:(BOOL)animated
                                           completion:(void (^ _Nullable)(UIViewController *_Nullable presentedController, NSError *_Nullable error))completion;
```

In above methods, `completion` block would return an `error` if presentation fails for any reason. `presentedController` can be used to dismiss the Signing under progress if needed. SDK utilizes [notifications](https://github.com/docusign/native-ios-sdk/blob/master/DocuSignSDK.framework/Headers/DSMNotificationCodes.h) to relay information related to errors and events. 

Sample swift code to retrieve the signing-URL and present the signing ceremony.

```
let presentingViewController = self
let envelopeId = ? // captive (embedded) envelope guid
let clientUserId = ? // client user id as configured during envelope creation
DSMEnvelopesManager().presentCaptiveSigning(withPresenting: presentingViewController,
                                            envelopeId: envelopeId,
                                            recipientUserName: "John Wood",
                                            recipientEmail: "john.wood@dsxtr.com",
                                            recipientClientUserId: clientUserId,
                                            animated: true { viewController, error in
                                                if let error = error {
                                                   // handle error
                                                   ...
                                                   return
                                                }
                                                // use viewController as needed (e.g. force dismiss if client app need to exit DocuSign Signing Ceremony)
                                                ...
                                            }
```

### D. Redirecting the User

Native iOS SDK handles the redirection and dismisses the signing ceremony to return control to the client-app.

#### **Tracking Events**

Client apps may register for various notification, such as `DSMEnvelopeSyncingSucceededNotification`, to receive the details on various stages of signing. <br>
Notification object with `userInfo` contains `envelopeId` and other relevant information. Other relevant notifications for Online Signing and SDK events can be found in the ([header file](https://github.com/docusign/native-ios-sdk/blob/master/DocuSignSDK.framework/Headers/DSMNotificationCodes.h)). Some of the important notifications are:
- `DSMSigningCompletedNotification`
- `DSMSigningCancelledNotification`

Swift sample to register and handle `DSMSigningCancelledNotification`:

```      
override func viewDidLoad() {
   super.viewDidLoad()

   NotificationCenter.default.addObserver(self, selector: #selector(onSigningCancelled(_:)), name: NSNotification.Name(rawValue: "DSMSigningCancelledNotification"), object: nil)        
}

@objc func onSigningCancelled(_ notification:Notification) {
   // Handle the notification
   guard let envelopeId = notification.userInfo?[DSMEnvelopeIdKey] as? String else {
      // log the envelopeId for signing cancelled event
   }
   ...
}
```

#### Notification `userInfo` Keys & Signing failure reasons

- `DSMEnvelopeIdKey` is added to `userInfo` with any of the Online Signing notifications.
- `DSMAdditionalInfo` is added to `userInfo` when user views a completed document and exits signing.
- `DSMErrorKey` is added to `userInfo` when Signing encounters an error. In case of Embedded Signing, for an example it would contain api returned error when `get /envelopes/{envelopeId}/receipients` fails.
- `DSMSigningExitReasonKey` is added to `userInfo` when signer decides to `decline` or `cancel` using `Finish Later`. The value contains `cancel` or `decline`.
- `DSMSigningModeKey` is added to `userInfo` with all of the Signing Notifications. In case of Embedded Signing, it’s value is set as `online`.
- Further details can be found on [Notification Keys section](/DocuSignSDK.framework/Headers/DSMNotificationCodes.h#L129).

## Embedded signing without SDK authentication

The Native iOS SDK untethers Captive Signing from authentication and directly launches the signing experience using the Captive Recipient Signing URL. <br>
This method relies on the integrating client application to independently retrieve the signing URL for the given envelope and recipient in order to view and capture signatures once the Native SDK `setup` call is complete. <br>
When using this interface, there is no need to perform login or logout for the SDK user. One caveat is to use the signing URL within a short span of time (five minutes) before it expires. 

This sample Swift code demonstrates retrieving the signing URL and presenting the signing experience using the `presentCaptiveSigningWithPresentingController:signingUrl:envelopeId:recipientId:animated:completion:` API on [DSMEnvelopesManager](https://github.com/docusign/native-ios-sdk/blob/master/DocuSignSDK.xcframework/ios-arm64_armv7/DocuSignSDK.framework/Headers/DSMEnvelopesManager.h).

```
let presentingViewController = self
let signingUrl = <signing-url> // the embedded signing url as retrieved with client backend integration
let envelopeId = <created-envelope-id> // captive (embedded) envelope guid
let recipientId = <custom-recipient-id> // captive (embedded) recipient id used to create envelope
DSMEnvelopesManager().presentCaptiveSigning(withPresenting: presentingViewController,
    signingUrl: signingUrl,
    envelopeId: envelopeId,
    recipientId: recipientId,
    animated: true { viewController, error in
    if let error = error {
      // handle error
      ...
      return
    }
    // Use viewController as needed (for instance, force-dismiss if the client app needs to exit DocuSign signing experience)
    ...
}
```

## Embedded Signing with WKWebView

`WKWebView` could be used to load a signing URL that is retrieved via the [API interation](https://developers.docusign.com/docs/esign-rest-api/how-to/request-signature-in-app-embedded/) and available for the mobile app to use. Using this alternative to SDK would require handling custom events and further customization to reach the desired UX. For any Online Signing Component or API related questions, best to reach out to [DocuSign Support](https://support.docusign.com/contactSupport) or post a question on [StackOverflow](https://stackoverflow.com/questions/tagged/docusignapi).

**Note**: DocuSign SDK provides native UI components on top of the Signing Experience (e.g. Top Navigation Bar, Signature Adoption and Consumer Disclosure Handling). SDK also handles all of the URL navigation requests and associated events that are generated by the Online Signing Components along with the detailed telemetry.
