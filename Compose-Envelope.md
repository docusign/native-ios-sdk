
# DocuSign iOS SDK Compose Envelope

## V1 Compose Envelope - using EnvelopeDefinition [Beta-3]

### Changes in Beta-3

- Compose Envelope: updated Builders for Tabs, Recipient & Document to receive strings for recipientId, tabId, documentId instead of Number.
- Xamarin Specific: Fix for missing SignTab -- now tabs are rendered same as a native app.
- Xamarin Specific: Known issue with Signature adoption, on-going investigation.
- Xamarin Specific: Known issue with existing betas -- `LoginWith...:` methods on the `DSMManager` returns error related to keychain data persistence & fetch operations. For now, as a work around, ignore the error as it doesn't affect the sdk functionality significantly (e.g. initialize compose envelope, sign offline envelopes, etc). Planned fix for persistence & fetch keychain is for another beta release at a later date.

### Using EnvelopeBuilder & Resuming composed envelope

[DSMEnvelopeBuilder](/DocuSignSDK.framework/Headers/DSMEnvelopeBuilder.h) allows adding Signers, PDF-documents and Tabs among other customizable options to compose an envelope definition object and cache it with [DSMEnvelopeManager](/DocuSignSDK.framework/Headers/DSMEnvelopesManager.h). Afterwards, envelope definition object can be used to directly launch signing ceremony in offline mode using `resumeSigningEnvelopeWithPresentingController:...` method on [DSMEnvelopeManager](/DocuSignSDK.framework/Headers/DSMEnvelopesManager.h). This new flow to compose and resume envelope allows client apps to skip the [DocuSign SDK UI components](#v1-compose-envelope---ui-components) entirely to get documents signed with preassigned tabs and provides an alternative to using Compose-UI or using [Envelope Templates](/DocuSignSDK.framework/Headers/DSMTemplatesManager.h).

#### Compose EnvelopeDefinition

[DSMEnvelopesManager](DocuSignSDK.framework/Headers/DSMEnvelopesManager.h) has the following interface defined that takes an `DSMEnvelopeDefinition` object to launch signing.

```
/*!
 * @discussion Creates an envelope programmatically using DSMEnvelopeBuilder.
 * @param signingMode compose envelope in either online or offline mode, see DSMSigningMode
 * @param completion completion block to be executed after envelope is successfully created.
 * @warning passing nil to a presentationController will not be able to load the offline envelope flow.
 * @see DSMEnvelopeBuilder
 */
- (void)composeEnvelopeWithEnvelopeDefinition:(DSMEnvelopeDefinition *)envelope
                                  signingMode:(DSMSigningMode)signingMode
                                   completion:(nullable void(^)(NSString *_Nullable envelopeId, NSError *error))completion;
```

#### Load Signing

Once the envelope has been composed and saved on the local device, resume envelope interface can be used to start the signing ceremony for local signers.

```
/*!
 * @discussion Resume signing with a cached envelope. This call can be made when device is offline.
 * @param presentingController controller will be presented on top of the given presentingController passed.
 * @param envelopeId An Id of the envelope to be resumed.
 * @param completion completion block to be executed after envelope signing has been resumed.
 */
- (void)resumeSigningEnvelopeWithPresentingController:(UIViewController *)presentingController
                                           envelopeId:(NSString *)envelopeId
                                           completion:(void(^)(UIViewController *_Nullable presentedController, NSError *_Nullable error))completion;
```

#### Syncing Signed Envelopes with DocuSign Server

Finally, once the signing is complete the signed envelope is cached on device. The cached envelopes can be synced with `syncEnvelopes` method on `DSMEnvelopesManager`. 

**Note:** *Offline Signing* account feature must be enabled to perform Sync successfully. Please connect [**DocuSign Support**](https://support.docusign.com/en/home) in order to get *Offline Signing* enabled. 

```
/*!
 * @discussion Sync the pending envelopes on the device to create remote envelopes.
 * An envelope can be in pending Sync state when
 * a) created envelope's local InPersonSigner(s) or self-Signer have finished signing,
 *   and either has no pending local InPersonSigner(s) or only has pending remote
 *   signer(s) in next signing order.
 * b) created envelope only has pending remote signer(s) in next signing order.
 * @use When device is online and there has been sign and send Offline and pending sync to server.
 * @use Data validation or extraction for an offline completed envelope should be done before invoking the sync. Once an envelope is successfully synced, it's deleted from the cache on the device.
 * @discussion Relevant Notifications that can be used to track the progress of an envelope sync task: DSMEnvelopeSyncingStartedNotification, DSMEnvelopeSyncingSucceededNotification, DSMEnvelopeSyncingEndedNotification, DSMEnvelopeSyncingFailedNotification.
 * @see DSMNotificationCodes
 */
- (void)syncEnvelopes;
```

#### Tracking Events

Client apps may register for various notification, such as `DSMEnvelopeSyncingSucceededNotification`, to receive the details on various stages of signing & envelope syncing. Notification object with `userInfo` contains `envelopeId` of synced document on server. It’s recommended to implement other relevant notifications ([header file](https://github.com/docusign/native-ios-sdk/blob/master/DocuSignSDK.framework/Headers/DSMNotificationCodes.h)) to capture and log details. Take a look at header file for the important notifications to achieve desired results, some are:
- `DSMSigningCompletedNotification`
- `DSMSigningCancelledNotification`
- `DSMEnvelopeSyncingFailedNotification`

An example of another notification `DSMEnvelopeCachedNotification` from the [header file](https://github.com/docusign/native-ios-sdk/blob/master/DocuSignSDK.framework/Headers/DSMNotificationCodes.h).

```
/*!
 * @brief Notification sent when caching is enabled for a given record (envelope).
 * @discussion Returned userInfo contains envelopeId associated with DSMEnvelopeIdKey, templateId associated with DSMTemplateIdKey. This can be posted on a thread other than MainThread.
 * [[NSNotificationCenter defaultCenter] postNotificationName:DSMEnvelopeCachedNotification object:nil userInfo:userInfo];
 * Note: Enabling setup configuration `DSM_SETUP_ENABLE_OFFLINE_SIGNING_SAVE_ENVELOPE_PROGRESS_KEY` would result in this notification being sent every time a local offline envelope is saved after local signer finishes signing.
 */
extern NSString * const DSMEnvelopeCachedNotification;
```

### Customizing DSMEnvelopeDefinition: Adding Signers, PDFs and Tabs using Builders

The newly exposed interface in [DSMEnvelopesManager](DocuSignSDK.framework/Headers/DSMEnvelopesManager.h) uses `DSMEnvelopeBuilder` to customize the envelope definition. Commonly used builders with [`DSMEnvelopeBuilder`](DocuSignSDK.framework/Headers/DSMEnvelopeBuilder.h) are `DSMDocumentBuilder`, `DSMTabBuilder`, `DSMRecipientBuilder`, `DSMTextCustomFieldBuilder` and `DSMListCustomFieldBuilder`. 

Here are some of the snippets that can be used to compose the `DSMEnvelopeDefinition`.

```
// Create a envelope with email and message
DSMEnvelopeDefinition *envelope = [[[[DSMEnvelopeBuilder builder]
                                          addEmailSubject: @"DocuSign: NDA.pdf"]
                                          addEmailMessage: @"Hi Jane Wood, I'm sending you an NDA to sign and return, ...."]
                                        build];

// Create a document with pdf file and assign a name and id
DSMEnvelopeDocument *document = [[[[[DSMDocumentBuilder builder]
                                          addName: @"NDADocument"]
                                          addDocumentId: "doc1"]
                                          addFilePath: [[NSBundle mainBundle] pathForResource: @"NDA" ofType: @"pdf"]] 
                                        build];

// Create an envelope recipient with name and email and assign an id and type with routing order
DSMEnvelopeRecipient *recipient = [[[[[[DSMRecipientBuilder builderForType: DSMRecipientTypeSigner]
                                          addRecipientId: @"FirstRecipient"]
                                          addSignerName: @"Jane Wood"]
                                          addSignerEmail: @"JaneWood@docusign.com"]
                                          addRoutingOrder: 1] 
                                        build];

// Create a signature tab at a given position on a document page
DSMEnvelopeTab *signTab = [[[[[[[DSMTabBuilder builderForType: DSMTabTypeSignHere]
                                                          addName: @"Signature"]
                                                          addRecipientId: @"FirstRecipient"]
                                                          addDocumentId: "doc1"]
                                                          addFrame: CGRectMake(100, 300, 40, 50)]
                                                          addPageNumber: 1
                                                  ] build]

// Create a text based tab at a given postion on a document page
DSMEnvelopeTab *nameTab = [[[[[[[DSMTabBuilder builderForType:DSMTabTypeText]
                                          addName: @"Name"]
                                          addRecipientId: @"FirstRecipient"]
                                          addFrame: CGRectMake(100, 200, 120, 30)]
                                          addDocumentId: "doc1"]
                                          addPageNumber: 1] 
                                        build];

// Alternatively, all these could be chained with multiple builders.
@try {
  DSMEnvelopeDefinition *envelope = [[[[[[[DSMEnvelopeBuilder builder]
                      addEnvelopeName: @"DocuSign NDA"]
                      addEmailSubject: @"DocuSign: NDA.pdf"]
                      addEmailMessage: @"Hi Jane Wood, I'm sending you an NDA to sign and return, ...."]
                      addRecipient:[[[[[[DSMRecipientBuilder builderForType: DSMRecipientTypeSigner]
                                          addRecipientId: @"FirstRecipient"]
                                          addSignerName: @"Jane Wood"]
                                          addSignerEmail: @"JaneWood@docusign.com"]
                                          addTab: [[[[[[[DSMTabBuilder builderForType: DSMTabTypeSignHere]
                                                          addName: @"Signature"]
                                                          addRecipientId: @"FirstRecipient"]
                                                          addDocumentId: "doc1"]
                                                          addFrame: CGRectMake(100, 300, 40, 50)]
                                                          addPageNumber: 1
                                                  ] build]
                                    ] build]] 
                      addDocument:[[[[[DSMDocumentBuilder builder]
                                          addName: @"NDADocument"]
                                          addDocumentId: "doc1"]
                                          addFilePath: [[NSBundle bundleForClass: [self class]] pathForResource: @"NDA" ofType: @"pdf"]
                                  ] build]
                ] build];
  if (envelope) {
    // Compose the envelope to automatically cache it
    [self.envelopesManager composeEnvelopeWithEnvelopeDefinition: envelope
                              signingMode: DSMSigningModeOffline
                              completion: ^(NSString * _Nullable envelopeId, NSError * _Nonnull error) {
                                    // error checks in case envelope compose failed. Also use notifications for caching related events.
                                    if (error) { ... }

                                    // Resume the envelope to start the signing process
                                    [self.envelopesManager resumeSigningEnvelopeWithPresentingController: self
                                            envelopeId: envelopeId
                                            completion: ^(UIViewController * _Nullable presentedController, NSError * _Nullable error) {
                                        // error checks in case UI presentation failed. Use notifications for other events.
                                        if (error) { ... }
                                    }];                                
                                }
    ];
  }
} @catch (NSException *exception) {
  // Handle exception
}
```

Note: This interface can change in the final `v2.4` release.



## V1 Compose Envelope - UI Components

The Compose Envelope flow allows user the ability to create an envelope (adding documents, recipients, and tags) without previously downloading any templates, both online or offline where behaviour will differentiate the two after an envelope has been created.

The client app is responsible for detecting when network connectivity is available, require a user to be logged in, and present the appropriate flow. To do this, invoke the following method in ` DSMEnvelopesManager.h`.

```
/*!
* @discussion Start creating an envelope to manually add documents, recipients and tags. Client app is responsible for detecting network to present appropriate online/offline flow.
* @param presentingController controller will be presented on top of the given presentingController passed.
* @param signingMode compose envelope in either online or offline mode, see DSMSigningMode
* @param resumeWithDraft determines whether to initialize flow with a previously saved draft (if any)
* @param animated if the presentation of sign and send be animated or not.
* @param completion completion block to be executed after compose envelope controller is presented
* @warning passing nil to a presentationController will not be able to load the offline envelope flow.
* @discussion Relevant Notifications that can be used to track the progress of an envelope sync task: DSMOnlineEnvelopeSendFailedNotification.
* @see DSMNotificationCodes
*/
- (void)presentComposeEnvelopeControllerWithPresentingController:(UIViewController *)presentingController
                                                     signingMode:(DSMSigningMode)signingMode
                                                 resumeWithDraft:(BOOL)resumeWithDraft
                                                        animated:(BOOL)animated
                                                      completion:(void(^)(UIViewController *viewController))completion;
```                                                      

If `resumeWithDraft` is set to `false`, the previously cached draft envelope, if any, will be removed. 
You are able to determine whether there is a previously cached draft envelope (there can only be one at a time) by invoking:

```
/*!
* @discussion Returns whether there is a current cached envelope in draft status. Once an envelope is successfully synced, it's deleted from the cache on the device. This can be used to determine whether presenting compose envelope flow should be resumed with the draft envelope. There can only be one draft cached envelope at a given time.
* @return BOOL, true if there is a cached draft envelope
*/
- (BOOL)hasCachedDraftEnvelope;
```

### Requirements
----------------------
- the setup constant `DSM_SETUP_ICLOUD_DOCUMENT_ENABLED` must be set to `DSM_SETUP_TRUE_VALUE` in order for document selection to work. Depending the iOS version, the following must also be done:
- For iOS10 and below, iCloud entitlement must be added along with iCloud documents in order for document selection to work
- For iOS11+, the Compose Envelope flow requires the use of the Files app (to select documents on the device, iCloud, or other third-party apps) and will work without any further configuration
