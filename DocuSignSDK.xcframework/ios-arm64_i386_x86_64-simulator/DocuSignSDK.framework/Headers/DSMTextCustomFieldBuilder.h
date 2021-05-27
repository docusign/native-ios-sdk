#import <Foundation/Foundation.h>
#import <DSMEnvelopeTextCustomField.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 * @interface DSMTextCustomFieldBuilder
 * @abstract TextCustomFieldBuilder to construct an object of DSMEnvelopeTextCustomField.
 * @see DSMEnvelopeTextCustomField
 */
@interface DSMTextCustomFieldBuilder : NSObject

/*!
 * @discussion return an instance of text custom field builder.
 */
+ (instancetype)builder;

/*!
 * @discussion add custom text field id and return the builder object.
 * @param fieldId an string (unique) representing custom field id.
 */
- (DSMTextCustomFieldBuilder *)addFieldId:(NSString *)fieldId;
/*!
 * @discussion add custom text field name and return the builder object.
 * @param name a string representing custom field name
 */
- (DSMTextCustomFieldBuilder *)addName:(NSString *)name;
/*!
 * @discussion add custom text field name and return the builder object.
 * @param value a string representing custom field value
 */
- (DSMTextCustomFieldBuilder *)addValue:(NSString *)value;
/*!
 * @discussion add custom text field name and return the builder object.
 * @param show a boolean representing the flag to show it
 */
- (DSMTextCustomFieldBuilder *)show:(BOOL)show;
/*!
 * @discussion Creates an envelope text custom field
 */
- (DSMEnvelopeTextCustomField *)build;

@end

NS_ASSUME_NONNULL_END
