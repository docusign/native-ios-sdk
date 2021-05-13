#import <DocuSignSDK/DocuSignSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface DSMEnvelopesManager (DSMInternalAdditions)

/*!
 * @discussion Creates an envelope programmatically using json data that represents envelope definition. Note: **For internal DocuSign use only and can be removed in future versions**
 * @param envelopeName name of the envelope.
 * @param additionalParams any additional params that could be used with this flow (internal use only).
 * @param signingMode compose envelope in either online or offline mode, see DSMSigningMode
 * @param completion completion block to be executed after envelope is successfully created.
 * @warning passing nil to a presentationController will not be able to load the offline envelope flow.
 * @see DSMEnvelopeBuilder
 */
- (void)composeEnvelopeWithJSON:(NSString *)jsonData
                   envelopeName:(NSString *)envelopeName
               additionalParams:(NSString *)additionalParams
                    signingMode:(DSMSigningMode)signingMode
                     completion:(nullable void(^)(NSString *_Nullable envelopeId, NSError *error))completion;

@end

NS_ASSUME_NONNULL_END
