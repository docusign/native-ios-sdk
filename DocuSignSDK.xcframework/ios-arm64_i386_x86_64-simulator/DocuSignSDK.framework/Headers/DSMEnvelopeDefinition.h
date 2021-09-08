#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSMEnvelopeTemplate.h>

@class DSMSender;

@interface DSMEnvelopeDefinition : DSMEnvelopeTemplate

@property (nonatomic, strong) NSString *envelopeName;

@property (nonatomic, strong) DSMSender *sender;

@end
