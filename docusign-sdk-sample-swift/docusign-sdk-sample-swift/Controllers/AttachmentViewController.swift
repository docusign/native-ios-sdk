//
//  AttachmentViewController.swift
//  docusign-sdk-sample-swift
//
//  
//  Copyright © 2017 DocuSign. All rights reserved.
//

import UIKit


class AttachmentViewController: UIViewController
{
    // MARK: UI Elements

    @IBOutlet weak var btn_barSkip: UIBarButtonItem!
    @IBOutlet weak var btn_attach: UIButton!
    @IBOutlet weak var lbl_attach: UILabel!
    @IBOutlet weak var vw_document: UIWebView!


    // MARK: UI Lifecycle Methods
    
    override func viewDidLoad()
    {
        super.viewDidLoad();
        self.styleUIElements();
    }

    override func viewWillAppear(_ animated: Bool) {
        // allow only portrait orientation
        let appDelegate = UIApplication.shared.delegate as! AppDelegate
        appDelegate.lockPortraitOrientation = true;
    }

    
    // MARK: IBAction Methods
    
    @IBAction func skipButtonTapped(_ sender: Any)
    {
        // segue to docusign screen
        self.performSegue(withIdentifier: "segueAttachmentDocusign", sender: self)
    }
    
    @IBAction func attachButtonTapped(_ sender: Any)
    {
        // load PDF included in bundle
        if let documentURL = Bundle.main.url(forResource: "Portfolio", withExtension: "pdf", subdirectory: nil, localization: nil)
        {
            do {
                let data = try Data(contentsOf: documentURL);
                self.vw_document.load(data, mimeType: "application/pdf", textEncodingName: "", baseURL: documentURL.deletingLastPathComponent());
                self.vw_document.isHidden = false;
                
                // hide attach button
                self.btn_attach.isHidden = true;
                self.lbl_attach.isHidden = true;
                
                // update navigation button
                self.btn_barSkip.title = "Next";
                
                // capture url for attachment
                ProfileManager.sharedInstance.setAttachmentPath(attachmentUrl: documentURL);
                
                // display developer's notes
                self.promptDevAttachment();
            }
            catch {
                NSLog("Error loading PDF file as attachment.");
            }
        }
    }
    

    // MARK: Private Methods
    
    private func promptDevAttachment()
    {
        let title = "Developer's Notes";
        let message = "For sample purposes, we have included a PDF document that has been attached. Ordinarily, you would guide the user through selecting an external PDF document to attach to the envelope.";
        let attachmentAlert = UIAlertController(title: title, message: message, preferredStyle: UIAlertControllerStyle.alert)
        
        // add Ok action
        attachmentAlert.addAction(UIAlertAction(title: "Ok", style: UIAlertActionStyle.default, handler: nil))

        self.present(attachmentAlert, animated: true, completion: nil)
    }
    
    private func styleUIElements()
    {
        // set custom nav title
        self.navigationItem.titleView = Bundle.main.loadNibNamed("CustomNavTitle", owner: nil, options: nil)?.first as! UIView?;
    }

}
