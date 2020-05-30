#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/*!
 @class DSMErrorDetails
 */
@interface DSMErrorDetails : NSObject
/*!  @brief An error code associated with the error. [optional]
 */
@property (nonatomic, copy) NSString *errorCode;
/*!  @brief A short error message. [optional]
 */
@property (nonatomic, copy) NSString *message;

@end

NS_ASSUME_NONNULL_END
