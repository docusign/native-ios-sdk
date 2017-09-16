//
//  AgreementsViewController.swift
//  docusign-sdk-sample-swift
//
//  
//  Copyright © 2017 DocuSign. All rights reserved.
//

import DocuSignSDK
import SVProgressHUD
import UIKit


class AgreementsViewController: UIViewController, UITableViewDelegate, UITableViewDataSource
{

    // ui elements
    @IBOutlet weak var tableView: UITableView!
    
    // private variables / members
    private let cellReuseIdentifier = "cell_template";
    private var mTemplateList = [DSMEnvelopeTemplateDefinition]();
    private var refreshControl: UIRefreshControl!

    
    // MARK: UI Lifecycle Methods
    
    override func viewDidLoad()
    {
        super.viewDidLoad();
        self.styleUIElements();

        tableView.delegate = self;
        tableView.dataSource = self;
        
        let nib = UINib(nibName: "TemplateTableViewCell", bundle: nil);
        tableView.register(nib, forCellReuseIdentifier: cellReuseIdentifier);
        
        // add refresh control to table view
        refreshControl = UIRefreshControl()
        refreshControl.attributedTitle = NSAttributedString(string: "Pull to refresh")
        refreshControl.addTarget(self, action: #selector(refresh), for: UIControlEvents.valueChanged);
        tableView.addSubview(refreshControl)

        // fetch list of template definitions
        TemplatesManager.sharedInstance.getTemplateListWithCompletion { (templateDefinitions) in
            if (templateDefinitions != nil)
            {
                self.mTemplateList = templateDefinitions!;
                self.tableView.reloadData();
            }
        }

    }

    override func viewWillAppear(_ animated: Bool) {
        // allow only portrait orientation
        let appDelegate = UIApplication.shared.delegate as! AppDelegate
        appDelegate.lockPortraitOrientation = true;
    }

    
    // MARK: TableView Methods
    
    // number of sections in table view
    func numberOfSections(in tableView: UITableView) -> Int
    {
        return 1;
    }
    
    
    // number of rows in table view
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int
    {
        return mTemplateList.count;
    }
    
    
    // create a cell for each table view row
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell
    {
        // create a new cell if needed or reuse an old one
        let cell: TemplateTableViewCell =  self.tableView.dequeueReusableCell(withIdentifier: cellReuseIdentifier) as! TemplateTableViewCell!;
        
        return cell;
    }
    
    
    // configure cell before display
    func tableView(_ tableView: UITableView, willDisplay cell: UITableViewCell, forRowAt indexPath: IndexPath)
    {
        let template: DSMEnvelopeTemplateDefinition = mTemplateList[indexPath.row];
        let templateCell: TemplateTableViewCell = cell as! TemplateTableViewCell;
        templateCell.lbl_templateName.text = template.name;
        
        // set image and action for download button
        if (TemplatesManager.sharedInstance.templateIsCachedWithId(templateId: template.templateId))
        {
            // template is already cached
            templateCell.accessoryType = UITableViewCellAccessoryType.disclosureIndicator;
            templateCell.btn_download.removeTarget(self, action: nil, for: .touchUpInside);
            templateCell.btn_download.isHidden = true;
        }
        else
        {
            // template needs to be downloaded
            templateCell.btn_download.setBackgroundImage(UIImage(named: "download"), for: UIControlState.normal);
            templateCell.btn_download.addTarget(self, action: #selector(downloadButtonTapped(_:)), for: .touchUpInside);
        }
    }

    // method to run when table view cell is tapped
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        // fetch template for selected row
        let template: DSMEnvelopeTemplateDefinition = self.mTemplateList[indexPath.row];
        let templateId: String = template.templateId;
        ProfileManager.sharedInstance.setCurrentTemplateId(templateId: templateId);

        // prompt offline or online
        self.promptUseOfflineFlow();
    }

    
    // MARK: Selector or Helper Methods
    
    func downloadButtonTapped(_ sender:UIButton) {
        
        if let cell = sender.superview?.superview as? UITableViewCell
        {
            SVProgressHUD.show(withStatus: "Downloading...");
            
            // determine table row index and associated template id
            let indexPath = self.tableView.indexPath(for: cell)
            let templateId = mTemplateList[(indexPath?.row)!].templateId;
            
            if (templateId != nil)
            {
                // cache the specified template
                TemplatesManager.sharedInstance.cacheTemplateWithId(templateId: templateId!) { (errMsg) in
                    SVProgressHUD.dismiss();
                    
                    if (errMsg != nil)
                    {
                        self.displayErrorPrompt(errMsg: errMsg!);
                    }
                    else
                    {
                        self.tableView.reloadData();
                    }
                };
            }
        }
    }
    

    func refresh(_ sender:Any) {
        
        TemplatesManager.sharedInstance.getTemplateListWithCompletion { (templateDefinitions) in
            if (templateDefinitions != nil)
            {
                self.mTemplateList = templateDefinitions!;
                self.tableView.reloadData();
                self.refreshControl.endRefreshing()
            }
        }
    }

    
    // MARK: Private Methods
    
    private func promptUseOfflineFlow()
    {
        let title = "Developer's Notes";
        let message = "Would you like to proceed with the offline or online signing flow?";
        let offlineAlert = UIAlertController(title: title, message: message, preferredStyle: UIAlertControllerStyle.alert)
        
        // offline
        offlineAlert.addAction(UIAlertAction(title: "Offline", style: UIAlertActionStyle.default, handler: { (alert: UIAlertAction) in
            NSLog("Use Offline");
            ProfileManager.sharedInstance.setUseOfflineFlow(useOffline: true);
            
            // check if template is cached
            let templateId: String = ProfileManager.sharedInstance.getCurrentTemplateId();
            if (TemplatesManager.sharedInstance.templateIsCachedWithId(templateId: templateId))
            {
                // segue to attachment screen
                self.performSegue(withIdentifier: "segueAgreementsAttachment", sender: self)
            }
            else
            {
                // template needs to be downloaded
                self.displayErrorPrompt(errMsg: "Template must be cached on device before proceeding with offline flow.");
            }
        }))

        // online
        offlineAlert.addAction(UIAlertAction(title: "Online", style: UIAlertActionStyle.default, handler: { (alert: UIAlertAction) in
            NSLog("Use Online");
            ProfileManager.sharedInstance.setUseOfflineFlow(useOffline: false);
            
            // segue to docusign screen
            self.performSegue(withIdentifier: "segueAgreementsDocusign", sender: self)

        }));

        // cancel
        offlineAlert.addAction(UIAlertAction(title: "Cancel", style: UIAlertActionStyle.default, handler: nil))

        self.present(offlineAlert, animated: true, completion: nil)
    }
    
    
    private func displayErrorPrompt(errMsg: String)
    {
        let alert = UIAlertController(title: "Error", message: errMsg, preferredStyle: UIAlertControllerStyle.alert)
        alert.addAction(UIAlertAction(title: "Ok", style: UIAlertActionStyle.default, handler: nil))
        self.present(alert, animated: true, completion: nil)
    }

    
    private func styleUIElements()
    {
        // set custom nav title
        self.navigationItem.titleView = Bundle.main.loadNibNamed("CustomNavTitle", owner: nil, options: nil)?.first as! UIView?;
    }

}
