//
//  OverviewViewController.swift
//  docusign-sdk-sample-swift
//
//  
//  Copyright © 2017 DocuSign. All rights reserved.
//

import UIKit
import DocuSignSDK

class OverviewViewController: UIViewController, UITableViewDelegate, UITableViewDataSource
{
    // ui elements
    @IBOutlet var tableView: UITableView!
    

    // private variables
    private let cellReuseIdentifier = "cell_appointment";
    
    
    // MARK: UI Lifecycle Methods
    
    override func viewDidLoad()
    {
        super.viewDidLoad()
       
        tableView.delegate = self;
        tableView.dataSource = self;

        let nib = UINib(nibName: "AppointmentTableViewCell", bundle: nil)
        tableView.register(nib, forCellReuseIdentifier: cellReuseIdentifier)
    }

    override func viewWillAppear(_ animated: Bool)
    {
        super.viewWillAppear(animated)
        
        let appDelegate = UIApplication.shared.delegate as! AppDelegate
        appDelegate.lockPortraitOrientation = false;
    }

    // MARK: actions
    @IBAction func onCreateNewAgreementTapped(_ sender: Any)
    {
        self.promptDevAction(composeEnvelopeHandler: presentComposeEnvelope)
    }
    
    // MARK: TableView Methods

    // number of sections in table view
    func numberOfSections(in tableView: UITableView) -> Int
    {
        return 1
    }
    
    // number of rows in table view
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 2;
    }

    // create a cell for each table view row
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell
    {
        
        // create a new cell if needed or reuse an old one
        let cell: AppointmentTableViewCell =  self.tableView.dequeueReusableCell(withIdentifier: cellReuseIdentifier) as! AppointmentTableViewCell!

        return cell;
    }
    
    // configure cell before display
    func tableView(_ tableView: UITableView, willDisplay cell: UITableViewCell, forRowAt indexPath: IndexPath)
    {
        let apptCell: AppointmentTableViewCell = cell as! AppointmentTableViewCell;
        
        switch indexPath.row
        {
            case 0:
                // first cell
                apptCell.lbl_date.text = "June 20, 2018";
                apptCell.lbl_clientName.text = "Tom Wood";
                apptCell.lbl_profileStatus.text = "Unsigned";
                apptCell.lbl_profileStatus.textColor = UIColor(red: 208.0/255, green: 2.0/255, blue: 27.0/255, alpha: 1.0);
                
                // add target action
                
                break;

            case 1:
                // second cell
                apptCell.lbl_date.text = "June 19, 2018";
                apptCell.lbl_clientName.text = "Andrea G Kuhn";
                apptCell.lbl_profileStatus.text = "Signed";
                apptCell.lbl_profileStatus.textColor = UIColor(red: 126.0/255, green: 211.0/255, blue: 33.0/255, alpha: 1.0);
                break;
            
            default:
                break;
        }
    }
    
    // method to run when table view cell is tapped
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath)
    {
        if (indexPath.row == 0)
        {
            // Segue to the Client view controller
            self.performSegue(withIdentifier: "segueOverviewClient", sender: self)
        }
    }
    
    // MARK: private methods
    private func promptDevAction(composeEnvelopeHandler handler: @escaping (_ signingMode: DSMSigningMode) -> Void)
    {
        let title = "Developer's Notes";
        let message = "You can either compose an envelope in online or offline mode. You would need to check for network connectivity and present the appropriate view controller.";
        let agreementAlert = UIAlertController(title: title, message: message, preferredStyle: UIAlertControllerStyle.alert)
        
        // add Ok action
        agreementAlert.addAction(UIAlertAction(title: "Online Envelope", style: .default, handler: { (action) in
            handler(.online)
        }));
        
        agreementAlert.addAction(UIAlertAction(title: "Offline Envelope", style: .default, handler: { (action) in
            handler(.offline)
        }));
        agreementAlert.addAction(UIAlertAction(title: "Cancel", style: .cancel, handler:nil));
        self.present(agreementAlert, animated: true, completion: nil)
    }
    
    private func presentComposeEnvelope(_ signingMode: DSMSigningMode) -> Void
    {
        if #available(iOS 11.0, *) {
            EnvelopesManager.sharedInstance.presentComposeEnvelopeViewController(self, signingMode)
        } else {
            let alertController = UIAlertController(title: "iCloud Entitlement required", message: "For iOS 10 and below, iCloud entitlements must be added and DSM_SETUP_ICLOUD_DOCUMENT_ENABLED set to true for document picker usage.", preferredStyle: .actionSheet)
            
            let action = UIAlertAction(title: "OK", style: .default) { (action:UIAlertAction) in
                EnvelopesManager.sharedInstance.presentComposeEnvelopeViewController(self, signingMode)
            }
            alertController.addAction(action)
            self.present(alertController, animated: true, completion: nil)
        }
    }
    
}
