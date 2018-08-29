#import "DSMTabImageData.h"

/*! @protocol DSMImageTabProtocol
 *  @discussion Conforming to this protocol indicates instances can represent an image based annotation, such as DSMSignHereTab.
 *  @see DSMSignHere.h
 *  @see DSMInitialHere.h
 */
@protocol DSMImageTabProtocol

/*! @brief TabImageData contains NSData representing the adopted image based tabs (e.g. signatures, initials) */
@property(nonatomic, retain) DSMTabImageData *imageData;
/*! @brief Scale of the image based tabs. */
@property(nonatomic, copy) NSNumber *scaleValue;
/*!
 @brief Optional flag to determin if the image tab is required.
 @see DSMTextTabProtocol.h
 */
@property(nonatomic, assign) BOOL optional;

@end
