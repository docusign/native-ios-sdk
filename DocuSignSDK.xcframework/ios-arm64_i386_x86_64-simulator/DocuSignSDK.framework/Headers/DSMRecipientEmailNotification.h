#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class DSMRecipientEmailNotification
 */
@interface DSMRecipientEmailNotification : NSObject

/*!
 * @brief Specifies the subject of the email that is sent to all recipients.\n\nSee [ML:Template Email Subject Merge Fields] for information about adding merge field information to the email subject. [optional]
 */
@property (nonatomic, copy) NSString *emailSubject;
/*!
 * @brief Specifies the email body of the message sent to the recipient. \n\nMaximum length: 10000 characters. [optional]
 */
@property (nonatomic, copy) NSString *emailBody;
/*!
 * @brief A simple type enumeration of the language used. The supported languages, with the language value shown in parenthesis, are: Arabic (ar), Bahasa Indonesia (id), Bahasa Melayu (ms) Bulgarian (bg), Czech (cs), Chinese Simplified (zh_CN), Chinese Traditional (zh_TW), Croatian (hr), Danish (da), Dutch (nl), English US (en), English UK (en_GB), Estonian (et), Farsi (fa), Finnish (fi), French (fr), French Canada (fr_CA), German (de), Greek (el), Hebrew (he), Hindi (hi), Hungarian (hu), Italian (it), Japanese (ja), Korean (ko), Latvian (lv), Lithuanian (lt), Norwegian (no), Polish (pl), Portuguese (pt), Portuguese Brazil (pt_BR), Romanian (ro),Russian (ru), Serbian (sr), Slovak (sk), Slovenian (sl), Spanish (es),Spanish Latin America (es_MX), Swedish (sv), Thai (th), Turkish (tr), Ukrainian (uk), and Vietnamese (vi). [optional]
 */
@property (nonatomic, copy) NSString *supportedLanguage;

@end

NS_ASSUME_NONNULL_END
