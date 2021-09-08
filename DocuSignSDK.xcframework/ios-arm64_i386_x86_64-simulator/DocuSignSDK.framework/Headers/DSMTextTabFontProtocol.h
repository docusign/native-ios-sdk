NS_ASSUME_NONNULL_BEGIN

/*! @protocol DSMTextTabFontProtocol
 *  @brief Conforming to this protocol indicates instances do have rendered font specific properties.
 *  @see DSMFullName.h
 *  @see DSMText.h
 *  @see DSMTitle.h
 *  @see DSMDateSigned.h
 */
@protocol DSMTextTabFontProtocol

/*! @brief The font to be used for the tab value. Supported Fonts: Arial, Arial, ArialNarrow, Calibri, CourierNew, Garamond, Georgia, Helvetica,   LucidaConsole, Tahoma, TimesNewRoman, Trebuchet, Verdana, MSGothic, MSMincho, Default. [optional]. */
@property(nonatomic, copy) NSString *font;
/*! @brief When set to **true**, the information in the tab is bold. [optional]. */
@property(nonatomic, assign) BOOL bold;
/*! @brief When set to **true**, the information in the tab is italic. [optional] */
@property(nonatomic, assign) BOOL italic;
/*! @brief When set to **true**, the information in the tab is underlined. [optional]. */
@property(nonatomic, assign) BOOL underline;
/*! @brief The font color used for the information in the tab.\n\nPossible values are: Black, BrightBlue, BrightRed, DarkGreen, DarkRed, Gold, Green, NavyBlue, Purple, or White. [optional]. */
@property(nonatomic, copy) NSString *fontColor;
/*! @brief The font size used for the information in the tab.\n\nPossible values are: Size7, Size8, Size9, Size10, Size11, Size12, Size14, Size16, Size18, Size20, Size22, Size24, Size26, Size28, Size36, Size48, or Size72. [optional]. */
@property(nonatomic, copy) NSString *fontSize;

@end

NS_ASSUME_NONNULL_END
