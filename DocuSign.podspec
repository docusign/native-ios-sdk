#
# Be sure to run `pod lib lint DocuSign.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'DocuSign'
  s.version          = '2.5'
  s.summary          = 'DocuSign Native iOS Framework to sign and send in your iOS apps'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
  DocuSign Native iOS Framework to sign and send in your iOS apps:
  - The DocuSign Native iOS SDK is compatible with both Swift and Objective-C applications.
  - Easily integrate DocuSign’s platform into your app with access to existing templates.
  - Sign and complete any document-based transaction, whether you’re online or where connectivity may be unreliable or nonexistent.
  - Custom fields in your templates are seamlessly populated with your own app’s data, which could include customer or contact information.
                       DESC

  s.homepage         = 'https://github.com/docusign/native-ios-sdk'
  s.screenshots      = 'https://developers.docusign.com/docs/ios-sdk/images/signature-phone.png', 'https://developers.docusign.com/docs/ios-sdk/images/fields.png'
  s.license          = { :type => 'DOCUSIGN SOFTWARE LICENSE AGREEMENT', :file => 'LICENSE.txt' }
  s.author           = { 'DocuSign' => 'devcenter@docusign.com' }
  s.social_media_url = 'https://twitter.com/DocuSignAPI'

  s.platform = :ios, '9.0'
  s.ios.deployment_target = '9.0'
  s.requires_arc = true
  s.preserve_paths = 'DocuSignSDK.framework'
  s.public_header_files = 'DocuSignSDK.framework/Headers/*.h'
  s.vendored_frameworks = 'DocuSignSDK.framework'
  s.resource = 'DocuSignSDK.framework/DocuSignSDK.bundle'
  # Update the source path for new release
  s.source = { :http => "https://github.com/docusign/native-ios-sdk/raw/release/2.5/DocuSignSDK.zip"}
  s.source_files = 'DocuSignSDK.framework/Headers/*.h'
  # Exclude `arm64` from the iphonesimulator builds
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

end
