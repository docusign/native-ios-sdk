#import <Foundation/Foundation.h>

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
@property (nonatomic, retain) NSSet<DSMTextCustomField *> *textCustomFields;

/*!
 * @brief A set of list custom fields. [optional]
 * @see DSMListCustomField.h
 */
@property (nonatomic, retain) NSSet<DSMListCustomField *> *listCustomFields;

@end
