import SwiftUI
import DocuSignSDK

struct ContentView: View {
    init() {
        print("ContentView - init")
    }
    
    var body: some View {
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
    }
}

private extension ContentView {
    func loginDocuSign() {
        // For demo, use `"https://demo.docusign.net/restapi"`
        // For prod, use `"https://docusign.net/restapi"`
        guard let hostURL = URL(string: "https://stage.docusign.net/restapi") else {
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
            let envelopeId = "0e8ff0d3-4548-4f21-9a2f-4c0fd99d03fd"
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
        let clientUserId = "ashok_stage@dsxtr.com"
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
    
    // MARK:- Docusign Notifications
    
    func onSigningCancelled(_ notification:Notification) {
        print("onSigningCancelled : \(notification.debugDescription)")
        guard let envelopeId = notification.userInfo?[DSMEnvelopeIdKey] as? String else {
            return
        }
        print ("envelopeId: " + envelopeId)
        // Update the UI on client-app
    }
    
    func onSigningCompleted(_ notification:Notification) {
        print("onSigningCompleted : \(notification.debugDescription)")
        guard let envelopeId = notification.userInfo?[DSMEnvelopeIdKey] as? String else {
            return
        }
        print ("envelopeId: " + envelopeId)
        // Update the UI on client-app
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
