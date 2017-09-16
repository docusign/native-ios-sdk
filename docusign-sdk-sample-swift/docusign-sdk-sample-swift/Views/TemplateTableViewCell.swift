//
//  TemplateTableViewCell.swift
//  docusign-sdk-sample-swift
//
//  
//  Copyright © 2017 DocuSign. All rights reserved.
//

import UIKit

class TemplateTableViewCell: UITableViewCell
{
    @IBOutlet weak var lbl_templateName: UILabel!
    @IBOutlet weak var btn_download: UIButton!

    override func awakeFromNib()
    {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool)
    {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
