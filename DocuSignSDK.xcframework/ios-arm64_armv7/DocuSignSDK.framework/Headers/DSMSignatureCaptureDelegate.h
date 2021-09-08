#import <Foundation/Foundation.h>
#import <DocuSignSDK/DSMSignatureCaptureMethod.h>

NS_ASSUME_NONNULL_BEGIN

/// DSMSignatureCaptureDelegate
/// Delegate to handle communication from Signature container view controllers to client apps.
/// @see DSMSignatureAdoptionDelegate
@protocol DSMSignatureCaptureDelegate <NSObject>

@required

/// signatureCapture:didFinishWithSignature
/// @viewController
/// @signature
- (void)signatureCapture:(UIViewController*)viewController didFinishWithSignature:(UIImage *)signature method:(DSMSignatureCaptureMethod)method;

/// signatureCapture:didFinishWithSignature
/// @viewController
/// @initials
- (void)signatureCapture:(UIViewController*)viewController didFinishWithInitials:(UIImage *)initials method:(DSMSignatureCaptureMethod)method;

/// signatureCaptureCanceled:error
/// @viewController
- (void)signatureCaptureCanceled:(UIViewController*)viewController method:(DSMSignatureCaptureMethod)method error:(nullable NSError *)error;

/// currentInterfaceOrientation
- (UIInterfaceOrientation)currentInterfaceOrientation;

/// getSignatureName - get the signature name for the signature capture via UseFont. SignatureName is used to generate the initials during capture process.
- (NSString *)getSignatureName;

/// shouldAutoDeleteAdoptedSignature - if adopted signature needs to be auto-deleted upon exit. Used when adopting signature for IPS.
- (BOOL)shouldAutoDeleteAdoptedSignature;

@optional

/// signatureCapture:didFinishWithSignature:andInitials
/// @viewController
/// @signature
/// @initials
- (void)signatureCapture:(UIViewController*)viewController didFinishWithSignature:(UIImage *)signature andInitials:(UIImage *)initials method:(DSMSignatureCaptureMethod)method;

/// signatureCaptureBackTapped
/// @viewController
- (void)signatureCaptureBackTapped:(UIViewController*)viewController method:(DSMSignatureCaptureMethod)method;

/// signatureCaptureCanceled:error
/// @viewController
- (void)signatureCaptureCreateAndClose:(UIViewController*)viewController;
@end

NS_ASSUME_NONNULL_END
