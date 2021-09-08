#ifndef DSMUserFilterType_h
#define DSMUserFilterType_h

/*!
 * @abstract A filter to narrow down search by ownership.
 * @constant DSMUserFilterTypeAll Templates/Folders all templates and folders eligible for the account.
 * @constant DSMUserFilterTypeOwnedByMe Templates/Folders created only by you
 * @constant DSMUserFilterTypeSharedWithMe Templates/Folders shared with you
 */
typedef NS_ENUM(NSUInteger, DSMUserFilterType) {
    DSMUserFilterTypeAll = 0,
    DSMUserFilterTypeOwnedByMe,
    DSMUserFilterTypeSharedWithMe,
};
#endif /* DSMUserFilterType_h */
