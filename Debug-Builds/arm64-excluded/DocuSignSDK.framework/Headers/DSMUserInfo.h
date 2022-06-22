#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class DSMUserInfo
 */
@interface DSMUserInfo : NSObject

/*! @brief The user name of the authenticated user */
@property(nonatomic, copy) NSString *userName;

/*! @brief The user e-mail of the authenticated user. */
@property(nonatomic, copy) NSString *email;

/*! @brief The user ID of the authenticated user. */
@property(nonatomic, copy) NSString *userId;

/*! @brief TODO:Empty. */
@property(nonatomic, copy) NSString *userType;

/*! @brief Status of the user's account. One of:
 ActivationRequired
 ActivationSent
 Active
 Closed
 Disabled */
@property(nonatomic, copy) NSString *userStatus;

/*! @brief TODO:Empty. */
@property(nonatomic, copy) NSString *uri;

@end

NS_ASSUME_NONNULL_END
