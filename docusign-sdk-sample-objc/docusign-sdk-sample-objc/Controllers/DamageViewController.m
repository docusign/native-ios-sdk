//
//  DamageViewController.m
//  docusign-sdk-sample-objc
//
//  Copyright © 2017 DocuSign. All rights reserved.
//

#import "DamageViewController.h"
#import "ProfileManager.h"
#import "ConfigurationConstants.h"


@interface DamageViewController ()

// ui elements
@property (nonatomic, strong) IBOutlet UIBarButtonItem * barButtonNext;
@property (nonatomic, strong) IBOutlet UITextField * tf_damageDate;
@property (nonatomic, strong) IBOutlet UITextField * tf_damageType;
@property (nonatomic, strong) IBOutlet UITextField * tf_damageEstimate;
@property (nonatomic, strong) IBOutlet UITextView * tv_damageComments;

@end


@implementation DamageViewController


#pragma mark - UI Lifecycle Methods

- (void) viewDidLoad
{
    [super viewDidLoad];
    [self styleUIElements];
    
    // for sample, pre-populate fake damage info
    [self loadDamageInfo];
}


#pragma mark - IBAction Methods

- (IBAction) nextButtonTapped:(id)sender
{
    // save damage info
    [[ProfileManager sharedInstance] setDamageInfo:[self createDamageInfoDict]];
    
    // for demo: determine whether user wants online or offline flow
    if (CONFIGURATION_SHOW_OFFLINE_ONLINE_SIGNING_DEV_PROMPT) {
        [self promptOnlineOrOffline];
    } else {
        if (CONFIGURATION_DEFAULT_TO_OFFLINE_SIGNING) {
            [[ProfileManager sharedInstance] setOfflineFlow:YES];
        } else {
            [[ProfileManager sharedInstance] setOfflineFlow:NO];
        }
        [self performSegueWithIdentifier:@"segue_docusign" sender:self];
    }
}


#pragma mark - Private Methods

- (void) loadDamageInfo
{
    // for demo: populate damage info fields with fake data
    NSDictionary * damageInfo = [ProfileManager getFakeDamageInfo];
    self.tf_damageType.text = damageInfo[@"damageType"];
    self.tf_damageDate.text = damageInfo[@"damageDate"];
    self.tf_damageEstimate.text = damageInfo[@"damageEstimate"];
    self.tv_damageComments.text = damageInfo[@"damageComments"];
}


- (NSDictionary *) createDamageInfoDict
{
    NSDictionary * damageInfo = @{@"damageType":self.tf_damageType.text,
                                  @"damageDate":self.tf_damageDate.text,
                                  @"damageEstimate":self.tf_damageEstimate.text,
                                  @"damageComments":self.tv_damageComments.text
                                  };
    return damageInfo;
}


- (void) promptOnlineOrOffline
{
    UIAlertAction *selectOfflineAction = [UIAlertAction actionWithTitle:@"Offline" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        NSLog(@"User selected offline flow");
        [[ProfileManager sharedInstance] setOfflineFlow:TRUE];
        
        // for offline flow, segue to attachment screen
        [self performSegueWithIdentifier:@"segue_damage_attachment" sender:self];
    }];
    
    UIAlertAction *selectOnlineAction = [UIAlertAction actionWithTitle:@"Online" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        NSLog(@"User selected online flow");
        [[ProfileManager sharedInstance] setOfflineFlow:FALSE];

        // for offline flow, segue to attachment screen
        [self performSegueWithIdentifier:@"segue_docusign" sender:self];
    }];
    
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:nil];
    
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"Developer's Notes" message:@"Would you like to proceed with the offline or online signing flow?" preferredStyle:UIAlertControllerStyleAlert];

    [alertController addAction:selectOfflineAction];
    [alertController addAction:selectOnlineAction];
    [alertController addAction:cancelAction];
    [self presentViewController:alertController animated:YES completion:nil];
}


// dismiss the keyboard when user taps return
- (BOOL) textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return TRUE;
}


// dismiss the keyboard when user taps outside
- (void) touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    [[self view] endEditing:TRUE];
}


- (void) styleUIElements
{
    // add custom nav title
    UIView * navTitleView = [[[NSBundle mainBundle] loadNibNamed:@"CustomNavTitle" owner:self options:nil] lastObject];
    self.navigationItem.titleView = navTitleView;

    // comments textview
    UIColor *borderColor = [UIColor colorWithRed:204.0/255.0 green:204.0/255.0 blue:204.0/255.0 alpha:1.0];
    self.tv_damageComments.layer.borderColor = borderColor.CGColor;
    self.tv_damageComments.layer.borderWidth = 1.0;
    self.tv_damageComments.layer.cornerRadius = 5.0;
}


@end
