#import "NSString+Additions.h"
@import DocuSignSDK;

@implementation NSString (Additions)

+ (NSString *)titleWithSDKVersion:(BOOL)withSDKVersion {
    if (withSDKVersion) {
        return [NSString stringWithFormat:@"Developer's Notes (%@)", [DSMManager buildVersion]];
    }
    return [NSString stringWithFormat:@"Developer's Notes"];
};

@end
