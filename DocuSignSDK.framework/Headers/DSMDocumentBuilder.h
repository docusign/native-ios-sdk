#import <Foundation/Foundation.h>
#import "DSMEnvelopeDocument.h"

@class DSMDocument;

@interface DSMDocumentBuilder : NSObject
+ (instancetype)builder;

- (DSMDocumentBuilder *)addName:(NSString *)name;
- (DSMDocumentBuilder *)addDocumentId:(NSUInteger)docId;
- (DSMDocumentBuilder *)addFilePath:(NSString *)filePath;

- (DSMEnvelopeDocument *)build;

@end
