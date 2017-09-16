#import <Foundation/Foundation.h>
@class DSMExpirations;
@class DSMReminders;
/*!
 @class DSMNotification
 */
@interface DSMNotification : NSObject
/*!
 * @brief When set to **true**, the account default notification settings are used for the envelope. [optional]
 */
@property (nonatomic, assign) BOOL useAccountDefaults;
/*!
 * @brief reminders The DSMReminders class object.
 * @see DSMReminders.h
 */
@property (nonatomic, retain) DSMReminders *reminders;
/*!
 * @brief expirations The DSMExpirations class object.
 * @see DSMExpirations.h
 */
@property (nonatomic, retain) DSMExpirations *expirations;

@end
