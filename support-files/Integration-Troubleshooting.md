
# Troubleshooting DocuSignSDK Integration issues

## Undefined Symbols

### Error when building project:

* Undefined symbol:
  * `_OBJC_CLASS_$_DSMEnvelopesManager`, 
  * `_OBJC_CLASS_$_DSMManager`, 
  * `_DSM_SETUP_TRUE_VALUE` and other similar symbols missing

![Undefined symbol in DocuSignSDK build error - Screenshot](docusignsdk-undefined-symbol.png)

### Root cause:

* Invalid binary file: `DocuSignSDK.framework/DocuSignSDK`
  * In projects with symbol missing issue, `DocuSignSDK` binary file size is in a few KB.
  * `DocuSignSDK` binary file under the framework directory isn't getting fetched correctly via the CocoaPods `pod install`. Correct `DocuSignSDK` binary is over 100MB, for example, the correct binary size as of `v2.2.5` is `105.8MB`. 

![Valid DocuSign SDK binary file - Screenshot](docusignsdk-binary-via-pods.png)

### Fix: Ensure Client is fetching DocuSignSDK Binary

* Close Xcode
* Go to the solution directory and perform `pod deintegrate` to uninitialize the pods.
* Remove pods & lock file with `rm Podfile.lock` & `rm -rf Pods/`
* Make sure `Podfile` has a correct entry for the beta branch, e.g.:
  * pod 'DocuSign', :git => 'https://github.com/docusign/native-ios-sdk.git', :branch => "beta/responsive-online-signing"
* `pod install` or `pod install --repo-update`
* Ensure `DocuSignSDK.framework/DocuSignSDK` binary file is available and is around `~105MB`
* Open workspace and build
