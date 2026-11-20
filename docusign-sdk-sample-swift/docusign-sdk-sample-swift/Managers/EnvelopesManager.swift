//
//  EnvelopesManager.swift
//  docusign-sdk-sample-swift
//
//  
//  Copyright © 2017 DocuSign. All rights reserved.
//

import DocusignNative
import DocuSignSDK
import Foundation
import UIKit


class EnvelopesManager
{
    // singleton instance
    static let sharedInstance = EnvelopesManager()

    // DSM Envelopes Manager
    var mDSMEnvelopesManager: DSMEnvelopesManager?
    var mNativeSigningManager: NativeSigningManager?
    
    // list of template definitions
    var mEnvelopeDefinitions: [DSMEnvelopeDefinition]?

    //This prevents others from using the default '()' initializer for this class.
    private init()
    {
        if (self.mDSMEnvelopesManager == nil)
        {
            self.mDSMEnvelopesManager = DSMEnvelopesManager()
        }
        if (self.mNativeSigningManager == nil)
        {
            self.mNativeSigningManager = NativeSigningManager()
        }
    }
    

    func getCachedEnvelopeIds() -> [String]?
    {
        return self.mDSMEnvelopesManager?.cachedEnvelopeIds()
    }


    func syncEnvelopes() -> Void
    {
        self.mDSMEnvelopesManager?.syncEnvelopes()
    }
    
    func presentComposeEnvelopeViewController(_ presentingController: UIViewController, _ signingMode: DSMSigningMode) -> Void
    {
        guard let pdfPath = Bundle.main.path(forResource: "Portfolio", ofType: "pdf") else {
            NSLog("Error: Portfolio.pdf not found in bundle.")
            return
        }

        let documentId = "1"
        let recipientId = "1"
        let clientName = ProfileManager.sharedInstance.getClientName()
        let clientEmail = ProfileManager.sharedInstance.getClientData()["email"] ?? "tom.wood@digital.com"

        let signTab = DSMTabBuilder(for: .signHere)
            .addName("Signature")
            .addRecipientId(recipientId)
            .addDocumentId(documentId)
            .addFrame(CGRect(x: 100, y: 300, width: 50, height: 40))
            .addPageNumber(1)
            .build()

        let document = DSMDocumentBuilder()
            .addName("Portfolio.pdf")
            .addDocumentId(documentId)
            .addFilePath(pdfPath)
            .build()

        let recipientBuilder: DSMRecipientBuilder
        if signingMode == .offline {
            recipientBuilder = DSMRecipientBuilder(for: .inPersonSigner)
                .addRecipientId(recipientId)
                .addSignerName(clientName)
                .addSignerEmail(clientEmail)
                .addHostName(ProfileManager.Static.userName)
                .addHostEmail(ProfileManager.Static.defaultUsername)
                .addRoutingOrder(1)
                .add(signTab)
        } else {
            recipientBuilder = DSMRecipientBuilder(for: .signer)
                .addRecipientId(recipientId)
                .addSignerName(clientName)
                .addSignerEmail(clientEmail)
                .addRoutingOrder(1)
                .add(signTab)
        }

        let envelope = DSMEnvelopeBuilder()
            .addEnvelopeName("Portfolio Agreement")
            .addEmailSubject("Please DocuSign: Portfolio.pdf")
            .addEmailMessage("Please review and sign the attached portfolio agreement.")
            .add(document)
            .add(recipientBuilder.build())
            .build()

        self.mDSMEnvelopesManager?.composeEnvelope(with: envelope, signingMode: signingMode) { envelopeId, error in
            if let error = error {
                NSLog("Error composing envelope: \(error.localizedDescription)")
                return
            }
            guard let envelopeId = envelopeId else { return }

            if signingMode == .offline {
                Task { @MainActor in
                    do {
                        _ = try await self.mNativeSigningManager?.resumeSigning(
                            presentingVC: presentingController,
                            envelopeId: envelopeId,
                            animated: true
                        )
                    } catch {
                        NSLog("Error resuming offline signing: \(error.localizedDescription)")
                    }
                }
            } else {
                self.mDSMEnvelopesManager?.presentSigning(
                    withPresenting: presentingController,
                    envelopeId: envelopeId,
                    animated: true,
                    completion: nil
                )
            }
        }
    }
    
}
