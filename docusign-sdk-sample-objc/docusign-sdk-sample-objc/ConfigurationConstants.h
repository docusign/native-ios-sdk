#ifndef ConfigurationConstants_h
#define ConfigurationConstants_h

/** Configuration constant to show the damage attachment screen. Setting it to NO will skip the damage attachement entirely.
 */
static BOOL const CONFIGURATION_SHOW_DAMAGE_ATTACHMENT = YES;

/** Configuration constant to show the (developer) dialog to choose between offline vs online signing.
 */
static BOOL const CONFIGURATION_SHOW_OFFLINE_ONLINE_SIGNING_DEV_PROMPT = YES;

/** Configuration constant to use "offline signing" mode as default when (developer) dialog to choose between offline vs online signing is disabled via the CONFIGURATION_SHOW_OFFLINE_ONLINE_SIGNING_DEV_PROMPT (set as NO).
 */
static BOOL const CONFIGURATION_DEFAULT_TO_OFFLINE_SIGNING = YES;

/** Configuration constant to show the sync confirmation (developer) dialog when user completes the signing
 * process. Sync confirmation is shown again when a pending envelope for sync is tapped.
 */
static BOOL const CONFIGURATION_SHOW_SYNC_DEV_PROMPT = YES;

#endif /* ConfigurationConstants_h */
