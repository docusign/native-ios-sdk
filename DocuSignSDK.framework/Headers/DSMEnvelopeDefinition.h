#import <Foundation/Foundation.h>
#import "DSMEnvelopeTemplate.h"

@class DSMSender;

@interface DSMEnvelopeDefinition : DSMEnvelopeTemplate

@property (nonatomic, strong) NSString *envelopeName;

@property (nonatomic, strong) DSMSender *sender;

@end
