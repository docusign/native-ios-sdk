//
//  LoginViewController.swift
//  docusign-sdk-sample-swift
//
//  
//  Copyright © 2017 DocuSign. All rights reserved.
//


import DocuSignSDK
import SVProgressHUD
import UIKit


class LoginViewController: UIViewController, UITextFieldDelegate
{
    @IBOutlet weak var tf_username: UITextField!
    @IBOutlet weak var tf_password: UITextField!


    // MARK: UI Lifecycle Methods

    override func viewDidLoad()
    {
        super.viewDidLoad()

        // pre-populate the user credentials fields with defaults (if provided)
        tf_username.text = ProfileManager.Static.defaultUsername
        tf_password.text = ProfileManager.Static.defaultPassword
        tf_password.delegate = self
    }
    
    // MARK: IBAction Methods

    @IBAction func signInButtonTapped(_ sender: Any)
    {
        SVProgressHUD.show(withStatus: "Authenticating...")
        
        guard let email = tf_username.text else {
            return
        }
        
        guard let password = tf_password.text else {
            return
        }
        let integratorKey = ProfileManager.Static.integratorKey
        let hostUrl: URL! = ProfileManager.Static.demoHostApi
        
        if (isUsernameFormatValid(username: email) && isPasswordFormatValid(password: password))
        {
//            DSMManager.login(withEmail: email,
//                             password: password,
//                             integratorKey: integratorKey,
//                             host: hostUrl) { (accountInfo, error) in
//                SVProgressHUD.dismiss()
//                
//                if (error != nil)
//                {
//                    NSLog("Error logging in")
//                    // display error prompt
//                    self.promptError(err: error)
//                }
//                else
//                {
//                    NSLog("User authenticated")
//                    // segue to main navigation controller
//                    self.performSegue(withIdentifier: "segueMainNav", sender: nil)
//                }
//            }
        }
    }

    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        self.tf_password.resignFirstResponder()
        return true
    }

    // MARK: Private Methods
    
    func isUsernameFormatValid(username: String?) -> Bool
    {
        // check username is non-empty
        // TODO perform additional validation
        return ((username?.count)! > 0)
    }
    
    
    func isPasswordFormatValid(password: String?) -> Bool
    {
        // check password is non-empty
        // TODO Perform additional validation
        return ((password?.count)! > 0)
    }

    
    func promptError(err: Error?)
    {
        let title = "Error"
        let message = err?.localizedDescription

        let alert = UIAlertController(title: title, message: message, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "OK", style: .default) { action in })
        
        self.present(alert, animated: true)
    }
}
