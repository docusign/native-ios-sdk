#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@import UIKit;

@interface DSMAppearance : NSObject
/*!
 * @discussion Set navigation bar title text color with default background tint color and font size.
 * @param textColor text color to be set.
 * @warning If not set it will use the default settings.
 */
+ (void)setNavigationBarTitleTextColor:(UIColor *)textColor;

/*!
 * @discussion Set navigation bar title text color with background tint color.
 * @param textColor text color to be set.
 * @param backgroundTintColor background color to be set.
 * @param fontSize title font size to be set, default value is `18.0`.
 * @warning If not set it will use the default settings.
 */
+ (void)setNavigationBarTitleTextColor:(UIColor *)textColor backgroundTintColor:(UIColor *)backgroundTintColor fontSize:(CGFloat)fontSize;
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

NS_ASSUME_NONNULL_END
