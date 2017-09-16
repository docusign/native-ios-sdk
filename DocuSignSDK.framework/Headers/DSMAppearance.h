#import <Foundation/Foundation.h>

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
 * @discussion Set search bar tint color.
 * @param color color to be set.
 * @warning If not set it will use the default settings.
 */
+ (void)setSearchBarTintColor:(UIColor *)color;

@end
