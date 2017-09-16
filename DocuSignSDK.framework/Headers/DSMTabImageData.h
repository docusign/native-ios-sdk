#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class DSMTabImageData
 */
@interface DSMTabImageData : NSObject

/*!
 * @brief Image Data
 */
@property (nullable, nonatomic, retain) NSData *data;
/*!
* @discussion Image Data
* @param data image data
* @return instancetype
*/
- (instancetype)initWithData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
