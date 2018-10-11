//
//  ProfileManager.h
//  docusign-sdk-sample-objc
//
//  Copyright © 2017 DocuSign. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DocuSignSDK/DocuSignSDK.h"

@interface ProfileManager : NSObject

// get singleton instance of manager
+ (id) sharedInstance;
+ (BOOL)autoDownloadTemplates;
+ (BOOL)displayDeveloperNotes;

// static methods
+ (UIColor *) getAppNavColor;
+ (UIColor *) getAppBarItemsColor;
+ (NSString *) getIntegratorKey;
+ (NSString *) getHostApiUrl;
+ (NSDictionary *) getDefaultUserCredentials;
+ (NSDictionary *) getFakeClientInfo;
+ (NSDictionary *) getFakeDamageInfo;

// manage client policy number
- (void) setClientPolicyNum:(NSString *)policyNum;
- (NSString *) getClientPolicyNum;

// manage client and claim info
- (void) setClientInfo:(NSDictionary *)clientInfo;
- (NSDictionary *) getClientInfo;
- (void) setDamageInfo:(NSDictionary *)damageInfo;
- (NSDictionary *) getDamageInfo;

// manage the current template id
- (void) setClientTemplateId:(NSString *)templateId;
- (NSString *) getClientTemplateId;

// manage user choice to run offline or online flow
- (void) setOfflineFlow:(BOOL)offineFlowSelected;
- (BOOL) useOfflineFlow;

// manage pdf attachment
- (void) setAttachmentPath:(NSString *)attachmentPath;
- (NSString *) getAttachmentPath;

// manage data for the template
- (NSDictionary *) getTemplateTabDataForId:(NSString *)templateId;
- (NSArray *)getTemplateRecipientDataForId:(NSString *)templateId;
- (DSMCustomFields *)getCustomFieldsDataForTemplateId:(NSString *)templateId;
@end
