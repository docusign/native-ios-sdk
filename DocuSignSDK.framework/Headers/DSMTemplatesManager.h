//  DSMTemplatesManager.h
//  DocuSignSDK
#import <Foundation/Foundation.h>
#import "DSMTemplateCacheState.h"
#import "DSMDocumentInsertAtPosition.h"
#import "DSMSigningMode.h"
#import "DSMTextCustomField.h"
#import "DSMEnvelopeTemplateResults.h"
#import "DSMUserFilterType.h"

NS_ASSUME_NONNULL_BEGIN

@class UIViewController;
@class DSMEnvelopeTemplate;
@class DSMEnvelopeTemplateDefinition;
@class DSMFolder;
@class DSMRecipientDefault;
@class DSMEnvelopeDefaults;

/*!
 @abstract Various options to influence the template name matching.
 */
typedef NS_ENUM(NSUInteger, DSMSearchOptions) {
    DSMSearchOptionContainsMatch,
    DSMSearchOptionExactMatch,
    DSMSearchOptionPrefixMatch,
    DSMSearchOptionSuffixMatch
};

@protocol DSMTemplatesManagerDelegate;

/*!
 @class DSMTemplatesManager
 @abstract It contains methods provide methods that can be used to list, cache and uncache templates. Also, to initiate the signing ceremony with DocuSignSDK provided UI components for online/offline signing mode.
 @see DSMTemplatesManager.h
 */
@interface DSMTemplatesManager : NSObject

/*!
 * @brief The DSMTemplatesManagerDelegate class' delegate object.
 * @see DSMTemplatesManagerDelegate.h
 * @warning This delegate is used to notify cache success or failure for a given template id.
 */
@property (nonatomic, weak) id<DSMTemplatesManagerDelegate> delegate;
/*!
 * @discussion Retrieves the list of templates available to the currently logged in user.
 * @param completionBlock The completion block to be execute once the list of templates is retrieved.
 */
- (void)listTemplatesWithCompletion:(nullable void(^)(NSArray<DSMEnvelopeTemplateDefinition *> *_Nullable envelopeTemplateDefinitions, NSError *_Nullable error))completionBlock;

/*!
 * @discussion Retrieves the list of templates available to the currently logged in user based on searchText.
 * @param searchText searches the templates based on the text provided. If set to nil, fetches templates based on other params.
 * @param completionBlock The completion block to be execute once the list of templates is retrieved.
 * @warning This method requires internet connectivity and not suitable for offline use.
*/
- (void)listTemplatesWithSearchText:(nullable NSString *)searchText
                         Completion:(void(^)(DSMEnvelopeTemplateResults *_Nullable envelopeTemplateResults,
                                             NSError *_Nullable error))completionBlock;
/*!
 * @discussion Retrieves the list of templates available to the currently logged in user based on search parameters
 * @param searchText searches the templates based on the text provided. If set to nil, fetches templates based on other params.
 * @param startPosition the position from which remaining templates are returned. Typically used for pagination.
 * @param count the number of templates to be retrived. if set to nil then search returns all the Templates from startPosition.
 * @param folderIds an Array of folder ids from which templates are fetched. when set to nil, search will be conducted on root folder.
 * @param templateType the source of the Templates to be fetched from. @see DSMTemplatesType.h
 * @param ascendingOrder retrieves templates in ascending order.
 * @param completionBlock The completion block to be execute once the list of templates is retrieved.
 * @warning This method requires internet connectivity and not suitable for offline use.
*/
- (void)listTemplatesWithSearchText:(nullable NSString *)searchText
                      startPosition:(NSNumber *)startPosition
                              count:(nullable NSNumber *)count
                          folderIds:(nullable NSArray <NSString *>*)folderIds
                         filterType:(DSMUserFilterType)templateType
                     ascendingOrder:(BOOL)ascendingOrder
                         Completion:(void(^)(DSMEnvelopeTemplateResults *_Nullable envelopeTemplateResults,
                                             NSError *_Nullable error))completionBlock;
/*!
 * @discussion Retrieves the list of templates available to the currently logged in user matching the given predicate.
 * @param predicate The predicate to match the templates with. A predicate of nil returns all templates.
 * @param completionBlock The completion block to be execute once the list of templates is retrieved.
 */
- (void)listTemplatesWithSearchPredicate:(nullable NSPredicate *)predicate Completion:(nullable void(^)(NSArray<DSMEnvelopeTemplateDefinition *> *_Nullable envelopeTemplateDefinitions, NSError *_Nullable error))completionBlock;
/*!
 * @discussion Retrieves the list of templates available to the currently logged in user within a given folder.
 * @param folderId The ID of the folder from which to retrieve the templates from.
 * @param completionBlock The completion block to be execute once the list of templates is retrieved.
 */
- (void)listTemplatesWithFolderId:(NSString *)folderId completion:(nullable void(^)(NSArray<DSMEnvelopeTemplateDefinition *> *_Nullable envelopeTemplateDefinitions, NSError *_Nullable error))completionBlock;
/*!
 * @discussion Retrieves the list of templates available to the currently logged in user for given template name.
 * @param templateName The name of the template to retrieve.
 * @param options Specifies the type of search conducted on the template name.
 * @param completionBlock The completion block to be execute once the list of templates is retrieved.
 */
- (void)listTemplatesWithTemplateName:(NSString *)templateName searchOptions:(DSMSearchOptions)options completion:(nullable void(^)(NSArray<DSMEnvelopeTemplateDefinition *> *_Nullable envelopeTemplateDefinitions, NSError *_Nullable error))completionBlock;
/*!
 * @discussion Retrieves the list of template folders for the currently logged in user.
 * @param completionBlock The completion block to be execute once the list of template folders is retrieved.
 */
- (void)listTemplateFoldersWithCompletion:(nullable void(^)(NSArray<DSMFolder *> *_Nullable folders, NSError *_Nullable error))completionBlock;
/*!
 * @discussion Retrieve the list of template folders for logged in user based on user filter.
 * @param filterType Narrows down the resulting folder list by ownership.
 * @param completionBlock The completion block to be execute once the list of template folders is retrieved.
 * @see DSMUserFilterType.h
 */
- (void)listTemplateFoldersWithUserFilter:(DSMUserFilterType)filterType
                               completion:(nullable void(^)(NSArray<DSMFolder *> *_Nullable folders, NSError *_Nullable error))completionBlock;
/*!
 * @discussion Returns the cached state of a template. This call can be made when device is offline.
 * @param templateId An ID of the template whose status is enquired.
 * @return DSMTemplateCacheState
 * @see DSMTemplateCacheState.h
 */
- (DSMTemplateCacheState)cacheStateOfTemplateWithId:(NSString *)templateId;
/*!
 * @discussion Gives previously cached template details. This call can be made when device is offline.
 * @param templateId An ID of the template to retrieve.
 * @param includePdfs retrieve/include the pdf's or not.
 * @return DSMEnvelopeTemplate
 */
- (DSMEnvelopeTemplate *)cachedTemplateWithId:(NSString *)templateId includePdfs:(BOOL)includePdfs;
/*!
 * @discussion Cache a template for offline use.
 * @param templateId An ID of the template to be cached.
 * @param completionBlock Can pass in a completion block to be executed on completion of cache.
 */
- (void)cacheTemplateWithId:(NSString *)templateId completion:(nullable void(^)(NSError *_Nullable error))completionBlock;
/*!
 * @discussion Remove a cached template associated with a given templateId. This call can be made when device is offline.
 * @param templateId An ID of the template to be removed.
 */
- (void)removeCachedTemplateWithId:(NSString *)templateId;
/*!
 * @discussion Remove all cached templates. This call can be made when device is offline.
 */
- (void)removeCachedTemplates;
/*!
 * @discussion Retrieve a list of templates which are cached.  This call can be made when device is offline.
 * @return NSArray <DSMEnvelopeTemplate *>
 */
- (NSArray *)cachedTemplates;
/*!
 * @discussion Retrieve a list of templateIds for cached templates. This call can be made when device is offline.
 * @return NSArray <NSString *>
 */
- (NSArray *)cachedTemplateIds;
/*!
 * @discussion Return the total count of the templates cached for offline use. This call can be made when device is offline.
 * @return NSUInteger
 */
- (NSUInteger)cachedTemplateCount;
/*!
 * @discussion Can a template be cached and used for offline signing(some of the templates which are not supported in mobile signing can not be cached).
 * @param envelopeTemplate template to be cached.
 * @param error If error is passed it will be updated with the reason for unavailability for signing/cache in mobile.
 * @return BOOL
 * @warning This will default to NO and unable to cache reason is passed back only when error instance is passed while calling this.
 */
- (BOOL)canCacheEnvelopeTemplate:(DSMEnvelopeTemplate *)envelopeTemplate error:(NSError * _Nullable __autoreleasing * _Nullable)error;
/*!
 * @discussion Start Signing/Sending envelope off of a template with given templateId. It presents the required modal which can be dismissed if desired with the view-controller returned with completion block.
 * Depending on the recipient configuration (e.g. all remote signers), envelopes may directly be sent for online signing, or during offline signing, cached directly for sync later. In such case, observe DSMSigningCompletedNotification (online) and DSMEnvelopeCachedNotification (offline) notifications to keep track of signing process.
 * @param signingMode is DSMSigningModeOnline, if sign and send needs to happen online(using online web signing component) OR it will be DSMSigningModeOffline if signing in Offline (using native signing components).
 * @param presentingController signing component/controller will be presented on top of the given presentingController passed.
 * @param animated If the presentation of sign and send be animated or not.
 * @param completion Completion block to be executed after signing/sending is complete/finished.
 * @warning passing nil to a presentationController will not be able to load the sign and send flow.
 * @see DSMSigningMode.h
 */
- (void)presentSendTemplateControllerWithTemplateWithId:(NSString *)templateId
                                            signingMode:(DSMSigningMode)signingMode
                                   presentingController:(UIViewController *)presentingController
                                               animated:(BOOL)animated
                                             completion:(nullable void(^)(UIViewController *_Nullable viewController, NSError *_Nullable error))completion;
/*!
 * @discussion Start Signing/Sending envelope off of a template with the given templateId. It presents the required modal which can be dismissed if desired with the view-controller returned with completion block.
 * Depending on the recipient configuration (e.g. all remote signers), envelopes may directly be sent for online signing, or during offline signing, cached directly for sync later. In such case, observe DSMSigningCompletedNotification (online) and DSMEnvelopeCachedNotification (offline) notifications to keep track of signing process.
 * @param envelopeDefaults [Optional] Customizable envelope data before starting the signing ceremony @see DSMEnvelopeDefaults.h
 * @param pdfToInsert [Optional] Offline signing only, include a PDF to be inserted at beginning or end of envelope documents. if signingMode is DSMSigningModeOnline, pdfToInsert would be silently ignored.
 * @param insertAtPosition specifies if the pdf needs to be inserted at the beginning or end of Envelope.
 * @param signingMode is DSMSigningModeOnline, if sign and send needs to happen online(using online web signing component) OR it will be DSMSigningModeOffline if signing in Offline (using native signing components).
 * @param presentingController signing component/controller will be presented on top of the given presentingController passed.
 * @param animated if the presentation of sign and send be animated or not.
 * @param completion [Optional] Completion block to be executed after signing/sending is complete/finished
 * @warning passing nil to a presentationController will not be able to load the sign and send flow.
 * this defaulting is currently available only for offline signing and if pdfToInsert is passed and with out specifying insertAtPosition it will be defaulted to begining(DSMDocumentInsertAtPositionBeginning).
 * @see DSMDocumentInsertAtPosition.h for more details on ENUM to be passed for param insertAtPosition
 * @see DSMSigningMode.h
 */
- (void)presentSendTemplateControllerWithTemplateWithId:(NSString *)templateId
                                       envelopeDefaults:(nullable DSMEnvelopeDefaults *)envelopeDefaults
                                            pdfToInsert:(nullable NSData *)pdfToInsert
                                       insertAtPosition:(DSMDocumentInsertAtPosition)insertAtPosition
                                            signingMode:(DSMSigningMode)signingMode
                                   presentingController:(UIViewController *)presentingController
                                               animated:(BOOL)animated
                                             completion:(nullable void(^)(UIViewController *_Nullable viewController, NSError *_Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
