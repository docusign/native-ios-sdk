#import <DocuSignSDK/DSESObject.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DSESUserSignature
@end

// TODO: DSMUserSignature needs to be updated as it should be rather DSES* object.
@interface DSESUserSignature : DSESObject

@property(nonatomic, copy) NSString* signatureId;
@property(nonatomic, copy) NSString* signatureFont;
@property(nonatomic, copy) NSString* signatureImageUri;
@property(nonatomic, copy) NSString* signatureInitials;
@property(nonatomic, copy) NSString* initialsImageUri;
@property(nonatomic, copy) NSString* signature150ImageId;
@property(nonatomic, copy) NSString* initials150ImageId;
@property(nonatomic, copy) NSString* signatureName;
@property(nonatomic, copy) NSString* disallowUserResizeStamp;
@property(nonatomic, copy) NSString* createdDateTime;
@property(nonatomic, copy) NSString* adoptedDateTime;
@property(nonatomic, copy) NSString* status;

@end

NS_ASSUME_NONNULL_END
