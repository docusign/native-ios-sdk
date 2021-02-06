#import <Foundation/Foundation.h>
#import "DSMEnvelopeTextCustomField.h"

@interface DSMTextCustomFieldBuilder : NSObject

+ (instancetype)builder;

- (DSMTextCustomFieldBuilder *)addFieldId:(NSUInteger)fieldId;
- (DSMTextCustomFieldBuilder *)addName:(NSString *)name;
- (DSMTextCustomFieldBuilder *)addValue:(NSString *)value;
- (DSMTextCustomFieldBuilder *)show:(BOOL)show;

- (DSMEnvelopeTextCustomField *)build;

@end

