//
//  TemplatesViewController.swift
//  docusign-sdk-sample-swift
//
//  
//  Copyright © 2017 DocuSign. All rights reserved.
//

import DocuSignSDK
import SVProgressHUD
import UIKit


class TemplatesViewController: UIViewController, UITableViewDelegate, UITableViewDataSource, ContainerWithTableView
{
    // MARK: UI Elements

    @IBOutlet var tableView: UITableView!

    // MARK: Private Variables / Members

    private let cellReuseIdentifier = "cell_template";
    private var mTemplateList = [DSMEnvelopeTemplateDefinition]();
    private var refreshControl: UIRefreshControl!


    // MARK: UI Lifecycle Methods
    
    override func viewDidLoad()
    {
        super.viewDidLoad()

        tableView.delegate = self;
        tableView.dataSource = self;
        
        let nib = UINib(nibName: "TemplateTableViewCell", bundle: nil)
        tableView.register(nib, forCellReuseIdentifier: cellReuseIdentifier)
        
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
    
    // MARK: TableView Methods
    
    // number of sections in table view
    func numberOfSections(in tableView: UITableView) -> Int
    {
        return 1
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
        let cell: TemplateTableViewCell =  self.tableView.dequeueReusableCell(withIdentifier: cellReuseIdentifier) as! TemplateTableViewCell!
        
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
            templateCell.btn_download.setBackgroundImage(UIImage(named: "download_done"), for: UIControlState.normal);
            templateCell.btn_download.removeTarget(self, action: nil, for: .touchUpInside);
        }
        else
        {
            // template needs to be downloaded
            templateCell.btn_download.setBackgroundImage(UIImage(named: "download"), for: UIControlState.normal);
            templateCell.btn_download.addTarget(self, action: #selector(downloadButtonTapped(_:)), for: .touchUpInside)
        }
    }
    

    func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCellEditingStyle, forRowAt indexPath: IndexPath)
    {
        if (editingStyle == UITableViewCellEditingStyle.delete)
        {
            // remove specified template
            let templateId = self.mTemplateList[indexPath.row].templateId;
            TemplatesManager.sharedInstance.removeTemplateWithId(templateId: templateId!);
            
            // reload table to update template download status
            self.tableView.reloadData();
        }
    }


    func tableView(_ tableView: UITableView, titleForDeleteConfirmationButtonForRowAt indexPath: IndexPath) -> String? {
        return "Uncache";
    }
    
    
    // MARK: ContainerWithTableView Protocol Methods
    
    func startEditModeOnTableView()
    {
        tableView.setEditing(true, animated: true);
    }
    
    
    func endEditModeOnTableView()
    {
        tableView.setEditing(false, animated: true);
    }


    // MARK: Selector or Helper Methods

    func downloadButtonTapped(_ sender:UIButton)
    {
        if let cell = sender.superview?.superview as? UITableViewCell
        {
            SVProgressHUD.show(withStatus: "Downloading...");
            
            // determine table row index and associated template id
            let indexPath = self.tableView.indexPath(for: cell)
            let templateId = mTemplateList[(indexPath?.row)!].templateId;
        
            if (templateId != nil) {
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
                }
            }
        }
    }


    // MARK: Private Methods
    
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

    
    private func displayErrorPrompt(errMsg: String)
    {
        NSLog("Display error prompt: " + errMsg);
        
        let alert = UIAlertController(title: "Error", message: errMsg, preferredStyle: UIAlertControllerStyle.alert)
        alert.addAction(UIAlertAction(title: "Ok", style: UIAlertActionStyle.default, handler: nil))
        self.present(alert, animated: true, completion: nil)
    }

}
