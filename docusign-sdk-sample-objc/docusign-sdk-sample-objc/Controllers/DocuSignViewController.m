//
//  DocuSignViewController.m
//  docusign-sdk-sample-objc
//
//  Copyright © 2017 DocuSign. All rights reserved.
//


#import "DocuSignViewController.h"

#import "AppDelegate.h"
#import <DocuSignSDK/DocuSignSDK.h>
#import "ProfileManager.h"
#import "TemplatesManager.h"


@interface DocuSignViewController ()
@end


@implementation DocuSignViewController


#pragma mark - UI Lifecycle Methods

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self styleUIElements];

    // set sdk styling
    [DSMAppearance setNavigationBarTintColor:[ProfileManager getAppNavColor]];
    [DSMAppearance setBarButtonItemsTintColor:[ProfileManager getAppBarItemsColor]];

    ProfileManager * profileManager = [ProfileManager sharedInstance];
    // retrieve the selected template id
    NSString * templateId = [profileManager getClientTemplateId];
    
    // retrieve client data for insertion into template
    NSDictionary * tabData = [profileManager getTemplateTabData];
    
    BOOL useOffline = [profileManager useOfflineFlow];
    
    NSString * attachmentPath = [profileManager getAttachmentPath];
    
    // display template via sdk
    [[TemplatesManager sharedInstance] displayTemplateForSignature:templateId forController:self withTabs:tabData useOfflineFlow:useOffline withAttachmentAtPath:attachmentPath withCompletion:^(UIViewController * controller, NSError *error)
     {
         NSLog(@"Done displaying template.");

         // return to claims screen
         [self.navigationController popToRootViewControllerAnimated:TRUE];
     }];
}


- (void) viewWillAppear:(BOOL)animated
{
    // allow landscape orientation for sdk screens
    AppDelegate * appDelegate = (AppDelegate *)[UIApplication sharedApplication].delegate;
    appDelegate.restrictRotation = NO;
}


- (void) styleUIElements
{
    // add custom nav title
    UIView * navTitleView = [[[NSBundle mainBundle] loadNibNamed:@"CustomNavTitle" owner:self options:nil] lastObject];
    self.navigationItem.titleView = navTitleView;
}


@end
