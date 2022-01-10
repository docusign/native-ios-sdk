#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSESApiClient.h>
#import <DocuSignSDK/DSESConsumerDisclosure.h>

@interface DSESConsumerDisclosureApi : NSObject

@property(nonatomic, assign)DSESApiClient *apiClient;

-(instancetype) initWithApiClient:(DSESApiClient *)apiClient;
-(void) addHeader:(NSString*)value forKey:(NSString*)key;

-(NSNumber*) getConsumerDisclosureWithCompletionBlock :(NSString*) accountId
                                     completionHandler: (void (^)(DSESConsumerDisclosure* output, NSError* error))completionBlock;

@end
