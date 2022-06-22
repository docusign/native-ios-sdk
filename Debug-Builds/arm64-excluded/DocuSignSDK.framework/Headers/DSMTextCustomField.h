#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class DSMTextCustomField
 */
@interface DSMTextCustomField : NSObject

/*! @brief An ID used to specify a custom field. [optional] */
@property (nonatomic, copy) NSString *fieldId;
/*! @brief The name of the custom field. If you want to override the custom field's value on an envelope or template, the name property should exactly match with the name of the custom field.*/
@property (nonatomic, copy)  NSString * _Nonnull name;
/*! @brief A boolean indicating if the value should be displayed. [optional] */
@property (nonatomic, assign) BOOL show;
/*! @brief When set to **true**, the signer is required to pass "value" for this instance [optional] */
@property (nonatomic, assign) BOOL required;
/*! @brief The value of the custom field. This field is optional when required is set as **false**  */
@property (nonatomic, copy) NSString *value;
/*! @brief The configurationType of the custom field.  [optional] */
@property (nonatomic, copy) NSString *configurationType;

@end

NS_ASSUME_NONNULL_END
