#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSMSignatureCaptureConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

@class DSMAdoptedSignature;

@interface DSMSignatureService: NSObject

/*!
 * @discussion Show signature adoption controller that allows user to capture signature by drawing, using fonts or taking photo. It presents the required modal which can be dismissed if desired with the view-controller returned with completion block.
 * @param captureType signature associated with the tabType.
 * @param presentingController controller will be presented on top of the given presentingController passed.
 * @param delegate delegate to use when responding to signature capture.
 * @param signatureId id of the signature that is already adopted and user is adopting it again.
 * @param shouldTakePhotoOnly boolean value to determine if taking photo is the only capture method.
 * @param shouldShowNextButton boolean value to determine if next button is shown instead of create to transition to next signature capture.
 * @param animated boolean value to determine if the SignatureCapture is presented with animation.
 * @param completion Completion block to be executed after signature capture is presented.
 * @warning passing nil to a presentationController will not be able to load the Signature Capture.
 * @see DSMSignatureCaptureDelegate.h
 * @see DSMSignatureCaptureType.h
 */
+ (void)presentSignatureCaptureForType:(DSMSignatureCaptureType)captureType
                  presentingController:(UIViewController *)presentingController
                              delegate:(id<DSMSignatureCaptureDelegate>)delegate
                           signatureId:(nullable NSString *)signatureId
                   shouldTakePhotoOnly:(BOOL)shouldTakePhotoOnly
                  shouldShowNextButton:(BOOL)shouldShowNextButton
                              animated:(BOOL)animated
                            completion:(nullable void(^)(UIViewController *_Nullable presentedController))completion;

/*!
 * @discussion Show signature adoption controller that allows user to capture signature by drawing, using fonts or taking photo. It presents the required modal which can be dismissed if desired with the view-controller returned with completion block.
 * @param configuration various configurations to use to capture signatures.
 * @param presentingController controller will be presented on top of the given presentingController passed.
 * @param animated boolean value to determine if the SignatureCapture is presented with animation.
 * @param completion Completion block to be executed after signature capture is presented.
 * @warning passing nil to a presentationController will not be able to load the Signature Capture.
 * @see DSMSignatureCaptureDelegate.h
 * @see DSMSignatureCaptureType.h
 */
+ (void)presentSignatureWithConfiguration:(DSMSignatureCaptureConfiguration *)configuration
                     presentingController:(UIViewController *)presentingController
                                 animated:(BOOL)animated
                               completion:(nullable void(^)(UIViewController *_Nullable presentedController))completion;

/*!
 * @discussion Set image for signature type for a recipient in an envelope.
 * Note: `envelopeId` should match the id of the remote envelope ready to sign on the account under use.
 * @param signatureImage image associated with the tabType.
 * @param recipientId recipientId in the envelope.
 * @param envelopeId envelopeId of the remote envelope ready to sign by recipient.
 * @param type string representing the type of the account image, e.g. "signature_image" or "initials_image"
 * @param completion Completion block to be executed after signature image is set on the account. An optional error parameter to track any failure.
 */
+ (NSNumber *)setSignatureImage:(UIImage *)signatureImage
                  ofRecipientId:(NSString *)recipientId
                  forEnvelopeId:(NSString *)envelopeId
                           type:(NSString *)type
                     completion:(nullable void (^)(NSError *_Nullable error))completion;

/*!
 * @discussion Get signature for a recipient in an envelope.
 * Note: `envelopeId` should match the id of the remote envelope currently being signed on the account under use.
 * @param recipientId recipientId in the envelope.
 * @param envelopeId envelopeId of the remote envelope ready to sign by recipient.
 * @param completion Completion block to be executed after getting recipient signature on the account.
 * Completion has signature parameter that has adopted signature detail in case of successful fetch, otherwise, it has optional error object to track any failure.
 */
+ (NSNumber *)getSignatureForRecipientWithId:(NSString *) recipientId
                               forEnvelopeId:(NSString *)envelopeId
                                  completion:(nullable void (^)(DSMAdoptedSignature *_Nullable signature, NSError *_Nullable error))completion;

/*!
 * @discussion Set signature for a given signatureId associated with a user in an account.
 * @param signatureImage image associated with the capture.
 * @param signatureId Signature Id of the signature associated with User.
 * @param userId currently authenticated userId in the account.
 * @param type string representing the type of the account image, e.g. "signature_image" or "initials_image"
 * @param completion Completion block to be executed after signature image is set on the account. An optional error parameter to track any failure.
 */
+ (NSNumber *)setSignatureImage:(UIImage *)signatureImage
                  ofSignatureId:(NSString *)signatureId
                      forUserId:(NSString *)userId
                           type:(NSString *)type
                     completion:(nullable void (^)(DSMAdoptedSignature *_Nullable signature, NSError *_Nullable error))completion;

/*!
 * @discussion Create signature for a given signatureId associated with a user in an account.
 * @param signatureImage image associated with the signature name.
 * @param initialsImage image associated with the signature initials.
 * @param userId Id of User for which signature and initials images are being set.
 * @param signatureName user name
 * @param signatureInitials user initials
 * @param completion Completion block to be executed after signature image is set on the account. An optional error parameter to track any failure.
 * Note: API reference https://developers.docusign.com/esign-rest-api/reference/Users/UserSignatures/create#userSignaturesInformation
 */
+ (NSNumber *)createSignatureImage:(nullable UIImage *)signatureImage
                     initialsImage:(nullable UIImage *)initialsImage
                         forUserId:(NSString *)userId
                     signatureName:(NSString *)signatureName
                 signatureInitials:(NSString *)signatureInitials
                        completion:(nullable void (^)(DSMAdoptedSignature *_Nullable signature, NSError *_Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
