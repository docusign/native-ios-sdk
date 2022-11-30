#ifndef DSMErrorCodes_h
#define DSMErrorCodes_h

/**
 Error code specific to DocuSign Native SDK that can be returned in NSError objects.
 */
typedef NS_ENUM(NSInteger, DSMErrorCode) {
    DSMErrorCodeEnvelopeStatusNotSentOrDelivered = 1001,
    DSMErrorCodeAccountNotLoggedIn,
    DSMErrorCodeNoIncompleteLocalSigner,
    DSMErrorCodePaymentNotSupported,
    DSMErrorCodeNotarySignersNotSupported,
    DSMErrorCodeNoDocuments,
    DSMErrorCodeUnsupportedTabsForOffline,
    DSMErrorCodeSignerWithoutTabs,
    DSMErrorCodeFreeformSigner,
    DSMErrorCodeEnvelopeSave,
    DSMErrorCodeSignerCanNotSignOnMobile,
    DSMErrorCodeIs21CFRPart11Enabled,
    DSMErrorCodeSignerCanNotSignOffline,
    DSMErrorCodeEnvelopeReadyForSync,
    DSMErrorCodeEnvelopeNotReadyForSync,
    DSMErrorCodeEnvelopeNotCached,
    DSMErrorCodeTemplateHasInvalidTabs,
    DSMErrorCodeEnvelopeHasInvalidTabs,
    DSMErrorCodeTemplateRecipientTabHasInvalidAttributes,
    DSMErrorCodeEnvelopeRecipientTabHasInvalidAttributes,
    DSMErrorCodeTemplateRecipientHasInvalidAttributes,
    DSMErrorCodeEnvelopeRecipientHasInvalidAttributes,
    DSMErrorCodeTemplateWithSupplementalDocument,
    DSMErrorCodeEnvelopeWithSupplementalDocument,
    DSMErrorCodeEnvelopeWasModifiedWhileInOffline,
    DSMErrorCodeSignatureIdInvalidParameter,
    DSMErrorCodeTemplateNotificationHasInvalidAttribute,
    DSMErrorCodeBase64SignatureConversionFailed,
    DSMErrorCodeInvalidSignatureType
};

#endif /* DSMErrorCodes_h */
