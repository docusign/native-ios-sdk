//
//  AttachmentViewController.m
//  docusign-sdk-sample-objc
//
//  Copyright © 2017 DocuSign. All rights reserved.
//

#import "AttachmentViewController.h"

#import "AppDelegate.h"
#import "ProfileManager.h"


@interface AttachmentViewController ()

// ui elements
@property (nonatomic, strong) IBOutlet UIBarButtonItem * bt_skip;
@property (nonatomic, strong) IBOutlet UIButton * bt_attachDoc;
@property (nonatomic, strong) IBOutlet UIWebView * wv_document;

@end


@implementation AttachmentViewController


#pragma mark - UI Lifecycle Methods

- (void) viewDidLoad
{
    [super viewDidLoad];
    [self styleUIElements];
}


- (void) viewWillAppear:(BOOL)animated
{
    // allow only portrait orientation
    AppDelegate* appDelegate = (AppDelegate*)[UIApplication sharedApplication].delegate;
    appDelegate.restrictRotation = TRUE;
}


#pragma mark - IBAction Methods

- (IBAction)addAttachment:(id)sender
{
    // display PDF attachment
    NSString * path = [[NSBundle mainBundle] pathForResource:@"AccidentChecklist" ofType:@"pdf"];
    NSURL * targetURL = [NSURL fileURLWithPath:path];
    NSURLRequest * request = [NSURLRequest requestWithURL:targetURL];
    [self.wv_document loadRequest:request];
    [self.wv_document setHidden:FALSE];

    // hide attach button
    [self.bt_attachDoc setHidden:TRUE];

    // update navigation button
    self.bt_skip.title = @"Next";
    
    // capture attachment url
    [[ProfileManager sharedInstance] setAttachmentPath:path];

    // display developer's prompt
    if ([ProfileManager displayDeveloperNotes]) {
        [self promptAttachmentIncluded];
    }
}


#pragma mark - Private Methods

- (void) styleUIElements
{
    // add custom nav title
    UIView * navTitleView = [[[NSBundle mainBundle] loadNibNamed:@"CustomNavTitle" owner:self options:nil] lastObject];
    self.navigationItem.titleView = navTitleView;

    // border for attachment button
    UIColor * borderColor = [UIColor colorWithRed:7.0/255.0 green:62.0/255.0 blue:87.0/255.0 alpha:1.0];
    [self.bt_attachDoc.layer setBorderWidth:1.0];
    [self.bt_attachDoc.layer setBorderColor:[borderColor CGColor]];
}


- (void) promptAttachmentIncluded
{
    // display developer's notes regarding PDF attachment
    UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:nil];
    
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"Developer's Notes" message:@"For sample purposes, we have included a PDF document that has been attached. Ordinarily, you would guide the user through selecting an external PDF document to attach to the envelope." preferredStyle:UIAlertControllerStyleAlert];
    
    [alertController addAction:okAction];
    [self presentViewController:alertController animated:YES completion:nil];
}


@end
