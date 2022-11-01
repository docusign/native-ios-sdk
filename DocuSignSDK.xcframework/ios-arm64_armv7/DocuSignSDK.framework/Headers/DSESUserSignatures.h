#import <DocuSignSDK/DSESObject.h>
#import <DocuSignSDK/DSESUserSignature.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DSESUserSignatures
@end

@interface DSESUserSignatures : DSESObject

@property(nonatomic) NSArray<DSESUserSignature>* userSignatures;

@end

NS_ASSUME_NONNULL_END
