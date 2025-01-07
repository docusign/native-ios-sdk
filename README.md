<p align="center">
  <img src="https://github.com/user-attachments/assets/3efff3ff-4efb-47d2-950d-881212b9f27e"  alt="Docusign Logo"/>
</p>

# Docusign Native iOS SDK

The Docusign Native iOS SDK is a framework for Objective-C and Swift projects. Using the SDK, you can integrate Docusign's online and offline signing features into your iOS application. Leverage native iOS UI components to integrate with the Docusign ecosystem and use various features in your app.

Please refer to the [official site](https://developers.docusign.com/docs/mobile-sdks/ios-sdk/) for detailed instructions and getting started with Docusign Sandbox.

Requirements
============
- Requires iOS 13 or later.
- It is recommended that developers use Xcode 12.0 or later.

Installation
=============

**SPM**

Instructions for [Swift Package Manager](https://www.swift.org/documentation/package-manager/) support can be found in the S[wiftPackageManager.md](https://github.com/docusign/native-ios-sdk/blob/feature/spm-support/SwiftPackageManager.md) Markdown file.

**CocoaPods**

Refer to [Getting Started Guide](https://guides.cocoapods.org/using/getting-started.html) to install CocoaPods via `gem install cocoapods` command and initialize the project. 

* Add `pod 'DocuSign'` to podfile to target(s) in your project. Example: [Swift Sample App Podfile](docusign-sdk-sample-swift/Podfile)
* Run `pod install` in the same directory as your `Podfile` to get the Docusign Native iOS SDK pod. This should result in `Installing DocuSign `[Latest Release](https://github.com/docusign/native-ios-sdk/releases) output on the console and corresponding changes in the `Podfile.lock`.
  * In case of an existing project that uses an older version of 'DocuSign' pod, run `pod update 'DocuSign'` command on the terminal to update 'DocuSign' pod to the latest version from a previous version.
* Launch modified `.xcworkspace` project file with Xcode and use workspace going forward instead of `.xcodeproj` file.
  * Refer to [Integration Troubleshooting](support-files/Integration-Troubleshooting.md) in case of any issues.

Additional information related to cocoapods is also avaiable with [swift app](docusign-sdk-sample-swift/), [objective-c app](docusign-sdk-sample-objc/) and [swiftUI app](docusign-sdk-sample-swiftui/).

**Manual Integration Guide**

Use these steps to manually integrate the DocuSign framework in case your project doesn't use CocoaPods.

* Download the DocuSignSDKCombined.zip from the path [here](https://github.com/docusign/native-ios-sdk/blob/feature/spm-support/DocuSign.podspec#L32) and unarchive it.
* Copy the extracted folder to your project and add `DocuSignSDK.xcframework` and `DocuSignAPI.xcframework` to your dependencies.
  
Support
===========

* Refer the [Getting Started](https://developers.docusign.com/ios_sdk/developer.html) and [Integration](https://developers.docusign.com/ios_sdk/developer.html) section on the **Developer's Site** for more details on creating Docusign Sandbox Account, Integration and using SDK Core Interfaces.
* [Reference Docs](https://docusign.github.io/native-ios-sdk/documentation/docusignsdk/) to browse the latest developer documentation including API reference and public header files.
* Review [Change Log](CHANGELOG.md)

Guides: 
 * [Integration Troubleshooting](support-files/Integration-Troubleshooting.md)
 * [Using Envelope Defaults](Using-Envelope-Defaults.md)
 * [Privacy - Usage Permissions](support-files/Permissions-Requirements.md) for Camera, Photo Library, Contacts and Location Access.
 * [Telemetry Details](support-files/Telemetry-Details.md)  
 * [Embedded Signing](Embedded-Signing.md)
 * [Composing Envelopes](Compose-Envelope.md)

Sample apps: 
 * For SDK version `2.6.0` and above refer our latest: [TGK Financial Sample App](https://github.com/docusign/sample-app-tgk-financial-ios/)
[Deprecated] Sample Apps for reference with different languages
 * [swift](docusign-sdk-sample-swift/): Templates, Offline Envelopes, Events
 * [objective-c](docusign-sdk-sample-objc/): Templates, Offline Envelopes, Events
 * [swiftUI](docusign-sdk-sample-swiftui/): Captive (Embedded) Signing

Reaching out: 
* Open an [issue](https://github.com/docusign/native-ios-sdk/issues).
* 
* Docusign also have an active developer community on Stack Overflow, search the [DocuSignAPI](http://stackoverflow.com/questions/tagged/docusignapi) tag.

License
=======

The Docusign Native iOS SDK is licensed under the following [License](LICENSE.docx).
