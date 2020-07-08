## Telemetry Details

Release `v2.3.2` includes the addition of telemetry to track SDK events on the app side, such as starting signing and any of the errors that result during different phases. Telemetry is turned on by default and will help DocuSign debug any issues that may arise, but should you prefer to disable this you may set the `DSM_SETUP_ENABLE_TELEMETRY` flag to `false` when passing in the configuration flags to our SDK’s `DSMManager.setupWithConfiguration()` method

Following are the **telemetry events** (and associated **event-specific properties** listed in parentheses) that are now tracked via DocuSign Native iOS SDK:
 
* SDK authentication (success or failure, error reason if any)
* Signing ceremony started (DocuSign account ID, DocuSign envelope ID)
* Error during signing (error reason)
* HTML link tapped during signing (link URL)
* Online signing native component displayed (component such as native consumer disclosure, native signing palette, native signer selection, etc.)
* Signer / host finished signing (success or failure, error reason if any, DocuSign account ID, DocuSign envelope ID, DocuSign recipient ID)
* Signer / host cancelled signing (DocuSign account ID, DocuSign envelope ID, DocuSign recipient ID, cancelled by discard or save action)
 
For each of these events, Telemetry manager also include the following properties:
 
* Device connectivity (online / offline)
* Device network mode (e.g. WiFi)
* Device type (iPhone / iPad)
* iOS version
* DocuSign Native iOS SDK version
* DocuSign account ID
* DocuSign account name
* Timestamp
 
Note: These events are only sent to DocuSign backend and are not shared with any third-parties outside of DocuSign.