#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AddressBook/AddressBook.h>

@class CNContact;

@import ContactsUI;

@interface DSMContactManager : NSObject

NS_ASSUME_NONNULL_BEGIN

+ (CNContactPickerViewController *)contactsViewControllerFromSourceViewController:(nullable UIViewController *)sourceViewController;

/**
 *  NSArray of DSContact objects built from the device's Address Book and DocuSign.
 *
 *  @return NSArray of DSContact objects.
 */
+ (NSArray *)contactsArray;

+ (NSPredicate *)defaultPredicateForEnablingContact;
+ (NSPredicate *)defaultPredicateForSelectionOfContact;

+ (NSString *)formattedNameStringWithContact:(CNContact *)contact NS_AVAILABLE_IOS(9_0);

+ (BOOL)isAuthorizedToAccessContacts;


NS_ASSUME_NONNULL_END

@end
