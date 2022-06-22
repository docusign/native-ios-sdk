#import "DSMTab.h"
#import "DSMTextTabProtocol.h"
#import "DSMTextTabFontProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class DSMCompany
 @abstract It describes a Company tab capabilities.
 @discussion Specifies a tag on the document where you want the recipient's company name to appear.\n\nWhen getting information that includes this tab type, the original value of the tab when the associated envelope was sent is included in the response.
 @see DSMTextTabProtocol.h
 */
@interface DSMCompany : DSMTab <DSMTextTabProtocol, DSMTextTabFontProtocol>

/*! @brief The initial value of the tab when it was sent to the recipient. [optional]. */
@property(nonatomic, copy) NSString *originalValue;
/*! @brief When set to **true**, the field appears normally while the recipient is adding or modifying the information in the field, but the data is not visible (the characters are hidden by asterisks) to any other signer or the sender.\n\nWhen an envelope is completed the information is available to the sender through the Form Data link in the DocuSign Console.\n\nThis setting applies only to text boxes and does not affect list boxes, radio buttons, or check boxes. [optional]. */
@property(nonatomic, assign) BOOL concealValueOnDocument;
/*! @brief When set to **true**, disables the auto sizing of single line text boxes in the signing screen when the signer enters data. If disabled users will only be able enter as much data as the text box can hold. By default this is false. This property only affects single line text boxes. [optional]. */
@property(nonatomic, assign) BOOL disableAutoSize;
/*! @brief An optional value that describes the maximum length of the property when the property is a string. [optional]. */
@property(nonatomic, copy) NSNumber *maxLength;

//@property(nonatomic, copy) NSString *value;

@end

NS_ASSUME_NONNULL_END
