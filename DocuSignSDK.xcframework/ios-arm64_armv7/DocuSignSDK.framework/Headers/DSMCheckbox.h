#import <DocuSignSDK/DSMTab.h>
#import <DocuSignSDK/DSMTextTabProtocol.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class DSMCheckbox
 @abstract It describes a Checkbox tab capabilities.
 @discussion Specifies a tag on the document in a location where the recipient can select an option.
 @see DSMTextTabProtocol.h
 */
@interface DSMCheckbox : DSMTab <DSMTextTabProtocol>

/*! @brief When set to **true**, the checkbox is selected. [optional]. */
@property(nonatomic, assign) BOOL selected;
/*! @brief When set to **true**, this custom tab is shared. [optional]. */
@property(nonatomic, assign) BOOL shared;
/*! @brief Optional element for field markup. When set to **true**, the signer is required to initial when they modify a shared field. [optional]. */
@property(nonatomic, assign) BOOL requireInitialOnSharedChange;

@property(nonatomic, copy) NSArray<NSString *> * tabGroupLabels;

@end

NS_ASSUME_NONNULL_END
