#ifndef DSMDocumentInsertAtPosition_h
#define DSMDocumentInsertAtPosition_h

/*!
 * @typedef DSMDocumentInsertAtPosition
 * @brief A list of insert positions for a PDF.
 * @constant DSMDocumentInsertAtPositionBeginning insert given pdf at the beginning, default value.
 * @constant DSMDocumentInsertAtPositionEnd  insert given document at the end.
 * @see DSMTemplatesManager.h
 */
typedef NS_ENUM(NSUInteger, DSMDocumentInsertAtPosition) {
    DSMDocumentInsertAtPositionBeginning = 0,
    DSMDocumentInsertAtPositionEnd
} ;

#endif
