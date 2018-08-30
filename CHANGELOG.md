# DocuSign Native iOS Offline Templates SDK ChangeLog

## [v1.2.0] - 8/30/2018

### Added
* Supports Radio Tabs with offline Signing.
* Recipients can be defaulted and switched from an InPersonSigner type to a RemoteSigner type and ViceVersa before initiating the offline signing ceremony with `DSMRecipientDefault`.
* Tab value defaulting for text based tabs for offline signing through `tabValueDefaults` .
* Account level Envelope Custom Fields are now supported and can be created with `DSMCustomFields` through `DSMEnvelopeDefaults`. 
* Setup configuration updated to hide alerts that are shown during offline signing. The Setup constants can be found in `DSMSetupConstants` .
* Supports Formula Fields in offline signing that are only based on Date Signed Tabs.
* Enhanced Signature Pad to capture signatures.

### Fixed 
* Enhanced visual representation of Tags when highlited.
* Captured Signature during Signing Ceremony to maintain aspect ratio.

## Deprecated
* The following method  ` presentSendTemplateControllerWithTemplateWithId:tabValueDefaults:pdfToInsert:insertAtPosition:signingMode:presentingController:animated:completion:`  on `DSMTemplatesManager` should be replaced by  ` presentSendTemplateControllerWithTemplateWithId:envelopeDefaults:pdfToInsert:insertAtPosition:signingMode:presentingController:animated:completion:`  .

## [v1.1] -  - 2/23/2018

### Fixed
* Updated Swift and Objective C Sample Apps.
* Error Validations on unsupported tab types.
* Dismiss KeyBoard after editing TextFields on Swift Sample App.


## [v1.0] -  - 9/15/2017

### Added
* DocuSign Native iOS Offline Templates SDK Launch

