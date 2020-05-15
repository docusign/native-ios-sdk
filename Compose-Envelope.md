
# DocuSign iOS SDK Compose Envelope

## V1 Compose Envelope

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
