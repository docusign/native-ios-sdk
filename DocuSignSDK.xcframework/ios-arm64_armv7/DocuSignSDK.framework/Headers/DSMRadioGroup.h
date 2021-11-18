#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSMRadio.h>

/*!
 @class DSMRadioGroup
 */
@interface DSMRadioGroup : NSObject

/*! @brief Specifies the document ID number that the tab is placed on. This must refer to an existing Document's ID attribute. [optional] */
@property(nonatomic, copy) NSString *documentId;
/*! @brief Unique for the recipient. It is used by the tab element to indicate which recipient is to sign the Document. [optional] */
@property(nonatomic, copy) NSString *recipientId;
/*! @brief For conditional fields this is the TabLabel of the parent tab that controls this tab's visibility. [optional] */
@property(nonatomic, copy) NSString *conditionalParentLabel;
/*! @brief For conditional fields, this is the value of the parent tab that controls the tab's visibility.\n\nIf the parent tab is a Checkbox, Radio button, Optional Signature, or Optional Initial use \"on\" as the value to show that the parent tab is active. [optional] */
@property(nonatomic, copy) NSString *conditionalParentValue;
/*! @brief The name of the group. [optional] */
@property(nonatomic, copy) NSString *groupName;
/*! @brief Specifies the locations and status for radio buttons that are grouped together. [optional] */
@property(nonatomic, copy) NSArray<DSMRadio *> *radios;
/*! @brief When set to **true**, this custom tab is shared. [optional] */
@property(nonatomic, assign) BOOL shared;
/*! @brief Optional element for field markup. When set to **true**, the signer is required to initial when they modify a shared field. [optional] */
@property(nonatomic, assign) BOOL requireInitialOnSharedChange;
/*! @brief When set to **true** and shared is true, information must be entered in this field to complete the envelope. [optional] */
@property(nonatomic, assign) BOOL requireAll;

@end
