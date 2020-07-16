
# Troubleshooting DocuSignSDK Integration issues

## 1. Bitcode

### DocuSignSDK does not contain bitcode

```
{
  Apple XCode build error: '/Users/appName.Apps/Pods/DocuSign/DocuSignSDK.framework/DocuSignSDK' does not contain bitcode. You must rebuild it with bitcode enabled (Xcode setting ENABLE_BITCODE), obtain an updated library from the vendor, or disable bitcode for this target. file '/Users/appName.Apps/Pods/DocuSign/DocuSignSDK.framework/DocuSignSDK' for architecture armv7
}
```

Native SDK as of `v2.3.4` does not support bitcode, if your integration is dependent on **Bitcode**, do raise an [issue](https://github.com/docusign/native-ios-sdk/issues). The workaround for now is to have all app targets build without bitcode. In order to disable bitcode, client app would need to set `Enable Bitcode` under `Build Options` to `No` for each of the targets.

![Disable Bitcode for App Targets - Screenshot](disable-bitcode-app-targets.png)

## 2. Undefined Symbols

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
* Clean CocoaPods `DocuSign` pods in cache with `pod cache clean 'DocuSign' --all`
* Make sure `Podfile` has a correct entry, for example:
  * `pod 'DocuSign'` or
  * `pod 'DocuSign', :git => 'https://github.com/docusign/native-ios-sdk.git', :branch => "release/2.3.4"`
    * In case you are using specific branch to fetch `DocuSign` pod, additional steps to install [git-lfs](https://git-lfs.github.com/) are required as `pod install` fetches binary framework (>100MB file) via git-lfs hooks.
    * Install git-lfs via brew: `brew install git-lfs`
    * Activate git-lfs next: `git lfs install`
* `pod install` or `pod install --repo-update` 
* Ensure `DocuSignSDK.framework/DocuSignSDK` binary file is available and is around `~105MB`, If yes, open workspace and build. Report an issue if problem still persists.
