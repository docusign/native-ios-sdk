#import <Foundation/Foundation.h>
#import "DSMDocumentBuilder.h"
#import "DSMTextCustomField.h"
#import "DSMEnvelopeDocument.h"
#import "DSMEnvelopeRecipient.h"
#import "DSMEnvelopeTextCustomField.h"
#import "DSMEnvelopeListCustomField.h"
#import "DSMEnvelopeDefinition.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 * @interface DSMEnvelopeBuilder
 * @abstract EnvelopeBuilder to construct an object of DSMEnvelopeDefinition which can be used with envelope compose methods on EnvelopesManager.
 * @see DSMEnvelopeDocument DSMEnvelopeRecipient DSMEnvelopeTextCustomField DSMEnvelopeListCustomField DSMEnvelopesManager
 */
@interface DSMEnvelopeBuilder : NSObject

- (instancetype) init NS_UNAVAILABLE;

/*!
 @discussion return an instance of envelope builder.
 */
+ (instancetype)builder;

/*!
 * @discussion add email subject and return builder object.
 * @param subject a string representing email subject
 */
- (DSMEnvelopeBuilder *)addEmailSubject:(NSString *)subject;
/*!
 * @discussion add email message and return builder object.
 * @param message a string representing email message
 */
- (DSMEnvelopeBuilder *)addEmailMessage:(NSString *)message;
/*!
 * @discussion add envelope name and return builder object.
 * @param name a string representing envelope name
 */
- (DSMEnvelopeBuilder *)addEnvelopeName:(NSString *)name;

// Documents
/*!
 * @discussion add envelope document and return builder object.
 * @param document a document object that can also  be created with DSMDocumentBuilder
 * @see DSMDocumentBuilder DSMEnvelopeDocument
 */
- (DSMEnvelopeBuilder *)addDocument:(DSMEnvelopeDocument *)document;
/*!
 * @discussion add envelope documents and return builder object.
 * @param documents an array containing document objects which can also  be created with DSMDocumentBuilder
 * @see DSMDocumentBuilder DSMEnvelopeDocument
 */
- (DSMEnvelopeBuilder *)addDocuments:(NSArray<DSMEnvelopeDocument *> *)documents;

// Recipients
/*!
 * @discussion add envelope recipient and return builder object.
 * @param recipient a recipient object which can also  be created with DSMRecipientBuilder
 * @see DSMRecipientBuilder DSMEnvelopeRecipient
 */
- (DSMEnvelopeBuilder *)addRecipient:(DSMEnvelopeRecipient *)recipient;
/*!
 * @discussion add envelope recipients from an array and return builder object.
 * @param recipients an array containing recipient objects which can also  be created with DSMRecipientBuilder
 * @see DSMRecipientBuilder DSMEnvelopeRecipient
 */
- (DSMEnvelopeBuilder *)addRecipients:(NSArray<DSMEnvelopeRecipient *>*)recipients;

//Custom Fields
/*!
 * @discussion add custom text field and return builder object.
 * @param textCustomField a text custom field object which can also  be created with DSMTextCustomFieldBuilder
 * @see DSMTextCustomFieldBuilder
 */
- (DSMEnvelopeBuilder *)addTextCustomField:(DSMEnvelopeTextCustomField *)textCustomField;
/*!
 * @discussion add custom text field objects from an array and return builder object.
 * @param textCustomFields an array of text custom fields which can also  be created with DSMTextCustomFieldBuilder
 * @see DSMTextCustomFieldBuilder
 */
- (DSMEnvelopeBuilder *)addTextCustomFields:(NSArray<DSMEnvelopeTextCustomField *>*)textCustomFields;
/*!
 * @discussion add custom list field and return builder object.
 * @param listCustomField a list custom field object which can also  be created with DSMListCustomFieldBuilder
 * @see DSMListCustomFieldBuilder
 */
- (DSMEnvelopeBuilder *)addListCustomField:(DSMEnvelopeListCustomField *)listCustomField;
/*!
 * @discussion add custom list field objects from an array and return builder object.
 * @param listCustomFields an array of list custom field object which can also  be created with DSMListCustomFieldBuilder
 * @see DSMListCustomFieldBuilder
 */
- (DSMEnvelopeBuilder *)addListCustomFields:(NSArray<DSMEnvelopeListCustomField *>*)listCustomFields;

/*!
 * @discussion Creates an envelope using the DSMEnvelopeBuilder
 * @throws DSMEnvelopeException
 */
- (DSMEnvelopeDefinition *)build;

@end

NS_ASSUME_NONNULL_END
