//
//  AppDelegate.h
//  docusign-sdk-sample-objc
//
//  Copyright © 2017 DocuSign. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong) NSPersistentContainer *persistentContainer;

// manage if app is allowed to rotate orientation per screen
@property () BOOL restrictRotation;

- (void)saveContext;

@end

