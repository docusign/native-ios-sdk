//
//  TemplateManager.h
//  docusign-sdk-sample-objc
//
//  Copyright © 2017 DocuSign. All rights reserved.
//

#import <DocuSignSDK/DocuSignSDK.h>
#import <Foundation/Foundation.h>


@interface TemplatesManager : NSObject

// get singleton instance of manager
+ (id) sharedInstance;

// get list of template defitions
- (void) getTemplateListWithCompletion:(void(^)(NSArray<DSMEnvelopeTemplateDefinition *> *))completionHandler;

// check if the template with id is cached
- (BOOL) templateIsCachedWithId:(NSString *)templateId;

// download & cache the template with id
- (void) cacheTemplateWithId:(NSString *)templateId withCompletion:(void(^)(NSString *))completionHandler;

// remove the cached template with id
- (void) removeTemplateWithId:(NSString *)templateId;

- (void) displayTemplateForSignature:(NSString *)templateId forController:(UIViewController *)controller withTabs:(id)tabs withRecipients:(id)recipients withCustomFields:(DSMCustomFields *)customFields useOfflineFlow:(BOOL)useOffline withAttachmentAtPath:(NSString *)attachmentPath withCompletion:(void(^)(UIViewController *viewController, NSError *error))completionHandler;

@end
