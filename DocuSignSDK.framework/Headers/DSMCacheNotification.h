@interface DSMCacheNotification : NSObject
/*!  @brief templateId TODO:Doc
 */
@property (nonatomic, readonly, strong) NSString *templateId;
/*!  @brief error TODO:Doc
 */
@property (nonatomic, readonly, strong) NSError *error;
//TODO do we need a success attribute here

/*!
 * @discussion Initilize the notification object
 * @param templateId ID of a template.
 * @return instancetype
 */
- (instancetype)initWithTemplateId:templateId error:(NSError *)error;

@end
