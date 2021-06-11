#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@import UIKit;

@interface DSMAppearance : NSObject
/*!
* @discussion Set navigation bar tint color.
* @param color color to be set.
* @warning If not set it will use the default settings.
*/
+ (void)setNavigationBarTintColor:(UIColor *)color;
/*!
 * @discussion Set navigation bar title text color.
 * @param color color to be set.
 * @warning If not set it will use the default settings.
 */
+ (void)setNavigationBarTitleTextColor:(UIColor *)color;
/*!
 * @discussion Set navigation bar title text font color.
 * @param font font to be set.
 * @warning If not set it will use the default settings.
 */
+ (void)setNavigationBarTitleTextFont:(UIFont *)font;
/*!
 * @discussion Set the navigation bar title text font.
 * @param font font to be set.
 * @param color color to be set.
 * @warning If not set it will use the default settings.
 */
+ (void)setNavigationBarTitleTextFont:(UIFont *)font color:(UIColor *)color;
/*!
 * @discussion Set bar button items tint color.
 * @param color color to be set.
 * @warning If not set it will use the default settings.
 */
+ (void)setBarButtonItemsTintColor:(UIColor *)color;
/*!
 * @discussion Set bar button items tint color.
 * @param color color to be set.
 * @param [in] rightBarButtonsTintColor (Optional) tint color for the right bar button items.
 * @warning If not set it will use the default settings.
 */
+ (void)setBarButtonItemsTintColor:(UIColor *)color rightBarButtonsTintColor:(UIColor * _Nullable)rightBarButtonsTintColor;
/*!
 * @discussion Set search bar tint color.
 * @param color color to be set.
 * @warning If not set it will use the default settings.
 */
+ (void)setSearchBarTintColor:(UIColor *)color;

@end

NS_ASSUME_NONNULL_END
