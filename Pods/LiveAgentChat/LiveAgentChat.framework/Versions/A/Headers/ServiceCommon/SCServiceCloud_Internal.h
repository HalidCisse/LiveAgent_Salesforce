//
//  SCServiceCloud_Internal.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 11/12/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#import <ServiceCommon/ServiceCommon.h>

@class SCSingletonManager, SCInterfaceRouter, SCFloatingRootWindow, SCAttachmentContainerViewController;

/**
 ## Subproject Extensions
 
 This class is intended to be extended by sub-projects through the use of categories.  Each subproject can add whichever properties or methods to SCServiceCloud as needed for their various libraries.  Since these properties and methods will be exposed to developers consuming this SDK, it's important to ensure APIs that are exposed are clean and consistent with the rest of the project.
 
 The recommended approach for project-specific configurations would be to expose a sub-project's `SCManagedSingleton` public header to SCServiceCloud via a separate property.  For example, the Knowledge-specific user options are exposed through a property called `knowledge` on SCServiceCloud.
 
        - (SCKnowledgeInterface *)knowledge {
            SCKnowledgeInterface *result = nil;
            NSObject\<SCManagedSingleton\> *managedSingleton = self.manager[SCKnowledgeInterfaceManagerKey];
            if ([managedSingleton isKindOfClass:[SCKnowledgeInterface class]]) {
                result = (SCKnowledgeInterface*)managedSingleton;
            }
            return result;
        }

 Another option for settings that may be more universal than that would be to add the properties or methods directly to SCServiceCloud.
 */
@interface SCServiceCloud ()

/**
 Singleton manager for storing strong references, and initializing singleton instances, for various components that are included as part of Service Cloud Kit.
 
 @see SCSingletonManager
 @see SCManagedSingleton
 */
@property (atomic, strong, readonly) SCSingletonManager *manager;

/**
 Floating root window instance used and shared by the various library projects.
 @see SCFloatingRootWindow
 */
@property (nonatomic, strong) SCFloatingRootWindow *rootWindow;

/**
 Root view controller within the floating window that contains attachment controllers.
 @see SCAttachmentContainerViewController
 */
@property (nonatomic, weak) SCAttachmentContainerViewController *edgeContainerController;

/**
 Current interface style instance to manage navigation events and presentation controller configuration.
 @see SCInterfaceRouter
 */
@property (atomic, strong, readonly) SCInterfaceRouter *interfaceRouter;

/**
 Presents the view controller onto the root window, firing the appropriate delegate calls as needed.
 @param controller      View controller to modally present
 @param animated        Indicates whether the presentation should be animated.
 @param completionBlock Completion block triggered when the animation has completed.
 @see dismissController:animated:completion:
 */
- (void)presentController:(UIViewController*)controller animated:(BOOL)animated completion:(void (^)(void))completionBlock;

/**
 Dismisses the view controller from the root window, firing the appropriate delegate calls as needed.
 @param controller      View controller to dismiss
 @param animated        Indicates whether the dismissal should be animated.
 @param completionBlock Completion block triggered when the animation has completed.
 @see presentController:animated:completion:
 */
- (void)dismissController:(UIViewController*)controller animated:(BOOL)animated completion:(void (^)(void))completionBlock;

/**
 Asks the SCServiceCloudDelegate whether or not the action button associated with the given name should be shown to the user.
 @param name Action name.
 @return `YES` if the action button should be no, otherwise `NO`.
 */
- (BOOL)shouldShowActionWithName:(NSString*)name;

/**
 Asks the Delegate whether the calling service should be authenticated.
 You can assign the authenticated user account property to the sdk from this method.
 @param name The name of the service (Knowledge or Case).
 @return `YES` if the service should be authenticated; 'NO' to proceed as a guest user.
 */
- (BOOL)shouldAuthenticateServiceWithName:(NSString*)name;

/**
 Tells the delegate when an error is received while using the authenticated user account.
 @param error An error object containing details about why the authentication failed.
 */
- (void)serviceAuthenticationFailedWithError:(NSError*)error;

@end
