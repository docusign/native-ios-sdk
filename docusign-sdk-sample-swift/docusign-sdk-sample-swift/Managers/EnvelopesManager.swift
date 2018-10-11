//
//  EnvelopesManager.swift
//  docusign-sdk-sample-swift
//
//  
//  Copyright © 2017 DocuSign. All rights reserved.
//

import DocuSignSDK
import Foundation


class EnvelopesManager
{
    // singleton instance
    static let sharedInstance = EnvelopesManager()

    // DSM Envelopes Manager
    var mDSMEnvelopesManager: DSMEnvelopesManager?;
    
    // list of template definitions
    var mEnvelopeDefinitions: [DSMEnvelopeDefinition]?;

    //This prevents others from using the default '()' initializer for this class.
    private init()
    {
        if (self.mDSMEnvelopesManager == nil)
        {
            self.mDSMEnvelopesManager = DSMEnvelopesManager.init();
        }
    }
    

    func getCachedEnvelopeIds() -> [String]?
    {
        return self.mDSMEnvelopesManager?.cachedEnvelopeIds();
    }


    func syncEnvelopes() -> Void
    {
        self.mDSMEnvelopesManager?.syncEnvelopes();
    }
    
    func presentComposeEnvelopeViewController(_ presentingController:UIViewController, _ signingMode:DSMSigningMode) -> Void
    {
        // you can use method hasCachedDraftEnvelope() to determine whether you'd like to resume a draft or not
        self.mDSMEnvelopesManager?.presentComposeEnvelopeController(withPresenting:presentingController, signingMode:signingMode, resumeWithDraft: true, animated: true, completion: nil)
    }
    
}
