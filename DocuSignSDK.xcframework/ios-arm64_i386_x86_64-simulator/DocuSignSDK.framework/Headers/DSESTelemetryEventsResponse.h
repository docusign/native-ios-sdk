#import <DocuSignSDK/DSESObject.h>
#import <DocuSignSDK/DSESFailedTelemetryEvent.h>

@interface DSESTelemetryEventsResponse : DSESObject

@property (nonatomic, copy) NSArray<DSESFailedTelemetryEvent> *failedEvents;

@end

