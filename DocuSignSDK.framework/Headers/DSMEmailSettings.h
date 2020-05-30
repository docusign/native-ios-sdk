#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

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
@property (nonatomic, strong) NSSet<DSMBCCEmailAddress *> *bccEmailAddresses;

@end

NS_ASSUME_NONNULL_END
