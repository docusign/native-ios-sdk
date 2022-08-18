#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSMTabType.h>
#import <DocuSignSDK/DSMEnvelopeTab.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 * @interface DSMTabBuilder
 * @abstract TabBuilder to construct an object of DSMEnvelopeTab which can be used with envelope compose methods on EnvelopesManager. For each tab, a unique guid is assigned to `tabId` when built.
 * @see DSMEnvelopeBuilder DSMEnvelopesManager
 */
@interface DSMTabBuilder : NSObject

- (instancetype) init NS_UNAVAILABLE;

/*!
 @discussion return an instance of tab builder.
 */
+ (instancetype) builderForType:(DSMTabType)tabType;

/*!
 * @discussion add document id for the tab and return builder. The document id should be same as one of the documents added to the envelope.
 * @param documentId a unique string representing document id.
 */
- (DSMTabBuilder *)addDocumentId:(NSString *)documentId;
/*!
 * @discussion add recipient id for the tab and return builder. The recipient id should be same as one of the recipients added to the envelope.
 * @param recipientId a unique string representing recipient id
 */
- (DSMTabBuilder *)addRecipientId:(NSString *)recipientId;
/*!
 * @discussion add frame of the tab (e.g. CGFrameMake(100, 100, 50, 40) for Sign Tab) and return builder.
 * @param frame a frame to draw tab within
 */
- (DSMTabBuilder *)addFrame:(CGRect)frame;
/*!
 * @discussion add page number for the tab and return builder. 
 * @param pageNumber an integer representing tab's page number
 */
- (DSMTabBuilder *)addPageNumber:(int)pageNumber;
/*!
 * @discussion add a tab label and return builder
 * @param tabLabel a string representing tab's label
 */
- (DSMTabBuilder *)addTabLabel:(NSString *)tabLabel;
/*!
 * @discussion add a tab name and return builder
 * @param name a string representing tab's name
 */
- (DSMTabBuilder *)addName:(NSString *)name;
/*!
 * @discussion add a tab value and return builder
 * @param value a string representing tab's value
 */
- (DSMTabBuilder *)addValue:(NSString *)value;
/*!
 * @discussion add a tab group name and return builder
 * @param groupName a string representing tab's groupName
 */
- (DSMTabBuilder *)addGroupName:(NSString *)groupName;
/*!
 * @discussion add a tab scale value and return builder
 * @param scaleValue a string representing tab's scale
 */
- (DSMTabBuilder *)addScaleValue:(CGFloat)scaleValue;
/*!
 * @discussion add a boolean flag representing lock on tab and return builder
 * @param locked a boolean representing if the tab is locked
 */
- (DSMTabBuilder *)isLocked:(BOOL)locked;
/*!
 * @discussion add a boolean flag representing optionality on the tab and return the builder
 * @param isOptional a boolean representing if the tab is optional
 */
- (DSMTabBuilder *)isOptional:(BOOL)isOptional;
/*!
 * @discussion add a boolean flag representing selection on the radio or checkbox tab and return the builder.
 * @param selected a boolean representing if the radio or checkbox tab is selected
 * @note If an existing radio tab is selected in the same radio group, it'll be set as unselected in the process of adding a new radio tab which is selected.
 */
- (DSMTabBuilder *)isSelected:(BOOL)selected;
/*!
 * @discussion Creates an envelope tab using the DSMTabBuilder
 */
- (DSMEnvelopeTab *)build;

@end

NS_ASSUME_NONNULL_END
