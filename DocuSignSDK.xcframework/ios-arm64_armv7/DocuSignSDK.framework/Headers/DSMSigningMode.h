#ifndef DSMSigningMode_h
#define DSMSigningMode_h

#import <Foundation/Foundation.h>

extern NSString * const DSMSigningModeOnlineValue;
extern NSString * const DSMSigningModeOfflineValue;

/*!
 * @typedef DSMSigningMode
 * @brief Supported signing modes for envelopes & templates.
 * @constant DSMSigningModeOnline, default value, corresponds to DSMSigningModeOnlineValue ("online") value.
 * @constant DSMSigningModeOffline, corresponds to DSMSigningModeOfflineValue ("offline") value.
 */
typedef NS_ENUM(NSUInteger, DSMSigningMode) {
    DSMSigningModeOnline,
    DSMSigningModeOffline
};

#endif /* DSMSigningMode_h */

