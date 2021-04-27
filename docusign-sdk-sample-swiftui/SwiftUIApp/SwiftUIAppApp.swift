import SwiftUI
import DocuSignSDK

@main
struct SwiftUIApp: App {
    init() {
        print ("SwiftUI - DocuSign SDK Sample.")
        initializeDocuSign()
    }
    
    var body: some Scene {
        WindowGroup {            
            ContentView()
        }
    }
}

private extension SwiftUIApp {
    func initializeDocuSign() {
        // initialize DS sdk manager
        var configurations = DSMManager.defaultConfigurations()
        configurations[DSM_SETUP_POWERED_BY_DOCUSIGN_ENABLED] = DSM_SETUP_FALSE_VALUE
        configurations[DSM_SETUP_ONLINE_SIGNING_DISABLE_NATIVE_COMPONENTS] = DSM_SETUP_TRUE_VALUE

        // initialize DS sdk manager
        DSMManager.setup(withConfiguration: configurations)
    }
}
