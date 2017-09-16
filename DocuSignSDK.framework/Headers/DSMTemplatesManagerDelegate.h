//  DSMTemplatesManagerDelegate.h
//  DocuSignSDK
@protocol DSMTemplatesManagerDelegate <NSObject>

@required
/*!
 * @brief Cache template delegate callback when failed to cache template.
 * @option templateId TemplateId which was tried to cache
 * @option error Error reason for cache failure
 * @see DSMTemplatesManager.h
 */
- (void)templatesManager:(DSMTemplatesManager *)templatesManager failedToCacheTemplateWithId:(NSString *)templateId error:(NSError *)error;
/*!
 * @brief Cache template delegate callback when template cache complete.
 * @option templateId TemplateId which is cached.
 * @see DSMTemplatesManager.h
 */
- (void)templatesManager:(DSMTemplatesManager *)templatesManager cachedTemplateWithId:(NSString *)templateId;
/*!
 * @brief Cache template delegate callback when template cache process starts (cache in progress).
 * @option templateId TemplateId of the template to be cached.
 * @see DSMTemplatesManager.h
 */
- (void)templatesManager:(DSMTemplatesManager *)templatesManager cacheInProgressTemplateWithId:(NSString *)templateId;
/*!
 * @brief Cache template delegate callback when template allready exists in Cache but needs to be updated with recent data is in progress.
 * @option templateId TemplateId which is to be cached/updated.
 * @see DSMTemplatesManager.h
 */
- (void)templatesManager:(DSMTemplatesManager *)templatesManager cacheUpdateInProgressTemplateWithId:(NSString *)templateId;
/*!
 * @brief Cache template delegate callback when template is removed from cache.
 * @option templateId TemplateId which is removed from cache.
 * @see DSMTemplatesManager.h
 */
- (void)templatesManager:(DSMTemplatesManager *)templatesManager uncachedTemplateWithId:(NSString *)templateId;


@optional


@end
