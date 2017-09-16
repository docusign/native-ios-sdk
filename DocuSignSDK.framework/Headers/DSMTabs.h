#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class DSMDateSigned;
@class DSMSignHere;
@class DSMInitialHere;
@class DSMTitle;
@class DSMCheckbox;
@class DSMFullName;
@class DSMText;
@class DSMCompany;

/*!
 @class DSMTabs
 @abstract It aggregates all tabs defined for a recipient as individual array objects.
 @see DSMSigner.h
 @see DSMInPersonSigner.h
 */
@interface DSMTabs : NSObject

/*! @brief An array containing SignHere tabs. [optional]
 * @see DSMSignHere.h
 */
@property(nonatomic, copy) NSArray<DSMSignHere *> *signHereTabs;
/*! @brief An array containing InitialHere tabs. [optional]
 * @see DSMInitialHere.h
 */
@property(nonatomic, copy) NSArray<DSMInitialHere *> *initialHereTabs;
/*! @brief An array containing FullName tabs. [optional]
 * @see DSMFullName.h
 */
@property(nonatomic, copy) NSArray<DSMFullName *> *fullNameTabs;
/*! @brief An array containing DateSigned tabs. [optional]
 * @see DSMDateSigned.h
 */
@property(nonatomic, copy) NSArray<DSMDateSigned *> *dateSignedTabs;
/*! @brief An array containing Company tabs. [optional]
 * @see DSMCompany.h
 */
@property(nonatomic, copy) NSArray<DSMCompany *> *companyTabs;
/*! @brief An array containing Title tabs. [optional]
 * @see DSMTitle.h
 */
@property(nonatomic, copy) NSArray<DSMTitle *> *titleTabs;
/*! @brief An array containing Text tabs. [optional]
 * @see DSMText.h
 */
@property(nonatomic, copy) NSArray<DSMText *> *textTabs;
/*! @brief An array containing Checkbox tabs. [optional]
 * @see DSMCheckbox.h
 */
@property(nonatomic, copy) NSArray<DSMCheckbox *> *checkboxTabs;

/*!
 @method allTabs
 @abstract Return a set containing all tabs.
 @discussion This combines all tabs included in tab arrays (e.g. signHereTabs, textTabs, etc) in the exposed properties.
 @result  Returns the set generated with individual tabs from each of the array.
 */
- (NSSet *)allTabs;

@end
