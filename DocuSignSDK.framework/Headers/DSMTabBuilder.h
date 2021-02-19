#import <Foundation/Foundation.h>
#import "DSMTabType.h"
#import "DSMEnvelopeTab.h"

/*!
 * @interface DSMTabBuilder
 * @abstract TabBuilder to construct an object of DSMEnvelopeTab which can be used with envelope compose methods on EnvelopesManager.
 * @see DSMEnvelopeBuilder DSMEnvelopesManager
 */
@interface DSMTabBuilder : NSObject

- (instancetype) init NS_UNAVAILABLE;

/*!
 @discussion return an instance of tab builder.
 */
+ (instancetype) builderForType:(DSMTabType)tabType;

/*!
 * @discussion add document id for the tab and return builder
 * @param documentId an unsigned integer representing document id
 */
- (DSMTabBuilder *)addDocumentId:(NSUInteger)documentId;
/*!
 * @discussion add recipient id for the tab and return builder
 * @param recipientId an unsigned integer representing recipient id
 */
- (DSMTabBuilder *)addRecipientId:(NSUInteger)recipientId;
/*!
 * @discussion add frame of the tab (e.g. CGFrameMake(100, 100, 50, 40) for Sign Tab) and return builder.
 * @param frame a frame to draw tab within
 */
- (DSMTabBuilder *)addFrame:(CGRect)frame;
/*!
 * @discussion add page number for the tab and return builder
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
 * @param isLocked a boolean representing if the tab is locked
 */
- (DSMTabBuilder *)isLocked:(BOOL)isLocked;
/*!
 * @discussion add a boolean flag representing optionality on tab and return builder
 * @param isLocked a boolean representing if the tab is optional
 */
- (DSMTabBuilder *)isOptional:(BOOL)isOptional;
/*!
 * @discussion Creates an envelope tab using the DSMTabBuilder
 */
- (DSMEnvelopeTab *)build;

@end

