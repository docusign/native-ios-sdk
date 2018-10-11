//
//  TemplatesViewController.m
//  docusign-sdk-sample-objc
//
//  Copyright © 2017 DocuSign. All rights reserved.
//

#import "TemplatesViewController.h"

#import <DocuSignSDK/DocuSignSDK.h>
#import "AppDelegate.h"
#import "DownloadTemplateCell.h"
#import "ProfileManager.h"
#import "ProgressHUD.h"
#import "TemplatesManager.h"
#import "EnvelopesManager.h"

@interface TemplatesViewController ()

@property (nonatomic, strong) TemplatesManager * mTemplatesManager;
@property (nonatomic, strong) EnvelopesManager * mEnvelopesManager;
@property (nonatomic, strong) NSArray<DSMEnvelopeTemplateDefinition *> * mTemplateList;
@property (nonatomic, strong) UIRefreshControl * refreshController;

@end


@implementation TemplatesViewController

static NSString *tableCellId = @"downloadTemplateCell";


#pragma mark - UI Lifecycle Methods

- (void) viewDidLoad
{
    [super viewDidLoad];
    [self styleUIElements];

    // attach template manager
    self.mTemplatesManager = [TemplatesManager sharedInstance];
    self.mEnvelopesManager = [EnvelopesManager sharedInstance];
    
    // add refresh control for table view
    self.refreshController = [[UIRefreshControl alloc] init];
    [self.refreshController addTarget:self action:@selector(handleTableRefresh:)
                     forControlEvents:UIControlEventValueChanged];
    [self.tableView addSubview:self.refreshController];
}


- (void) viewWillAppear:(BOOL)animated
{
    // get list of template definitions
    [self fetchTemplateList];

    // allow landscape orientation for sdk screens
    AppDelegate * appDelegate = (AppDelegate *)[UIApplication sharedApplication].delegate;
    appDelegate.restrictRotation = NO;
}

#pragma mark - actions

- (IBAction)onOfflineClaimTapped:(id)sender {
    
    [self promptDevActionWithHandler:^(DSMSigningMode signingMode) {
        if (@available(iOS 11.0, *)) {
            [self.mEnvelopesManager presentComposeEnvelopeViewControllerWithPresentingController:self signingMode:signingMode];
        } else {
            UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"iCloud Entitlement required" message:@"For iOS 10 and below, iCloud entitlements must be added and DSM_SETUP_ICLOUD_DOCUMENT_ENABLED set to true for document picker usage." preferredStyle:UIAlertControllerStyleAlert];
            UIAlertAction *action = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
                [self.mEnvelopesManager presentComposeEnvelopeViewControllerWithPresentingController:self signingMode:signingMode];
            }];
            
            [alertController addAction:action];
            [self presentViewController:alertController animated:YES completion:nil];
        }
    }];
    
}

#pragma mark - TableView Delegate Methods

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.mTemplateList count];
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    // reuse cell object (or create a new object if needed)
    DownloadTemplateCell *cell = [tableView dequeueReusableCellWithIdentifier:tableCellId];
    if (cell == nil)
    {
        [tableView registerNib:[UINib nibWithNibName:@"DownloadTemplateCell" bundle:nil] forCellReuseIdentifier:tableCellId];
        cell = [tableView dequeueReusableCellWithIdentifier:tableCellId];
    }
    return cell;
}


- (void)tableView:(UITableView *)tableView willDisplayCell:(nonnull DownloadTemplateCell *)cell forRowAtIndexPath:(nonnull NSIndexPath *)indexPath
{
    DSMEnvelopeTemplateDefinition * template = [self.mTemplateList objectAtIndex:indexPath.row];

    // set name label
    cell.nameLabel.text = template.name;
    
    // determine image for accessory button
    if ([self.mTemplatesManager templateIsCachedWithId:template.templateId]) {
        // template is already cached
        [cell setAccessoryType:UITableViewCellAccessoryDisclosureIndicator];
        [cell.downloadButton setBackgroundImage:nil forState:UIControlStateNormal];
    }
    else
    {
        // template needs to be downloaded
        [cell.downloadButton setBackgroundImage:[UIImage imageNamed:@"download"] forState:UIControlStateNormal];
        [cell.downloadButton addTarget:self action:@selector(downloadTemplate:withEvent:)
                      forControlEvents:UIControlEventTouchUpInside];
    }
}


- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    DSMEnvelopeTemplateDefinition * template = [self.mTemplateList objectAtIndex:indexPath.row];
    
    // if template is already cached, then move to policy screen
    if ([self.mTemplatesManager templateIsCachedWithId:template.templateId])
    {
        // capture the selected template id
        [[ProfileManager sharedInstance] setClientTemplateId:template.templateId];
        
        // segue to policy screen
        [self performSegueWithIdentifier:@"segue_claim_policy"
                                  sender:[self.tableView cellForRowAtIndexPath:indexPath]];
    }
}


#pragma mark - Private Methods

- (void) fetchTemplateList
{
    [self.mTemplatesManager getTemplateListWithCompletion:^(NSArray<DSMEnvelopeTemplateDefinition*>* templates) {
        
        // store template defitions
        self.mTemplateList = templates;
        
        // refresh table view
        [self.tableView reloadData];
    }];
}


- (void) downloadTemplate:(UIControl *)button withEvent:(UIEvent *)event
{
    long rowIndex = [self getIndexForTableCell:event];
    
    [ProgressHUD show:@"Downloading..."];
    
    NSString * templateId = [self.mTemplateList objectAtIndex:rowIndex].templateId;
    [self.mTemplatesManager cacheTemplateWithId:templateId withCompletion:^(NSString * errorMsg) {
        [ProgressHUD dismiss];
        
        if (errorMsg == nil)
        {
            [self.tableView reloadData];
        }
        else
        {
            [self displayErrorPrompt:errorMsg];
        }
    }];
}


- (void)handleTableRefresh: (id)sender
{
    // retrieve template list
    [self fetchTemplateList];
    [self.refreshController endRefreshing];
}


- (long) getIndexForTableCell:(UIEvent *)event
{
    // determine the index of item tapped
    NSSet *touches = [event allTouches];
    UITouch *touch = [touches anyObject];
    CGPoint currentTouchPosition = [touch locationInView:self.tableView];
    NSIndexPath *indexPath = [self.tableView indexPathForRowAtPoint: currentTouchPosition];
    
    if (indexPath == nil)
        return -1;
    else
        return indexPath.row;
}


- (void) displayErrorPrompt:(NSString *)errorMessage
{
    NSLog(@"Error: %@", errorMessage);
    
    // display error alert
    UIAlertController * alertController = [UIAlertController alertControllerWithTitle:@"Error" message:errorMessage
                                                                       preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction * okAction = [UIAlertAction actionWithTitle:@"Ok" style:UIAlertActionStyleDefault handler:nil];
    [alertController addAction:okAction];
    [self presentViewController:alertController animated:YES completion:nil];
}


- (void) styleUIElements
{
    // add custom nav title
    UIView * navTitleView = [[[NSBundle mainBundle] loadNibNamed:@"CustomNavTitle" owner:self options:nil] lastObject];
    self.navigationItem.titleView = navTitleView;
}

- (void) promptDevActionWithHandler:(void(^)(DSMSigningMode signingMode))handler
{
    UIAlertAction *onlineAction = [UIAlertAction actionWithTitle:@"Online Envelope" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        handler(DSMSigningModeOnline);
    }];
    UIAlertAction *offlineAction = [UIAlertAction actionWithTitle:@"Offline Envelope" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        handler(DSMSigningModeOffline);
    }];
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:nil];
    
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"Developer's Notes" message:@"You can either compose an envelope in online or offline mode. You would need to check for network connectivity and present the appropriate view controller." preferredStyle:UIAlertControllerStyleAlert];
    
    [alertController addAction:onlineAction];
    [alertController addAction:offlineAction];
    [alertController addAction:cancelAction];
    [self presentViewController:alertController animated:YES completion:nil];
}

@end
