#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSESObject.h>


@interface DSESSignatureAdoptionConfigurations : DSESObject

@property(nonatomic, copy) NSString* disableDrawSignature;
@property(nonatomic, copy) NSString* disableStyleSelection;
@property(nonatomic, copy) NSString* disableUploadSignature;
@property(nonatomic, copy) NSString* signatureAdoptMode;
@property(nonatomic, copy) NSString* mobileSignatureAdoptMode;
@property(nonatomic, copy) NSString* minimumPixelsToAdoptSignature;
@property(nonatomic, copy) NSString* minimumPixelsToAdoptInitials;
@property(nonatomic, copy) NSString* lockRecipientName;
@property(nonatomic, copy) NSArray* /* NSString */ availableSignatureAdoptionStyles;

@end
