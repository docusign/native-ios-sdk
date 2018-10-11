//
//  AppDelegate.swift
//  docusign-sdk-sample-swift
//
//
//  Copyright © 2017 DocuSign. All rights reserved.
//


import CoreData
import DocuSignSDK
import UIKit


@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate
{
    var window: UIWindow?

    // manages whether rotation is allowed per screen
    var lockPortraitOrientation: Bool = true;
    

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool
    {
        // initialize DS sdk manager
        var configuration = DSMManager.defaultConfigurations()!;
        // hide offline signing alerts
        configuration[DSM_SETUP_OFFLINE_SIGNING_HIDE_ALERTS_KEY] = DSM_SETUP_TRUE_VALUE;
        
        if #available(iOS 11.0, *) {
            // icloud entitlement is not required for iOS 11+ - set constant to true to enable document picker usage
            configuration[DSM_SETUP_ICLOUD_DOCUMENT_ENABLED] = DSM_SETUP_TRUE_VALUE;
        } else {
            // icloud entitlement (icloud documents) is required for iOS 10 and below for document picker usage
            // if icloud is enabled, then this constant should be set to DSM_SETUP_TRUE_VALUE
            configuration[DSM_SETUP_ICLOUD_DOCUMENT_ENABLED] = DSM_SETUP_FALSE_VALUE;
        }
        
        //configuration[DSM_SETUP_DISABLE_CONTACTS_USAGE_KEY] = DSM_SETUP_TRUE_VALUE;

        // initialize DS sdk manager
        DSMManager.setup(withConfiguration: configuration);

        return true
    }

    
    func applicationWillResignActive(_ application: UIApplication)
    {
        // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
        // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
    }

    
    func applicationDidEnterBackground(_ application: UIApplication)
    {
        // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
        // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    }

    
    func applicationWillEnterForeground(_ application: UIApplication)
    {
        // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
    }

    
    func applicationDidBecomeActive(_ application: UIApplication)
    {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    }

    
    func applicationWillTerminate(_ application: UIApplication)
    {
        // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
        // Saves changes in the application's managed object context before the application terminates.
        self.saveContext()
    }

    
    func application(_ application: UIApplication, supportedInterfaceOrientationsFor window: UIWindow?) ->
        UIInterfaceOrientationMask
    {
            if (lockPortraitOrientation) {
                return UIInterfaceOrientationMask(rawValue: UIInterfaceOrientationMask.portrait.rawValue)
            }
            else {
                return UIInterfaceOrientationMask(rawValue: UIInterfaceOrientationMask.all.rawValue)
            }
    }

    
    // MARK: - utility routines

    lazy var applicationDocumentsDirectory: URL = {
        let urls = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask)
        return urls[urls.count-1]
    }()
    

    // MARK: - Core Data stack (generic)

    lazy var managedObjectModel: NSManagedObjectModel = {
        let modelURL = Bundle.main.url(forResource: "docusign_sdk_sample_swift", withExtension: "momd")!
        return NSManagedObjectModel(contentsOf: modelURL)!
    }()
    
    lazy var persistentStoreCoordinator: NSPersistentStoreCoordinator = {
        let coordinator = NSPersistentStoreCoordinator(managedObjectModel: self.managedObjectModel)
        let urls = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask)
        let url = self.applicationDocumentsDirectory.appendingPathComponent("docusign_sdk_sample_swift").appendingPathExtension("SingleViewCoreData.sqlite")
        
        do {
            try coordinator.addPersistentStore(ofType: NSSQLiteStoreType, configurationName: nil, at: url, options: nil)
        } catch {
            let dict : [String : Any] =
            [
                NSLocalizedDescriptionKey:"Failed to initialize the application's saved data" as NSString,
                NSLocalizedFailureReasonErrorKey:"There was an error loading the application's saved data." as NSString,
                NSUnderlyingErrorKey:error as NSError
            ]
            
            let wrappedError = NSError(domain: "YOUR_ERROR_DOMAIN", code: 9999, userInfo: dict)
            fatalError("Unresolved error \(wrappedError), \(wrappedError.userInfo)")
        }
        
        return coordinator
    }()
    
    
    // MARK: - Core Data stack (iOS 9)
    
    @available(iOS 9.0, *)
    lazy var managedObjectContext: NSManagedObjectContext = {
        var managedObjectContext = NSManagedObjectContext(concurrencyType: .mainQueueConcurrencyType)
        managedObjectContext.persistentStoreCoordinator = self.persistentStoreCoordinator
        return managedObjectContext
    }()
    

    // MARK: - Core Data stack (iOS 10)
    
    @available(iOS 10.0, *)
    lazy var persistentContainer: NSPersistentContainer = {
        let container = NSPersistentContainer(name: "docusign_sdk_sample_swift")
        container.loadPersistentStores(completionHandler: {
            (storeDescription, error) in
            if let error = error as NSError?
            {
                fatalError("Unresolved error \(error), \(error.userInfo)")
            }
        })
        return container
    }()
    
    
    // MARK: - Core Data context
    
    lazy var databaseContext : NSManagedObjectContext = {
        if #available(iOS 10.0, *) {
            return self.persistentContainer.viewContext
        } else {
            return self.managedObjectContext
        }
    }()
    
    
    // MARK: - Core Data save
    
    func saveContext ()
    {
        do {
            if databaseContext.hasChanges {
                try databaseContext.save()
            }
        } catch {
            let nserror = error as NSError
            
            fatalError("Unresolved error \(nserror), \(nserror.userInfo)")
        }
    }
}

