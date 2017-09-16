#import <Foundation/Foundation.h>

/*!
 @class DSMTextCustomField
 */
@interface DSMTextCustomField : NSObject

/*! @brief An ID used to specify a custom field. [optional] */
@property (nonatomic, copy) NSString *fieldId;
/*! @brief The name of the custom field. [optional] */
@property (nonatomic, copy) NSString *name;
/*! @brief A boolean indicating if the value should be displayed. [optional] */
@property (nonatomic, assign) BOOL show;
/*! @brief When set to **true**, the signer is required to fill out this tab [optional] */
@property (nonatomic, assign) BOOL required;
/*! @brief The value of the custom field. [optional] */
@property (nonatomic, copy) NSString *value;
/*! @brief TODO:Empty. configurationType */
@property (nonatomic, copy) NSString *configurationType;

@end
