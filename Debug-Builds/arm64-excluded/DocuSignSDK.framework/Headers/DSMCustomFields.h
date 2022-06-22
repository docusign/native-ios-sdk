#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DSMTextCustomField;
@class DSMListCustomField;
/*!
 @class DSMCustomFields
 */
@interface DSMCustomFields : NSObject

/*!
 * @brief A set of text custom fields. [optional]
 * @see DSMTextCustomField.h
 */
@property (nonatomic, strong) NSSet<DSMTextCustomField *> *textCustomFields;

/*!
 * @brief A set of list custom fields. [optional]
 * @see DSMListCustomField.h
 */
@property (nonatomic, strong) NSSet<DSMListCustomField *> *listCustomFields;

@end

NS_ASSUME_NONNULL_END
