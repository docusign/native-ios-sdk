//  DSMTemplatesManager.h
//  DocuSignSDK
#import <Foundation/Foundation.h>

#import "DSMTemplateCacheState.h"
#import "DSMDocumentInsertAtPosition.h"
#import "DSMSigningMode.h"

@class UIViewController;
@class DSMEnvelopeTemplate;
@class DSMEnvelopeTemplateDefinition;
@class DSMFolder;

typedef NS_ENUM(NSUInteger, DSMSearchOptions) {
    DSMSearchOptionContainsMatch,
    DSMSearchOptionExactMatch,
    DSMSearchOptionPrefixMatch,
    DSMSearchOptionSuffixMatch
};

@protocol DSMTemplatesManagerDelegate;

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
- (void)listTemplatesWithCompletion:(void(^)(NSArray<DSMEnvelopeTemplateDefinition *> *envelopeTemplateDefinitions, NSError *error))completionBlock;
/*!
 * @discussion Retrieves the list of templates available to the currently logged in user matching the given predicate.
 * @param predicate The predicate to match the templates with. A predicate of nil returns all templates.
 * @param completionBlock The completion block to be execute once the list of templates is retrieved.
 */
- (void)listTemplatesWithSearchPredicate: (NSPredicate *)predicate Completion:(void(^)(NSArray<DSMEnvelopeTemplateDefinition *> *envelopeTemplateDefinitions, NSError *error))completionBlock;
/*!
 * @discussion Retrieves the list of templates available to the currently logged in user within a given folder.
 * @param folderId The ID of the folder from which to retrieve the templates from.
 * @param completionBlock The completion block to be execute once the list of templates is retrieved.
 */
- (void)listTemplatesWithFolderId:(NSString *)folderId completion:(void(^)(NSArray<DSMEnvelopeTemplateDefinition *> *envelopeTemplateDefinitions, NSError *error))completionBlock;
/*!
 * @discussion Retrieves the list of templates available to the currently logged in user for given template name.
 * @param templateName The name of the template to retrieve.
 * @param searchOptions Specifies the type of search conducted on the template name.
 * @param completionBlock The completion block to be execute once the list of templates is retrieved.
 */
- (void)listTemplatesWithTemplateName:(NSString *)templateName searchOptions:(DSMSearchOptions)options completion:(void(^)(NSArray<DSMEnvelopeTemplateDefinition *> *envelopeTemplateDefinitions, NSError *error))completionBlock;
/*!
 * @discussion Retrieve the list of template folders for the currently logged in user.
 * @param completionBlock The completion block to be execute once the list of template folders is retrieved.
 */
- (void)listTemplateFoldersWithCompletion:(void(^)(NSArray<DSMFolder *> *folders, NSError *error))completionBlock;
/*!
 * @discussion Gives status of a template.
 * @param templateId An ID of the template whose status is enquired.
 * @return DSMTemplateCacheState 
 * @see DSMTemplateCacheState.h
 */
- (DSMTemplateCacheState)cacheStateOfTemplateWithId:(NSString *)templateId;
/*!
 * @discussion Gives previously cached template details.
 * @param templateId An ID of the template to be retrived.
 * @param includePdfs retrive/include the pdf's or not.
 * @return DSMEnvelopeTemplate
 */
- (DSMEnvelopeTemplate *)cachedTemplateWithId:(NSString *)templateId includePdfs:(BOOL)includePdfs;
/*!
 * @discussion Cache a template for offline use.
 * @param templateId An ID of the template to be cached.
 * @param completionBlock Can pass in a completion block to be executed on completion of cache.
 */
- (void)cacheTemplateWithId:(NSString *)templateId completion:(void(^)(NSError *))completionBlock;
/*!
 * @discussion Remove previously cached template.
 * @param templateId An ID of the template to be removed.
 */
- (void)removeCachedTemplateWithId:(NSString *)templateId;
/*!
 * @discussion Remove all previously cached templates.
 */
- (void)removeCachedTemplates;
/*!
 * @discussion Retrive all list of cached templates.
 * @return NSArray <DSMEnvelopeTemplate *>
 */
- (NSArray *)cachedTemplates;
/*!
 * @discussion Retrive all list of cached templateId's.
 * @return NSArray <NSString *>
 */
- (NSArray *)cachedTemplateIds;
/*!
 * @discussion number of templates cached for offline use.
 * @return NSUInteger
 */
- (NSUInteger)cachedTemplateCount;
/*!
 * @discussion Can a template be cached and used for offline signing(some of the templates which are not supported in mobile signing can not be cached).
 * @param envelopeTemplate template to be cached.
 * @param error If error is passed it will be updated with the reason for unavailability for signing/cache in mobile.
 * @return BOOL
 * @warning This will default to NO and unable to cache reason is passed back only when error instence is passed while calling this.
 */
- (BOOL)canCacheEnvelopeTemplate:(DSMEnvelopeTemplate *)envelopeTemplate error:(NSError *__autoreleasing*)error;
/*!
 * @discussion Start Signing/Sending envelope off of a template with given templateId.
 * @param signingMode is DSMSigningModeOnline, if sign and send needs to happen online(using online web signing component) OR it will be DSMSigningModeOffline if signing in Offline (using native signing components).
 * @param presentingController signing component/controller will be presented on top of the given presentingController passed.
 * @param animated If the presentation of sign and send be animated or not.
 * @param completion Completion block to be executed after signing/sending is complete/finished
 * @warning passing nil to a presentationController will not be able to load the sign and send flow.
 * @see DSMSigningMode.h
 */
- (void)presentSendTemplateControllerWithTemplateWithId:(NSString *)templateId
                                          signingMode:(DSMSigningMode)signingMode
                                   presentingController:(UIViewController *)presentingController
                                               animated:(BOOL)animated
                                             completion:(void(^)(UIViewController *viewController, NSError *error))completion;
/*!
 * @discussion Start Signing/Sending envelope off of a template with the given templateId.
 * @param tabValueDefaults Can be used to default the tabvalues NSDictionary<tab.tabLabel *, tab.value *>
 * @param pdfToInsert Can be used to pass a PDF to be inserted at begining or end of envelope documents.
 * @param insertAtPosition specigies if the pdf needs to eb inserted at the beginging or end of Envelope.
 * @param signingMode is DSMSigningModeOnline, if sign and send needs to happen online(using online web signing component) OR it will be DSMSigningModeOffline if signing in Offline (using native signing components).
 * @param presentingController signing component/controller will be presented on top of the given presentingController passed.
 * @param animated if the presentation of sign and send be animated or not.
 * @param completion completion block to be executed after signing/sending is complete/finished
 * @warning passing nil to a presentationController will not be able to load the sign and send flow.
 * this defaulting is currently available only for offline signing and if pdfToInsert is passed and with out specifying insertAtPosition it will be defaulted to begining(DSMDocumentInsertAtPositionBeginning).
 * @see DSMDocumentInsertAtPosition.h for more details on ENUM to be passed for param insertAtPosition
 * @see DSMSigningMode.h
 */
- (void)presentSendTemplateControllerWithTemplateWithId:(NSString *)templateId
                                       tabValueDefaults:(NSDictionary<NSString *, NSString *> *)tabValueDefaults
                                            pdfToInsert:(NSData *)pdfToInsert
                                       insertAtPosition:(DSMDocumentInsertAtPosition)insertAtPosition
                                          signingMode:(DSMSigningMode)signingMode
                                   presentingController:(UIViewController *)presentingController
                                               animated:(BOOL)animated
                                             completion:(void(^)(UIViewController *viewController, NSError *error))completion;

@end
