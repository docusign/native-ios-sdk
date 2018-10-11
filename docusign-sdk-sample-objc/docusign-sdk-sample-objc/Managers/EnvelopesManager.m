//
//  EnvelopeManager.m
//  docusign-sdk-sample-objc
//
//  Copyright © 2017 DocuSign. All rights reserved.
//

#import "EnvelopesManager.h"

@interface EnvelopesManager ()

// properties
@property (nonatomic, retain) DSMEnvelopesManager *mDSMEnvelopesManager;
@property (nonatomic, retain) NSArray<DSMEnvelopeDefinition *> *mEnvelopeDefinitions;

@end


@implementation EnvelopesManager

+ (id) sharedInstance
{
    static EnvelopesManager * sharedManager = nil;
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedManager = [[self alloc] init];

        if (sharedManager.mDSMEnvelopesManager == nil)
        {
            sharedManager.mDSMEnvelopesManager = [[DSMEnvelopesManager alloc] init];
        }

    });
    return sharedManager;
}


#pragma mark - Public Methods

// get list of cached envelope defitions
- (NSArray<DSMEnvelopeTemplateDefinition *> *) getCachedEnvelopesList
{
    return [self.mDSMEnvelopesManager cachedEnvelopes];
}


// get list of cached envelope ids
- (NSArray<NSString *> *) getCachedEnvelopeIds
{
    return [self.mDSMEnvelopesManager cachedEnvelopeIds];
}


// sync cached envelopes
- (void) syncCachedEnvelopes
{
    [self.mDSMEnvelopesManager syncEnvelopes];
}


// remove cached envelope by id
- (void) removeCachedEnvelopeById:(NSString *)envelopeId
{
    [self.mDSMEnvelopesManager removeCachedEnvelopeWithId:envelopeId];
}

// present compose envelope view controller
- (void) presentComposeEnvelopeViewControllerWithPresentingController:(UIViewController *)controller signingMode:(DSMSigningMode)signingMode {
    // you can use method hasCachedDraftEnvelope to determine whether you'd like to resume a draft or not
    [self.mDSMEnvelopesManager presentComposeEnvelopeControllerWithPresentingController:controller signingMode:signingMode resumeWithDraft:YES animated:YES completion:nil];
}

@end
