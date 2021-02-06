#import <Foundation/Foundation.h>
#import "DSMEnvelopeListCustomField.h"

@interface DSMListCustomFieldBuilder : NSObject

+ (instancetype)builder;

- (DSMListCustomFieldBuilder *)addFieldId:(NSUInteger)fieldId;
- (DSMListCustomFieldBuilder *)addName:(NSString *)name;
- (DSMListCustomFieldBuilder *)addList:(NSArray <NSString *>*)listValues;
- (DSMListCustomFieldBuilder *)addValue:(NSString *)value;
- (DSMListCustomFieldBuilder *)show:(BOOL)show;

- (DSMEnvelopeListCustomField *)build;

@end

