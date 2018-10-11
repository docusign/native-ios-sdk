//
//  PolicyViewController.m
//  docusign-sdk-sample-objc
//
//  Copyright © 2017 DocuSign. All rights reserved.
//

#import "PolicyViewController.h"
#import "ProfileManager.h"


@interface PolicyViewController ()

// ui view and text fields
@property (nonatomic, strong) IBOutlet UIView * vw_clientInfo;
@property (nonatomic, strong) IBOutlet UIView * vw_clientAddress;
@property (nonatomic, strong) IBOutlet UIView * vw_clientContact;

@property (nonatomic, strong) IBOutlet UIBarButtonItem * barButtonNext;

@property (nonatomic, strong) IBOutlet UITextField * tf_policyNum;
@property (nonatomic, strong) IBOutlet UITextField * tf_firstName;
@property (nonatomic, strong) IBOutlet UITextField * tf_lastName;
@property (nonatomic, strong) IBOutlet UITextField * tf_address;
@property (nonatomic, strong) IBOutlet UITextField * tf_city;
@property (nonatomic, strong) IBOutlet UITextField * tf_state;
@property (nonatomic, strong) IBOutlet UITextField * tf_country;
@property (nonatomic, strong) IBOutlet UITextField * tf_zipCode;
@property (nonatomic, strong) IBOutlet UITextField * tf_phone;
@property (nonatomic, strong) IBOutlet UITextField * tf_email;
@property (nonatomic, strong) IBOutlet UITextField * tf_driversLicense;
@property (nonatomic, strong) IBOutlet UITextField * tf_licensePlate;

@end


@implementation PolicyViewController


#pragma mark - UI Lifecycle Methods

- (void) viewDidLoad
{
    [super viewDidLoad];
    [self styleUIElements];
}


#pragma mark - IBAction Methods

- (IBAction) searchButtonTapped:(id)sender
{
    // unhide the client info
    self.vw_clientInfo.hidden = FALSE;
    self.vw_clientAddress.hidden = FALSE;
    self.vw_clientContact.hidden = FALSE;

    // load client data for the specified policy number
    [self loadClientInfo:self.tf_policyNum.text];
    
    // enable next button
    self.barButtonNext.enabled = TRUE;
}


- (IBAction) nextButtonTapped:(id)sender
{
    // save client info
    NSDictionary * clientInfoDict = [self createClientInfoDict];
    [[ProfileManager sharedInstance] setClientInfo:clientInfoDict];
    
    // segue to damage screen
    [self performSegueWithIdentifier:@"segue_policy_damage" sender:sender];
}


#pragma mark - Private Methods

- (void) loadClientInfo:(NSString *)policyNum
{

    NSDictionary * clientInfo = [ProfileManager getFakeClientInfo];

    // populate client info fields
    self.tf_firstName.text = clientInfo[@"firstName"];
    self.tf_lastName.text = clientInfo[@"lastName"];
    self.tf_address.text = clientInfo[@"address"];
    self.tf_city.text = clientInfo[@"city"];
    self.tf_state.text = clientInfo[@"state"];
    self.tf_country.text = clientInfo[@"country"];
    self.tf_zipCode.text = clientInfo[@"zipCode"];
    self.tf_phone.text = clientInfo[@"phone"];
    self.tf_email.text = clientInfo[@"email"];
    self.tf_driversLicense.text = clientInfo[@"driversLicense"];
    self.tf_licensePlate.text = clientInfo[@"licensePlate"];

}


- (NSDictionary *) createClientInfoDict
{
    NSDictionary * clientInfo = @{@"policyNum":self.tf_policyNum.text,
                                  @"firstName":self.tf_firstName.text,
                                  @"lastName":self.tf_lastName.text,
                                  @"address":self.tf_address.text,
                                  @"city":self.tf_city.text,
                                  @"state":self.tf_state.text,
                                  @"country":self.tf_country.text,
                                  @"zipCode":self.tf_zipCode.text,
                                  @"phone":self.tf_phone.text,
                                  @"email":self.tf_email.text,
                                  @"driversLicense":self.tf_driversLicense.text,
                                  @"licensePlate":self.tf_licensePlate.text
                                  };
    return clientInfo;
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
}


@end
