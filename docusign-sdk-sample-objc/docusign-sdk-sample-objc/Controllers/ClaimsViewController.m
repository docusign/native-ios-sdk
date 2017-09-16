//
//  ClaimsViewController.m
//  docusign-sdk-sample-objc
//
//  Copyright © 2017 DocuSign. All rights reserved.
//

#import "ClaimsViewController.h"

#import "AppDelegate.h"
#import <DocuSignSDK/DocuSignSDK.h>
#import "EnvelopesManager.h"
#import "ProfileManager.h"
#import "ProgressHUD.h"


@interface ClaimsViewController ()

// ui elements
@property (nonatomic, strong) IBOutlet UITableView * tableView;
@property (nonatomic, strong) IBOutlet UILabel * lbl_claimsToBeSynced;
@property (nonatomic, strong) UIRefreshControl * refreshController;

// properties
@property (nonatomic, strong) NSArray<DSMEnvelopeDefinition *> * mEnvelopeDefinitions;
@property (nonatomic, strong) NSArray<NSString *> * mEnvelopeIds;

@end


@implementation ClaimsViewController


#pragma mark - UI Lifecycle Methods

- (void) viewDidLoad
{
    [super viewDidLoad];

    // subscribe to events for syncing envelopes
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector
     (handleEnvelopeSyncingSucceededNotification:) name:DSMEnvelopeSyncingSucceededNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector
     (handleEnvelopeSyncingFailedNotification:) name:DSMEnvelopeSyncingFailedNotification object:nil];

    // add refresh control for table view
    self.refreshController = [[UIRefreshControl alloc] init];
    [self.refreshController addTarget:self action:@selector(handleTableRefresh:)
                     forControlEvents:UIControlEventValueChanged];
    [self.tableView addSubview:self.refreshController];
}


- (void) viewWillAppear:(BOOL)animated
{
    // allow only portrait orientation
    AppDelegate * appDelegate = (AppDelegate *)[UIApplication sharedApplication].delegate;
    appDelegate.restrictRotation = TRUE;

    // retrieve cached envelopes
    [self fetchEnvelopeList];

    // check if envelopes waiting to be cached
    long claimsCount = [self.mEnvelopeIds count];
    if (claimsCount > 0)
    {
        [self promptToSyncEnvelopes];
    }
}


#pragma mark - Private Methods

- (void) fetchEnvelopeList
{
    // retrieve list of envelopes
    self.mEnvelopeIds = [[EnvelopesManager sharedInstance] getCachedEnvelopeIds];

    // display number of envelopes waiting to be synced
    self.lbl_claimsToBeSynced.text = [NSString stringWithFormat:@"COMPLETED CLAIMS TO BE SYNCED: %li", [self.mEnvelopeIds count]];
    
    // refresh table view
    [self.tableView reloadData];
}


- (void)handleTableRefresh: (id)sender
{
    // retrieve cached envelopes
    [self fetchEnvelopeList];

    [self.refreshController endRefreshing];
}


- (void) promptToSyncEnvelopes
{
    UIAlertAction *syncAction = [UIAlertAction actionWithTitle:@"Sync Claims" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {

        // sync envelopes
        [ProgressHUD show:@"Sync Claims..."];
        [[EnvelopesManager sharedInstance] syncCachedEnvelopes];
    }];
    
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"Don't Sync" style:UIAlertActionStyleCancel handler:nil];
    
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"Developer's Notes" message:@"For sample purposes, we've drawn attention to the fact that completed envelopes need to sync with the server. However, you will likely want to detect when a network connection is available and perform this task in the background." preferredStyle:UIAlertControllerStyleAlert];
    
    [alertController addAction:syncAction];
    [alertController addAction:cancelAction];
    [self presentViewController:alertController animated:YES completion:nil];
}


#pragma mark - TableView Delegate Methods

- (NSInteger) tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    //return [self.mEnvelopeDefinitions count];
    return [self.mEnvelopeIds count];
}


- (UITableViewCell *) tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *tableCellId = @"EnvelopeCell";
    
    // reuse cell object (or create a new object if needed)
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:tableCellId];
    if (cell == nil)
    {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:tableCellId];
    }
    
    // display envelope id/name
    NSString * envelopeId = [self.mEnvelopeIds objectAtIndex:indexPath.row];
    cell.textLabel.text = [NSString stringWithFormat:@"%@", envelopeId];

    return cell;
}


#pragma mark - Event Handlers

/**
 Handles notification when envelope syncing succeeds.
 @param notification The notification event object.
 */
- (void) handleEnvelopeSyncingSucceededNotification:(NSNotification *)notification
{
    dispatch_async(dispatch_get_main_queue(), ^{
        NSLog(@"Envelope syncing succeeded");
        // refresh list
        [self fetchEnvelopeList];
        [ProgressHUD dismiss];
    });
}


/**
 Handles notification when envelope syncing fails.
 @param notification The notification event object.
 */
- (void) handleEnvelopeSyncingFailedNotification:(NSNotification *)notification
{
    dispatch_async(dispatch_get_main_queue(), ^{
        NSLog(@"Envelope syncing failed");
        // refresh list
        [self fetchEnvelopeList];
        [ProgressHUD dismiss];
    });
}


@end
