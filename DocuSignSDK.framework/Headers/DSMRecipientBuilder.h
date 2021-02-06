#import <Foundation/Foundation.h>
#import "DSMRecipientType.h"
#import "DSMEnvelopeRecipient.h"
#import "DSMEnvelopeTab.h"

@interface DSMRecipientBuilder : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)builderForType:(DSMRecipientType)recipientType;
- (DSMRecipientBuilder *)addRecipientId:(NSUInteger)recipientId;
- (DSMRecipientBuilder *)addSignerName:(NSString *)signerName;
- (DSMRecipientBuilder *)addSignerEmail:(NSString *)signerEmail;

- (DSMRecipientBuilder *)addHostName:(NSString *)hostName;
- (DSMRecipientBuilder *)addHostEmail:(NSString *)hostEmail;
- (DSMRecipientBuilder *)addRoutingOrder:(int)order;

- (DSMRecipientBuilder *)addTab:(DSMEnvelopeTab *)tab;
- (DSMRecipientBuilder *)addTabs:(NSArray<DSMEnvelopeTab *>*)tabs;

- (DSMEnvelopeRecipient *)build;

@end


