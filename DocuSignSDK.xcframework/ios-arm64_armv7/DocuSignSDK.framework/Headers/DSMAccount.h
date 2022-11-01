#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSESLoginInformation.h>
#import <DocuSignSDK/DSMAuthenticationMethod.h>
#import <DocuSignSDK/DSMGlobalTypeDefines.h>

@class DSMCDRecipient;
@class DSMAccountInfo;

@interface DSMAccount : NSObject

typedef enum {
    DSMSignAndReturnWithLink,
    DSMSignAndReturnWithAttachment
} DSMSignAndReturnMethod;

@property (nonatomic, readonly, strong) NSString *userId;
@property (nonatomic, readonly, strong) NSString *accountId;
@property (nonatomic, strong) NSString *accountName;
@property (nonatomic, strong) NSDictionary *accountSettings;
@property (nonatomic, readonly, strong) NSString *apiPassword;
@property (nonatomic, strong) NSString *consumerDisclosure;
@property (nonatomic, strong) NSString *consumerDisclosureId;
@property (nonatomic, readonly, strong) NSString *integratorKey;
@property (nonatomic, readonly, strong) NSString *accessToken;
@property (nonatomic, readonly, strong) NSString *userName;
@property (nonatomic, strong) NSDictionary *userSettings;
@property (nonatomic, readonly, strong) NSString *email;
@property (nonatomic, readonly, strong) NSURL *host;
@property (nonatomic, readwrite) BOOL hasAdoptedSignature;
@property (nonatomic, readonly) DSMAuthenticationMethod authenticationMethod;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithLoginInfo:(DSESLoginInformation *)loginInfo host:(NSURL *)host integratorKey:(NSString *)integratorKey;

- (instancetype)initWithAccountInfo:(DSMAccountInfo *)accountInfo;

- (instancetype)initWithUserId:(NSString *)userId userName:(NSString *)userName email:(NSString *)email apiPassword:(NSString *)apiPassword accountId:(NSString *)accountId host:(NSURL *)host integratorKey:(NSString *)integratorKey;

- (instancetype)initWithAccessToken:(NSString *)accessToken userId:(NSString *)userId userName:(NSString *)userName email:(NSString *)email accountId:(NSString *)accountId host:(NSURL *)host integratorKey:(NSString *)integratorKey;

- (instancetype)initWithApiPassword:(NSString *)apiPassword userId:(NSString *)userId userName:(NSString *)userName email:(NSString *)email accountId:(NSString *)accountId host:(NSURL *)host integratorKey:(NSString *)integratorKey;

- (void)syncAdditionalDataWithCompletion:(DSMErrorBlock)completion;

- (BOOL)canOfflineSend;
- (BOOL)signerCanSignOnMobile;
- (DSMSignAndReturnMethod)shouldSignAndReturnWithMethod;

@end

@interface DSMAccount (NativeSigning)

//- (BOOL)isSameUser:(DSUser *)user;
- (BOOL)caseInsensitivelyMatchesNameAndEmailOfRecipient:(id)recipient;
- (BOOL)caseInsensitivelyMatchesHostNameAndHostEmailOfRecipient:(id)recipient;
- (BOOL)caseInsensitivelyMatchesName:(NSString *)name andEmail:(NSString *)email;

@end
