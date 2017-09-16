//
//  InvestmentViewController.swift
//  docusign-sdk-sample-swift
//
//  
//  Copyright © 2017 DocuSign. All rights reserved.
//

import UIKit


class InvestmentViewController: UIViewController
{
    @IBOutlet weak var tf_clientNumber: UITextField!
    @IBOutlet weak var tf_investmentAmount: UITextField!


    // MARK: UI Lifecycle Methods
    
    override func viewDidLoad()
    {
        super.viewDidLoad();
        self.styleUIElements();
        
        self.loadInvestmentData();
    }


    // MARK: IBAction Methods

    @IBAction func nextButtonTapped(_ sender: Any)
    {
        // Store investment details
        ProfileManager.sharedInstance.setClientInvestmentInfo(clientNumber: self.tf_clientNumber.text!,
                                                              investmentAmount: self.tf_investmentAmount.text!);
        
        // segue to agreement screen
        self.performSegue(withIdentifier: "segueInvestmentAgreements", sender: self);
    }

    
    // MARK: Private Methods
    
    private func loadInvestmentData()
    {
        let clientData = ProfileManager.sharedInstance.getClientData();
        
        self.tf_clientNumber.text = clientData["clientNumber"];
        self.tf_investmentAmount.text = clientData["investmentAmount"];
    }
    
    
    private func styleUIElements()
    {
        // set custom nav title
        self.navigationItem.titleView = Bundle.main.loadNibNamed("CustomNavTitle", owner: nil, options: nil)?.first as! UIView?;
    }

}
