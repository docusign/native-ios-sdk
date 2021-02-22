#import <Foundation/Foundation.h>
#import "DSMRecipientType.h"
#import "DSMEnvelopeRecipient.h"
#import "DSMEnvelopeTab.h"

/*!
 * @interface DSMRecipientBuilder
 * @abstract RecipientBuilder to construct an object of DSMEnvelopeRecipient which can be used with DSMEnvelopeBuilder.
 * @see DSMEnvelopeBuilder DSMEnvelopeRecipient DSMEnvelopesManager DSMEnvelopeTab
 */
@interface DSMRecipientBuilder : NSObject

- (instancetype)init NS_UNAVAILABLE;

/*!
 * @discussion return an instance of recipient builder for a given type.
 * @param recipientType type of recipient
 */
+ (instancetype)builderForType:(DSMRecipientType)recipientType;

/*!
 * @discussion add recipient id and return builder object.
 * @param recipientId a string representing recipient id
 */
- (DSMRecipientBuilder *)addRecipientId:(NSUInteger)recipientId;
/*!
 * @discussion add signer name and return builder object.
 * @param signerName a string representing signer name
 */
- (DSMRecipientBuilder *)addSignerName:(NSString *)signerName;
/*!
 * @discussion add signer email and return builder object.
 * @param signerEmail a string representing signer email
 */
- (DSMRecipientBuilder *)addSignerEmail:(NSString *)signerEmail;
/*!
 * @discussion add host name and return builder object.
 * @param hostName a string representing host name
 */
- (DSMRecipientBuilder *)addHostName:(NSString *)hostName;
/*!
 * @discussion add host email and return builder object.
 * @param hostEmail a string representing host email
 */
- (DSMRecipientBuilder *)addHostEmail:(NSString *)hostEmail;
/*!
 * @discussion add recipient signing (or routing) order return builder object.
 * @param order an int representing routing order
 */
- (DSMRecipientBuilder *)addRoutingOrder:(int)order;
/*!
 * @discussion add an envelope tab for the recipient and return builder object.
 * @param tab an object of envelope tab
 */
- (DSMRecipientBuilder *)addTab:(DSMEnvelopeTab *)tab;
/*!
 * @discussion add an array of envelope tabs for the recipient and return builder object.
 * @param tabs an array of envelope tabs
 */
- (DSMRecipientBuilder *)addTabs:(NSArray<DSMEnvelopeTab *>*)tabs;
/*!
 * @discussion return the envelope recipient object
 */
- (DSMEnvelopeRecipient *)build;

@end


