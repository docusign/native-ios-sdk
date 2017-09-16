#import <Foundation/Foundation.h>

@class DSMBCCEmailAddress;
/*!
 @class DSMEmailSettings
 */
@interface DSMEmailSettings : NSObject
/*!
 * @brief TODO:Doc
 */
@property (nonatomic, copy) NSString *replyEmailAddressOverride;
/*!
 * @brief TODO:Doc
 */
@property (nonatomic, copy) NSString *replyEmailNameOverride;
/*!
 * @brief The NSSet of DSMBCCEmailAddress class object.
 * @see DSMBCCEmailAddress.h
 */
@property (nonatomic, retain) NSSet<DSMBCCEmailAddress *> *bccEmailAddresses;

@end
