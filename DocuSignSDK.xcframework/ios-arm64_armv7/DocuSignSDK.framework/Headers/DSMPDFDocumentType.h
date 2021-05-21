#ifndef DSMPDFDocumentType_h
#define DSMPDFDocumentType_h

#import <Foundation/Foundation.h>

extern NSString * const DSMPDFDocumentTypeCertificateValue;
extern NSString * const DSMPDFDocumentTypeCombinedValue;

/*!
 * @typedef DSMPDFDocumentType
 * @brief Different type of PDF documents part of template or envelope.
 * @constant DSMPDFDocumentTypeCombinedValue, default value, corresponds to DSMPDFDocumentTypeCombinedValue ("combined") value.
 * @constant DSMPDFDocumentTypeCertificateValue, corresponds to DSMPDFDocumentTypeCertificateValue ("certificate") value.
 */
typedef NS_ENUM(NSUInteger, DSMPDFDocumentType) {
    DSMPDFDocumentTypeCombined,
    DSMPDFDocumentTypeCertificate
};

#endif /* DSMPDFDocumentType_h */

