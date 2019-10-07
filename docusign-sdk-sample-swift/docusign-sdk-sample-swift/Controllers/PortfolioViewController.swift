//
//  PortfolioViewController.swift
//  docusign-sdk-sample-swift
//
//  
//  Copyright © 2017 DocuSign. All rights reserved.
//

import UIKit


class PortfolioViewController: UIViewController
{
    // MARK: UI Elements
    
    @IBOutlet weak var lbl_signedStatus: UILabel!
    @IBOutlet weak var lbl_clientName: UILabel!
    

    // MARK: UI Lifecycle Methods
    
    override func viewDidLoad()
    {
        super.viewDidLoad()
    }
 
    override func viewWillAppear(_ animated: Bool) {

        // set client name
        lbl_clientName.text = ProfileManager.sharedInstance.getClientName()
        
        // set signed label based on whether envelopes need to sync
        let envelopeIdsToSync = EnvelopesManager.sharedInstance.getCachedEnvelopeIds()

        if (envelopeIdsToSync != nil && (envelopeIdsToSync?.count)! > 0)
        {
            // envelopes need to sync, mark as signed
            self.lbl_signedStatus.text = "Signed"
            self.lbl_signedStatus.textColor = UIColor(red: 126.0/255, green: 211.0/255, blue: 33.0/255, alpha: 1.0)
        }
        else
        {
            // mark unsigned
            self.lbl_signedStatus.text = "Unsigned"
            self.lbl_signedStatus.textColor = UIColor(red: 208.0/255, green: 2.0/255, blue: 27.0/255, alpha: 1.0)
        }
    }
}
