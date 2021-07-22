#ifndef DSMErrorCodes_h
#define DSMErrorCodes_h

typedef SInt32 DSMErrorCode;
/**
 Error code specific to DocuSign Native SDK that can be returned in NSError objects.
 */
typedef NS_ENUM(DSMErrorCode, DSM_ErrorCode) {
    DSMErrorCodeEnvelopeStatusNotSentOrDelivered = 1001,
    DSMErrorCodeNoIncompleteLocalSigner,
    DSMErrorCodePaymentNotSupported,
    DSMErrorCodeNotarySignersNotSupported,
    DSMErrorCodeNoDocuments,
    DSMErrorCodeSignerCanNotSignOffline,
    DSMErrorCodeUnsupportedTabsForOffline,
    DSMErrorCodeSignerWithoutTabs,
    DSMErrorCodeFreeformSigner,
    DSMErrorCodeEnvelopeSave,
    DSMErrorSignerCanNotSignOnMobile,
    DSMErrorIs21CFRPart11Enabled,
    DSMErrorSignerCanNotSignOffline,
    DSMErrorEnvelopeReadyForSync,
    DSMErrorEnvelopeNotCached,
    DSMErrorTemplateHasInvalidTabs,
    DSMErrorEnvelopeHasInvalidTabs,
    DSMErrorTemplateRecipientTabHasInvalidAttributes,
    DSMErrorEnvelopeRecipientTabHasInvalidAttributes,
    DSMErrorTemplateRecipientHasInvalidAttributes,
    DSMErrorEnvelopeRecipientHasInvalidAttributes,
    DSMErrorTemplateWithSupplementalDocument,
    DSMErrorEnvelopeWithSupplementalDocument
};

#endif /* DSMErrorCodes_h */
