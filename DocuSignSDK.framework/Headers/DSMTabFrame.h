#import <Foundation/Foundation.h>

/*!
 @class DSMTabFrame
 */
@interface DSMTabFrame : NSObject

/*! @brief This indicates the horizontal offset of the object on the page. DocuSign uses 72 DPI when determining position. [optional]. */
@property(nonatomic) NSInteger originX;
/*! @brief This indicates the vertical offset of the object on the page. DocuSign uses 72 DPI when determining position. [optional]. */
@property(nonatomic) NSInteger originY;
/*! @brief Width of the tab in pixels. [optional]. */
@property(nonatomic) NSInteger width;
/*! @brief Height of the tab in pixels. [optional]. */
@property(nonatomic) NSInteger height;

@end
