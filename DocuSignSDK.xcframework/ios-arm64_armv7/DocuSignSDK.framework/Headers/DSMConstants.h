#import <Foundation/Foundation.h>

#pragma mark - USER Error Constants
extern NSString * const DSM_USER_ADDITIONAL_DATA_FETCH_ERROR;
extern NSString * const DSM_USER_LOGIN_ERROR;
extern NSString * const DSM_USER_PERSIST_ERROR;
extern NSString * const DSM_USER_DATA_FETCH_ERROR;
extern NSString * const DSM_USER_DATA_DELETE_ERROR;
extern NSString * const DSM_USER_NOT_LOGGED_IN_ERROR;

#pragma mark - SDK Error Constants
extern NSString * const DSM_SDK_SETUP_ERROR;
extern NSString * const DSM_SDK_FETCH_ERROR;

#pragma mark - Template Error Constants
extern NSString * const DSM_TEMPLATE_IMPORT_ERROR;
extern NSString * const DSM_TEMPLATE_SAVE_ERROR;
extern NSString * const DSM_TEMPLATE_SEND_ERROR;
extern NSString * const DSM_TEMPLATE_SIGN_ERROR;
extern NSString * const DSM_TEMPLATE_ENVELOPE_DEFAULTS_ERROR;

#pragma mark - Document Creation error Constants
extern NSString * const DSM_DOCUMENT_INVALID_TYPE_ERROR;
extern NSString * const DSM_DOCUMENT_EXCEEDS_LIMIT_ERROR;
extern NSString * const DSM_DOCUMENT_GENERIC_ERROR;

#pragma mark - Envelope Error Constants
extern NSString * const DSM_ENVELOPE_SAVE_ERROR;
extern NSString * const DSM_ENVELOPE_RESUME_ERROR;
extern NSString * const DSM_ENVELOPE_SYNC_ERROR;
extern NSString * const DSM_ENVELOPE_COREDATA_PERSISTENCE_FAILED_REASON;
extern NSString * const DSM_ENVELOPE_CREATION_ONLINEMODE_UNSUPPORTED;
extern NSString * const DSM_ENVELOPE_WITH_INVALID_TEXT_TAB_DEFAULTS_REASON;
extern NSString * const DSM_ENVELOPE_RESUME_FAILED_REASON;
extern NSString * const DSM_ENVELOPE_SYNC_FAILED_REASON;
extern NSString * const DSM_ENVELOPE_IMPORT_ERROR;

#pragma mark - Captive Signing
extern NSString * const DSM_ENVELOPE_CAPTIVE_RECIPIENTS_ERROR;

#pragma mark - Signature Adoption
extern NSString * const DSM_SIGNATURE_GET_ERROR;
extern NSString * const DSM_SIGNATURE_SET_ERROR;
extern NSString * const DSM_SETTINGS_GET_ERROR;

#pragma mark - Offline Signing
extern NSString * const DSM_ENVELOPE_DOWNLOAD_ERROR;
extern NSString * const DSM_ENVELOPE_UPLOAD_ERROR;
