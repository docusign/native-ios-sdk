#import <Foundation/Foundation.h>
#import "DSMSignatureCaptureDelegate.h"
#import "DSMSignatureCaptureType.h"

NS_ASSUME_NONNULL_BEGIN

/*! @brief Signature capture configurations aggregator.
 */
@interface DSMSignatureCaptureConfiguration : NSObject

/*! boolean value to determine if taking photo is the only capture method.
 */
@property (nonatomic, assign) BOOL shouldTakePhotoOnly;
// TODO: convert the booleans into NS_OPTIONS (Post Phase 1 release)
/*! boolean value to determine if using fonts to capture signature is not a capture method (e.g. Offline signing). Default value is `false`.
*/
@property (nonatomic, assign) BOOL shouldHideUseFonts;
/*! boolean value to determine if next button is shown instead of create to transition to next signature capture.
*/
@property (nonatomic, assign) BOOL shouldShowNextButton;
/*! signature associated with the tabType.
 */
@property (nonatomic, assign) DSMSignatureCaptureType captureType;
/*! delegate to use when responding to signature capture.
*/
@property (nonatomic, weak) id<DSMSignatureCaptureDelegate> delegate;
/*! id of the signature that is already adopted and user is adopting it again.
*/
@property (nonatomic, copy, nullable) NSString *signatureId;

@end

NS_ASSUME_NONNULL_END
