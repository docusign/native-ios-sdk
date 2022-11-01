#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSESObject.h>
#import <DocuSignSDK/DSESTabs.h>
#import <DocuSignSDK/DSESErrorDetails.h>

@protocol DSESWitness
@end

@interface DSESWitness : DSESObject

@property(nonatomic) NSString* name;
@property(nonatomic) NSString* email;
@property(nonatomic) NSString* defaultRecipient;
@property(nonatomic) DSESTabs* tabs;
@property(nonatomic) NSString* signInEachLocation;
@property(nonatomic) NSString* requireSignerCertificate;
@property(nonatomic) NSString* recipientId;
@property(nonatomic) NSString* routingOrder;
@property(nonatomic) NSString* note;
@property(nonatomic) NSString* roleName;
@property(nonatomic) DSESErrorDetails* errorDetails;
@property(nonatomic) NSString* recipientType;

@end
