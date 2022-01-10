#import <DocuSignSDK/DSESObject.h>

@class DSMCDClientContext;

@interface DSESClientContext : DSESObject

@property (nonatomic, copy) NSString *application;
@property (nonatomic, copy) NSString *environment;
@property (nonatomic, copy) NSString *site;

- (instancetype)initWithDSMCDClientContext:(DSMCDClientContext *)clientContext;

@end

