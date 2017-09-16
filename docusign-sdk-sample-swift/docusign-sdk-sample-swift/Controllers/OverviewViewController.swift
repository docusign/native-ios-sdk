//
//  OverviewViewController.swift
//  docusign-sdk-sample-swift
//
//  
//  Copyright © 2017 DocuSign. All rights reserved.
//

import UIKit


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
                apptCell.lbl_date.text = "July 15, 2017";
                apptCell.lbl_clientName.text = "Tom Wood";
                apptCell.lbl_profileStatus.text = "Unsigned";
                apptCell.lbl_profileStatus.textColor = UIColor(red: 208.0/255, green: 2.0/255, blue: 27.0/255, alpha: 1.0);
                
                // add target action
                
                break;

            case 1:
                // second cell
                apptCell.lbl_date.text = "July 17, 2017";
                apptCell.lbl_clientName.text = "Terry Williams";
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
}
