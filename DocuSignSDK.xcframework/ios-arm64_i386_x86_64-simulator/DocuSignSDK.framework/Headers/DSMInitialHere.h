#import <DocuSignSDK/DSMTab.h>
#import <DocuSignSDK/DSMImageTabProtocol.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class DSMInitialHere
 @abstract It describes a InitialHere tab capabilities.
 @discussion Specifies a tag to have a recipient place their initials in the document. The \"optional\" parameter sets if the initials are required or optional.
 @see DSMImageTabProtocol.h
 */
@interface DSMInitialHere : DSMTab <DSMImageTabProtocol>

@end

NS_ASSUME_NONNULL_END
