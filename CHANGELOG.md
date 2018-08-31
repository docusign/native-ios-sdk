# DocuSign Native iOS Offline Templates SDK Changelog

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
* DocuSign Native iOS Offline Templates SDK launch.
