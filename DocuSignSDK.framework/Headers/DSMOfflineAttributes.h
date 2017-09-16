#import <Foundation/Foundation.h>

/*!
 @class DSMOfflineAttributes
 */
@interface DSMOfflineAttributes : NSObject
/*!
 * @brief A string with GUID of the account. This can be retrieved with the [ML:Get Disclosure] call. [optional]
 */
@property (nonatomic, copy) NSString *accountEsignId;
/*!
 * @brief A string containing information about the model of the device used for offline signing. [optional]
 */
@property (nonatomic, copy) NSString *deviceModel;
/*!
 * @brief A string containing information about the type of device used for offline signing. [optional]
 */
@property (nonatomic, copy) NSString *deviceName;
/*!
 * @brief A string containing the latitude of the device location at the time of signing. [optional]
 */
@property (nonatomic, copy) NSNumber *gpsLatitude;
/*!
 * @brief A string containing the longitude of the device location at the time of signing. [optional]
 */
@property (nonatomic, copy) NSNumber *gpsLongitude;
/*!
 * @brief TODO:Doc
 */
@property (nonatomic, copy) NSString *offlineSigningHash;
/*!
 * @brief TODO:Doc
 */
@property (nonatomic, copy) NSString *consumerDisclosureId;

@end

