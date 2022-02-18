
# Troubleshooting DocuSignSDK Integration issues

## 1. Bitcode

### Bitcode is supported with v2.9 onwards

Use DocuSign Native iOS SDK v2.9 or higher to enable Bitcode in your app.

Native SDK `v2.8` or prior does not support bitcode, if your integration is dependent on **Bitcode**, do update with `pod update 'DocuSign'` to fetch `v2.9` or higher.

Following error occurs with integrations that are using `v2.8` or prior releases.

```
{
  Apple XCode build error: '/Users/appName.Apps/Pods/DocuSign/DocuSignSDK.framework/DocuSignSDK' does not contain bitcode. You must rebuild it with bitcode enabled (Xcode setting ENABLE_BITCODE), obtain an updated library from the vendor, or disable bitcode for this target. file '/Users/appName.Apps/Pods/DocuSign/DocuSignSDK.framework/DocuSignSDK' for architecture armv7
}
```

## 2. Simulator Build fails for `arm64`

### Simulator Build error

* `ld: building for iOS Simulator, but linking in dylib built for iOS, file '.../Pods/DocuSign/DocuSignSDK.framework/DocuSignSDK' for architecture arm64`
* `ld: could not reparse object file in bundle: ‘Invalid version (Producer: ‘’ Reader: ‘’)’, using libLTO version ‘LLVM version 12.0.0, ()’ for architecture arm64` - specific to `Xcode12.4`.

This is a known issue that happens with Xcode12.4 and higher builds for `iphonesimulator*` and Apple Silicon (M1 chips) for SDK version `v2.5` and earlier.

![building for iOS Simulator Error - Screenshot](simulator-build-release-archieve-issue.png)

### Fix with SDK version `2.5.1`

This issue has been addressed with SDK `v2.5.1` release. Use `pod update 'DocuSign'` to upgrade the pod that contains *XCFramework* instead of *Binary Fat Framework*. `v2.5.1` is built with Xcode12.5 and supports both Apple Silicon & Intel hardware. Apps which are using older version of Xcode and not using *Modern Build System*, it's recommended to use `v2.5` or earlier versions to integrate with *Universal Binary* `DocuSignSDK.framework`. Projects which are using *Modern Build System* or shipping a SDK, it's recommended to utilize `v2.5.1` with Xcode12.5. 

## 3. Undefined Symbols

### Error when building project:

* Undefined symbol:
  * `_OBJC_CLASS_$_DSMEnvelopesManager`, 
  * `_OBJC_CLASS_$_DSMManager`, 
  * `_DSM_SETUP_TRUE_VALUE` and other similar symbols missing

![Undefined symbol in DocuSignSDK build error - Screenshot](docusignsdk-undefined-symbol.png)

### Root cause:

* Invalid binary file: `DocuSignSDK.framework/DocuSignSDK`. In projects with missing symbol issues, `DocuSignSDK` binary file size is in a few KB.
  * `v2.5` and earlier: `DocuSignSDK` binary file under the framework isn't getting fetched correctly via the CocoaPods `pod install`. Correct `DocuSignSDK` binary is over 100MB. For example, the correct binary size as of `v2.5` is `105.8MB`. 
  * `v2.5.1`: `DocuSignSDK` binary files are invalid for the XCFramework under the `Pods\` directory. 
    * Incorrect file size for `DocuSignSDK` binary in `DocuSignSDK.xcframework\ios-arm64_i386_x86_64-simulator\DocuSignSDK.framework\` or  `DocuSignSDK.xcframework\ios-arm64_armv7\DocuSignSDK.framework\`.

![Valid DocuSign SDK binary file - Screenshot](docusignsdk-binary-via-pods.png)

### Fix: Ensure Client is fetching DocuSignSDK Binary

1. Close Xcode
2. Go to the solution directory and perform `pod deintegrate` to uninitialize the pods.
3. Remove pods & lock file with `rm Podfile.lock` & `rm -rf Pods/`
4. Clean CocoaPods `DocuSign` pods in cache with `pod cache clean 'DocuSign' --all`
5. Make sure `Podfile` has a correct entry, for example:
  * `pod 'DocuSign'` or
  * Using Specific Commit: `pod 'DocuSign', :git => 'https://github.com/docusign/native-ios-sdk.git', :commit => "3ed4ed6985e44d12c99ae7a9f2b5bda66dd00b4d"`
  * Using Specific Branch: `pod 'DocuSign', :git => 'https://github.com/docusign/native-ios-sdk.git', :branch => "beta-branch-name"`
    * In case you are using specific branch to fetch `DocuSign` pod, **additional steps are required** to install [git-lfs](https://git-lfs.github.com/) as `pod install` fetches binary framework (>100MB file) via git-lfs hooks.
    * Install git-lfs via brew: `brew install git-lfs`
    * Activate git-lfs next: `git lfs install`
6. `pod install` or `pod install --repo-update` 
7. Ensure `DocuSignSDK.framework/DocuSignSDK` binary file is available and is around `~105MB`, If yes, open workspace and build. Report an issue if problem still persists.
