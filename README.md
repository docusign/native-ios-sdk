![DocuSign Logo](images/docusign.svg)
# DocuSign Native iOS SDK

The DocuSign Native iOS SDK is a framework for Objective-C and Swift projects. Using the SDK, you can integrate the online and offline signing features of DocuSign into your own iOS application.

For detailed instructions and getting started with DocuSign Sandbox, please refer to the [official site](https://developers.docusign.com/ios_sdk/).

Requirements
============
- The SDK is written in Objective-C, but will work with projects in Objective-C or Swift (4.2 and later).
- Requires iOS 11 or later.
- It is recommended that developers use Xcode 11.1 or later.

Installation
=============

**CocoaPods**

Refer to [Getting Started Guide](https://guides.cocoapods.org/using/getting-started.html) to install CocoaPods via `gem install cocoapods` command and initialize the project. Take a look at sample projects included here [swift app](docusign-sdk-sample-swift/) and [objective-c app](docusign-sdk-sample-objc/).

* Add `pod 'DocuSign'` to podfile to target(s) in your project. Example: [Swift Sample App Podfile](docusign-sdk-sample-swift/Podfile)
* Run `pod install` in the same directory as your `Podfile` to get the DocuSign Native iOS SDK pod. This should result in `Installing DocuSign (2.2.4)` output on the console and corresponding changes in the `Podfile.lock`.
  * In case of an existing project that uses older version of 'DocuSign' pod, run `pod update 'DocuSign'` command on terminal to update 'DocuSign' pod to the latest version from a previous version.
* Launch modified `.xcworkspace` project file with Xcode and use workspace going forward instead of `.xcodeproj` file.


**Manual Integration Guide**
* Download the [DocuSignSDK.zip](DocuSignSDK.zip) and unarchive it. 
* Copy the `DocuSignSDK.framework` to root folder of your app and follow the steps on the [Integration](https://developers.docusign.com/ios_sdk/developer.html) section.


Support
===========

* Refer the [Getting Started](https://developers.docusign.com/ios_sdk/developer.html) and [Integration](https://developers.docusign.com/ios_sdk/developer.html) section on the **Developer's Site** for more details on creating DocuSign Sandbox Account, Integration and using SDK Core Interfaces.
* [Reference Docs](https://developers.docusign.com/ios_sdk/refdocs/html/annotated.html) to browse the latest developer documentation including API reference and public header files.
* Review [Change Log](ChangeLog.md)
* Guide: [Using Envelope Defaults](Using-Envelope-Defaults.md)
* Raise an issue here on GitHub.
* We also have an active developer community on Stack Overflow, search the [DocuSignAPI](http://stackoverflow.com/questions/tagged/docusignapi) tag.

License
=======

The DocuSign Native iOS SDK is licensed under the following [License](LICENSE.docx).
