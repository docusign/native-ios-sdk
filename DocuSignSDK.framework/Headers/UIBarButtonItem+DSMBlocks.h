#import <UIKit/UIKit.h>
typedef void(^BarButtonItemBlock)(UIBarButtonItem *barButtonItem);

@interface UIBarButtonItem (DSMBlocks)

- (id)initWithBarButtonSystemItem:(UIBarButtonSystemItem)systemItem completionBlock:(BarButtonItemBlock)completion;
- (id)initWithTitle:(NSString *)title style:(UIBarButtonItemStyle)style completionBlock:(BarButtonItemBlock)completion;

@end
