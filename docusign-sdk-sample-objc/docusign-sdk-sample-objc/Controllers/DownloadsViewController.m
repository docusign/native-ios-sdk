//
//  DownloadsViewController.m
//  docusign-sdk-sample-objc
//
//  Copyright © 2017 DocuSign. All rights reserved.
//

#import "DownloadsViewController.h"

#import "AppDelegate.h"
#import <DocuSignSDK/DocuSignSDK.h>
#import "DownloadTemplateCell.h"
#import "ProgressHUD.h"
#import "TemplatesManager.h"


@interface DownloadsViewController ()

// properties
@property (nonatomic, strong) TemplatesManager * mTemplatesManager;
@property (nonatomic, strong) NSArray<DSMEnvelopeTemplateDefinition *> * mTemplateList;
@property (nonatomic, strong) UIRefreshControl * refreshController;

@end


@implementation DownloadsViewController


#pragma mark - Private Variables

static NSString *tableCellId = @"downloadTemplateCell";


#pragma mark - UI Lifecycle Methods

- (void) viewDidLoad
{
    [super viewDidLoad];

    // attach template manager
    self.mTemplatesManager = [TemplatesManager sharedInstance];

    // add refresh control for table view
    self.refreshController = [[UIRefreshControl alloc] init];
    [self.refreshController addTarget:self action:@selector(handleTableRefresh:)
                     forControlEvents:UIControlEventValueChanged];
    [self.tableView addSubview:self.refreshController];
}


- (void) viewWillAppear:(BOOL)animated
{
    AppDelegate* appDelegate = (AppDelegate*)[UIApplication sharedApplication].delegate;
    appDelegate.restrictRotation = TRUE;

    // get list of template definitions
    [self fetchTemplateList];
}


#pragma mark - Protocol ContainerWithTableView

- (void) startEditModeOnTableView
{
    [self.tableView setEditing:YES animated:YES];
}


- (void) endEditModeOnTableView
{
    [self.tableView setEditing:NO animated:YES];
}


#pragma mark - TableView Delegate Methods

- (NSInteger) tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.mTemplateList count];
}


- (UITableViewCell *) tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
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
    
    // set template name
    cell.nameLabel.text = template.name;
    
    // determine image for accessory button
    if ([self.mTemplatesManager templateIsCachedWithId:template.templateId])
    {
        // template is already cached
        [cell.downloadButton setBackgroundImage:[UIImage imageNamed:@"download_done"] forState:UIControlStateNormal];
        [cell.downloadButton removeTarget:self action:nil forControlEvents:UIControlEventTouchUpInside];
    }
    else
    {
        // template needs to be downloaded
        [cell.downloadButton setBackgroundImage:[UIImage imageNamed:@"download"] forState:UIControlStateNormal];
        [cell.downloadButton addTarget:self action:@selector(downloadTemplate:withEvent:)
                      forControlEvents:UIControlEventTouchUpInside];
    }
}


- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    if (editingStyle == UITableViewCellEditingStyleDelete)
    {
        // remove template based on user delete
        DSMEnvelopeTemplateDefinition * template = [self.mTemplateList objectAtIndex:indexPath.row];
        [self.mTemplatesManager removeTemplateWithId:template.templateId];
        
        // reload data to update template download status
        [self.tableView reloadData];
    }
}


- (NSString *) tableView:(UITableView *)tableView titleForDeleteConfirmationButtonForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return @"Uncache";
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
    NSLog(@"Row Selected: %ld", rowIndex);
 
    [ProgressHUD show:@"Downloading..."];

    NSString * templateId = [self.mTemplateList objectAtIndex:rowIndex].templateId;
    [self.mTemplatesManager cacheTemplateWithId:templateId withCompletion:^(NSString * errorMsg) {
        [ProgressHUD dismiss];

        if (errorMsg == nil) {
            [self.tableView reloadData];
        }
        else {
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


@end
