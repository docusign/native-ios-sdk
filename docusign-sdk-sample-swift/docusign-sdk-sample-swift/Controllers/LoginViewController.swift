//
//  LoginViewController.swift
//  docusign-sdk-sample-swift
//
//  
//  Copyright © 2017 DocuSign. All rights reserved.
//


import DocuSignAPI
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
        tf_username.placeholder = "Email"
        tf_password.placeholder = "OAuth Access Token (leave blank for OAuth web login)"
        tf_username.text = ProfileManager.Static.defaultUsername
        tf_password.text = ProfileManager.Static.defaultPassword
        tf_password.delegate = self
    }
    
    // MARK: IBAction Methods

    @IBAction func signInButtonTapped(_ sender: Any)
    {
        guard let email = tf_username.text else {
            return
        }
        
        let accessToken = tf_password.text ?? ""
        let integratorKey = ProfileManager.Static.integratorKey
        let accountId = ProfileManager.Static.accountId
        guard let hostUrl = ProfileManager.Static.demoHostApi else {
            return
        }
        
        let handleCompletion: (DSMAccountInfo?, Error?) -> Void = { accountInfo, error in
            DispatchQueue.main.async {
                SVProgressHUD.dismiss()
                if let error = error {
                    NSLog("Error logging in: \(error.localizedDescription)")
                    self.promptError(err: error)
                } else {
                    NSLog("User authenticated")
                    self.performSegue(withIdentifier: "segueMainNav", sender: nil)
                }
            }
        }
        
        if !accessToken.isEmpty && accessToken != "<MY-OAUTH-ACCESS-TOKEN-HERE>" && isUsernameFormatValid(username: email) {
            SVProgressHUD.show(withStatus: "Authenticating...")
            DSMManager.login(withAccessToken: accessToken,
                             accountId: accountId,
                             userId: ProfileManager.Static.userId,
                             userName: ProfileManager.Static.userName,
                             email: email,
                             host: hostUrl,
                             integratorKey: integratorKey,
                             refreshToken: nil,
                             expiresIn: nil,
                             completion: handleCompletion)
        } else {
            DSMManager.login(withOAuthEnv: .demo,
                             accountId: accountId,
                             redirectUri: ProfileManager.Static.redirectUri,
                             integratorKey: integratorKey,
                             completion: handleCompletion)
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
