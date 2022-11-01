#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSESObject.h>

@interface DSESConsumerDisclosure : DSESObject

@property (nonatomic) NSString *accountEsignId;
@property (nonatomic) NSString *esignAgreement;
@property (nonatomic) NSString *mustAgreeToEsign;
@property (nonatomic) NSString *companyName;

@end
