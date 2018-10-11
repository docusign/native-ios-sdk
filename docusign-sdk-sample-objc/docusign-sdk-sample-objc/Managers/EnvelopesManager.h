//
//  EnvelopeManager.h
//  docusign-sdk-sample-objc
//
//  Copyright © 2017 DocuSign. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DocuSignSDK/DocuSignSDK.h>

@interface EnvelopesManager : NSObject

// get singleton instance of manager
+ (id) sharedInstance;

// get list of cached envelope defitions
- (NSArray<DSMEnvelopeDefinition *> *) getCachedEnvelopesList;

// get list of cached envelope ids
- (NSArray<NSString *> *) getCachedEnvelopeIds;

// sync cached envelopes
- (void) syncCachedEnvelopes;

// remove cached envelope by id
- (void) removeCachedEnvelopeById:(NSString *)envelopeId;

// present compose envelope view controller
- (void) presentComposeEnvelopeViewControllerWithPresentingController:(UIViewController *)controller signingMode:(DSMSigningMode)signingMode;

@end
