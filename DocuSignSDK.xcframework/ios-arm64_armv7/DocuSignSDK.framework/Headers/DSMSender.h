#import <Foundation/Foundation.h>

@interface DSMSender : NSObject

/*  [optional] The account ID associated with the envelope.
 */
@property(nonatomic, nullable, copy) NSString* accountId;

/*  [optional] The name on the account.
 */
@property(nonatomic, nullable, copy) NSString* accountName;

/*  [optional] Access code provided to the user to activate the account.
 */
@property(nonatomic, nullable, copy) NSString* activationAccessCode;

/*  [optional] The user's email address.
 */
@property(nonatomic, nullable, copy) NSString* email;

/*  [optional] When set to true, indicates that the user is logged in. This is a read-only property
 */
@property(nonatomic, assign) BOOL loginStatus;

/*  [optional] The user's membership ID.
 */
@property(nonatomic, nullable, copy) NSString* membershipId;

/*  [optional] When set to true, specifies that an activation email will be sent to the user.
 */
@property(nonatomic, assign) BOOL sendActivationEmail;

/*  [optional] A URI containing the user ID.
 */
@property(nonatomic, nullable, copy) NSString* uri;

/*  [optional] The ID of the user to access.
 
 Note: Users can only access their own information. A user, even one with Admin rights, cannot access another user's settings.
 */
@property(nonatomic, nullable, copy) NSString* userId;

/*  [optional] The name of the user.
 */
@property(nonatomic, nullable, copy) NSString* userName;

/*  [optional] Status of the user's account. One of:
 * - ActivationRequired
 * - ActivationSent
 * - Active
 * - Closed
 * - Disabled
 */
@property(nonatomic, nullable, copy) NSString* userStatus;

/*  [optional] The type of user, for example CompanyUser.
 */
@property(nonatomic, nullable, copy) NSString* userType;


@end

