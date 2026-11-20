//
//  DocuSignViewController.swift
//  docusign-sdk-sample-swift
//
//  
//  Copyright © 2017 DocuSign. All rights reserved.
//


import DocuSignSDK
import UIKit


class DocuSignViewController: UIViewController
{

    // MARK: UI Lifecycle Methods

    override func viewDidLoad()
    {
        super.viewDidLoad()
        self.styleUIElements()

        // set sdk styling
        DSMAppearance.setNavigationBarTitleTextColor(
            UIColor.white,
            backgroundTintColor: UIColor(red: 46.0/255, green: 109.0/255, blue: 164.0/255, alpha: 1.0),
            fontSize: 18.0
        )
        DSMAppearance.setBarButtonItemsTintColor(UIColor.white)

        let templateId: String = ProfileManager.sharedInstance.getCurrentTemplateId()
        let tabData: Dictionary = ProfileManager.sharedInstance.getTemplateTabData(templateId:templateId)
        let recipientData: Array = ProfileManager.sharedInstance.getTemplateRecipientData(templateId:templateId)
        let onlineSign: Bool = !ProfileManager.sharedInstance.getUseOfflineFlow()
        let attachmentUrl: URL? = ProfileManager.sharedInstance.getAttachmentUrl()
        let customFields = ProfileManager.sharedInstance.getCustomFieldsData(templateId:templateId)

        // display template via sdk
        TemplatesManager.sharedInstance.displayTemplateForSignature(templateId: templateId, controller: self, tabData: tabData, recipientData: recipientData, customFields:customFields, onlineSign: onlineSign, attachmentUrl: attachmentUrl) { (controller, errMsg) in
            
            // return to client screen
            if let vcIndex = self.navigationController?.viewControllers.firstIndex(where: { $0 is ClientViewController }),
               let clientVC = self.navigationController?.viewControllers[vcIndex] as? ClientViewController {
                self.navigationController?.popToViewController(clientVC, animated: true)
            }
        }
    }

    // MARK: Private Methods
    
    private func styleUIElements()
    {
        // set custom nav title
        self.navigationItem.titleView = Bundle.main.loadNibNamed("CustomNavTitle", owner: nil, options: nil)?.first as! UIView?
    }

}
