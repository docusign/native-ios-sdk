#import <Foundation/Foundation.h>

#pragma mark - Setup Constants - Contacts access
/*!
 * @brief Disable contacts access from SDK to override the default behaviour. Default behaviour is to use contacts and it would show permission prompt related to
 * NSContactsUsageDescription. Info plist should have a NSContactsUsageDescription entry to avoid crash.
 * @see DSMManager
 */
static NSString * const DSM_SETUP_DISABLE_CONTACTS_USAGE_KEY = @"dsm.setup.disable.contacts.usage";

/*! @brief "true" representing BOOL true.
 */
static NSString * const DSM_SETUP_TRUE_VALUE = @"true";

/*! @brief "false" representing BOOL false.
 */
static NSString * const DSM_SETUP_FALSE_VALUE = @"false";

#pragma mark - Setup Constants - Offline
/*!
 * @brief Hide all of the alerts that are shown during offline signing. Default behaviour is to show all alerts during offline signing.
 * Acceptable value are "true" or "false".
 */
static NSString * const DSM_SETUP_OFFLINE_SIGNING_HIDE_ALERTS_KEY = @"dsm.setup.offline.signing.hide.alerts";

/*!
 * @brief Enable UI components to switch recipients during offline signing of an envelope. Default behaviour is to have ui components to switch recipients disabled during offline signing.
 * Acceptable value are "true" or "false".
 */
static NSString * const DSM_SETUP_OFFLINE_SIGNING_HIDE_SWITCH_RECIPIENT_UI_KEY = @"dsm.setup.offline.signing.switch.recipients.ui";

#pragma mark - Setup Constants - Offline Tab Conversion
/*!
 * @brief Allow templates with unsupported offline v1 tab types to set mergeField info as nil during auto-conversion.
 * Default value is "false".
 * Acceptable value are "true" or "false".
 */
static NSString * const DSM_SETUP_OFFLINE_SIGNING_SET_MERGEFIELD_AS_NIL_FOR_TABS_CONVERSION = @"dsm.setup.offline.signing.set.mergefields.as.nil.for.tab.conversion";

/*!
 * @brief Allow templates with ziptabs to be downloaded for offline signing. Enabling this would autoconvert the ziptabs to the texttabs and remove any mergefield info if DSM_SETUP_OFFLINE_SIGNING_SET_MERGEFIELD_AS_NIL_FOR_TABS_CONVERSION is set as "true".
 * Default value is "false".
 * Acceptable value are "true" or "false".
 */
static NSString * const DSM_SETUP_OFFLINE_SIGNING_CONVERT_ZIPTABS_TO_TEXTTABS = @"dsm.setup.offline.signing.convert.ziptabs.to.texttabs";

/*!
 * @brief Allow templates with numberTabs to be downloaded for offline signing. Enabling this would autoconvert the numberTabs to the texttabs and remove any mergefield info if DSM_SETUP_OFFLINE_SIGNING_SET_MERGEFIELD_AS_NIL_FOR_TABS_CONVERSION is set as "true".
 * Default value is "false".
 * Acceptable value are "true" or "false".
 */
static NSString * const DSM_SETUP_OFFLINE_SIGNING_CONVERT_NUMBERTABS_TO_TEXTTABS = @"dsm.setup.offline.signing.convert.numbertabs.to.texttabs";

/*!
 * @brief Allow templates with emailTabs to be downloaded for offline signing. Enabling this would autoconvert the emailtabs to the texttabs and remove any mergefield info if DSM_SETUP_OFFLINE_SIGNING_SET_MERGEFIELD_AS_NIL_FOR_TABS_CONVERSION is set as "true".
 * Default value is "false".
 * Acceptable value are "true" or "false".
 */
static NSString * const DSM_SETUP_OFFLINE_SIGNING_CONVERT_EMAILTABS_TO_TEXTTABS = @"dsm.setup.offline.signing.convert.emailtabs.to.texttabs";

/*!
 * @brief Allow templates with dateTabs to be downloaded for offline signing. Enabling this would autoconvert the dateTabs to the texttabs and remove any mergefield info if DSM_SETUP_OFFLINE_SIGNING_SET_MERGEFIELD_AS_NIL_FOR_TABS_CONVERSION is set as "true".
 * Default value is "false".
 * Acceptable value are "true" or "false".
 */
static NSString * const DSM_SETUP_OFFLINE_SIGNING_CONVERT_DATETABS_TO_TEXTTABS = @"dsm.setup.offline.signing.convert.datetabs.to.texttabs";
