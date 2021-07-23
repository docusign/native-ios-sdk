import SwiftUI
import DocuSignSDK

struct ContentView: View {
    
    @State var showsAlert = false
    @State var alertTitle = ""
    @State var alertMessage = ""
    
    @State var signingUrl = ""
    @State var envelopeId = ""
    
    init() {
        print("ContentView - init")
    }
    
    var body: some View {
        VStack {
            VStack(alignment: .center, spacing: 8, content: {
                Text("Hello, world!")
                    .padding()
                Button("DocuSign") {
                    print("DocuSign Tapped")
                    loginDocuSign()
                }.onReceive(NotificationCenter.default.publisher(for: Notification.Name(rawValue: "DSMSigningCompletedNotification")), perform: { notification in
                    onSigningCompleted(notification)
                }).onReceive(NotificationCenter.default.publisher(for: Notification.Name(rawValue: "DSMSigningCancelledNotification")), perform: { notification in
                    onSigningCancelled(notification)
                })
            }).padding(30)
            
            VStack(alignment: .center, spacing: 10, content: {
                
                TextField ("Envelope Id", text: $envelopeId)
                
                TextField ("Signing Url", text: $signingUrl)
                
                Button("Launch Captive Signing") {
                    print("Captive Signing Tapped")
                    if let presentingViewController = getPresentingViewController() {
                        loadSigning(envelopeId, signingUrl: signingUrl, presentingViewController: presentingViewController)
                    }
                    
                }.onReceive(NotificationCenter.default.publisher(for: Notification.Name(rawValue: "DSMSigningCompletedNotification")), perform: { notification in
                    onSigningCompleted(notification)
                    showsAlert = true
                }).onReceive(NotificationCenter.default.publisher(for: Notification.Name(rawValue: "DSMSigningCancelledNotification")), perform: { notification in
                    onSigningCancelled(notification)
                    showsAlert = true
                }).alert(isPresented: $showsAlert, content: { () -> Alert in
                    Alert(title:Text(alertTitle) , message: Text(alertMessage), dismissButton: .default(Text("Ok"), action: { showsAlert = false }))
                })
                
            }).padding()
            .border(Color.black, width: 1)
        }
    }
}

private extension ContentView {
    func loginDocuSign() {
        // For stage, use `"https://stage.docusign.net/restapi"`
        // For prod, use `"https://docusign.net/restapi"`
        guard let hostURL = URL(string: "https://demo.docusign.net/restapi") else {
            return
        }
        
        DSMManager.login(withAccessToken: "-your-access-token-",
                         accountId: "-your-account-id-",
                         userId: "-your-user-id-",
                         userName: "-your-user-name-",
                         email: "-your-email-",
                         host: hostURL,
                         integratorKey: "-your-integrator-key-") { accountInfo, error in
            
            self.handlePostLogin(accountInfo: accountInfo, error: error)
            
        }
    }
    
    func handlePostLogin(accountInfo: DSMAccountInfo?, error: Error?) {
        if let error = error {
            print("Error logging in: " + error.localizedDescription)
        } else {
            print("User authenticated!")
            let envelopeId = "-your-captive-signing-envelope-id-"
            let keyWindow = UIApplication.shared.windows.filter {$0.isKeyWindow}.first
            if var topController = keyWindow?.rootViewController {
                while let presentedViewController = topController.presentedViewController {
                    topController = presentedViewController
                }
                loadSigning(envelopeId, presentingViewController: topController)
            }
        }
    }
    
    func loadSigning(_ envelopeId: String, presentingViewController: UIViewController?) {
        guard let presentingViewController = presentingViewController else {
            return
        }
        // Make sure the client user id is same as the created envelope.
        let clientUserId = "-client-user-id-for-recipient-in-envelope-"
        // Invoke captive signing session with envelopeId & clientUserId to fetch the signingURL with SDK and load the signing session.
        DSMEnvelopesManager().presentCaptiveSigning(withPresenting: presentingViewController,
                                                    envelopeId: envelopeId,
                                                    recipientClientUserId: clientUserId,
                                                    animated: true) { viewController, error in
            // Handle error
            if error != nil {
                print("Unable to launch signing ceremony with clientUserId variant!")
            }
            // Dismiss the signing using `viewController` from the client app
            print("viewController with signing session")
        }
    }
    
    
    func loadSigning(_ envelopeId: String, signingUrl: String, recipientId: String? = nil, presentingViewController: UIViewController?) {
        guard let presentingViewController = presentingViewController else {
            return
        }
        // Invoke captive signing session with envelopeId & signingURL with SDK and load the signing session.
        DSMEnvelopesManager().presentCaptiveSigning(withPresenting: presentingViewController,
                                                    signingUrl: signingUrl,
                                                    envelopeId: envelopeId,
                                                    recipientId: recipientId,
                                                    animated: true) { viewController, error in
            // Handle error
            if error != nil {
                print("Unable to launch signing ceremony with signing url")
            }
            // Dismiss the signing using `viewController` from the client app
            print("viewController with signing session")
        }
    }
    
    func getPresentingViewController() -> UIViewController? {
        let keyWindow = UIApplication.shared.windows.filter {$0.isKeyWindow}.first
        if var topController = keyWindow?.rootViewController {
            while let presentedViewController = topController.presentedViewController {
                topController = presentedViewController
            }
            return topController
        }
        return nil
    }
    
    // MARK:- Docusign Notifications
    
    func onSigningCancelled(_ notification:Notification) {
        print("onSigningCancelled : \(notification.debugDescription)")
        guard let envelopeId = notification.userInfo?[DSMEnvelopeIdKey] as? String else {
            return
        }
        print ("envelopeId: " + envelopeId)
        // Update the UI on client-app
        alertTitle = envelopeId
        alertMessage = notification.description
    }
    
    func onSigningCompleted(_ notification:Notification) {
        print("onSigningCompleted : \(notification.debugDescription)")
        guard let envelopeId = notification.userInfo?[DSMEnvelopeIdKey] as? String else {
            return
        }
        print ("envelopeId: " + envelopeId)
        // Update the UI on client-app
        alertTitle = envelopeId
        alertMessage = notification.description
        
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
