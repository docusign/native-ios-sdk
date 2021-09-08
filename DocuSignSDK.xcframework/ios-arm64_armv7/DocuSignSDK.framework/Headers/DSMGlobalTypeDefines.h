NS_ASSUME_NONNULL_BEGIN

typedef void(^DSMVoidBlock)(void);
typedef void(^DSMAlertActionBlock)(UIAlertAction *);
typedef void(^DSMErrorBlock)(NSError *error);
typedef void(^DSMBOOLBlock)(NSNumber *result, NSError *error);

// Envelope Synchronization
@class DSMCDEnvelopeDefinition;
@class DSMEnvelopeDefinition;

typedef void(^DSMEnvelopeBlock)(DSMCDEnvelopeDefinition * _Nullable envelope, NSError * _Nullable error);

typedef void(^DSMRecipientsRoutingOrderAndTagsBlock)(NSSet *envelopeDSRecipientIDs, NSSet <NSString *> *currentUserFreeFormRecipientIDs, NSNumber *currentRoutingOrder, NSSet *supportedDSTagIDs, NSSet *unsupportedDSTagIDs, NSError * _Nullable error);

// Envelope update
typedef void(^DSMUpdateEnvelopeBlock)(NSError * _Nullable error, DSMEnvelopeDefinition * _Nullable envelope);

NS_ASSUME_NONNULL_END
