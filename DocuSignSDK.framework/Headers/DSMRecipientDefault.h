#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, DSMRecipientType);
typedef NS_ENUM(NSUInteger, DSMEnvelopeDefaultsUniqueRecipientSelectorType);

/*!
 @class DSMRecipientDefault
 @abstract Parent class that contains the recipient default values to apply to override template data before starting signing ceremony.
 @see DSMEnvelopeDefaults.h
 */
@interface DSMRecipientDefault : NSObject

/*! Name of inPersonSigner, Required only in case of recipientType as DSMRecipientTypeInPersonSigner.
 @see DSMRecipientType
 */
@property (nonatomic, retain) NSString *inPersonSignerName;
/*! Email of the recipient, required for both DSMRecipientTypeInPersonSigner or DSMRecipientTypeSigner
 @see DSMRecipientType
 */
@property (nonatomic, retain) NSString *recipientEmail;
/*! Name of the recipient, required for both DSMRecipientTypeInPersonSigner or DSMRecipientTypeSigner
 @see DSMRecipientType
 */
@property (nonatomic, retain) NSString *recipientName;
/*! Selector value to identify a recipient with Id (e.g. "1" or "41774568"). Required when DSMEnvelopeDefaultsUniqueRecipientSelectorType is set as DSMEnvelopeDefaultsUniqueRecipientSelectorTypeRecipientId.
 @see DSMEnvelopeDefaultsUniqueRecipientSelectorType
 */

@property (nonatomic, retain) NSString *recipientId;
/*! Selector value to identify a recipient with a given roleName (e.g. "SalesRep 1"). Required when DSMEnvelopeDefaultsUniqueRecipientSelectorType is set as DSMEnvelopeDefaultsUniqueRecipientSelectorTypeRecipientRoleName.
 @see DSMEnvelopeDefaultsUniqueRecipientSelectorType
 */
@property (nonatomic, retain) NSString *recipientRoleName;

/*! Type of the recipient selector
 @see DSMEnvelopeDefaultsUniqueRecipientSelectorType
 */
@property (nonatomic, assign) DSMEnvelopeDefaultsUniqueRecipientSelectorType recipientSelectorType;
/*! Type of the recipient (Host vs RemoteSigner)
 @see DSMRecipientType.h
 */
@property (nonatomic, assign) DSMRecipientType recipientType;


/*! When this boolean set to "true" the recipient will be removed during envelope creation.To remove a recipient, recipientName and recipientEmail is not required. Default value for this parameter is false.
 @see recipientId,recipientRoleName
 */
@property (nonatomic, assign) BOOL removeRecipient;

@end
