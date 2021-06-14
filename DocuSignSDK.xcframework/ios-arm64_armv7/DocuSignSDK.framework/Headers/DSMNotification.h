#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

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
@property (nonatomic, strong) DSMReminders *reminders;
/*!
 * @brief expirations The DSMExpirations class object.
 * @see DSMExpirations.h
 */
@property (nonatomic, strong) DSMExpirations *expirations;

@end

NS_ASSUME_NONNULL_END
