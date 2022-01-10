#import <DocuSignSDK/DSESObject.h>
#import <DocuSignSDK/DSESTelemetryEvent.h>

@protocol DSESFailedTelemetryEvent
@end

@interface DSESFailedTelemetryEvent : DSESObject

@property (nonatomic, copy) DSESTelemetryEvent *event;
@property (nonatomic, copy) NSString *failureReason;

@end

