
# How to auto update the cached templates

### How to only update the templates which have been cached earlier and were changed on DocuSign web? 

Solution: Compare `lastModified` and `cachedDateTime` to selectively download modified templates 

### Implementation details

Rather than relying on users to remove the cached template and download the updated templates again, following solution can be used for automatically updating the cached templates download. This can be done on client side by issuing a `cacheTemplateWithId` call for only templates which were changed after caching was done. It can be deduced after the comparision of modified and cached datetime for templates. 

### Template's last modified datetime

`DSMEnvelopeTemplateDefinition` is the lightweight object; its array is returned with the `[DSMTemplateManager listTemplatesWithCompletion:..]` method. It has a property `lastModified` that refers to modified time on the remote (on server) template.

```
@interface DSMEnvelopeTemplateDefinition : NSObject

/*!
* @brief The date and time the item was last modified. [optional]
*/
@property(nonatomic, copy) NSDate *lastModified;

@end
```

Sample `lastModified`

```
(lldb) po templateDefinition.lastModified
2018-10-30 15:05:21 +0000
```


### Template's last cached datetime  

`DSMEnvelopeTemplate` is the cached copy of the template. It has a property `cachedDateTime` that stores the last time the template was stored successfully on device. 


```
@interface DSMEnvelopeTemplate : NSObject <DSMEnvelopeHelperProtocol>

/*!
* @brief The date and time the envelope or template was cached.
*/
@property (nonatomic, copy) NSDate *cachedDateTime;

@end
```

Sample `cachedDateTime`
```
(lldb) po cachedTemplate.cachedDateTime
2018-10-30 15:04:57 +0000
```

### Sample code

Code snippet to auto download a template if it was modified. It compares the lastModified datetime on remote template vs cached template.

```  
- (void)autoUpdateCacheForTemplates:(NSArray<DSMEnvelopeTemplateDefinition *> *)envelopeTemplateDefinitions {

    // array containing all cached templates
    NSArray *cachedTemplates = [self.templatesManager cachedTemplates];
    
    // iterate over the cached templates array
    for (DSMEnvelopeTemplate *cachedTemplate in cachedTemplates) {
        
        // cached template Id is used to filter the updated envelope template definition (unique template id)  
        NSString *templateId = cachedTemplate.envelopeTemplateDefinition.templateId;
        
        // updated (remote) envelope template definition reference. Filter the list of templates with a matching cached templates id.
        DSMEnvelopeTemplateDefinition *updatedTemplateDefinition = 
            [[envelopeTemplateDefinitions filteredArrayUsingPredicate:[NSPredicate predicateWithBlock:
                ^BOOL(DSMEnvelopeTemplateDefinition *envelopeTemplateDefinition, NSDictionary *bindings) {
                    return [templateId isEqualToString:envelopeTemplateDefinition.templateId];
                }
             ]] firstObject];
        
        // cache (download) template again if it was modified after the last time it was cached
        if ([cachedTemplate.cachedDateTime compare:[updatedTemplateDefinition lastModified]] == NSOrderedAscending) {
            [self.templatesManager cacheTemplateWithId:templateId completion:^(NSError *error) {
              // handle error and reload view
                }
            }];
        }
    }
}

- (void)fetchTemplates {
    // get list of templates when online
    [self.templatesManager listTemplatesWithCompletion:^(NSArray<DSMEnvelopeTemplateDefinition *> *envelopeTemplateDefinitions, NSError *error) {
        if (error) {
          // handle error
        } else {
            // try to auto download the updated templates
            [self autoUpdateCacheForTemplates:envelopeTemplateDefinitions];
            // reload view
            [self.tableView reloadData];
        }
    }];
}
```


