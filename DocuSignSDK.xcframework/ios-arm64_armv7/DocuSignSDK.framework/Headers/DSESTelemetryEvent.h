#import <DocuSignSDK/DSESObject.h>
#import "DSMCDTelemetryEvent.h"
@class DSESClientContext;

@protocol DSESTelemetryEvent
@end

@interface DSESTelemetryEvent : DSESObject

@property (nonatomic, copy) NSString *appVersion;
@property (nonatomic, copy) NSString *identity;
@property (nonatomic, copy) NSString *traceToken;
@property (nonatomic, copy) NSString *eventCategory;
@property (nonatomic, copy) NSString *eventName;
@property (nonatomic, copy) NSString *eventType;
@property (nonatomic, copy) NSArray <NSString *> *applications;
@property (nonatomic, strong) DSESClientContext *clientContext;
@property (nonatomic, copy) NSDictionary<NSString *, NSString *> *data;

- (instancetype)initWithDSMCDTelemetryEvent:(DSMCDTelemetryEvent *)cdEvent;

@end
