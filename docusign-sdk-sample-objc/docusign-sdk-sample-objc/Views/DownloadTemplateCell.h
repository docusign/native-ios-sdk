//
//  DownloadsTableViewCell.h
//  docusign-sdk-sample-objc
//
//  Copyright © 2017 DocuSign. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DownloadTemplateCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UILabel * nameLabel;
@property (weak, nonatomic) IBOutlet UIButton * downloadButton;

@end
