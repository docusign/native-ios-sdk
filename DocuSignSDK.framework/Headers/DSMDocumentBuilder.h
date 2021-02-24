#import <Foundation/Foundation.h>
#import "DSMEnvelopeDocument.h"

NS_ASSUME_NONNULL_BEGIN

@class DSMDocument;

/*!
 @interface DSMDocumentBuilder
 @abstract DocumentBuilder to construct an object of DSMEnvelopeDocument which can be used with DSMEnvelopeBuilder.
 @see DSMEnvelopeBuilder DSMEnvelopeDocument DSMEnvelopesManager
 */
@interface DSMDocumentBuilder : NSObject

/*!
 @discussion return an instance of document builder.
 */
+ (instancetype)builder;

/*!
 * @discussion add document name and return builder object.
 * @param name a string representing document name
 */
- (DSMDocumentBuilder *)addName:(nonnull NSString *)name;
/*!
 * @discussion add document id and return builder object. All of the tabs added to a recipient in envelope must belong to a valid document id.
 * @param documentId a string representing document id
 */
- (DSMDocumentBuilder *)addDocumentId:(nonnull NSString *)documentId;
/*!
 * @discussion add document file path in the bundle and return builder object.
 * @param filePath a string representing document file path
 */
- (DSMDocumentBuilder *)addFilePath:(nonnull NSString *)filePath;

/*!
 * @discussion return the envelope document object
 */
- (DSMEnvelopeDocument *)build;

@end

NS_ASSUME_NONNULL_END
