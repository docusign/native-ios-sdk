#ifndef DSMTabType_h
#define DSMTabType_h

/*!
 * @brief A list of tab types for envelopes & templates.
 * @constant DSMTabTypeUnsupported Unsupported, default value.
 * @constant DSMTabTypeSignHere SignHere Tab. @see DSMSignHere.h
 * @constant DSMTabTypeInitialHere InitialHere Tab. @see DSMInitialHere.h
 * @constant DSMTabTypeText Text Tab. @see DSMText.h
 * @constant DSMTabTypeCheckbox Checkbox Tab. @see DSMCheckbox.h
 * @constant DSMTabTypeCompany Company Tab. @see DSMCompany.h
 * @constant DSMTabTypeTitle Title Tab. @see DSMTitle.h
 * @constant DSMTabTypeFullName FullName Tab. @see DSMFullName.h
 * @constant DSMTabTypeDateSigned DateSigned Tab. @see DSMDateSigned.h
 * @constant DSMTabTypeFormula Formula Tab. @see DSMFormula.h
 * @constant DSMTabTypeRadio Radio Tab. @see DSMRadio.h
 */
typedef NS_ENUM(NSUInteger, DSMTabType) {
    DSMTabTypeUnsupported = 0,
    DSMTabTypeSignHere,
    DSMTabTypeInitialHere,
    DSMTabTypeText,
    DSMTabTypeCheckbox,
    DSMTabTypeCompany,
    DSMTabTypeTitle,
    DSMTabTypeFullName,
    DSMTabTypeDateSigned,
    DSMTabTypeFormula,
    DSMTabTypeRadio
};

#endif /* DSMTabType_h */
