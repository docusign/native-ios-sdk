#ifndef DSMEnvelopeCacheState_h
#define DSMEnvelopeCacheState_h

/*!
 * @typedef DSMEnvelopeCacheState
 * @brief A list of envelope cache states.
 * @constant DSMEnvelopeCacheStateUncached Envelope is uncached.
 * @constant DSMEnvelopeCacheStateInProgress Envelope cache is in progress.
 * @constant DSMEnvelopeCacheStateCached Envelope is cached.
 */
typedef NS_ENUM(NSUInteger, DSMEnvelopeCacheState) {
    DSMEnvelopeCacheStateUncached = 0,
    DSMEnvelopeCacheStateInProgress,
    DSMEnvelopeCacheStateCached,
};

#endif
