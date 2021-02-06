#import <Foundation/Foundation.h>
#import "DSMDocumentBuilder.h"
#import "DSMTextCustomField.h"
#import "DSMEnvelopeDocument.h"
#import "DSMEnvelopeRecipient.h"
#import "DSMEnvelopeTextCustomField.h"
#import "DSMEnvelopeListCustomField.h"
#import "DSMEnvelopeDefinition.h"

@interface DSMEnvelopeBuilder : NSObject

+ (instancetype)builder;

- (DSMEnvelopeBuilder *)addEmailSubject:(NSString *)subject;
- (DSMEnvelopeBuilder *)addEmailMessage:(NSString *)message;
- (DSMEnvelopeBuilder *)addEnvelopeName: (NSString *)name;

// Documents
- (DSMEnvelopeBuilder *)addDocument:(DSMEnvelopeDocument *)document;
- (DSMEnvelopeBuilder *)addDocuments:(NSArray<DSMEnvelopeDocument *> *)documents;

// Recipients
- (DSMEnvelopeBuilder *)addRecipient:(DSMEnvelopeRecipient *)recipient;
- (DSMEnvelopeBuilder *)addRecipients:(NSArray<DSMEnvelopeRecipient *>*)recipient;

//Custom Fields
- (DSMEnvelopeBuilder *)addTextCustomField:(DSMEnvelopeTextCustomField *)textCustomField;
- (DSMEnvelopeBuilder *)addTextCustomFields:(NSArray<DSMEnvelopeTextCustomField *>*)textCustomFields;
- (DSMEnvelopeBuilder *)addListCustomField:(DSMEnvelopeListCustomField *) listCustomField;
- (DSMEnvelopeBuilder *)addListCustomFields:(NSArray<DSMEnvelopeListCustomField *>*) listCustomFields;

/** Creates an envelope using the DSMEnvelopeBuilder
 * @throws DSMEnvelopeException
 */
- (DSMEnvelopeDefinition *)build;

@end
