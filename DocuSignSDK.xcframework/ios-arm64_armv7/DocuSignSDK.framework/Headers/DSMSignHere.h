#import <DSMTab.h>
#import <DSMImageTabProtocol.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class DSMSignHere
 @abstract It describes a SignHere tab capabilities.
 @discussion A complex type the contains information about the tag that specifies where the recipient places their signature in the document. The \"optional\" parameter sets if the signature is required or optional.
 @see DSMImageTabProtocol.h
 */
@interface DSMSignHere : DSMTab <DSMImageTabProtocol>

@end

NS_ASSUME_NONNULL_END
