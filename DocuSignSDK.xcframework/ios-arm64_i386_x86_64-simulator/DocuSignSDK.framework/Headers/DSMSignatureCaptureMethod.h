#ifndef DSMSignatureCaptureMethod_h
#define DSMSignatureCaptureMethod_h

/*!
* @brief Various Signature capture methods (Draw, UseFont & TakePhoto) that can be used to adopt Signatures for SignHere and InitialsHere tabs..
*/
typedef NS_ENUM(NSUInteger, DSMSignatureCaptureMethod) {
    DSMSignatureCaptureMethodDraw = 0,
    DSMSignatureCaptureMethodUseFont = 1,
    DSMSignatureCaptureMethodTakePhoto = 2
};

#endif /* DSMSignatureCaptureMethod_h */
