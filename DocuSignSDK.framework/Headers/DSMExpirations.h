#import <Foundation/Foundation.h>

/*!
 @class DSMExpirations
 */
@interface DSMExpirations : NSObject
/*!  
 * @brief When set to **true**, the envelope expires (is no longer available for signing) in the set number of days. If false, the account default setting is used. If the account does not have an expiration setting, the DocuSign default value of 120 days is used. [optional]
 */
@property (nonatomic, assign) BOOL expireEnabled;
/*!  
 * @brief An integer that sets the number of days the envelope is active. [optional]
 */
@property (nonatomic, copy) NSNumber *expireAfter;
/*!  
 * @brief An integer that sets the number of days before envelope expiration that an expiration warning email is sent to the recipient. If set to 0 (zero), no warning email is sent. [optional]
 */
@property (nonatomic, copy) NSNumber *expireWarn;

@end
