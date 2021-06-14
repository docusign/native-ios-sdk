NS_ASSUME_NONNULL_BEGIN

/*! @protocol DSMTextTabProtocol
 *  @brief Conforming to this protocol indicates instances can represent a text based annotation, such as DSMFullNameTab.
 *  @see DSMFullName.h
 *  @see DSMText.h
 *  @see DSMDateSigned.h
 */
@protocol DSMTextTabProtocol
/*!
 * @brief When set to **true**, the signer is required to fill out this tab [optional]
 */
@property(nonatomic, assign) BOOL required;
/*! @brief When set to **true**, the signer cannot change the data of the custom tab. [optional]. */
@property (nonatomic, assign) BOOL locked;

@end

NS_ASSUME_NONNULL_END
