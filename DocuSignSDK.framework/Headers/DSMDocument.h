#import <CoreData/CoreData.h>

@class DSMNameValue;
/*!
 @class DSMDocument
 */
@interface DSMDocument : NSObject
/*!
 * @brief Specifies the document ID number that the tab is placed on. This must refer to an existing Document's ID attribute. [optional]
 */
@property (nonatomic, copy) NSString *documentId;
/*!
 * @brief TODO:Doc
 */
@property (nonatomic, copy) NSString *uri;
/*!
 * @brief The file id from the cloud storage service where the document is located. This information is returned using [ML:GET /folders] or [ML:/folders/{folderid}]. [optional]
 */
@property (nonatomic, copy) NSString *remoteUrl;
/*!
 * @brief TODO:Doc
 */
@property (nonatomic, copy) NSString *name;
/*!
 * @brief TODO:Doc
 */
@property (nonatomic, copy) NSString *password;
/*!
 * @brief When set to **true**, PDF form field data is transformed into document tab values when the PDF form field name matches the DocuSign custom tab tabLabel. The resulting PDF form data is also returned in the PDF meta data when requesting the document PDF. See the [ML:Transform PDF Fields] section for more information about how fields are transformed into DocuSign tabs. [optional]
 */
@property (nonatomic, assign) BOOL transformPdfFields;
/*!
 * @brief The file extension type of the document. If the document is not a PDF it is converted to a PDF. [optional]
 */
@property (nonatomic, copy) NSString *fileExtension;
/*!
 * @brief TODO:Doc
 */
@property (nonatomic, copy) NSString *order;
/*!
 * @brief TODO:Doc
 */
@property (nonatomic, copy) NSString *pages;
/*!
 * @brief When set to **true**, the document is been already encrypted by the sender for use with the DocuSign Key Manager Security Appliance. [optional]
 */
@property (nonatomic, assign) BOOL encryptedWithKeyManager;
/*!
 * @brief The document byte stream. This allows putting a base64 version of document bytes into an envelope. [optional]
 */
@property (nonatomic, copy) NSString *documentBase64;
/*!
 * @brief TODO:Doc
 */
@property (nonatomic, copy) NSString *applyAnchorTabs;
/*!
 * @brief TODO:Doc
 */
@property (nonatomic, copy) NSString *sandboxFilePath; // Coredata
/*!
 * @brief TODO:Doc
 */
@property (nonatomic, copy) NSData *pdf; // Coredata
/*!
 * @brief TODO:Doc
 */
@property (nonatomic, copy) NSString *display;
/*!
 * @brief TODO:Doc
 */
@property (nonatomic, copy) NSString *signerMustAcknowledge;
/*!
 * @brief TODO:Doc
 */
@property (nonatomic, assign) BOOL includeInDownload;
/*!
 * @brief NSSet of DSMNameValue class object.
 * @see DSMNameValue.h
 */
@property (nonatomic, retain) NSSet<DSMNameValue *> *documentFields;

@end
