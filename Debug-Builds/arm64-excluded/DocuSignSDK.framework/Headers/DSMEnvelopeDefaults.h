#import <Foundation/Foundation.h>
#import "DSMEnvelopeDefaults.h"
#import "DSMRecipientDefault.h"
#import "DSMCustomFields.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class DSMEnvelopeDefaults
 @abstract Parent class that contains the various defaults values to apply to override template data before starting signing ceremony.
 @see DSMRecipientDefault.h
 */
@interface DSMEnvelopeDefaults : NSObject

/*!
 @brief Array of defaults data to assign to recipients in a template. Note: when recipient defaults are used, array must contain recipient defaults for all of the recipients that are part of the template.
 @see DSMRecipientDefault
 */
@property (nonatomic, strong, nullable) NSArray<DSMRecipientDefault *> *recipientDefaults;
/*!
 @brief Email subject to use when generating an envelope with a given template
 */
@property (nonatomic, strong, nullable) NSString *emailSubject;
/*!
 @brief Email body to use when generating an envelope with a given template
 */
@property (nonatomic, strong, nullable) NSString *emailBlurb;
/*!
 @brief Envelope title to use during signing ceremony
 */
@property (nonatomic, strong, nullable) NSString *envelopeTitle;
/*!
 @brief Dictionary containing the tab defaults data to apply for recipient tabs. Each key contains tabLabel (@see DSMTab.h) to uniquely identify a tab in a given template. Value for each of the key is the custom-string that is assigned as value to the tab object identified by tabLabel. Note: Only text based tabs are supported for tab defaults.
 @see DSMText
 */
@property (nonatomic, strong, nullable) NSDictionary<NSString *, NSString *> *tabValueDefaults;
/*!
 @brief Custom fields can override the default custom fields in the template or can be added as new fields.
 @see DSMCustomFields
 */
@property (nonatomic, strong, nullable) DSMCustomFields *customFields;

@end

NS_ASSUME_NONNULL_END
