#import <DocuSignSDK/DocuSignSDK.h>

/*!
 @class DSMFormula
 @abstract Various options to influence the template name matching.
 */
@interface DSMFormula : DSMTab

/* When set to **true**, sets this as a payment tab. Can only be used with Text, Number, Formula, or List tabs. The value of the tab must be a number. [optional]
 */
@property(nonatomic,assign) BOOL isPaymentAmount;
/* The Formula string contains the TabLabel for the reference tabs used in the formula and calculation operators. Each TabLabel must be contained in brackets. \nMaximum Length: 2000 characters.\n\n*Example*: Three tabs (TabLabels: Line1, Line2, and Tax) need to be added together. The formula string would be: \n\n[Line1]+[Line2]+[Tax] [optional]
 */
@property(nonatomic,strong) NSString* formula;
/* A regular expressionn used to validate input for the tab. [optional]
 */
@property(nonatomic,strong) NSString* validationPattern;
/* The message displayed if the custom tab fails input validation (either custom of embedded). [optional]
 */
@property(nonatomic,strong) NSString* validationMessage;
/* When set to **true**, this custom tab is shared. [optional]
 */
@property(nonatomic,assign) BOOL shared;
/* Optional element for field markup. When set to **true**, the signer is required to initial when they modify a shared field. [optional]
 */
@property(nonatomic,assign) BOOL requireInitialOnSharedChange;
/* When set to **true**, the sender must populate the tab before an envelope can be sent using the template. \n\nThis value tab can only be changed by modifying (PUT) the template. \n\nTabs with a `senderRequired` value of true cannot be deleted from an envelope. [optional]
 */
@property(nonatomic,assign) BOOL senderRequired;
/* When set to **true** and shared is true, information must be entered in this field to complete the envelope. [optional]
 */
@property(nonatomic,assign) BOOL requireAll;

/* The initial value of the tab when it was sent to the recipient. [optional]
 */
@property(nonatomic,strong) NSString* originalValue;
/* Width of the tab in pixels. [optional]
 */
@property(nonatomic,strong) NSNumber* width;
/* When set to **true**, the signer is required to fill out this tab [optional]
 */
@property(nonatomic,assign) BOOL required;
/* When set to **true**, the signer cannot change the data of the custom tab. [optional]
 */
@property(nonatomic,assign) BOOL locked;
/* When set to **true**, the field appears normally while the recipient is adding or modifying the information in the field, but the data is not visible (the characters are hidden by asterisks) to any other signer or the sender.\n\nWhen an envelope is completed the information is available to the sender through the Form Data link in the DocuSign Console.\n\nThis setting applies only to text boxes and does not affect list boxes, radio buttons, or check boxes. [optional]
 */
@property(nonatomic,assign) BOOL concealValueOnDocument;
/* When set to **true**, disables the auto sizing of single line text boxes in the signing screen when the signer enters data. If disabled users will only be able enter as much data as the text box can hold. By default this is false. This property only affects single line text boxes. [optional]
 */
@property(nonatomic,assign) BOOL disableAutoSize;
/* An optional value that describes the maximum length of the property when the property is a string. [optional]
 */
@property(nonatomic,strong) NSNumber* maxLength;

/* The font to be used for the tab value. Supported Fonts: Arial, Arial, ArialNarrow, Calibri, CourierNew, Garamond, Georgia, Helvetica,   LucidaConsole, Tahoma, TimesNewRoman, Trebuchet, Verdana, MSGothic, MSMincho, Default. [optional]
 */
@property(nonatomic,strong) NSString* font;
/* When set to **true**, the information in the tab is bold. [optional]
 */
@property(nonatomic,assign) BOOL bold;
/* When set to **true**, the information in the tab is italic. [optional]
 */
@property(nonatomic,assign) BOOL italic;
/* When set to **true**, the information in the tab is underlined. [optional]
 */
@property(nonatomic,assign) BOOL underline;
/* The font color used for the information in the tab.\n\nPossible values are: Black, BrightBlue, BrightRed, DarkGreen, DarkRed, Gold, Green, NavyBlue, Purple, or White. [optional]
 */
@property(nonatomic,strong) NSString* fontColor;
/* The font size used for the information in the tab.\n\nPossible values are: Size7, Size8, Size9, Size10, Size11, Size12, Size14, Size16, Size18, Size20, Size22, Size24, Size26, Size28, Size36, Size48, or Size72. [optional]
 */
@property(nonatomic,strong) NSString* fontSize;

/* This indicates the horizontal offset of the object on the page. DocuSign uses 72 DPI when determining position. [optional]
 */
@property(nonatomic,strong) NSString* xPosition;
/* This indicates the vertical offset of the object on the page. DocuSign uses 72 DPI when determining position. [optional]
 */
@property(nonatomic,strong) NSString* yPosition;

/* This indicates the number of decimal places tabs should round to. Currently We support 0 or two. [optional]
 */
@property(nonatomic,strong) NSNumber* roundDecimalPlaces;


@end
