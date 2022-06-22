#ifndef DSMAuthenticationMethod_h
#define DSMAuthenticationMethod_h

NS_ASSUME_NONNULL_BEGIN

/*!
 * @typedef DSMAuthenticationMethod
 * @brief Authentication method used with the login.
 * @constant DSMAuthenticationMethodUndefined No authentication method defined.
 * @constant DSMAuthenticationMethodApiPassword Legacy OAuth login.
 * @constant DSMAuthenticationMethodAccessToken OAuth 2 login.
 * Further Reading: https://developers.docusign.com/esign-rest-api/guides/authentication
 */
typedef NS_ENUM(NSUInteger, DSMAuthenticationMethod) {
    DSMAuthenticationMethodUndefined = 0,
    DSMAuthenticationMethodApiPassword,
    DSMAuthenticationMethodAccessToken
};

#endif

NS_ASSUME_NONNULL_END
