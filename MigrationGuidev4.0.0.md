# Docusign iOS SDK version 4.0 Migration guide

## Summary

This guide is for customers who are using Docusign iOS SDK version below 4.0 in their mobile apps. Please refer to this guide to migrate from an older version of Docusign SDK to version 4.0 (and above).

With this new version of SDK, v4.0, we have moved our Envelope offline signing and Template offline Sending to use modern components, with better performance and smaller footprint.

Due to these changes and in our attempt to modularize our SDK, we introduced a new Framework **DocusignNative**. It is still within the same **DocuSignSDK package**, so there are no changes in how you integrate with our SDK either through Cocoapods or through SPM. However, there are some breaking changes when calling methods from `DSMEnvelopesManager` and `DSMTemplatedManager`. These methods have now moved to `NativeSigningManager` in the DocusignNative Module. Here are the steps to migrate these flows.

### Replaced Functionality:

1. **Offline envelope signing**  
   The method `resumeSigningEnvelope(withPresenting:, envelopeId:, completion:)` inside `DSMEnvelopesManager`, is now simply replaced with a very similar method `resumeSigning(presentingVC:, envelopeId:)` from `NativeSigningManager`. The parameters are still the same, only change is that it’s from a different Manager now and it supports new swift concurrency  
   

```
do {
     let vc = try await NativeSigningManager().resumeSigning(presentingVC: presentingController, envelopeId: id)
   } catch let error {
       print(error)
   }
```

2. **Offline Template Sending (and Signing)**  
   The method `presentSendTemplateControllerWithTemplate(withId:, envelopeDefaults:, pdfToInsert:, insertAtPosition: , signingMode: , presenting:, animated:, completion:)` inside `DSMTemplatesManager`, is now simply replaced with a very similar method `presentSendTemplate(presentingViewController:, templateId:, envelopeDefaults:, insertAtPosition:, pdfToInsert:, animated:)` from `NativeSigningManager`. The parameters are still the same, only change is that it’s from a different Manager now and it **supports new swift concurrency**.  
   

```
do {
      let vc = try await self.mNativeSigningManager?.presentSendTemplate(presentingViewController: presentingVC, templateId: templateId, envelopeDefaults: envelopeDefaults, insertAtPosition: .beginning, pdfToInsert: nil, animated: true)
      completion(vc, nil)
   } catch {
      completion(nil, error)
   }
```

### Deprecated Functionality:

- Compose Envelope, UI Flow to create envelopes from scratch, has been fully deprecated.

```
presentComposeEnvelopeControllerWithPresentingController
```

- Non-PDF File conversion: Creating `DSMEnvelopeDefinition` with documents that are non-PDF type will cause an error of type `invalidDocumentFormat`.

### Added Functionality:

- New configuration to allow SDK to detect page rotation on documents and adjust it to ensure tags are rendered upright, default value is `false`. Set to `true` in case tags are showing rotated on documents.

```
DSM_SETUP_ENABLE_OFFLINE_NORMALIZE_ROTATED_DOCUMENTS_KEY
```

