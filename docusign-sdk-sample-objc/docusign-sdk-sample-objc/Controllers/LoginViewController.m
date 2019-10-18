//
//  LoginViewController.m
//  docusign-sdk-sample-objc
//
//  Copyright © 2017 DocuSign. All rights reserved.
//

#import "LoginViewController.h"

#import "AppDelegate.h"
#import <DocuSignSDK/DocuSignSDK.h>
#import <ProgressHUD/ProgressHUD.h>
#import "ProfileManager.h"

@interface LoginViewController () <UITextFieldDelegate>

// ui elements
@property (nonatomic, strong) IBOutlet UITextField * usernameInput;
@property (nonatomic, strong) IBOutlet UITextField * passwordInput;

@end


@implementation LoginViewController


#pragma mark - UI Lifecycle Methods

- (void) viewDidLoad
{
    [super viewDidLoad];
   
    // pre-populate the user credentials fields with defaults (if provided)
    NSDictionary * defaultUserCredentials = [ProfileManager getDefaultUserCredentials];
    self.usernameInput.text = defaultUserCredentials[@"defaultUsername"];
    self.passwordInput.text = defaultUserCredentials[@"defaultPassword"];
    
    self.passwordInput.delegate = self;
}


- (void) viewWillAppear:(BOOL)animated
{
    // screen should only display portrait
    AppDelegate* appDelegate = (AppDelegate*)[UIApplication sharedApplication].delegate;
    appDelegate.restrictRotation = TRUE;
}


#pragma mark - IBAction Methods

- (IBAction) loginButtonTapped:(UIButton *)sender
{

    [ProgressHUD show:@"Authenticating..."];

    NSString * email = self.usernameInput.text;
    NSString * password = self.passwordInput.text;
    
    // check username and password formats are valid
    if ([self isUsernameFormatValid:email] && [self isPasswordFormatValid:password]) {
        
        // log user into docusign api
        NSString * integratorKey = [ProfileManager getIntegratorKey];
        NSString * hostApiUrl = [ProfileManager getHostApiUrl];
        [DSMManager loginWithEmail:email password:password integratorKey:integratorKey host:[NSURL URLWithString:hostApiUrl] completion:^(DSMAccountInfo *accountInfo, NSError *error) {
            
                if (error != nil) {
                    NSLog(@"An error occurred attempting to log into DocuSign: %@", error);
                    [ProgressHUD dismiss];
                    
                    // display alert to user
                    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"Login Failed"
                                                                                             message:error.localizedDescription
                                                                                      preferredStyle:UIAlertControllerStyleAlert];
                    UIAlertAction *actionOk = [UIAlertAction actionWithTitle:@"Ok" style:UIAlertActionStyleDefault handler:nil];
                    [alertController addAction:actionOk];
                    [self presentViewController:alertController animated:TRUE completion:nil];
                }
                else {
                    NSLog(@"User Authenticated");
                    [ProgressHUD dismiss];

                    // proceed to app main nav
                    [self performSegueWithIdentifier:@"segueMainNav" sender:self];
                }
            }];
    }
}

- (IBAction)passwordFieldPrimaryAction:(id)sender {
    [sender resignFirstResponder];
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    [self.passwordInput resignFirstResponder];
    return YES;
}

#pragma mark - Private Methods

- (bool) isUsernameFormatValid:(NSString *)username
{
    // check username is non-empty
    // TODO perform additional validation
    return (username.length > 0);
}


- (bool) isPasswordFormatValid:(NSString *)password
{
    // check password is non-empty
    // TODO Perform additional validation
    return (password.length > 0);
}


@end
