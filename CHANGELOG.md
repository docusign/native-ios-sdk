# DocuSign Native iOS SDK Changelog

## [v2.1.4] - 07/22/2019

### Changed
* Improved Next Field Navigation -  The initial navigation moves to the next empty required field. New setup configuration. `DSM_SETUP_OFFLINE_SIGNING_NAVIGATE_BLANK_REQUIRED_FIELDS` to enable `Navigate blank required fields`.
* Enhanced client logging - Verbose error logging for ‘login, persistence, & sync’ related methods.
* Responsive signing is disabled for DocuSign SDK.

## [v2.1.3] - 05/17/2019

### Added
* New setup configuration `DSM_SETUP_OFFLINE_SIGNING_USE_PLACEHOLDER_TAB_VALUE` exposed to allow replacing placeholder values for empty text-based tabs (for example "Text", "Company", "Title", etc) with empty strings during offline signing.

### Changed
* `Next Field Navigation` ignores the non-editable text tabs in all cases and keeps the previous assigned tab value unchanged. (bug-fix)
* DocuSign branding update for Momentum 2019

## [v2.1.2] - 04/18/2019

### Added
* `TransactionId` is sent in addition with `EnvelopeId` and `TemplateId` with notifications to help track templates and corresponding envelopes.
* Ability to track and link the offline & corresponding online envelope using `TransactionId` for updated `EnvelopeId` upon successful sync.

### Changed
* `Consumer Disclosure` is dismissed in all cases; earlier misconfigured tabs in templates caused `Consumer Disclosure` to not get dismissed if error alerts were also hidden via setup configuration.

## [v2.1.1] - 03/12/2019

### Added
* *CocoaPods* support added for Native iOS SDK. Use `pod 'DocuSign'` to fetch the latest SDK framework. Note: Recommended to use CocoaPods `v1.4.0` and up.
* New notification `DSMOfflineEnvelopeSigningErrorNotification` added to track misc offline signing errors related to template setup (for example invalid formula used). 

## [v2.1] - 01/18/2019

### Added
* Three Properties such as `syncFailureReason(String)`, `failedAttemptsToSync (Integer)` and `lastModifiedDateTime` shall be updated on `DSMEnvelopeDefinition` when envelope fails to Sync (meta data to track envelopes & sync process).

## [v2.1] - 12/20/2018

### Added
* New notification `DSMFoundReadonlyAndRequiredTabsWithInvalidDefaultsNotification` is added to notify when Readonly AND Required AND nil-value Text based tabs are detected during envelope creation. Related configuration`DSM_SETUP_OFFLINE_SIGNING_CONVERT_INVALID_READONLY_REQUIRED_TEXTTABS_TO_EDITABLE` to auto-convert such tabs to non-Readonly is exposed, it's default value is `true` to allow signers to finish offline signing such envelopes.

### Changed
* `DSMTemplateIdKey` ("templateId") is sent in addition with `DSMEnvelopeIdKey` ("envelopeId") for some notifications.

## [v2.1] - 11/06/2018

### Added
* Support for `DSMAccountInfo` with all `login*` methods in the `DSMManager`. `DSMAccountInfo` object is retuned with the completion `completion:^(DSMAccountInfo *accountInfo, NSError *error)` for login methods exposed in `DSMManager`.

### Changed
* Method signatures for following `loginWith*` methods now include additional `networkMode` parameter and `completion:^(DSMAccountInfo *accountInfo, NSError *error)` has additional parameter `DSMAccountInfo *accountInfo`:
   - `loginWithUserId:password:integratorKey:host:completion:`
   - `loginWithAccessToken:accountId:userId:userName:email:host:integratorKey:networkMode:completion:`
   - `loginWithAPIPassword:accountId:userId:userName:email:host:integratorKey:networkMode:completion:`

## [v2.0] - 10/9/2018

### Added
* Support for compose envelope functionality for both online and offline capability. Start creating an envelope to manually add documents, recipients and tags using the method `presentComposeEnvelopeControllerWithPresentingController:signingMode:resumeWithDraft:animated:completion:` on `DSMEnvelopesManager`.                                              
* Utility method to determine whether there is a previously cached draft envelope (there can only be one at a time) by invoking `hasCachedDraftEnvelope` on `DSMEnvelopesManager`.
* Powered By DocuSign footer for online and offline signing ceremony. This feature can be enabled or disabled using setup configuration and the constants can be found in `DSMSetupConstants`.

### Changed
* Updated Swift and Objective-C Sample Apps.

## [v1.2] - 8/30/2018

### Added
* Support for radio tabs with offline signing.
* Recipient defaulting and switching from an InPersonSigner type to a RemoteSigner type and vice versa before initiating the offline signing ceremony with `DSMRecipientDefault`.
* Tab value defaulting for text-based tabs for offline signing through `tabValueDefaults`.
* Support for account-level envelope custom fields. They can be created with `DSMCustomFields` through `DSMEnvelopeDefaults`.
* Setup configuration for hiding alerts that are shown during offline signing. The setup constants can be found in `DSMSetupConstants`.
* Support for formula fields in offline signing that are only based on date signed tabs.

### Changed
* Updated signature drawing tools on signature pad

### Fixed
* Enhanced visual representation of tabs when highlighted.
* Maintain aspect ratio of captured signature during signing ceremony.

### Deprecated
* The method `presentSendTemplateControllerWithTemplateWithId:tabValueDefaults:pdfToInsert:insertAtPosition:signingMode:presentingController:animated:completion:` in `DSMTemplatesManager` should be replaced by  ` presentSendTemplateControllerWithTemplateWithId:envelopeDefaults:pdfToInsert:insertAtPosition:signingMode:presentingController:animated:completion:`.

## [v1.1] - 2/23/2018

### Changed
* Updated Swift and Objective-C Sample Apps.

### Fixed
* Error validations on unsupported tab types.
* Dismiss keyboard after editing text fields in Swift Sample App.


## [v1.0] - 9/15/2017

### Added
* DocuSign Native iOS SDK launch.
