#import <Foundation/Foundation.h>

/*!
 @class DSMConsumerDisclosure
 */
@interface DSMConsumerDisclosure : NSObject

@property (nullable, nonatomic, copy) NSString * accountEsignId;
@property (nullable, nonatomic, copy) NSString * esignAgreement;
@property (nullable, nonatomic, copy) NSString * companyName;
@property (nonatomic, assign) BOOL mustAgreeToEsign;

@end

