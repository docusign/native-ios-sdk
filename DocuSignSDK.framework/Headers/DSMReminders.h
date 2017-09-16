#import <Foundation/Foundation.h>
/*!
 @class DSMReminders
 */
@interface DSMReminders : NSObject
/*!
 * @brief When set to **true**, the envelope expires (is no longer available for signing) in the set number of days. If false, the account default setting is used. If the account does not have an expiration setting, the DocuSign default value of 120 days is used. [optional]
 */
@property (nonatomic, assign) BOOL reminderEnabled;
/*!
 * @brief An interger that sets the number of days after the recipient receives the envelope that reminder emails are sent to the recipient. [optional]
 */
@property (nonatomic, copy) NSNumber *reminderDelay;
/*!
 * @brief An interger that sets the interval, in days, between reminder emails. [optional]
 */
@property (nonatomic, copy) NSNumber *reminderFrequency;

@end
