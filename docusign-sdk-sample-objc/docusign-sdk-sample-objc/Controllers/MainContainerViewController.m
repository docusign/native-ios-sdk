//
//  MainContainerViewController.m
//  docusign-sdk-sample-objc
//
//  Copyright © 2017 DocuSign. All rights reserved.
//

#import "MainContainerViewController.h"

#import "AppDelegate.h"
#import <DocuSignSDK/DocuSignSDK.h>
#import "DownloadsViewController.h"


@interface MainContainerViewController ()

#pragma mark - Properties

// ui elements
@property (weak, nonatomic) IBOutlet UIView * customNavTitle;
@property (weak, nonatomic) IBOutlet UIView * claimsContainer;
@property (weak, nonatomic) IBOutlet UIView * downloadsContainer;
@property (weak, nonatomic) IBOutlet UIBarButtonItem * editBarButton;
@property (weak, nonatomic) IBOutlet UISegmentedControl * segmentedControl;

// reference to the embeded downloads view controller
// used to reference ui objects inside container from outer nav bar
@property (weak, nonatomic) DownloadsViewController * downloadsVC;

@end


@implementation MainContainerViewController


#pragma mark - Private Variables

// used to track if downloads table view is in edit mode
bool editModeEnabled = FALSE;


#pragma mark - UI Lifecycle Methods

- (void) viewDidLoad
{
    [super viewDidLoad];
    [self styleUIElements];

    // register for envelope signing completed event
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleEnvelopeSignedNotification:)
                                                 name:DSMSigningCompletedNotification object:nil];

    // hide edit button from nav bar
    self.editBarButton.enabled = FALSE;
    self.editBarButton.title = @"";
}


- (void) viewWillAppear:(BOOL)animated
{
    // allow only portrait orientation
    AppDelegate * appDelegate = (AppDelegate *)[UIApplication sharedApplication].delegate;
    appDelegate.restrictRotation = TRUE;
}


- (void) prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    NSString * segueName = segue.identifier;
    if ([segueName isEqualToString: @"downloads_embed"])
    {
        // capture a reference to the downloads view controller
        self.downloadsVC = (DownloadsViewController *) [segue destinationViewController];
    }
}


#pragma mark - IBAction Methods

- (IBAction) segmentValueChanged:(id)sender
{
    UISegmentedControl *segment = sender;
    
    switch(segment.selectedSegmentIndex)
    {
        case 0:
            // show claims screen
            self.editBarButton.enabled = FALSE;
            self.editBarButton.title = @"";
            self.claimsContainer.hidden = FALSE;
            break;
        case 1:
            // show downloads screen
            self.editBarButton.enabled = TRUE;
            self.editBarButton.title = @"Edit";
            self.claimsContainer.hidden = TRUE;
            break;
        default:
            break;
    }
}


- (IBAction) editBarButtonTapped:(id)sender
{
    if (editModeEnabled)
    {
        // end edit mode on tableview
        editModeEnabled = FALSE;
        self.editBarButton.title = @"Edit";
        [self.downloadsVC endEditModeOnTableView];
    }
    else
    {
        // enter edit mode on tableview
        editModeEnabled = TRUE;
        self.editBarButton.title = @"Cancel";
        [self.downloadsVC startEditModeOnTableView];
    }
}


#pragma mark - Event Handlers

/**
 Handles notification when envelope is signed.
 @param notification The notification event object.
 */
- (void) handleEnvelopeSignedNotification:(NSNotification *)notification
{
    //[[[DSMEnvelopesManager alloc] init] syncEnvelopes];
    NSLog(@"handleEnvelopeSignedNotification received: Envelope was signed.");
    NSLog(@"Created a new envelope: %@",notification);
}


#pragma mark - Private Methods

- (void) styleUIElements
{
    // add custom nav title
    UIView * navTitleView = [[[NSBundle mainBundle] loadNibNamed:@"CustomNavTitle" owner:self options:nil] lastObject];
    self.navigationItem.titleView = navTitleView;

    // set font for segmented control
    [self.segmentedControl setTitleTextAttributes:@{NSFontAttributeName:[UIFont fontWithName:@"OpenSans-Regular" size:12.0]} forState:UIControlStateNormal];
}


@end
