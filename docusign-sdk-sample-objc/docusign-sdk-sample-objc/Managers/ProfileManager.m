//
//  ProfileManager.m
//  docusign-sdk-sample-objc
//
//  Copyright © 2017 DocuSign. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DocuSignSDK/DocuSignSDK.h>
#import "ProfileManager.h"


@interface ProfileManager ()

@property (nonatomic, retain) NSString * mClientPolicyNum;
@property (nonatomic, retain) NSDictionary * mClientInfo;
@property (nonatomic, retain) NSDictionary * mDamageInfo;
@property (nonatomic, retain) NSString * mCurrentTemplateId;
@property (nonatomic, assign) BOOL mUseOfflineFlow;
@property (nonatomic, retain) NSString * mAttachmentPath;

@end


/*
 * Sample App Data
 * Update the values below with details from your developer sandbox account
 */

// default host api url
static NSString * const demoHostApi = @"https://demo.docusign.net/restapi";

// integrator key from your DS account goes here
static NSString * const integratorKey = @"<MY-INTEGRATOR-KEY-HERE>";

// optionally include credentials in order to pre-populate user login info
static NSString * const defaultUsername =  @"<MY-USERNAME-HERE>";
static NSString * const defaultPassword = @"<MY-PASSWORD-HERE>";

// keys for custom fields on template
static NSString * tabKey_name = @"Text f22e466c-b63a-47e8-bb8d-405a017def57";
static NSString * tabKey_policyNum = @"Text a32157b0-166f-4563-8331-c15870835f82";
static NSString * tabKey_damageDate = @"Text 2407d40f-8711-4457-a217-26b743ea8860";
static NSString * tabKey_damageType = @"Text 6e9f67ac-5e76-4a39-9b2f-f0777f0e3c1b";
static NSString * tabKey_damageEstimate = @"Text 59a404aa-1b09-4787-bfa3-61d04f288439";

// Momentum demo template
static NSString * templateIdMomemtumDemo = @"606f0e95-a419-4280-86ac-234913037962";
static NSString * tabLabelIdFullName = @"Text FullName";
static NSString * tabLabelIdAddressLine1 = @"Text Address Line 1";
static NSString * tabLabelIdAddressLine2 = @"Text Address Line 2";
static NSString * tabLabelIdAddressLine3 = @"Text Address Line 3";
static NSString * tabLabelIdClientNumber = @"Text Client Number";
static NSString * tabLabelIdInvestmentAmount = @"Text Investment Amount";

@implementation ProfileManager

#pragma mark - Static Methods

+ (UIColor *) getAppNavColor
{
    return [UIColor colorWithRed:7.0/255.0 green:62.0/255.0 blue:87.0/255.0 alpha:1.0];
}


+ (UIColor *) getAppBarItemsColor
{
    return [UIColor whiteColor];
}

+ (NSString *) getIntegratorKey
{
    return integratorKey;
}


+ (NSString *) getHostApiUrl
{
    return demoHostApi;
}


+ (NSDictionary *) getDefaultUserCredentials
{
    // return NSDictionary with default username & password
    return @{@"defaultUsername":defaultUsername, @"defaultPassword":defaultPassword};
}

+ (BOOL)autoDownloadTemplates {
    return NO;
}

+ (BOOL)displayDeveloperNotes {
    return NO;
}

+ (NSDictionary *) getFakeClientInfo
{
    NSDictionary * fakeClientInfo = @{@"policyNum":@"A1-34287-03", @"firstName":@"Tom", @"lastName":@"Wood", @"address":@"726 Tennessee St", @"city":@"San Francisco", @"state":@"California", @"country":@"U.S.A.", @"zipCode":@"94107", @"phone":@"415-555-1234", @"email":@"tom.wood@dsxtr.com", @"driversLicense":@"N2148870", @"licensePlate":@"6DZG261"};
    return fakeClientInfo;
}


+ (NSDictionary *) getFakeDamageInfo
{
    NSDictionary * fakeDamageInfo = @{@"damageType":@"Single Automobile Collision", @"damageDate":@"2017-04-14", @"damageEstimate":@"$12,000.00", @"damageComments":@"Driver lost control of the automobile, jumped the sidewalk and crashed into a tree. The incident occurred at dusk with a light rain falling. Poor visibility and wet pavement appear to have contributed to the incident."};
    return fakeDamageInfo;
}

+ (id) sharedInstance
{
    static ProfileManager * sharedManager = nil;
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedManager = [[self alloc] init];
        
        // init properties
        sharedManager.mClientPolicyNum = nil;
        sharedManager.mCurrentTemplateId = nil;
        sharedManager.mUseOfflineFlow = TRUE;
        sharedManager.mAttachmentPath = nil;
        
    });
    return sharedManager;
}


#pragma mark - Private Methods

- (void) setClientPolicyNum:(NSString *)policyNum
{
    self.mClientPolicyNum = policyNum;
}


- (NSString *) getClientPolicyNum
{
    return self.mClientPolicyNum;
}


- (void) setClientInfo:(NSDictionary *)clientInfo
{
    self.mClientInfo = clientInfo;
}


- (NSDictionary *) getClientInfo
{
    return self.mClientInfo;
}


- (void) setDamageInfo:(NSDictionary *)damageInfo
{
    self.mDamageInfo = damageInfo;
}


- (NSDictionary *) getDamageInfo
{
    return self.mDamageInfo;
}


- (void) setClientTemplateId:(NSString *)templateId
{
    self.mCurrentTemplateId = templateId;
}


- (NSString *) getClientTemplateId
{
    return self.mCurrentTemplateId;
}


- (void) setOfflineFlow:(BOOL)offlineFlowSelected
{
    self.mUseOfflineFlow = offlineFlowSelected;
}


- (BOOL) useOfflineFlow
{
    return self.mUseOfflineFlow;
}


- (void) setAttachmentPath:(NSString *)attachmentPath
{
    self.mAttachmentPath = attachmentPath;
}


- (NSString *) getAttachmentPath
{
    return self.mAttachmentPath;
}


/**
 Returns NSArray of the recipient data that will be passed into the template
 */
- (NSArray *)getTemplateRecipientDataForId:(NSString *)templateId {
    if (![templateId isEqualToString:templateIdMomemtumDemo]) {
        return nil;
    }
    
    /*Recipients can be defaulted using either RoleName or RecipientId.
     Using RoleName:
     recipientIPS1.recipientSelectorType = DSMEnvelopeDefaultsUniqueRecipientSelectorTypeRecipientRoleName;
     recipientIPS1.recipientRoleName = @"In Person Signer";
     */
    NSMutableArray *recipientDefaults = [NSMutableArray arrayWithCapacity:1];
    
    NSString *recipientIdIPS1 = @"18375691"; // IPS 1
    
    DSMRecipientDefault *recipientIPS1 = [[DSMRecipientDefault alloc] init];
    recipientIPS1.recipientId = recipientIdIPS1;
    recipientIPS1.recipientSelectorType = DSMEnvelopeDefaultsUniqueRecipientSelectorTypeRecipientId;
    recipientIPS1.recipientType = DSMRecipientTypeInPersonSigner;
    recipientIPS1.inPersonSignerName = @"Tom Wood";
    recipientIPS1.recipientName = @"docusignsdk user";
    recipientIPS1.recipientEmail = @"docusignsdk.user@dsxtr.com";
    
    [recipientDefaults addObject:recipientIPS1];
    
    return [recipientDefaults copy];
}


/**
 Returns NSDictionary of the data that will be passed into the template
 */
- (NSDictionary *) getTemplateTabDataForId:(NSString *)templateId
{
    // gather client data
    NSString * client_full_name = [NSString stringWithFormat:@"%@ %@",
                            self.mClientInfo[@"firstName"], self.mClientInfo[@"lastName"]];
    
    NSString * policyNum = [NSString stringWithFormat:@"%@",self.mClientInfo[@"policyNum"]];
    NSString * damageDate = [NSString stringWithFormat:@"%@",self.mDamageInfo[@"damageDate"]];
    NSString * damageType = [NSString stringWithFormat:@"%@",self.mDamageInfo[@"damageType"]];
    NSString * damageEstimate = [NSString stringWithFormat:@"%@",self.mDamageInfo[@"damageEstimate"]];
    NSString * addressLine1 = [NSString stringWithFormat:@"%@",self.mClientInfo[@"address"]];
    NSString * addressLine2 = [NSString stringWithFormat:@"%@ %@",self.mClientInfo[@"city"],self.mClientInfo[@"state"]];
    NSString * addressLine3 = [NSString stringWithFormat:@"%@ %@",self.mClientInfo[@"country"], self.mClientInfo[@"zipCode"]];

    if ([templateId isEqualToString:templateIdMomemtumDemo]) {
        // map the client data to custom fields in the template
        NSDictionary * tabData = @{tabLabelIdFullName:client_full_name,
                                   tabLabelIdClientNumber:policyNum,
                                   tabLabelIdAddressLine1:addressLine1,
                                   tabLabelIdAddressLine2:addressLine2,
                                   tabLabelIdAddressLine3:addressLine3,
                                   tabLabelIdInvestmentAmount:damageEstimate
                                   };
        return tabData;
    } else {
        // map the client data to custom fields in the template
        NSDictionary * tabData = @{tabKey_name:client_full_name,
                                   tabKey_policyNum:policyNum,
                                   tabKey_damageDate:damageDate,
                                   tabKey_damageType:damageType,
                                   tabKey_damageEstimate:damageEstimate
                                   };
        return tabData;
    }
}

/**
 Returns CustomFields that will be passed into the template
 */
- (DSMCustomFields *)getCustomFieldsDataForTemplateId:(NSString *)templateId {
    if (![templateId isEqualToString:templateIdMomemtumDemo]) {
        return nil;
    }
    
    //Create Text CustomField
    DSMTextCustomField *textCustomField = [[DSMTextCustomField alloc]init];
    textCustomField.name = @"Investor";
    textCustomField.value = @"Tom Wood";
    textCustomField.show = YES;
    
    //Link to CustomFields
    DSMCustomFields *customFields = [[DSMCustomFields alloc] init];
    customFields.textCustomFields = [NSSet setWithObject:textCustomField];
    
    return customFields;
}


@end
