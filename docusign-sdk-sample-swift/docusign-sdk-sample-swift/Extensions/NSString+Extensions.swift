import Foundation
import DocuSignSDK

extension String {
  /**
   Return title with optional DocuSign SDK version
   */
   static func developerNotesTitle(with sdkVersion:Bool) -> String {
        if sdkVersion {
            return "Developer's Notes (\(DSMManager.buildVersion())"
        }
        return "Developer's Notes"
  }
}
