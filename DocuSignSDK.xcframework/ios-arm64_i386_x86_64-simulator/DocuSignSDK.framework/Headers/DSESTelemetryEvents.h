#import <DocuSignSDK/DSESObject.h>
#import <DocuSignSDK/DSESTelemetryEvent.h>

@interface DSESTelemetryEvents : DSESObject

/// Event should be of type `DSESTelemetryEvent`
@property (nonatomic) NSArray<DSESTelemetryEvent> *events;

- (instancetype)initWithDSMCDTelemetryEvents:(NSArray *)cdTelemetryEvents;

@end

