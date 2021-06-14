#ifndef DSMRecipientType_h
#define DSMRecipientType_h

/*!
 * @typedef DSMRecipientType
 * @brief A list of Recipient Types for envelope and templates.
 * @constant DSMRecipientTypeNotSet not set, default value.
 * @constant DSMRecipientTypeAgent agent recipient type. @see DSMAgent.h
 * @constant DSMRecipientTypeCC carbon copy recipient type. @see DSMCarbonCopy.h
 * @constant DSMRecipientTypeCertifiedDelivery certified delivery recipient type. @see DSMDSMCertifiedDelivery.h
 * @constant DSMRecipientTypeEditor editor recipient type. @see DSMEditor.h
 * @constant DSMRecipientTypeIntermediary intermediary recipient type. @see DSMIntermediary.h
 * @constant DSMRecipientTypeInPersonSigner inperson signer recipient type. @see DSMInPersonSigner.h
 * @constant DSMRecipientTypeSigner signer recipient type. @see DSMSigner.h
 */
typedef NS_ENUM(NSUInteger, DSMRecipientType) {
    DSMRecipientTypeNotSet,
    DSMRecipientTypeAgent,
    DSMRecipientTypeCC,
    DSMRecipientTypeCertifiedDelivery,
    DSMRecipientTypeEditor,
    DSMRecipientTypeIntermediary,
    DSMRecipientTypeInPersonSigner,
    DSMRecipientTypeSigner,
} ;

#endif /* DSMRecipientType_h */
