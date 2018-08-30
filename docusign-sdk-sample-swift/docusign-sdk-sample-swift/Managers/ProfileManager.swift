//
//  ProfileManager.swift
//  docusign-sdk-sample-swift
//
//  
//  Copyright © 2017 DocuSign. All rights reserved.
//

import UIKit
import DocuSignSDK


class ProfileManager
{
    // singleton instance
    static let sharedInstance = ProfileManager()
    
    //This prevents others from using the default '()' initializer for this class.
    private init()
    {
        self.clientData = ProfileManager.Static.fakeClientData;
    }


    /*
     * Sample App Data
     * Update the values below with details from your developer sandbox account
     */
    
    struct Static
    {
        // default host api url
        static let demoHostApi: URL? = URL(string: "https://demo.docusign.net/restapi");

        // integrator key from your DS account goes here
        static let integratorKey: String = "<MY-INTEGRATOR-KEY-HERE>";

        // optionally include credentials in order to pre-populate user login info
        static let defaultUsername: String =  "<MY-USERNAME-HERE>";
        static let defaultPassword: String = "<MY-PASSWORD-HERE>";
        
        // keys for custom fields on template
        static let tabKey_name: String = "Text dc02e5f6-ff92-4d84-b13d-d82f4c886e81";
        static let tabKey_address1: String = "Text 05f929aa-b3c6-4c17-bf22-3f7e6bfbe473";
        static let tabKey_address2: String = "Text 526bf465-583e-426f-9671-04dadbb16dbc";
        static let tabKey_address3: String = "Text fa6374f6-1fe0-4a71-907a-0c3342791df3";
        static let tabKey_clientNumber: String = "Text c8985ea9-4126-4c70-832f-b8f06c76fae1";
        static let tabKey_investmentAmount: String = "Text 9edc0b80-1604-4079-bf0a-1b0b2a5be361";
        
        // fake data used to pre-populate client info
        static let fakeClientData: Dictionary<String, String> = ["firstName":"Tom",
                                                                 "lastName":"Wood",
                                                                 "address":"726 Tennessee St",
                                                                 "city":"San Francisco",
                                                                 "state":"California",
                                                                 "country":"U.S.A.",
                                                                 "zipCode":"94107",
                                                                 "email":"tom.wood@digital.com",
                                                                 "phone":"415-555-1234",
                                                                 "clientNumber":"FA-45231-005",
                                                                 "investmentAmount":"$25,000.00"
        ];
        
        // Momentum demo template
        static let templateIdMomemtumDemo = "606f0e95-a419-4280-86ac-234913037962";
        static let tabLabelIdFullName = "Text FullName";
        static let tabLabelIdAddressLine1 = "Text Address Line 1";
        static let tabLabelIdAddressLine2 = "Text Address Line 2";
        static let tabLabelIdAddressLine3 = "Text Address Line 3";
        static let tabLabelIdClientNumber = "Text Client Number";
        static let tabLabelIdInvestmentAmount = "Text Investment Amount";

        // Momentum demo template - WireTransfer
        static let templateIdMomemtumDemoWireTransfer = "ff088ecf-5d8b-42c5-9160-569f26beb3a2";
        static let tabLabelIdOwnerFullName = "Text OwnerFullName";
        static let tabLabelIdOwnerEmailAddress = "Text EmailAddress";
        static let tabLabelIdTransferAmount = "Text Amount";
        static let tabLabelIdCurrency = "Text Currency";
        static let tabLabelIdRoutingNumber = "Text RoutingNumber";
        static let tabLabelIdBankName = "Text BankName";
        static let tabLabelIdAccountNumber = "Text AccountNumber";
        static let tabLabelIdAdditionalDetails = "Text AdditionalDetails";
        static let tabLabelIdNameOfWireRecipient = "Text NameOfWireRecipient";
        static let tabLabelIdAddressOfWireRecipient = "Text AddressOfWireRecipient";
        static let tabLabelIdSWIFTCode = "Text SWIFTCode";
        static let tabLabelIdCountry = "Text Country";
        static let tabLabelIdSourceRoutingNumber = "Text SourceRoutingNumber";
        static let tabLabelIdSourceAccountNumber = "Text SourceAccountNumber";
        static let tabLabelIdSenderFullName = "Text SenderFullName";
        
        static let autoDownloadTemplates = true;
        static let displayDeveloperNotes = false;
    }

    
    // members
    private var mCurrentTemplateId: String = "";
    private var mUseOfflineFlow: Bool = true;
    private var mAttachmentUrl: URL?;
    private var mEnvelopesNeedToSync: Bool = false;
    private var clientData = Dictionary<String, String>();
    

    // MARK: Public Methods
    
    func setCurrentTemplateId(templateId: String)
    {
        self.mCurrentTemplateId = templateId;
    }
    
    
    func getCurrentTemplateId() -> String
    {
        return self.mCurrentTemplateId;
    }
    
    
    func setUseOfflineFlow(useOffline: Bool)
    {
        self.mUseOfflineFlow = useOffline;
    }


    func getUseOfflineFlow() -> Bool
    {
        return self.mUseOfflineFlow;
    }


    func setAttachmentPath(attachmentUrl: URL)
    {
        self.mAttachmentUrl = attachmentUrl;
    }
    
    
    func getAttachmentUrl() -> URL?
    {
        return self.mAttachmentUrl;
    }

    
    func setEnvelopesNeedToSync(needToSync: Bool)
    {
        self.mEnvelopesNeedToSync = needToSync;
    }
    
    
    func getEnvelopesNeedToSync() -> Bool
    {
        return self.mEnvelopesNeedToSync
    }

    
    func setClientPersonalInfo(firstName:String?, lastName:String?, address:String?, city:String?, state:String?, country:String?, zipCode:String?, email:String?, phone:String?)
    {
        self.clientData["firstName"] = firstName != nil ? firstName : "";
        self.clientData["lastName"] = lastName != nil ? lastName : "";
        self.clientData["address"] = address != nil ? address : "";
        self.clientData["city"] = city != nil ? city : "";
        self.clientData["state"] = state != nil ? state : "";
        self.clientData["country"] = country != nil ? country : "";
        self.clientData["zipCode"] = zipCode != nil ? zipCode : "";
        self.clientData["email"] = email != nil ? email : "";
        self.clientData["phone"] = phone != nil ? phone : "";
    }


    func setClientInvestmentInfo(clientNumber:String, investmentAmount:String)
    {
        self.clientData["clientNumber"] = clientNumber;
        self.clientData["investmentAmount"] = investmentAmount;
    }

    
    func getClientData() -> Dictionary<String, String>
    {
        return self.clientData;
    }
    
    
    func getClientName() -> String
    {
        return self.clientData["firstName"]! + " " + self.clientData["lastName"]!;
    }

    
    /**
     Returns Dictionary of the data that will be passed into the template
     */
    func getTemplateTabData(templateId:String) -> Dictionary<String,String>
    {
        var tabData = Dictionary<String, String>();
        if templateId == ProfileManager.Static.templateIdMomemtumDemo {
            tabData[ProfileManager.Static.tabLabelIdFullName] = self.getClientName();
            tabData[ProfileManager.Static.tabLabelIdAddressLine1] = self.clientData["address"];
            tabData[ProfileManager.Static.tabLabelIdAddressLine2] = self.clientData["city"]! + ", " + self.clientData["state"]!;
            tabData[ProfileManager.Static.tabLabelIdAddressLine3] = self.clientData["country"]! + " " + self.clientData["zipCode"]!;
            tabData[ProfileManager.Static.tabLabelIdClientNumber] = self.clientData["clientNumber"];
            tabData[ProfileManager.Static.tabLabelIdInvestmentAmount] = self.clientData["investmentAmount"];
        } else if templateId == ProfileManager.Static.templateIdMomemtumDemoWireTransfer {
            // 1
            tabData[ProfileManager.Static.tabLabelIdOwnerFullName] = self.getClientName();
            tabData[ProfileManager.Static.tabLabelIdOwnerEmailAddress] = "tom.wood@dsxtr.com";
            // 2
            tabData[ProfileManager.Static.tabLabelIdTransferAmount] = self.clientData["investmentAmount"];
            tabData[ProfileManager.Static.tabLabelIdCurrency] = "USD"
            // 3
            tabData[ProfileManager.Static.tabLabelIdRoutingNumber] = "121000358";
            tabData[ProfileManager.Static.tabLabelIdBankName] = "Bank of Andromeda";
            tabData[ProfileManager.Static.tabLabelIdAccountNumber] = "AFK-786650001-0X";
            tabData[ProfileManager.Static.tabLabelIdAdditionalDetails] = "Initial investment amount, September 2018";
            tabData[ProfileManager.Static.tabLabelIdNameOfWireRecipient] = "TGK Capital Financial, LLC.";
            tabData[ProfileManager.Static.tabLabelIdAddressOfWireRecipient] = self.clientData["address"]! + ", " + self.clientData["city"]! + ", " + self.clientData["state"]! + ", " + self.clientData["country"]! + " " + self.clientData["zipCode"]!;
            tabData[ProfileManager.Static.tabLabelIdSWIFTCode] = "BOAAUS3N";
            tabData[ProfileManager.Static.tabLabelIdCountry] = self.clientData["country"];
            // 4
            tabData[ProfileManager.Static.tabLabelIdSourceRoutingNumber] = "121000358";
            tabData[ProfileManager.Static.tabLabelIdSourceAccountNumber] = "AFK-650001788-0X";
            // 5
            tabData[ProfileManager.Static.tabLabelIdSenderFullName] = self.getClientName();
        } else {
            tabData[ProfileManager.Static.tabKey_name] = self.getClientName();
            tabData[ProfileManager.Static.tabKey_address1] = self.clientData["address"];
            tabData[ProfileManager.Static.tabKey_address2] = self.clientData["city"]! + ", " + self.clientData["state"]!;
            tabData[ProfileManager.Static.tabKey_address3] = self.clientData["country"]! + " " + self.clientData["zipCode"]!;
            tabData[ProfileManager.Static.tabKey_clientNumber] = self.clientData["clientNumber"];
            tabData[ProfileManager.Static.tabKey_investmentAmount] = self.clientData["investmentAmount"];
        }
        return tabData;
    }

    /**
     Returns Array of the recipient data that will be passed into the template
     */
    func getTemplateRecipientData(templateId:String) -> Array<DSMRecipientDefault>
    {
        if templateId != ProfileManager.Static.templateIdMomemtumDemo && templateId != ProfileManager.Static.templateIdMomemtumDemoWireTransfer {
            return [];
        }
        
        /*Recipients can be defaulted using either RoleName or RecipientId.
         Using RoleName:
            recipientDatum.recipientSelectorType = DSMEnvelopeDefaultsUniqueRecipientSelectorType.recipientRoleName
            recipientDatum.recipientRoleName = "In Person Signer"
        */
        let recipientDatum = DSMRecipientDefault.init();
        recipientDatum.recipientId = "18375691";
        recipientDatum.recipientSelectorType = DSMEnvelopeDefaultsUniqueRecipientSelectorType.recipientId
        recipientDatum.recipientType = DSMRecipientType.inPersonSigner;
        recipientDatum.inPersonSignerName = "Tom Wood";
        recipientDatum.recipientName = "docusignsdk user";
        recipientDatum.recipientEmail = "docusignsdk.user@dsxtr.com";
        return [recipientDatum];
    }
    
    /**
     Returns CustomFields that will be passed into the template
     */
    func getCustomFieldsData(templateId:String) -> DSMCustomFields? {
        if templateId != ProfileManager.Static.templateIdMomemtumDemo && templateId != ProfileManager.Static.templateIdMomemtumDemoWireTransfer {
            return nil;
        }
        
        //Create Text CustomField
        let textCustomField = DSMTextCustomField()
        textCustomField.name = "Investor"
        textCustomField.value = "Tom Wood"
        textCustomField.show = true
        
        //Link to CustomFields
        let customFields = DSMCustomFields()
        customFields.textCustomFields = [textCustomField]
        return customFields
    }

}
