#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSESObject.h>

@protocol DSESSender
@end

@interface DSESSender : DSESObject

/*  [optional] The account ID associated with the envelope.
 */
@property(nonatomic) NSString* accountId;

/*  [optional] The name on the account.
 */
@property(nonatomic) NSString* accountName;

/*  [optional] Access code provided to the user to activate the account.
 */
@property(nonatomic) NSString* activationAccessCode;

/*  [optional] The user's email address.
 */
@property(nonatomic) NSString* email;

/*  [optional] When set to true, indicates that the user is logged in. This is a read-only property
 */
@property(nonatomic) NSString* loginStatus;

/*  [optional] The user's membership ID.
 */
@property(nonatomic) NSString* membershipId;

/*  [optional] When set to true, specifies that an activation email will be sent to the user.
 */
@property(nonatomic) NSString* sendActivationEmail;

/*  [optional] A URI containing the user ID.
 */
@property(nonatomic) NSString* uri;

/*  [optional] The ID of the user to access.
 
 Note: Users can only access their own information. A user, even one with Admin rights, cannot access another user's settings.
 */
@property(nonatomic) NSString* userId;

/*  [optional] The name of the user.
 */
@property(nonatomic) NSString* userName;

/*  [optional] Status of the user's account. One of:
 * - ActivationRequired
 * - ActivationSent
 * - Active
 * - Closed
 * - Disabled
 */
@property(nonatomic) NSString* userStatus;

/*  [optional] The type of user, for example CompanyUser.
 */
@property(nonatomic) NSString* userType;

@end

