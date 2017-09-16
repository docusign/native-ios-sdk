//  DSMEnvelopesManager.h
//  DocuSignSDK
#import <Foundation/Foundation.h>

/*!
 @class DSMEnvelopesManager
 @abstract It aggregates all envelope cache & sync functionality used with offline signing envelopes generated via templates.
 @see DSMTemplatesManager.h
 */
@interface DSMEnvelopesManager : NSObject

/*!
 * @discussion Sync envelope with given envelopeId.
 * @use When device is online and there has been sign and send Offline and pending sync to server.
 */
- (void)syncEnvelopeWithId:(NSString *)envelopeId;

/*!
 * @discussion Sync envelopes signed/sent offline.
 * @use When device is online and there has been sign and send Offline and pending sync to server.
 */
- (void)syncEnvelopes;

/*!
 * @discussion Remove a cached envelope.
 * @param envelopeId An Id of the envelope to be removed.
 */
- (void)removeCachedEnvelopeWithId:(NSString *)envelopeId;

/*!
 * @discussion Retrive all cached envelopes.
 * @return NSArray <DSMEnvelopeDefinition *>
 * @see DSMEnvelopeDefinition.h
 */
- (NSArray *)cachedEnvelopes;

/*!
 * @discussion Retrive all envelopeIds for cached envelopes.
 * @return NSArray <NSString *>
 */
- (NSArray <NSString *> *)cachedEnvelopeIds;

/*!
 * @discussion Remove all cached envelopes.
 */
- (void)removeCachedEnvelopes;

@end
