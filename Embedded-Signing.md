
# DocuSign iOS SDK - Embedded Signing

## Embedded Signing

[Embedded Signing](https://developers.docusign.com/docs/esign-rest-api/esign101/concepts/embedding/) enables users to view and sign documents within the app using generated signing URLs for each of the envelope. To present the signing request in the app UI, the logged in SDK user must be the document sender and have access to the sent envelope to retrieve the signing URL. Additional details are available on [eSign guide for Embedded Signing](https://developers.docusign.com/docs/esign-rest-api/esign101/concepts/embedding/). 

### A. User Authentication 

[DSMManager](https://github.com/docusign/native-ios-sdk/blob/master/DocuSignSDK.framework/Headers/DSMManager.h) has multiple ways to login with SDK, the following method is the recommended interface to use.

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

### B. Retriving signing URL and presenting signing request 

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

### D. Redirecting the User

Native iOS SDK handles the redirection and dismisses the signing ceremony to return control to the client-app.

#### **Tracking Events**

Client apps may register for various notification, such as `DSMEnvelopeSyncingSucceededNotification`, to receive the details on various stages of signing. Notification object with `userInfo` contains `envelopeId` and other relevant information. Other relevant notifications for Online Signing and SDK events can be found in the ([header file](https://github.com/docusign/native-ios-sdk/blob/master/DocuSignSDK.framework/Headers/DSMNotificationCodes.h)). Some of the important notifications are:
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

        }
        ...
    }
```