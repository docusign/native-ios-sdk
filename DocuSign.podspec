# Be sure to run `pod lib lint DocuSign.podspec' to ensure this is a
# valid spec before submitting.

Pod::Spec.new do |s|
  s.name             = 'DocuSign'
  s.version          = '3.4.0'
  s.summary          = 'Docusign Native iOS Framework to sign and send in your iOS apps'

  s.description      = <<-DESC
  Docusign Native iOS Framework to sign and send in your iOS apps:
  - The Docusign Native iOS SDK is compatible with both Swift and Objective-C applications.
  - Easily integrate Docusign’s platform into your app with access to existing templates.
  - Sign and complete any document-based transaction, whether you’re online or where connectivity may be unreliable or nonexistent.
  - Custom fields in your templates are seamlessly populated with your own app’s data, which could include customer or contact information.
                       DESC

  s.homepage         = 'https://github.com/docusign/native-ios-sdk'
  s.screenshots      = 'https://developers.docusign.com/docs/ios-sdk/images/signature-phone.png', 'https://developers.docusign.com/docs/ios-sdk/images/fields.png'
  s.license          = { :type => 'DOCUSIGN SOFTWARE LICENSE AGREEMENT', :file => 'LICENSE.txt' }
  s.author           = { 'Docusign' => 'devcenter@docusign.com' }
  s.social_media_url = 'https://twitter.com/DocusignAPI'

  s.platform = :ios, '12.0'
  s.ios.deployment_target = '12.0'
  s.requires_arc = true
  s.preserve_paths = ['DocuSignSDK.xcframework', 'DocuSignAPI.xcframework']
  s.vendored_frameworks = [
		"DocuSignSDK.xcframework",
		"DocuSignAPI.xcframework"]
  s.resource   = 'DocuSignSDK.xcframework/**/DocuSignSDK.bundle'
  # Update the source path for new release
  s.source = { :http => "https://docucdn-a.akamaihd.net/prod/docusigniossdk/3.4.0/DocuSignSDK.zip"}
end
