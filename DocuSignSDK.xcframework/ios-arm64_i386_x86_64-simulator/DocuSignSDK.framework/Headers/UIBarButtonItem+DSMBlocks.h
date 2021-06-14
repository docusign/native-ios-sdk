#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^BarButtonItemBlock)(UIBarButtonItem *barButtonItem);

@interface UIBarButtonItem (DSMBlocks)

- (id)initWithBarButtonSystemItem:(UIBarButtonSystemItem)systemItem completionBlock:(nullable BarButtonItemBlock)completion;
- (id)initWithTitle:(NSString *)title style:(UIBarButtonItemStyle)style completionBlock:(nullable BarButtonItemBlock)completion;

@end

NS_ASSUME_NONNULL_END
