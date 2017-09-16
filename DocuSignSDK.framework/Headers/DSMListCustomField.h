#import <Foundation/Foundation.h>

/*!
 @class DSMListCustomField
 */
@interface DSMListCustomField : NSObject

/*! @brief An ID used to specify a custom field. [optional] */
@property (nonatomic, copy) NSString *fieldId;
/*! @brief The name of the custom field. [optional] */
@property (nonatomic, copy) NSString *name;
/*! @brief A boolean indicating if the value should be displayed. [optional] */
@property (nonatomic, assign) BOOL show;
/*! @brief When set to **true**, the signer is required to fill out this tab [optional] */
@property (nonatomic, assign) BOOL required;
/*! @brief The value of the custom field.\n\nMaximum Length: 100 characters. [optional] */
@property (nonatomic, copy) NSString *value;
/*! @brief An array of list items. [optional] */
@property (nonatomic, copy) NSArray<NSString *> *listItems;
/*! @brief TODO:Empty. configurationType */
@property (nonatomic, copy) NSString *configurationType;

@end
