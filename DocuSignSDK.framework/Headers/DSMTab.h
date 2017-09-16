#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@class DSMTabFrame, DSMMergeField, DSMErrorDetails;

typedef NS_ENUM(NSUInteger, DSMTabType);
/*!
 @class DSMTab
 */
@interface DSMTab : NSObject

/*!
 * @brief The DSMTabType enum denoting tab type.
 * @see DSMTabType.h
 */
@property(nonatomic) DSMTabType tabType;
/*! @brief Specifies the document ID number that the tab is placed on. This must refer to an existing Document's ID attribute. [optional]. */
@property (nonatomic, copy) NSString *documentId;
/*! @brief The label string associated with the tab. [optional]. */
@property (nonatomic, copy) NSString *tabLabel;
/*! @brief Specifies the page number on which the tab is located. [optional]. */
@property (nonatomic, copy) NSNumber *pageNumber;
/*! @brief Unique for the recipient. It is used by the tab element to indicate which recipient is to sign the Document. [optional]. */
@property (nonatomic, copy) NSString *recipientId;
/*! @brief The unique identifier for the tab. The tabid can be retrieved with the [ML:GET call]. [optional]. */
@property (nonatomic, copy) NSString *tabId;
/*! @brief When set to **true**, the sender cannot change any attributes of the recipient. Used only when working with template recipients. [optional]. */
@property (nonatomic, assign) BOOL templateLocked;
/*! @brief When set to **true**, the sender may not remove the recipient. Used only when working with template recipients. [optional]. */
@property (nonatomic, assign) BOOL templateRequired;
/*! @brief TODO:Empty:Tab tabOrder. */
@property (nonatomic, copy) NSNumber *tabOrder;
/*! @brief TODO:Empty:Tab name. */
@property (nonatomic, copy) NSString *name;
/*! @brief The DocuSign generated custom tab ID for the custom tab to be applied. This can only be used when adding new tabs for a recipient. When used, the new tab inherits all the custom tab properties. [optional]. */
@property (nonatomic, copy) NSString *customTabId;
/*! @brief Anchor text information for a radio button. [optional]. */
@property (nonatomic, copy) NSString *anchorString;
/*! @brief Specifies the X axis location of the tab, in achorUnits, relative to the anchorString. [optional]. */
@property (nonatomic, copy) NSNumber *anchorXOffset;
/*! @brief Specifies the Y axis location of the tab, in achorUnits, relative to the anchorString. [optional]. */
@property (nonatomic, copy) NSNumber *anchorYOffset;
/*! @brief Specifies units of the X and Y offset. Units could be pixels, millimeters, centimeters, or inches. [optional]. */
@property (nonatomic, copy) NSString *anchorUnits;
/*! @brief When set to **true**, this tab is ignored if anchorString is not found in the document. [optional]. */
@property (nonatomic, assign) BOOL anchorIgnoreIfNotPresent;
/*! @brief TODO:Empty:Tab anchorCaseSensitive. */
@property (nonatomic, assign) BOOL anchorCaseSensitive;
/*! @brief TODO:Empty:Tab anchorMatchWholeWord. */
@property (nonatomic, assign) BOOL anchorMatchWholeWord;
/*! @brief TODO:Empty:Tab anchorHorizontalAlignment. */
@property (nonatomic, copy) NSString *anchorHorizontalAlignment;
/*! @brief For conditional fields this is the TabLabel of the parent tab that controls this tab's visibility. [optional]. */
@property (nonatomic, copy) NSString *conditionalParentLabel;
/*! @brief For conditional fields, this is the value of the parent tab that controls the tab's visibility.\n\nIf the parent tab is a Checkbox, Radio button, Optional Signature, or Optional Initial use \"on\" as the value to show that the parent tab is active. [optional]. */
@property (nonatomic, copy) NSString *conditionalParentValue;
/*! @brief Indicates the envelope status. Valid values are:\n\n* sent - The envelope is sent to the recipients. \n* created - The envelope is saved as a draft and can be modified and sent later. [optional]. */
@property (nonatomic, copy) NSString *status;

/*!
 * @brief The DSMTabFrame class object.
 * @see DSMTabFrame.h
 */
@property (nonatomic, retain) DSMTabFrame *frame;
/*!
 * @brief The DSMMergeField class object.
 * @see DSMMergeField.h
 */
@property (nonatomic, retain) DSMMergeField* mergeField;
/*!
 * @brief The DSMErrorDetails class object.
 * @see DSMErrorDetails.h
 */
@property (nonatomic, retain) DSMErrorDetails* errorDetails;
//@property (nonatomic, retain) DSMCDTabImageData *imageData;

/*! @brief Specifies the value of the tab. [optional]. */
@property (nonatomic, copy) NSString *value; // TODO: (SDK) added this as it's being used for checkbox, text, etc. Find a better way instead.

/*! @brief TODO:Empty:Method value. */
- (CGRect)frameAsCGRect;
/*! @brief TODO:Empty:Method value. */
- (void)setFrameWithCGRect:(CGRect)frame;

@end
