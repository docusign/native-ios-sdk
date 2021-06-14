#import <DocuSignSDK/DSMTab.h>
#import <DocuSignSDK/DSMTextTabFontProtocol.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class DSMDateSigned
 @abstract It describes a DateSigned tab capabilities.
 @discussion Specifies a tag on the document where you want the date of document signing to appear.
 @see DSMTextTabProtocol.h
 */
@interface DSMDateSigned : DSMTab <DSMTextTabFontProtocol>

//@property(nonatomic, copy) NSString *value;

@end

NS_ASSUME_NONNULL_END
