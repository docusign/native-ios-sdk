#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSESObject.h>


@interface DSMUserSignature : DSESObject

@property (nonatomic, copy) NSString *adoptedDateTime;
@property (nonatomic, copy) NSString *createdDateTime;
@property (nonatomic, copy) NSString *initialsImageUri;
@property (nonatomic, copy) NSString *signatureFont;
@property (nonatomic, copy) NSString *signatureImageUri;
@property (nonatomic, copy) NSString *signatureInitials;
@property (nonatomic, copy) NSString *signatureName;
@property (nonatomic, copy) NSString *signatureType;
@property (nonatomic, copy) NSString *initials150ImageId;
@property (nonatomic, copy) NSString *signature150ImageId;
@property (nonatomic, copy) NSString *signatureId;

@end
