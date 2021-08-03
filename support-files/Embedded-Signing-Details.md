# Embedded Signing with iOS SDK

We are announcing the [Embedded Signing](https://developers.docusign.com/docs/esign-rest-api/how-to/request-signature-in-app-embedded/) capabilities on mobile SDKs in our continued pursuit to empower app developers to achieve a robust signing experience on mobile devices. Embedded Signing is a departure from the usual Remote Recipients pattern, in which DocuSign SDK brokers the communication with envelope Recipients via native UI components to select the recipient and accept legal disclosures to sign the document. Embedded Signing, in contrast, enables a mobile app to maintain its connection with envelope Recipients by incorporating the DocuSign Signing Service directly into its process flow. The functional result is a more fluid document transaction and a more transparent feature extension to view and sign documents seamlessly with the client app. The new Captive Signing APIs on mobile SDKs improves on the Signing experience by providing a robust wrapper around the [Signing API](https://developers.docusign.com/docs/esign-rest-api/how-to/request-signature-in-app-embedded/). SDK also handles all of the URL navigation requests and associated events that the Online Signing Components generate along with the detailed telemetry to capture all the required events.

## Setting up Native SDK

[DSMManager](https://github.com/docusign/native-ios-sdk/blob/master/DocuSignSDK.framework/Headers/DSMManager.h) provides an API `setup` to prepare the Native SDK for the Signing use. For advance usage, `setupWithConfiguration:` allows custom [configurations](https://github.com/docusign/native-ios-sdk/blob/master/DocuSignSDK.framework/Headers/DSMSetupConstants.h) to finetune the Signing experience. A swift example below performs setup with extra configuration `DSM_SETUP_CAPTIVE_SIGNING_USE_LANGUAGE_CODE` to customize the [language](https://www.docusign.com/how-it-works/global) for the Signing ceremony.

```
// Invoke sdk setup with custom configurations
var configurations = DSMManager.defaultConfigurations()

// Set the language as Japanese - "ja" for Signing Session
configurations[DSM_SETUP_CAPTIVE_SIGNING_USE_LANGUAGE_CODE] = DSM_LANGUAGE_CODE_FOR_JAPANESE

DSMManager.setup(withConfiguration: configurations)
```

The [supported languages](https://www.docusign.com/how-it-works/global) codes for Signing are listed in the [DSMLanguageConstants](https://github.com/docusign/native-ios-sdk/blob/release/2.5.3-beta/DocuSignSDK.framework/Headers/DSMLanguageConstants.h) header.

## Authentication with SDK

Authenticated users on Native SDK allow the client app to access all of the features available as part of the API. Once an SDK user is logged in with the client app, the interchangeable use of components such as Templates, Captive Signing, and Offline Signings is possible. Client apps explicitly looking to use the Captive Signing flow may skip the user authentication and directly use `signingURL` variant to launch the embedded signing session as detailed in the `Captive Signing without SDK authentication` section. For any other integrations, which rely on the SDK to handle interactions with DocuSign APIs, this part details the steps involved in the authentication.

[DSMManager](https://github.com/docusign/native-ios-sdk/blob/master/DocuSignSDK.framework/Headers/DSMManager.h) defines the interface to login with DocuSign OAuth when the client app has a valid access token retrived independently of the iOS SDK. Additional details on how to [get an access token](https://developers.docusign.com/platform/auth). Once authenticated, perform [`userinfo` request](https://developers.docusign.com/platform/auth/reference/user-info/) to fetch the additional properties such as `userId`, `username`, `host`, etc required for the login API `loginWithAccessToken:accountId:userId:userName:email:host:integratorKey` as defined in [DSMManager](https://github.com/docusign/native-ios-sdk/blob/master/DocuSignSDK.framework/Headers/DSMManager.h). Swift sample snippet to perform login.

```
// Retrive all of the required parameters for login
let accessToken = <client-access-token> // AccessToken as fetched with auth API
`userinfo` 
let accountId = <client-account-id>     // Account id as per /user-info
let userId = <user-id>                  // User id as per /user-info
let userName = <user-name>              // User name as fetched with /user-info
let email = <email>                     // email as fetched with /user-info
let hostUrl = <host>                    // HostURL as fetched with /user-info request

// Login with DocuSign SDK
DSMManager.login(withAccessToken: accessToken,
                       accountId: accountId,
                          userId: userId,
                        userName: userName,
                           email: email,
                            host: hostUrl,
                   integratorKey: integratorKey) { accountInfo, error in
                     if let error = error {
                        // handle and log sdk login error
                        ...
                        return
                     }
                     // login is successful, process `accountInfo` as needed
                     ...
            }
```

To clear the credentials and persisted data on the device, including offline signed envelopes and downloaded templates, use the `logout` method on [DSMManager](https://github.com/docusign/native-ios-sdk/blob/master/DocuSignSDK.framework/Headers/DSMManager.h).

```
if DSMManager.logout() {
    print ("Successfully logged out user and cleared local data.")
}
```

For additional details, [Swift sample app](https://github.com/docusign/native-ios-sdk/tree/master/docusign-sdk-sample-swift) implements the authentication flow for a hypothetical financial services company: [TGK Capital](https://dsdemos.esigndemos.com/dsportals/finance2/). TGK Capital app allows investors to sign agreements seamlessly when integrated with the mobile iOS SDK.


## Retrieving signing URL and Presenting the Signing session 

Embedded Signing enables users to view and sign documents within the app using generated signing URLs for each sent envelope. To present the signing request in the app UI, the logged-in SDK user must be the document sender and have access to the sent envelope to retrieve the signing URL. Additional details are available on [eSign concepts page](https://developers.docusign.com/docs/esign-rest-api/esign101/concepts/embedding/) and [eSign API guide](https://developers.docusign.com/docs/esign-rest-api/how-to/request-signature-in-app-embedded/) for Embedded Signing. The [`Swift UI` based sample app](https://github.com/docusign/native-ios-sdk/tree/master/docusign-sdk-sample-swiftui) also contains detail on the required steps.


The following interfaces on [DSMEnvelopesManager](https://github.com/docusign/native-ios-sdk/blob/master/DocuSignSDK.framework/Headers/DSMEnvelopesManager.h) allow client-apps to retrieve the signing URL and load the captive signing session for an authenticated user. The envelope creation process described in [Signing API Guide](https://developers.docusign.com/docs/esign-rest-api/how-to/request-signature-in-app-embedded/) contains the `clientUserId` and other recipient view details. Note that the first variant makes an extra API call to fetch information `recipientUserName` and `recipientEmail` associated with the recipient view.


- Captive Signing with envelopeId and recipient's clientUserId: `presentCaptiveSigningWithPresentingController:envelopeId:recipientClientUserId:animated:completion:`
- Captive Signing with envelopeId and recipient's clientUserId, userName & email: `presentCaptiveSigningWithPresentingController:envelopeId:recipientUserName:recipientEmail:recipientClientUserId:animated:completion:`

```
let presentingViewController = self
let envelopeId = ? // guid of captive (embedded) envelope ready to sign
let clientUserId = ? // client user id as configured during envelope creation
DSMEnvelopesManager().presentCaptiveSigning(withPresenting: presentingViewController,
                                            envelopeId: envelopeId,
                                            recipientClientUserId: clientUserId,
                                            animated: true { viewController, error in
                                                if let error = error {
                                                   // handle error
                                                   ...
                                                   return
                                                }
                                                // use viewController as needed (e.g., force dismiss if client app need to exit DocuSign Signing Ceremony)
                                                ...
                                            }
```

Additionally, the following method overload is available if the integrated app already has recipient details. Using this method would avoid making additional API call  [DSMEnvelopesManager](https://github.com/docusign/native-ios-sdk/blob/master/DocuSignSDK.framework/Headers/DSMEnvelopesManager.h).

```
...
DSMEnvelopesManager().presentCaptiveSigning(withPresenting: presentingViewController,
                                            envelopeId: envelopeId,
                                            recipientUserName: "John Wood",
                                            recipientEmail: "john.wood@dsxtr.com",
                                            recipientClientUserId: clientUserId,
                                            animated: true { viewController, error in
                                                ...
                                            }
```

## Captive Signing without SDK authentication

SDK untethers Captive Signing from authentication and directly launches the Signing ceremony using the Captive Recipient Signing URL. This method relies on the integrating client application to independently retrieve the signing URL for the given envelope and recipient to view and capture signatures once the Native SDK Setup is complete. When using this interface, there is no need to perform login or logout for the SDK user.

Sample swift code to retrieve the signing-URL and present the signing ceremony using `presentCaptiveSigningWithPresentingController:signingUrl:envelopeId:recipientId:animated:completion:` API on [DSMEnvelopesManager](https://github.com/docusign/native-ios-sdk/blob/release/2.5.3-beta/DocuSignSDK.framework/Headers/DSMEnvelopesManager.h).

```
let presentingViewController = self
let signingUrl = <signing-url> // the embedded signing url as retrived with client backend integration
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
                                                // use viewController as needed (e.g., force dismiss if client app need to exit DocuSign Signing Ceremony)
                                                ...
                                            }
```

This variant allows performing Captive Signing without user authentication, an additional method [DSMManager](https://github.com/docusign/native-ios-sdk/blob/master/DocuSignSDK.framework/Headers/DSMManager.h) allows, optionally, to remove all DocuSign related cookies generated in a signing ceremony with `clearAllWebCookies` after each signing session.

```
/*!
@method clearAllWebCookies
@abstract clear/clean all DocuSign-related cookies generated in the online signing ceremony. This method gives explicit control to clean cookies after each signing session.
*/
+ (void)clearAllWebCookies;
```

## Processing Events and Handling Errors

Native iOS SDK handles the redirection and dismisses the signing ceremony to return control to the client-app when it's successfully completed. In case of presentation errors with the Signing session launch, `completion` block would return an `error` with failure reason. Client app may dismiss the `presentedController` to discard the Signing in progress at any time to regain control. 

SDK utilizes [notifications](https://github.com/docusign/native-ios-sdk/blob/master/DocuSignSDK.framework/Headers/DSMNotificationCodes.h) to relay information related to errors and events. Client apps may register for various notifications, such as `DSMEnvelopeSyncingSucceededNotification`, to receive the details on various stages of Signing. Notification object with `userInfo` contains `envelopeId` and other relevant information. Relevant notifications for Online Signing and SDK events can be found in the ([header file](https://github.com/docusign/native-ios-sdk/blob/master/DocuSignSDK.framework/Headers/DSMNotificationCodes.h)). Some of the important notifications are:
- `DSMSigningCompletedNotification`
- `DSMSigningCancelledNotification`

Here a view is registering and handling signing notifications. On signing completed, in case of Captive Signing with `recipientURL`, `clearAllWebCookies` is used for additional control.

```      
override func viewDidLoad() {
   super.viewDidLoad()

   NotificationCenter.default.addObserver(self, selector: #selector(onSigningCompleted(_:)), name: NSNotification.Name(rawValue: "DSMSigningCompletedNotification"), object: nil)

   NotificationCenter.default.addObserver(self, selector: #selector(onSigningCancelled(_:)), name: NSNotification.Name(rawValue: "DSMSigningCancelledNotification"), object: nil)        
}

@objc func onSigningCompleted(_ notification:Notification) {
   // Handle the notification
   guard let envelopeId = notification.userInfo?[DSMEnvelopeIdKey] as? String else {
      // log the envelopeId for signing completed event
      ...
      DSMManager.clearAllWebCookies()
   }
   ...
}

@objc func onSigningCancelled(_ notification:Notification) { ... }
```

### Notification `userInfo` Keys & Signing event details

- `DSMEnvelopeIdKey` is added to `userInfo` with any of the Online Signing notifications.
- `DSMAdditionalInfo` is added to `userInfo` when the user views a completed document and exits Signing.
- `DSMErrorKey` is added to `userInfo` when Signing encounters an error. In the case of Embedded Signing, for example, it would contain an API returned error when `get /envelopes/{envelopeId}/receipients` fails.
- `DSMSigningExitReasonKey` is added to `userInfo` when signer decides to `decline` or `cancel` using `Finish Later`. The value contains `cancel` or `decline`.
- `DSMSigningModeKey` is added to `userInfo` with all of the Signing Notifications. In the case of Embedded Signing, `online` is the defined value for it.
- `DSMNotificationCodes` contains more details on [Notification Keys](https://github.com/docusign/native-ios-sdk/blob/master/DocuSignSDK.framework/Headers/DSMNotificationCodes.h#L129).

## Additional Resources

- [Embedded Signing](https://developers.docusign.com/docs/esign-rest-api/how-to/request-signature-in-app-embedded/)

- [Native iOS SDK](https://github.com/docusign/native-ios-sdk)

- [Native Android SDK](https://github.com/docusign/mobile-android-sdk) 

- [Requesting Embedded Signature in App](https://developers.docusign.com/docs/esign-rest-api/how-to/request-signature-in-app-embedded/)
