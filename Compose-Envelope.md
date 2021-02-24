
# DocuSign iOS SDK Compose Envelope

## V1 Compose Envelope - Programmatically [Beta-3]

### Use envelope builder to supply Signers with PDFs and Tabs among with other customizable options to directly launch signing ceremony in offline mode. This method allows client app to skip the DocuSign SDK UI components to add PDFs, Signers and Tabs.

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

### How to customize DSMEnvelopeDefinition add Signers, PDFs and Tabs along with other details:

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
                                                          addDocumentId: @"doc1"]
                                                          addFrame: CGRectMake(100, 300, 40, 50)]
                                                          addPageNumber: 1
                                                  ] build]

// Create a text based tab at a given postion on a document page
DSMEnvelopeTab *nameTab = [[[[[[[DSMTabBuilder builderForType:DSMTabTypeText]
                                          addName: @"Name"]
                                          addRecipientId: @"FirstRecipient"]
                                          addFrame: CGRectMake(100, 200, 120, 30)]
                                          addDocumentId: @"doc1"]
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
                                                          addDocumentId: @"doc1"]
                                                          addFrame: CGRectMake(100, 300, 40, 50)]
                                                          addPageNumber: 1
                                                  ] build]
                                    ] build]] 
                      addDocument:[[[[[DSMDocumentBuilder builder]
                                          addName: @"NDADocument"]
                                          addDocumentId: @"doc1"]
                                          addFilePath: [[NSBundle bundleForClass: [self class]] pathForResource: @"NDA" ofType: @"pdf"]
                                  ] build]
                ] build];
  if (envelope) {
    // Compose the envelope to automatically cache it
    [self.envelopesManager composeEnvelopeWithEnvelopeDefinition: envelope
                              signingMode: DSMSigningModeOffline
                              completion: ^(NSString * _Nullable envelopeId, NSError * _Nonnull error) {
                                    // error checks
                                    if (error) { ... }

                                    // Resume the envelope to start the signing process
                                    [self.envelopesManager resumeSigningEnvelopeWithPresentingController: self
                                            envelopeId: envelopeId
                                            completion: ^(UIViewController * _Nullable presentedController, NSError * _Nullable error) {
                                        // Handle error
                                    }];                                
                                }
    ];
  }
} @catch (NSException *exception) {
  // Handle exception
}
```
Note: The beta interface can change in the final `v2.4` release.

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
