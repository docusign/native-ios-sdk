#ifndef DSMEnvelopeDefaultsUniqueRecipientSelectorType_h
#define DSMEnvelopeDefaultsUniqueRecipientSelectorType_h

#import <Foundation/Foundation.h>

/*!
 * @typedef DSMEnvelopeDefaultsUniqueRecipientSelectorType
 * @brief "recipientId" and "roleName" are supported ways to uniquely identify a  recipient in a template. "recipientId" is always unique for each of the recipients in a template. "roleName" can potentially identify a uniqe recipient, if it's ensured to have unique string identifer during template creation.
 * Refer to DocuSign API documentation on using "roleName" for templates along with dependencies on "routingOrder", "name" & "email" for recipients.
 * @constant DSMEnvelopeDefaultsUniqueRecipientSelectorTypeRecipientId, default value, corresponds to DSMEnvelopeDefaultsUniqueRecipientSelectorTypeRecipientId (i.e. will use "recipientId" to uniquely identify a single recipent in a template) value.
 * @constant DSMEnvelopeDefaultsUniqueRecipientSelectorTypeRecipientRoleName, corresponds to DSMEnvelopeDefaultsUniqueRecipientSelectorTypeRecipientRoleName (i.e. will use "roleName" to uniquely identify a single recipent in a template) value.
 */
typedef NS_ENUM(NSUInteger, DSMEnvelopeDefaultsUniqueRecipientSelectorType) {
    DSMEnvelopeDefaultsUniqueRecipientSelectorTypeRecipientId,
    DSMEnvelopeDefaultsUniqueRecipientSelectorTypeRecipientRoleName
};

#endif /* DSMEnvelopeDefaultsUniqueRecipientSelectorType_h */

