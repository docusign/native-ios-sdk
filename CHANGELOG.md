# DocuSign Native iOS SDK Changelog

## [v3.5.0] - 01/06/2025

### Added
* SPM Support - Use version 3.5.0 and refer to instructions on [SwiftPackageManager.md](https://github.com/docusign/native-ios-sdk/blob/master/SwiftPackageManager.md).
* Xcode 16 support.

### Changed
* Updated some DSAPI Models to combine common properties for Recipients and Tabs.
* Updated Contacts fetch to retrieve Phone numbers in addition to email.

## [v3.4.0] - 09/20/2024

### Fixed
* Authorization issue that prevented some of the network calls to be successfully completed with DocusignAPI SDK.
* Network calls with boolean parameters on DocusignAPI SDK interface now allows nil values as well. With earlier versions, these parameters were sent as either default true or false.
* Optional Sign and Initial tabs show the dependent tabs correctly when used with conditional setup.

### Changed
* Templates with multichannel (SMS, Whatsapp) delivery recipients are currently blocked. Reach out to customer support or raise an issue on Github if you need this supported.
* Outdated fonts replaced with modern assets.

## [v3.3.0] - 04/11/2024
### Changed
* Branding update.

## [v3.2.0] - 01/25/2024
### Added
* Support for Sending online Templates with Signing Groups.
* Support Xcode 15 Requirements for Signing Certification and Privacy Manifest.
* Support for Conditional Tabs for offline downloaded envelopes.
* Added Configuration `DSM_SETUP_DISABLE_APPEARANCE` to Disable Applying Appearance changes Automatically on SDK setup [Issue #130](https://github.com/docusign/native-ios-sdk/issues/130)

### Fixed
* Fixes in Request layer and API calls setup.

## [v3.1.0] - 06/14/2023
### Added
* *(iOS 12+)* Support for OAuthLogin with helper functions for Authentication to DocuSign. If you use oAuth no need to create your own Authentication browser you can simply call `loginWithOAuthEnv` and pass the needed params to authenticate to DocuSignSDK.

### Changed
* Added two new parameters *Optional* to `loginWithAccessToken` method for `refreshToken` and `expiresIn` in case of oAuth happening from Host App side.
* Prep work for spinning off DocuSignAPI as a separate Pod.

### Removed
* Legacy Libraries (KeyChain)

## [v3.0.5] - 05/15/2023
### Added
* [Conditional Tabs](https://developers.docusign.com/docs/esign-rest-api/esign101/concepts/tabs/conditional-fields/) are now supported for Templates and envelopes created locally (Envelopes downloaded from remote server are not supported yet)

### Changed
* During Offline Signing, `Sign Later` is now preferred option to be shown for all envelopes created on device using documents or templates. `Discard Progress` option is now deprecated.

### Fixed
* Checkbox group validation has been updated to resolve [issue #145](https://github.com/docusign/native-ios-sdk/issues/145).

## [v3.0.4] - 03/24/2023
### Added
* Allow sending online envelopes with templates that have recipients with SBS (Standard Based Signature) by default.
* New setup configuration `DSM_SETUP_DISABLE_STANDARD_BASED_SIGNATURE` to disable template sends that have SBS.

### Fixed
* Fix issue with Resuming envelopes created offline Issue #143

## [v3.0.3] - 02/08/2023
### Added
* Support to Paper signing through Fax flow with a new Signing Exit Notification reason `DSMSigningExitReasonFaxPending`

### Fixed
* Issue with Templates to disable templates with SBS recipients

## [v3.0.2] - 12/11/2022
### Fixed
* Fix Bug for Envelope resume after saving Issue 137( https://github.com/docusign/native-ios-sdk/issues/137)


## [v3.0.1] - 11/22/2022
### Added
* Checkbox tab and groups are supported with the DSMEnvelopeDefaults. Use `true` and `false` with checkbox `tabLabel` i.e. `Data Label` to set the default value.
* Radio tab and groups are supported with the `DSMEnvelopeDefaults`. Use `true` and `false` with radio `tabValue` i.e. `Radio Button Values`, a difference when compared to `Checkbox`, to set the default value.
### Fixed
* Bug fixes and enhancements related to offline & online signing for Tab Groups & other features.

## [v3.0.0] - 11/01/2022
### Added
* New REST ESignature APIs added all in Swift
* Support for Envelope Caching
* Support for Template Search and filtering
* Support for new Signature pallet

## [v2.12] - 08/18/2022

### Added
* New setup configuration key `DSM_SETUP_DISABLE_CUSTOMFIELD_DOCUSIGNIT` to control Custom tab `AppName=DocuSignIt` from being sent with all envelopes. The default of this config is `False`. Enabling it with `True` will only send this custom tab with Sign and Return envelopes. A Sign and Return envelope has a Signer (not a host or in-person-signer) with email that is the same as the Sender email.

### Fixed
* Radio Buttons and tabs in general were not maintaining `value` attribute offline, now it can be used to identify tabs.

## [v2.11] - 06/07/2022

### Fixed
* Radio tabs during offline signing processes the `locked` and `selected` attributes correctly.

## [v2.10.1] - 04/04/2022

### Fixed
* DocuSign telemetry improvements with a resolved issue related to reporting events.

## [v2.10.0] - 03/23/2022

_Now DocuSign XCFramework is built with Xcode13.3._

### Fixed
* Offline envelope sending is now blocked if no tabs are added to any of the recipients.
* Turn off location prompt when signing is in progress. Removed the associated configuration `DSM_SETUP_CAPTIVE_SIGNING_DISABLE_LOCATION_PERMISSION`. Refer the online guide to [disable location tracking](https://support.docusign.com/en/articles/Disabling-DocuSign-Geolocation-during-Signing) during Signing.

## [v2.9.0] - 02/15/2022

### Added
* DocuSign Native iOS SDK supports Bitcode.

### Removed
* Removed the `DSMAppearance` method to set navigation bar tint color separately `+ (void)setNavigationBarTintColor:(UIColor *)color;`.

### Changed
* Added `backgroundTintColor` and `fontSize` as additional parameters to set navigation bar text attributes with `DSMAppearance`. The updated method is `+ (void)setNavigationBarTitleTextColor:(UIColor *)textColor backgroundTintColor:(UIColor *)backgroundTintColor fontSize:(CGFloat)fontSize;`.

## [v2.8.0] - 01/05/2022

### Added
* DocuSign-ESign REST API endpoints are now available to use with Native-iOS-SDK. DocuSign-ESign (`DSES*`) interface exposes functionality in addition to the regular DocuSign-Mobile (`DSM*`) classes. Newly added headers are part of `DocuSignSDK.framework/Headers/DSES*.h` files and could be used with `DSESApiClient` and corresponding API service (e.g. `DSESAccountsApi`).

## [v2.7.0] - 11/18/2021

### Fixed
* Fix Issue with RadioGroupTabs https://github.com/docusign/native-ios-sdk/issues/103
* Fix Locale Name for Greek
* Fix issue with UIViewController Initialization for iOS 15

## [v2.6.0] - 11/03/2021

### Fixed
* Fixes related to background tasks on embedded-signing.

### Removed
* Removed legacy auth methods in `DSMManager`. The deprecated methods are `loginWithEmail:password:integratorKey:host:completion` and `loginWithApiPassword:accountId:userId:username:email:host:integratorKey:completion`.

## [v2.5.3] - 09/09/2021

### Added
* New interface to launch captive signing using recipient view url with `presentCaptiveSigningWithPresentingController:signingUrl:envelopeId:recipientId:animated:completion:` in `DSMEnvelopesManager`.
* New interface to clear web cookies `clearAllWebCookies` on `DSMManager`.
* New setup configuration `DSM_SETUP_CAPTIVE_SIGNING_DISABLE_LOCATION_PERMISSION` to disable location tracking during captive signing.

### Fixed
* Fixes related to embedded-signing session time out. When session times out during Captive Signing with Url, `DSMSigningCancelledNotification` Notification is now sent with additional parameter associated with `exitReason` key in `userInfo`.
* Fixed `DSMDocumentBuilderException` that is caused when a filePath is passed to `DSMDocumentBuilder`.

## [v2.5.2] - 06/15/2021

### Fixed
* IPA export no longer fails for certain conditions.

## [v2.5.1] - 06/14/2021

### Added
* Native-iOS-SDK is built with Xcode12.5 and now includes XCFramework as the primary framework for CocoaPods distribution.

### Fixed
* Online signing for failing envelopes returns signing-cancelled notification with `error` details in `userInfo`.

## [v2.5] - 05/12/2021

### Deprecated
* Deprecation for the legacy auth methods in `DSMManager`. The deprecated methods are `loginWithEmail:password:integratorKey:host:completion` and `loginWithApiPassword:accountId:userId:username:email:host:integratorKey:completion`.

### Fixed
* Fixes related to embedded-signing finish later. `DSMSigningCancelledNotification` Notification is now sent with additional parameter associated with `exitReason` key in `userInfo`.

## [v2.4.1] - 03/19/2021

### Changed
* Online Signing loading indicator is displayed by default for all signing sessions.

### Added
* New setup configuration `DSM_SETUP_HIDE_ONLINE_SIGNING_LOADING_INDICATOR_KEY` to allow client apps to hide the Online Signing loading spinner.

## [v2.4] - 03/05/2021

### Added
* New interface to create envelopes and start signing directly using [Compose Envelopes](Compose-Envelope.md) flow with `composeEnvelopeWithEnvelopeDefinition:signingMode:completion` in `DSMEnvelopesManager`.

## [v2.3.8] - 01/22/2021

### Added
* Support client apps to send responsive documents using templates for responsive signing. Such templates need to be configured to use responsive documents.
* New setup configuration `DSM_SETUP_ONLY_USE_COMPANY_NAME_WITH_CD` to allow client apps to customize Consumer Disclosures to use only company name.

## [v2.3.7] - 11/02/2020

### Added
* Additional SDK events and properties are captured and sent using DocuSign Telemetry API.

## [v2.3.6] - 10/15/2020

### Fixed
* Fixes related to tabs placement in the document.

## [v2.3.5] - 09/04/2020

### Added
* Embedded (Captive) Signing is now supported with  `presentCaptiveSigningWithPresentingController` via `DSMEnvelopesManager`. API reference available at [Embedded Signing](https://developers.docusign.com/esign-rest-api/guides/concepts/embedding).
* New setup configuration `DSM_SETUP_DISABLE_EMAIL_IPS_FIELD_CD` to allow client apps to hide the email field when the consumer disclosure screen is displayed.

### Fixed
* Bug fixes and enhancements.

## [v2.3.4] - 07/17/2020

### Added
* Now `fontSize` property on the text tabs is used during offline signing. Tab level, `fontSize` ranges from `size7` to `size72`.  

### Fixed
* Bug fixes and enhancements.

## [v2.3.3] - 07/08/2020

### Fixed
* Fix to allow Offline Signing to complete in single session for a resumed envelope with signers in later routing order.

## [v2.3.2] - 07/01/2020

### Added
* New setup configuration `DSM_SETUP_ENABLE_TELEMETRY` to configure client telemetry. When this configuration is enabled, SDK captures various events using DocuSign Telemetry API.

## [v2.3.1] - 06/08/2020

### Fixed
* Offline Signing Crash related to `NSInvalidArgumentException` with `[DSMPTNPDFViewController toolOverlayView]` on `v2.3`.

## [v2.3] - 05/29/2020

### Added
* New setup configuration `DSM_SETUP_ONLINE_SIGNING_DISABLE_NATIVE_COMPONENTS` to disable the native components such as SignatureAdoption, ConsumerDisclosure during Online Signing. When native components are disabled, online web signing components are used instead.
* Ability to online sign a remote envelope that has been sent to get signatures using `+[DSMEnvelopesManager presentSigningWithPresentingController:envelopeId:animated:completion]`.

### Changed
* Native iOS SDK is built with Xcode 11.5

## [v2.2.5] - 04/03/2020

### Fixed
* Replaced deprecated instances of UIWebView with WKWebView in settings storyboard.

## [v2.2.4] - 03/20/2020

### Fixed
* Replaced deprecated instances of UIWebView with WKWebView.

## [v2.2.3] - 02/11/2020

### Added
* Ability to save signing session of an offline envelop locally on a device and ability to resume signing progress for the saved envelope at a later time. `DSMEnvelopesManager` allows presenting an offline signing session with a previously saved envelope on same device using `+[DSMEnvelopesManager resumeSigningEnvelopeWithPresentingController:envelopeId:completion`.
* New setup configuration `DSM_SETUP_ENABLE_OFFLINE_SIGNING_SAVE_ENVELOPE_PROGRESS_KEY` to enable the UI components to prompt users to save progress of an offline signed envelope to a device locally. If this configuration is enabled, by default it's disabled, `DSMEnvelopeCachedNotification` is sent whenever a local signer finishes signing session, this notification also contains the `envelopeId` that can be used later to resume signing progress of a saved envelope.
* Additional notification `DSMOfflineEnvelopeSaveErrorNotification` is sent if an envelope fails to save on device with error under `DSM_ENVELOPE_SAVE_ERROR` domain.
* Resuming a fully signed envelope, which is ready for sync, is not allowed and it results in a new error under `DSM_ENVELOPE_RESUME_ERROR` domain.

## [v2.2.2] - 01/30/2020

### Fixed
* Patch for App Store Connect error code `ERROR ITMS-90542` related to `Unexpected CFBundleSupportedPlatforms Key in Tools.Bundle/Info.plist` of a 3rd party library.

## [v2.2.1] - 01/28/2020

### Changed
* Native iOS SDK is built with Xcode 11.3

### Fixed
* Patch for App Store Connect error code `ERROR ITMS-90535` related to `Unexpected CFBundleExecutable Key in Tools.Bundle/Info.plist` of a 3rd party library.

## [v2.2] - 10/18/2019

### Changed
* Native iOS SDK is built with Xcode 11.1 and supports iOS13 & iPadOS.
* Dark Mode - The SDK UI Components uses light mode and overrides the dark mode.

### Fixed
* Signature adoption fix for iOS13 & iPadOS.

## [v2.1.6] - 10/03/2019

### Removed
* NetworkMode - Removed all instances of NetworkMode. Login methods have been updated to remove NetworkMode parameter.
* Login with userId - Class method for login with userId `+[DSMManager loginWithUserId:password:integratorKey:host:completion:]` has been removed in favor of login with email class method `+[DSMManager loginWithEmail:password:integratorKey:host:completion]`.
* Clear credentials and cached templates: Class method `+[DSMManager clearCredentialsAndCachedTemplates]` is removed in favour of `+[DSMManager logout]`.

### Added
* Login with email: Class method for login with email `+[DSMManager loginWithEmail:password:integratorKey:host:completion]`.
* Account Setup: Class method to fetch additional account data `+[DSMManager fetchSettingsWithAccountInfo:completion]`. This gets additional account data that includes consumer disclosure and various settings.
* Logout: Class method to perform user logout with credential and cache document deletion `+[DSMManager logout]`.
* Is Session Active: Class method to query if there is an active user authentication session `+[DSMManager isSessionActiveWithEmail:password:integratorKey:host]`.
* API Timeout: New setup configuration `DSM_SETUP_DEFAULT_API_TIMEOUT` to customize the API session timeout. Class method to query configured value of API timeout `+[DSMManager configuredValueForSetupKeyAPITimeout]`.
* Setup Constants: Constants to query API timeouts defined in `DSMSetupConstants header`. New constants: `DSM_SETUP_API_TIMEOUT_MIN_VALUE`, `DSM_SETUP_API_TIMEOUT_MAX_VALUE` and `DSM_SETUP_API_TIMEOUT_DEFAULT_VALUE`.

### Changed
* Login Session - Authentication sessions are cached and reused whenever applicable to reduce the API calls related to user login and account data persistence.
* Persistence - Improved keychain handling with the data persistence.
* Login with accessToken - Removed `networkMode` parameter from the class method `+[DSMManager loginWithAccessToken:accountId:userId:userName:email:host:integratorKey:networkMode:completion:]`. It's now changed to `+[DSMManager loginWithAccessToken:accountId:userId:userName:email:host:integratorKey:completion:]`.
* Login with apiPassword - Removed `networkMode` parameter from the class method `+[DSMManager loginWithApiPassword:accountId:userId:userName:email:host:integratorKey:networkMode:completion:]`. It's now changed to `+[DSMManager loginWithApiPassword:accountId:userId:userName:email:host:integratorKey:completion:]`.

## [v2.1.5] - 08/13/2019

### Added
* New setup configuration `DSM_SETUP_RECIPIENT_DEFAULTS_CASE_INSENSITIVELY_MATCH_ROLE_NAME` allows more flexible recipient matching based on case insensitive `roleName` comparasion in the templates. This can be used to override the default strict `roleName` match behaviour during application of recipient-default-values.
* New setup configuration `DSM_SETUP_TAB_DEFAULTS_COMPARISION` allows more flexible tab matching based on data-label comparasion during application of tab-default-values. `DSMTabComparision` enum values `DSMTabComparisionCaseAndDiacriticInsensitive` and `DSMTabComparisionContains` can be used to override the default `DSMTabComparisionStrictMatch` behaviour.

## [v2.1.4] - 07/22/2019

### Added
* Improved Next Field Navigation -  The initial navigation moves to the next empty required field. New setup configuration `DSM_SETUP_OFFLINE_SIGNING_NAVIGATE_BLANK_REQUIRED_FIELDS` to enable `Navigate blank required fields`.

### Changed
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
