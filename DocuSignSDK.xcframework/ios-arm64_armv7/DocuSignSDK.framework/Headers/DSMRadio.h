#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSMTab.h>
#import <DocuSignSDK/DSMTextTabProtocol.h>
@class DSMRadioGroup;

/*!
 @class DSMRadio
 */
@interface DSMRadio : DSMTab <DSMTextTabProtocol>

/*! @brief This indicates the horizontal offset of the object on the page. DocuSign uses 72 DPI when determining position. [optional] */
@property(nonatomic) NSInteger *xPosition;
/*! @brief This indicates the vertical offset of the object on the page. DocuSign uses 72 DPI when determining position. [optional] */
@property(nonatomic) NSInteger *yPosition;
/*! @brief When set to **true**, the radio button is selected. [optional] */
@property(nonatomic, assign) BOOL selected;
/*! @brief When set to **true**, the signer is required to fill out this tab [optional] */
@property(nonatomic, assign) BOOL required;
/*! @brief When set to **true**, the signer cannot change the data of the custom tab. [optional] */
@property(nonatomic, assign) BOOL  locked;
/*! @brief Parent radio group */
@property (nonatomic, weak) DSMRadioGroup *radioGroup;

@end
