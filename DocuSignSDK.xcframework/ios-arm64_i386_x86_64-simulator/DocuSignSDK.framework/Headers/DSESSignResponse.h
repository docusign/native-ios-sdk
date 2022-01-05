#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSESObject.h>
#import <DocuSignSDK/DSESErrorDetails.h>


@protocol DSESSignResponse
@end

@interface DSESSignResponse : DSESObject

@property(nonatomic) DSESErrorDetails* errorDetails;

@end
