//
//  MainContainerViewController.swift
//  docusign-sdk-sample-swift
//
//  
//  Copyright © 2017 DocuSign. All rights reserved.
//

import UIKit

class MainContainerViewController: UIViewController {
    
    // ui elements
    @IBOutlet weak var segmentedControl: UISegmentedControl!
    @IBOutlet weak var vw_overviewContainer: UIView!
    @IBOutlet weak var vw_clientContainer: UIView!
    @IBOutlet weak var vw_templatesContainer: UIView!
    @IBOutlet weak var bt_navEdit: UIBarButtonItem!

    // reference to the embeded templates view controller
    // used to reference ui objects inside container from outer nav bar
    private var templatesVC: TemplatesViewController?


    // used to track if downloads table view is in edit mode
    private var editModeEnabled: Bool = false


    // MARK: UI Lifecycle Methods
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.styleUIElements()
        
        // hide edit button from nav bar
        self.bt_navEdit.isEnabled = false
        self.bt_navEdit.title = ""
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?)
    {
        if (segue.identifier == "segueMainNavTemplates")
        {
            templatesVC = segue.destination as? TemplatesViewController
        }
    }

    
    // MARK: IBAction Methods

    @IBAction func indexChanged(_ sender: UISegmentedControl)
    {
        switch segmentedControl.selectedSegmentIndex
        {
            case 0:
                // show overview screen
                vw_overviewContainer.isHidden = false
                vw_clientContainer.isHidden = true
                vw_templatesContainer.isHidden = true
                bt_navEdit.isEnabled = false
                bt_navEdit.title = ""
                break

            case 1:
                // show clients screen
                vw_overviewContainer.isHidden = true
                vw_clientContainer.isHidden = false
                vw_templatesContainer.isHidden = true
                bt_navEdit.isEnabled = false
                bt_navEdit.title = ""
                break
            
            case 2:
                // show templates screen
                vw_overviewContainer.isHidden = true
                vw_clientContainer.isHidden = true
                vw_templatesContainer.isHidden = false
                bt_navEdit.isEnabled = true
                bt_navEdit.title = "Edit"
                break
            
            default:
                break
        }
    }

    
    @IBAction func editButtonTapped(_ sender: Any)
    {
        NSLog("Edit button tapped")

        if (editModeEnabled)
        {
            // end edit mode on tableview
            editModeEnabled = false
            bt_navEdit.title = "Edit"
            templatesVC?.endEditModeOnTableView()
        }
        else
        {
            // enter edit mode on tableview
            editModeEnabled = true
            bt_navEdit.title = "Cancel"
            templatesVC?.startEditModeOnTableView()
        }
    }

    
    // MARK: Private Methods
    
    private func styleUIElements()
    {
        // set custom nav title
        self.navigationItem.titleView = Bundle.main.loadNibNamed("CustomNavTitle", owner: nil, options: nil)?.first as! UIView?
    }
}
