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
    func getTemplateTabData() -> Dictionary<String,String>
    {
        var tabData = Dictionary<String, String>();
        tabData[ProfileManager.Static.tabKey_name] = self.getClientName();
        tabData[ProfileManager.Static.tabKey_address1] = self.clientData["address"];
        tabData[ProfileManager.Static.tabKey_address2] = self.clientData["city"]! + ", " + self.clientData["state"]!;
        tabData[ProfileManager.Static.tabKey_address3] = self.clientData["country"]! + " " + self.clientData["zipCode"]!;
        tabData[ProfileManager.Static.tabKey_clientNumber] = self.clientData["clientNumber"];
        tabData[ProfileManager.Static.tabKey_investmentAmount] = self.clientData["investmentAmount"];

        return tabData;
    }

}
