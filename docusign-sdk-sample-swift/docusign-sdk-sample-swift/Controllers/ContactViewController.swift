//
//  ContactViewController.swift
//  docusign-sdk-sample-swift
//
//  
//  Copyright © 2017 DocuSign. All rights reserved.
//

import UIKit


class ContactViewController: UIViewController,UITextFieldDelegate
{
    // MARK: UI Elements
    
    @IBOutlet weak var tf_firstName: UITextField!
    @IBOutlet weak var tf_lastName: UITextField!
    @IBOutlet weak var tf_phone: UITextField!
    @IBOutlet weak var tf_email: UITextField!
    @IBOutlet weak var tf_address: UITextField!
    @IBOutlet weak var tf_city: UITextField!
    @IBOutlet weak var tf_state: UITextField!
    @IBOutlet weak var tf_country: UITextField!
    @IBOutlet weak var tf_zipCode: UITextField!


    // UI Lifecycle Methods
    
    override func viewDidLoad()
    {
        super.viewDidLoad()
        self.styleUIElements()
        
        // for demo purposes, pre-populate with fake data
        self.loadContactData()
    }


    override func viewWillDisappear(_ animated: Bool) {
        // save any changes to the personal info
        ProfileManager.sharedInstance.setClientPersonalInfo(
            firstName: self.tf_firstName.text,
            lastName: self.tf_lastName.text,
            address: self.tf_address.text,
            city: self.tf_city.text,
            state: self.tf_state.text,
            country: self.tf_country.text,
            zipCode: self.tf_zipCode.text,
            email: self.tf_email.text,
            phone: self.tf_phone.text)
    }
    
    
    // MARK: Private Methods
    
    private func loadContactData()
    {
        let clientData = ProfileManager.sharedInstance.getClientData()
        
        self.tf_firstName.text = clientData["firstName"]
        self.tf_firstName.delegate = self 
        
        self.tf_lastName.text = clientData["lastName"]
        self.tf_lastName.delegate = self 
        
        self.tf_phone.text = clientData["phone"]
        self.tf_phone.delegate = self 

        self.tf_email.text = clientData["email"]
        self.tf_email.delegate = self 

        self.tf_address.text = clientData["address"]
        self.tf_address.delegate = self 

        self.tf_city.text = clientData["city"]
        self.tf_city.delegate = self 

        self.tf_state.text = clientData["state"]
        self.tf_state.delegate = self 

        self.tf_country.text = clientData["country"]
        self.tf_country.delegate = self 

        self.tf_zipCode.text = clientData["zipCode"]
        self.tf_zipCode.delegate = self 
    }
    
    
    private func styleUIElements()
    {
        // set custom nav title
        self.navigationItem.titleView = Bundle.main.loadNibNamed("CustomNavTitle", owner: nil, options: nil)?.first as! UIView?
    }
    
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        self.view.endEditing(true)
        return true 
    }

}
