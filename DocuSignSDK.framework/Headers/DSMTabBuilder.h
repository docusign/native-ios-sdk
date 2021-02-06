#import <Foundation/Foundation.h>
#import "DSMTabType.h"
#import "DSMEnvelopeTab.h"

@interface DSMTabBuilder : NSObject
- (instancetype) init NS_UNAVAILABLE;
+ (instancetype) builderForType:(DSMTabType)tabType;


- (DSMTabBuilder *)addDocumentId:(NSUInteger)documentId;
- (DSMTabBuilder *)addRecipientId:(NSUInteger)recipientId;
- (DSMTabBuilder *)addFrame:(CGRect)frame;
- (DSMTabBuilder *)addPageNumber:(int)pageNumber;
- (DSMTabBuilder *)addTabLabel:(NSString *)tabLabel;
- (DSMTabBuilder *)addName:(NSString *)name;
- (DSMTabBuilder *)addValue:(NSString *)value;
- (DSMTabBuilder *)addGroupName:(NSString *)groupName;
- (DSMTabBuilder *)addScaleValue:(CGFloat)scaleValue;
- (DSMTabBuilder *)isLocked:(BOOL)isLocked;
- (DSMTabBuilder *)isOptional:(BOOL)isOptional;

- (DSMEnvelopeTab *)build;

@end

