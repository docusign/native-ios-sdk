//
//  TemplatesManager.swift
//  docusign-sdk-sample-swift
//
//
//  Copyright © 2017 DocuSign. All rights reserved.
//

import DocuSignSDK
import Foundation

class TemplatesManager
{
    // singleton instance
    static let sharedInstance = TemplatesManager()
    
    // DSM Template Manager
    var templatesManager: DSMTemplatesManager?
    
    // list of template definitions
    var templateDefinitions: [DSMEnvelopeTemplateDefinition]?
    
    
    //This prevents others from using the default '()' initializer for this class.
    private init() {
        
        if (templatesManager == nil)
        {
            templatesManager = DSMTemplatesManager()
        }
    }
    
    typealias templateDefinitionsCompletionHandler = (_ templateDefinitions: [DSMEnvelopeTemplateDefinition]?) -> Void
    
    func getTemplateListWithCompletion(completionHandler: @escaping templateDefinitionsCompletionHandler)
    {
        // retrieve list of template definitions
        templatesManager?.listTemplates() { (templates, error) in
            NSLog("Get Template Definitions")
            
            if let error = error {
                NSLog("Error: \(error.localizedDescription)")
            }
            else {
                self.templateDefinitions = templates
                completionHandler(templates)
            }
        }
    }
    
    
    // check if template with templateId is cached on device
    func templateIsCachedWithId(templateId: String) -> Bool {
        return (templatesManager?.cacheStateOfTemplate(withId: templateId) == DSMTemplateCacheState.cached)
    }
    
    
    //typealias cacheTemplateCompletionHandler = (_ errMsg: String?) -> Void
    
    func cacheTemplateWithId(templateId: String, completionHandler: @escaping (String?) -> Void) {
        
        templatesManager?.cacheTemplate(withId: templateId, completion: { (error: Error?) in
            if let error = error {
                completionHandler(error.localizedDescription)
            }
            else {
                completionHandler(nil)
            }
        })
    }
    
    
    func removeTemplateWithId(templateId: String)
    {
        // remove the specified template
        templatesManager?.removeCachedTemplate(withId: templateId)
    }
    
    
    func displayTemplateForSignature(templateId: String, controller: UIViewController, tabData: Dictionary<String, String>, recipientData: Array<DSMRecipientDefault>, customFields:DSMCustomFields?, onlineSign: Bool, attachmentUrl: URL?, completionHandler: @escaping ((UIViewController?, Error?) -> Void))
    {
        // load PDF data
        var pdfData: Data?
        if (attachmentUrl != nil)
        {
            do {
                pdfData = try Data(contentsOf: attachmentUrl!)
            }
            catch {
                NSLog("Error loading PDF data")
            }
        }
        
        let envelopeDefaults = DSMEnvelopeDefaults()
        envelopeDefaults.recipientDefaults = recipientData.count > 0 ? recipientData : nil
        envelopeDefaults.tabValueDefaults = tabData
        envelopeDefaults.customFields = customFields
        
        templatesManager?.presentSendTemplateControllerWithTemplate (
            withId: templateId,
            envelopeDefaults: envelopeDefaults,
            pdfToInsert: pdfData,
            insertAtPosition: .end,
            signingMode: onlineSign ? .online : .offline,
            presenting: controller,
            animated: true) { (view, error) in
                if let error = error {
                    NSLog("Error encountered during signing: \(error.localizedDescription)")
                }
                if view == nil {
                    // `view` is `nil` if all of the signers pending for signature are remote
                    // A) Envelope is sent to next remote signer, should receive `DSMSigningCompletedNotification` during online signing.
                    // B) Or in case of offline signing, envelope is successfully cached and now awaiting sync.
                    NSLog("Warning: Encountered `nil view` during signing.")
                } else {
                    // DocuSign SDK UI components are active if >=1 local signers are pending signature
                    NSLog("DocuSign Native iOS SDK - UI components active")
                }
        }
    }
}

