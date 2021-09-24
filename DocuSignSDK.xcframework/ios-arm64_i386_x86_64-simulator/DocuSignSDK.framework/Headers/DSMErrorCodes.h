#ifndef DSMErrorCodes_h
#define DSMErrorCodes_h

/**
 Error code specific to DocuSign Native SDK that can be returned in NSError objects.
 */
typedef NS_ENUM(NSInteger, DSMErrorCode) {
    DSMErrorCodeEnvelopeStatusNotSentOrDelivered = 1001,
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
    DSMErrorCodeEnvelopeNotCached,
    DSMErrorCodeTemplateHasInvalidTabs,
    DSMErrorCodeEnvelopeHasInvalidTabs,
    DSMErrorCodeTemplateRecipientTabHasInvalidAttributes,
    DSMErrorCodeEnvelopeRecipientTabHasInvalidAttributes,
    DSMErrorCodeTemplateRecipientHasInvalidAttributes,
    DSMErrorCodeEnvelopeRecipientHasInvalidAttributes,
    DSMErrorCodeTemplateWithSupplementalDocument,
    DSMErrorCodeEnvelopeWithSupplementalDocument,
    DSMErrorCodeEnvelopeWasModifiedWhileInOffline
};

#endif /* DSMErrorCodes_h */
