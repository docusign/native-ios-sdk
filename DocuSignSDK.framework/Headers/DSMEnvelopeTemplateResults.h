#import <Foundation/Foundation.h>
#import "DSMEnvelopeTemplateDefinition.h"
#import "DSMFolder.h"

@interface DSMEnvelopeTemplateResults : NSObject

/* The list of requested templates. [optional]
 */
@property(nonatomic) NSArray<DSMEnvelopeTemplateDefinition *>* envelopeTemplates;
/* The number of results returned in this response. [optional]
 */
@property(nonatomic) NSString* resultSetSize;
/* Starting position of the current result set. [optional]
 */
@property(nonatomic) NSString* startPosition;
/* The last position in the result set. [optional]
 */
@property(nonatomic) NSString* endPosition;
/* The total number of items available in the result set. This will always be greater than or equal to the value of the `resultSetSize` property. [optional]
 */
@property(nonatomic) NSString* totalSetSize;
/* The URI to the next chunk of records based on the search request. If the endPosition is the entire results of the search, this is null. [optional]
 */
@property(nonatomic) NSString* nextUri;
/* The postal code for the billing address. [optional]
 */
@property(nonatomic) NSString* previousUri;
/*  [optional]
 */
@property(nonatomic) NSArray<DSMFolder *>* folders;

@end
