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
    var mDSMTemplatesManager: DSMTemplatesManager?;
    
    // list of template definitions
    var mTemplateDefinitions: [DSMEnvelopeTemplateDefinition]?;
    

    //This prevents others from using the default '()' initializer for this class.
    private init() {

        if (self.mDSMTemplatesManager == nil)
        {
            self.mDSMTemplatesManager = DSMTemplatesManager.init();
        }
    }


    typealias templateDefinitionsCompletionHandler = (_ templateDefinitions: [DSMEnvelopeTemplateDefinition]?) -> Void;
    func getTemplateListWithCompletion(completionHandler: @escaping templateDefinitionsCompletionHandler)
    {
        // retrieve list of template definitions
        self.mDSMTemplatesManager?.listTemplates(completion: { (templateDefinitions, errMsg) in
            NSLog("Get Template Definitions");
    
            if (errMsg != nil) {
                NSLog("Error: " + errMsg!.localizedDescription);
            }
            else {
                self.mTemplateDefinitions = templateDefinitions;
                completionHandler(templateDefinitions);
            }
        })
    }
    

    // check if template with templateId is cached on device
    func templateIsCachedWithId(templateId: String) -> Bool {
        return (self.mDSMTemplatesManager?.cacheStateOfTemplate(withId: templateId) == DSMTemplateCacheState.cached);
    }
    

    //typealias cacheTemplateCompletionHandler = (_ errMsg: String?) -> Void;
    func cacheTemplateWithId(templateId: String, completionHandler: @escaping (String?) -> Void) {
       
        self.mDSMTemplatesManager?.cacheTemplate(withId: templateId, completion: { (err: Error?) in
            if (err != nil) {
                completionHandler(err?.localizedDescription);
            }
            else {
                completionHandler(nil);
            }
        })
    }
    

    func removeTemplateWithId(templateId: String)
    {
        // remove the specified template
        self.mDSMTemplatesManager?.removeCachedTemplate(withId: templateId);
    }


    func displayTemplateForSignature(templateId: String, controller: UIViewController, tabData: Dictionary<String, String>, recipientData: Array<DSMRecipientDefault>, customFields:DSMCustomFields?, onlineSign: Bool, attachmentUrl: URL?, completionHandler: @escaping ((UIViewController?, Error?) -> Void))
    {
        // load PDF data
        var pdfData: Data?;
        if (attachmentUrl != nil)
        {
            do {
                pdfData = try Data(contentsOf: attachmentUrl!);
            }
            catch {
                NSLog("Error loading PDF data");
            }
        }
        
        let mDSMEnvelopeDefaults = DSMEnvelopeDefaults();
        mDSMEnvelopeDefaults.recipientDefaults = recipientData.count > 0 ? recipientData : nil;
        mDSMEnvelopeDefaults.tabValueDefaults = tabData;
        mDSMEnvelopeDefaults.customFields = customFields
        
        self.mDSMTemplatesManager?.presentSendTemplateControllerWithTemplate(withId: templateId, envelopeDefaults: mDSMEnvelopeDefaults, pdfToInsert: pdfData, insertAtPosition: DSMDocumentInsertAtPosition.end, signingMode: onlineSign ? DSMSigningMode.online : DSMSigningMode.offline, presenting: controller, animated: true, completion: completionHandler);
    }
    
}
