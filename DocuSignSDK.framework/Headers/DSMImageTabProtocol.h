#import "DSMTabImageData.h"

/*! @protocol DSMImageTabProtocol
 *  @discussion Conforming to this protocol indicates instances can represent an image based annotation, such as DSMSignHereTab.
 *  @see DSMSignHere.h
 *  @see DSMInitialHere.h
 */
@protocol DSMImageTabProtocol

/*! @brief TODO:Empty:Tab imageData. */
@property(nonatomic, retain) DSMTabImageData *imageData;
/*! @brief TODO:Empty:Tab scaleValue. */
@property(nonatomic, copy) NSNumber *scaleValue;
/*! @brief TODO:Empty:Tab optional. */
@property(nonatomic, assign) BOOL optional;

@end
