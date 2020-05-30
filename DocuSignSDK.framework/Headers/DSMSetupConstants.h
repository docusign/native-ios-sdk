#import <Foundation/Foundation.h>

/*!
 * @brief Various Comparison methods that can be used for comparing the TabLabels (also called DataLabels) with provided tab-defaults values during signing ceremony kickoff.
 * To be used with DSM_SETUP_TAB_DEFAULTS_COMPARISON.
 */
typedef enum : NSUInteger {
    DSMTabComparisonStrictMatch = 0,
    DSMTabComparisonCaseAndDiacriticInsensitive,
    DSMTabComparisonContains,
} DSMTabComparison;

#pragma mark - Setup Constants - Contacts access

/*!
 * @brief Disable contacts access from SDK to override the default behaviour. Default behaviour is to use contacts and it would show permission prompt related to
 * NSContactsUsageDescription. Info plist should have a NSContactsUsageDescription entry to avoid crash.
 * @see DSMManager
 */
extern NSString * const DSM_SETUP_DISABLE_CONTACTS_USAGE_KEY;

/*! @brief "true" representing BOOL true.
 */
extern NSString * const DSM_SETUP_TRUE_VALUE;

/*! @brief "false" representing BOOL false.
 */
extern NSString * const DSM_SETUP_FALSE_VALUE;

/*! @brief Minimum value for the API timeout, set as 30 seconds.
 */
extern NSInteger const DSM_SETUP_API_TIMEOUT_MIN_VALUE;

/*! @brief Default value for the API timeout, set as 120 seconds.
 */
extern NSInteger const DSM_SETUP_API_TIMEOUT_DEFAULT_VALUE;

/*! @brief Maximum value for the API timeout, set as 1200 seconds.
 */
extern NSInteger const DSM_SETUP_API_TIMEOUT_MAX_VALUE;

#pragma mark - Setup Constants - Offline

/*!
 * @brief Hide all of the alerts that are shown during offline signing. Default behaviour is to show all alerts during offline signing.
 * Acceptable value is either "true" or "false".
 */
extern NSString * const DSM_SETUP_OFFLINE_SIGNING_HIDE_ALERTS_KEY;

/*! @brief This settings allows overriding the default api timeout. Default value is set to DSM_SETUP_API_TIMEOUT_DEFAULT_VALUE (= 120 seconds).
*/
extern NSString * const DSM_SETUP_DEFAULT_API_TIMEOUT;

/*!
 * @brief Enable UI components to switch recipients during offline signing of an envelope. Default behaviour is to have ui components to switch recipients disabled during offline signing.
 * Acceptable value is either "true" or "false".
 */
extern NSString * const DSM_SETUP_OFFLINE_SIGNING_HIDE_SWITCH_RECIPIENT_UI_KEY;

/*!
 * @brief Allow progress of an offline envelope to be saved locally after a local signer completes signing. It also enables the UI components to conditionally allow progress save of an offline envelope. Default behaviour is to have save progress disable during offline signing.
 * Acceptable value is either "true" or "false".
 * Default value is "false".
 * Note: Enabling this would result in receiving the `DSMEnvelopeCachedNotification` notification multiple times during offline signing ceremony.
 * @see DSMNotificationCodes.h
 */
extern NSString * const DSM_SETUP_ENABLE_OFFLINE_SIGNING_SAVE_ENVELOPE_PROGRESS_KEY;

#pragma mark - Setup Constants - Offline Tab Conversion
/*!
 * @brief Allow templates with unsupported offline v1 tab types to set mergeField info as nil during auto-conversion.
 * Default value is "false".
 * Acceptable value is either "true" or "false".
 */
extern NSString * const DSM_SETUP_OFFLINE_SIGNING_SET_MERGEFIELD_AS_NIL_FOR_TABS_CONVERSION;

/*!
 * @brief Allow templates with ziptabs to be downloaded for offline signing. Enabling this would autoconvert the ziptabs to the texttabs and remove any mergefield info if DSM_SETUP_OFFLINE_SIGNING_SET_MERGEFIELD_AS_NIL_FOR_TABS_CONVERSION is set as "true".
 * Default value is "false".
 * Acceptable value is either "true" or "false".
 */
extern NSString * const DSM_SETUP_OFFLINE_SIGNING_CONVERT_ZIPTABS_TO_TEXTTABS;

/*!
 * @brief Allow use of document picker when selecting documents for composing offline envelopes. Enabling this requires iCloud entitlement to be enabled along with iCloud Documents if DSM_SETUP_ICLOUD_DOCUMENT_ENABLED is set as "true".
 * Default value is "false".
 * Acceptable value is either "true" or "false".
 */
extern NSString * const DSM_SETUP_ICLOUD_DOCUMENT_ENABLED;

/*! @brief Force the login session to be refreshed everytime login call is made. This settings allows overriding the default behaviour to reuse the saved authentication session for last logged in user.
 * Default value is "false" and it reuses a valid authentication session for a given user.
 */
extern NSString * const DSM_SETUP_FORCE_LOGIN_REFRESH_AUTHENTICATION_SESSION;

/*!
 * @brief Allow templates with numberTabs to be downloaded for offline signing. Enabling this would autoconvert the numberTabs to the texttabs and remove any mergefield info if DSM_SETUP_OFFLINE_SIGNING_SET_MERGEFIELD_AS_NIL_FOR_TABS_CONVERSION is set as "true".
 * Default value is "false".
 * Acceptable value is either "true" or "false".
 */
extern NSString * const DSM_SETUP_OFFLINE_SIGNING_CONVERT_NUMBERTABS_TO_TEXTTABS;

/*!
 * @brief Allow templates with emailTabs to be downloaded for offline signing. Enabling this would autoconvert the emailtabs to the texttabs and remove any mergefield info if DSM_SETUP_OFFLINE_SIGNING_SET_MERGEFIELD_AS_NIL_FOR_TABS_CONVERSION is set as "true".
 * Default value is "false".
 * Acceptable value is either "true" or "false".
 */
extern NSString * const DSM_SETUP_OFFLINE_SIGNING_CONVERT_EMAILTABS_TO_TEXTTABS;

/*!
 * @brief Allow templates with dateTabs to be downloaded for offline signing. Enabling this would autoconvert the dateTabs to the texttabs and remove any mergefield info if DSM_SETUP_OFFLINE_SIGNING_SET_MERGEFIELD_AS_NIL_FOR_TABS_CONVERSION is set as "true".
 * Default value is "false".
 * Acceptable value is either "true" or "false".
 */
extern NSString * const DSM_SETUP_OFFLINE_SIGNING_CONVERT_DATETABS_TO_TEXTTABS;

/*!
 * @brief Allows display of Powered By DocuSign footer. Enabling this would display the footer for Online and Offline signing if DSM_SETUP_POWERED_BY_DOCUSIGN_ENABLED is set as "true".
 * Default value is "true".
 * Acceptable value is either "true" or "false".
 */
extern NSString * const DSM_SETUP_POWERED_BY_DOCUSIGN_ENABLED;

/*!
 * @brief Allow templates with readonly and required text based tabs with nil value to be auto-converted to non-readonly text based tabs. Enabling this would autoconvert the text based tabs and set the bool locked (i.e. readonly) flag for such tabs to true if DSM_SETUP_OFFLINE_SIGNING_CONVERT_INVALID_READONLY_REQUIRED_TEXTTABS_TO_EDITABLE is set as "true".
 * Default value is "true".
 * Acceptable value is either "true" or "false".
 */
extern NSString * const DSM_SETUP_OFFLINE_SIGNING_CONVERT_INVALID_READONLY_REQUIRED_TEXTTABS_TO_EDITABLE;

/*! @brief Use a placeholder string indicative of tab-type (e.g. "Text", "Company", etc) instead of showing empty string for text based tabs with empty value.
 * Default value is "true".
 * Acceptable value is either "true" or "false".
 */
extern NSString * const DSM_SETUP_OFFLINE_SIGNING_USE_PLACEHOLDER_TAB_VALUE;

/*! @brief Allows Next button on offline signing ceremony to navigate and focus only on empty required fields.
 * Default value is "false".
 * Acceptable value is either "true" or "false".
 * Refer [Auto-Navigation]: https://support.docusign.com/en/guides/ndse-admin-guide-signing-settings
 */
extern NSString * const DSM_SETUP_OFFLINE_SIGNING_NAVIGATE_BLANK_REQUIRED_FIELDS;

/*! @brief Find tabs for setting default values during signing ceremony based on this search criteria.
 * This setting allows overriding the default behaviour of the DocuSign API (for example, when tabLabels are used for formulas. To reference other tabs in your formulas you must match their case-sensitive tabLabel.): https://developers.docusign.com/esign-rest-api/guides/features/tabs
 * Note A: During default values assignment for given tabs with matching tabLabels, only the value is assigned and no tabLabels are modified during signing-kickoff.
 * Note B: If DSMTabComparisonCaseAndDiacriticInsensitive and DSMTabComparisonContains values are used to override the default method DSMTabComparisonStrictMatch, it is up to the template creator and Native-iOS-SDK client to ensure valid tabLabel are used.
 * Acceptable value is DSMTabComparison.
 * Default value is DSMTabComparisonStrictMatch and performs a strict match doing complete match for a tabLabel.
 * @see DSMTabComparison
 */
extern NSString * const DSM_SETUP_TAB_DEFAULTS_COMPARISON;

/*! @brief Allow RecipientDefaults to case-insensitively match with template roleName(s). This setting allows overriding the default behaviour of the DocuSign API ([Applying a Template to an Envelope] - It is important to note that the roleName parameter is case-sensitive and must match the placeholder name you saved for the template role): https://developers.docusign.com/esign-rest-api/guides/features/templates
 * Note: If this setting is used to override the default behaviour of matching roleNames strictly (similar to DocuSignAPI), it is up to the template creator to ensure that any template underuse has unique roleName(s) based on the selected search method (case and diacritic insensitive match).
 * Default value is "false" and performs a strict match.
 * Acceptable value is either "true" or "false".
 */
extern NSString * const DSM_SETUP_RECIPIENT_DEFAULTS_CASE_INSENSITIVELY_MATCH_ROLE_NAME;

/*! @brief Allow Online Signing to load in complete non-native manner.
 * This results in hiding navigation & toolbar, use online signature adoption component, and disables other native sdk ui components.
 * Default value is "false"
 * Acceptable value is either "true" or "false".
 */
extern NSString * const DSM_SETUP_ONLINE_SIGNING_DISABLE_NATIVE_COMPONENTS;
