#ifndef DSMTemplateCacheState_h
#define DSMTemplateCacheState_h

/*!
 * @typedef DSMTemplateCacheState
 * @brief A list of template cache states.
 * @constant DSMTemplateCacheStateUncached Template is unchached.
 * @constant DSMTemplateCacheStateInProgress Template cache is in progress.
 * @constant DSMTemplateCacheStateUpdateInProgress Template cache is being updated.
 * @constant DSMTemplateCacheStateCached Template is cached.
 */
typedef NS_ENUM(NSUInteger, DSMTemplateCacheState) {
    DSMTemplateCacheStateUncached = 0,
    DSMTemplateCacheStateInProgress,
    DSMTemplateCacheStateUpdateInProgress,
    DSMTemplateCacheStateCached,
};

#endif
