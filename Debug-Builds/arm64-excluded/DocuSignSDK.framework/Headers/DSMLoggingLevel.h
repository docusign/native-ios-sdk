#ifndef DSMLoggingLevel_h
#define DSMLoggingLevel_h

typedef NS_ENUM (NSUInteger, DSMLoggingMask)
{
    DSMLoggingMaskError = 1 << 0,
    DSMLoggingMaskWarn = 1 << 1,
    DSMLoggingMaskDebug = 1 << 3,
};

/*!
 * @typedef DSMLoggingLevel
 * @brief Logging configuaration to fine-tune console output.
 * @constant DSMLoggingLevelOff No logs are generated.
 * @constant DSMLoggingLevelError Errors are logged.
 * @constant DSMLoggingLevelWarn Warning and Errors are logged.
 * @constant DSMLoggingLevelDebug Verbose logs.
 */
typedef NS_ENUM (NSUInteger, DSMLoggingLevel)
{
    DSMLoggingLevelOff = 0,
    DSMLoggingLevelError = (DSMLoggingMaskError),
    DSMLoggingLevelWarn = (DSMLoggingLevelError | DSMLoggingMaskWarn),
    DSMLoggingLevelDebug = NSUIntegerMax
};

#endif
