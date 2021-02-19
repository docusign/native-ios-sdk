#import <Foundation/Foundation.h>
#import "DSMEnvelopeListCustomField.h"

/*!
 * @interface DSMListCustomFieldBuilder
 * @abstract ListCustomFieldBuilder to construct an object of DSMEnvelopeListCustomField.
 * @see DSMEnvelopeListCustomField
 */
@interface DSMListCustomFieldBuilder : NSObject
/*!
 * @discussion return an instance of list custom field builder.
 */
+ (instancetype)builder;

/*!
 * @discussion add custom list field id and return the builder object.
 * @param fieldId an unsigned integer representing custom field id
 */
- (DSMListCustomFieldBuilder *)addFieldId:(NSUInteger)fieldId;
/*!
 * @discussion add custom list field name and return the builder object.
 * @param name a string representing custom field name
 */
- (DSMListCustomFieldBuilder *)addName:(NSString *)name;
/*!
 * @discussion add custom list fields from an array and return the builder object.
 * @param listValues an array of list values (strings) representing custom field values
 */
- (DSMListCustomFieldBuilder *)addList:(NSArray <NSString *>*)listValues;
/*!
 * @discussion add custom list field name and return the builder object.
 * @param value a string representing custom field value
 */
- (DSMListCustomFieldBuilder *)addValue:(NSString *)value;
/*!
 * @discussion add custom list field name and return the builder object.
 * @param show a boolean representing the flag to show it
 */
- (DSMListCustomFieldBuilder *)show:(BOOL)show;
/*!
 * @discussion Creates an envelope list custom field
 */
- (DSMEnvelopeListCustomField *)build;

@end
