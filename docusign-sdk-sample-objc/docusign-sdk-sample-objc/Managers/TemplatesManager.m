//
//  TemplateManager.m
//  docusign-sdk-sample-objc
//
//  Copyright © 2017 DocuSign. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TemplatesManager.h"


@interface TemplatesManager ()

@property (nonatomic, retain) DSMTemplatesManager *mDSMTemplatesManager;
@property (nonatomic, retain) NSArray<DSMEnvelopeTemplateDefinition *> *mTemplateDefinitions;

@end


@implementation TemplatesManager


#pragma mark - Static Methods

+(id)sharedInstance
{
    static TemplatesManager * sharedManager = nil;

    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedManager = [[self alloc] init];

        if (sharedManager.mDSMTemplatesManager == nil)
        {
            sharedManager.mDSMTemplatesManager = [[DSMTemplatesManager alloc] init];
        }
    });
    return sharedManager;
}


#pragma mark - Public Methods

- (void) getTemplateListWithCompletion:(void(^)(NSArray<DSMEnvelopeTemplateDefinition *> *))completionHandler
{
    // retrieve list of template definitions
    [self.mDSMTemplatesManager listTemplatesWithCompletion:^(NSArray<DSMEnvelopeTemplateDefinition *> *templateDefinitions, NSError *error)
     {
         if (error)
         {
             NSLog(@"An error occurred while fetching template definitions list: %@", error);
         }
         else
         {
             // store list of template definitions
             self.mTemplateDefinitions = templateDefinitions;
             completionHandler(templateDefinitions);
         }
     }];
}


- (BOOL) templateIsCachedWithId:(NSString *)templateId
{
    return [self.mDSMTemplatesManager cacheStateOfTemplateWithId:templateId] == DSMTemplateCacheStateCached;
}


- (void) cacheTemplateWithId:(NSString *)templateId withCompletion:(void(^)(NSString *))completionHandler
{
    // download template
    [self.mDSMTemplatesManager cacheTemplateWithId:templateId completion:^(NSError *error) {
        if (error)
        {
            NSLog(@"An error occurred downloading template: %@", error);
            completionHandler(error.localizedDescription);
        }
        else
        {
            completionHandler(nil);
        }
    }];
}


- (void) removeTemplateWithId:(NSString *)templateId
{
    // remove the specified template
    [self.mDSMTemplatesManager removeCachedTemplateWithId:templateId];
}


- (void) displayTemplateForSignature:(NSString *)templateId forController:(UIViewController *)controller
                            withTabs:(id)tabs withRecipients:(id)recipients withCustomFields:(DSMCustomFields *)customFields useOfflineFlow:(BOOL)useOffline withAttachmentAtPath:(NSString *)attachmentPath withCompletion:(void(^)(UIViewController *viewController, NSError *error))completionHandler
{
    // if an attachment was included, load PDF as NSData
    NSData * attachmentData = nil;
    if (attachmentPath != nil)
    {
        attachmentData = [[NSFileManager defaultManager] contentsAtPath:attachmentPath];
    }
    
    DSMEnvelopeDefaults *envelopeDefauts = [[DSMEnvelopeDefaults alloc] init];
    envelopeDefauts.recipientDefaults = recipients;
    envelopeDefauts.tabValueDefaults = tabs;
    envelopeDefauts.customFields = customFields;
    
    [self.mDSMTemplatesManager
     presentSendTemplateControllerWithTemplateWithId:templateId
     envelopeDefaults:envelopeDefauts
     pdfToInsert:attachmentData
     insertAtPosition:DSMDocumentInsertAtPositionEnd
     signingMode:(!useOffline) ? DSMSigningModeOnline :DSMSigningModeOffline
     presentingController:controller
     animated:YES
     completion:completionHandler];
}

@end

