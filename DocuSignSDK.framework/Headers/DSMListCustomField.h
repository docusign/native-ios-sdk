#import <Foundation/Foundation.h>

/*!
 @class DSMListCustomField
 */
@interface DSMListCustomField : NSObject

/*! @brief An ID used to specify a custom field. [optional] */
@property (nonatomic, copy) NSString *fieldId;
/*! @brief The name of the custom field. If you want to override the custom field's value on an envelope or template, the name property should exactly match with the name of the custom field.*/
@property (nonatomic, copy) NSString * _Nonnull name;
/*! @brief A boolean indicating if the value should be displayed to envelope creator. [optional] */
@property (nonatomic, assign) BOOL show;
/*! @brief When set to **true**, the signer is required to pass "value" for this instance [optional] */
@property (nonatomic, assign) BOOL required;
/*! @brief The value of the custom field. This field is optional when required is set as **false**  */
@property (nonatomic, copy) NSString *value;
/*! @brief An array of list items. [optional] */
@property (nonatomic, copy) NSArray<NSString *> *listItems;
/*! @brief A configurationType of custom Field. */
@property (nonatomic, copy) NSString *configurationType;

@end
