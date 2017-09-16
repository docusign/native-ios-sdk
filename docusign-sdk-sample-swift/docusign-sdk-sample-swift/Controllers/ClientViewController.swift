//
//  ClientViewController.swift
//  docusign-sdk-sample-swift
//
//  
//  Copyright © 2017 DocuSign. All rights reserved.
//

import UIKit


class ClientViewController: UIViewController
{
    // ui elements
    @IBOutlet weak var segmentedControl: UISegmentedControl!
    @IBOutlet weak var vw_portfolioContainer: UIView!
    @IBOutlet weak var vw_contactContainer: UIView!
    

    // MARK: UI Lifecycle Methods
    
    override func viewDidLoad()
    {
        super.viewDidLoad()
        self.styleUIElements();
    }

    override func viewWillAppear(_ animated: Bool) {
        // check for envelopes waiting to sync
        let envelopeIdsToSync = EnvelopesManager.sharedInstance.getCachedEnvelopeIds();
        if (envelopeIdsToSync != nil && (envelopeIdsToSync?.count)! > 0)
        {
            // sync envelopes
            EnvelopesManager.sharedInstance.syncEnvelopes();

            // prompt with developer notes
            self.promptSyncEnvelopes();
        }
    }
    

    // MARK: IBAction Methods
    
    @IBAction func indexChanged(_ sender: UISegmentedControl)
    {
        switch segmentedControl.selectedSegmentIndex
        {
        case 0:
            // show portfolio screen
            vw_portfolioContainer.isHidden = false;
            vw_contactContainer.isHidden = true;
            break;
            
        case 1:
            // show contact screen
            vw_portfolioContainer.isHidden = true;
            vw_contactContainer.isHidden = false;
            break;
            
        default:
            break;
        }
    }


    // MARK: Private Methods
    
    private func promptSyncEnvelopes()
    {
        let title = "Developer's Notes";
        let message = "For sample purposes, we've drawn attention to the fact that completed envelopes are now syncing with the server. However, you will likely perform this task automatically in the background, once a network connection is available.";
        let syncAlert = UIAlertController(title: title, message: message, preferredStyle: UIAlertControllerStyle.alert)
        
        // add Ok action
        syncAlert.addAction(UIAlertAction(title: "Ok", style: UIAlertActionStyle.default, handler: nil))
        
        self.present(syncAlert, animated: true, completion: nil)
    }
    
    
    private func styleUIElements()
    {
        // set custom nav title
        self.navigationItem.titleView = Bundle.main.loadNibNamed("CustomNavTitle", owner: nil, options: nil)?.first as! UIView?;
    }

}
