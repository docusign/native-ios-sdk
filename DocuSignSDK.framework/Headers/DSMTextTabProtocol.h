/*! @protocol DSMTextTabProtocol
 *  @discussion Conforming to this protocol indicates instances can represent a text based annotation, such as DSMFullNameTab.
 *  @see DSMFullName.h
 *  @see DSMText.h
 *  @see DSMDateSigned.h
 */
@protocol DSMTextTabProtocol
/*!
 * @brief When set to **true**, the signer is required to fill out this tab [optional]
 */
@property(nonatomic, assign) BOOL required;

@end
