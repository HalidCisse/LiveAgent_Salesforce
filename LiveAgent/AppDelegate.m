//
//  AppDelegate.m
//  LiveAgent
//
//  Created by Halid Cisse on 6/9/16.
//  Copyright © 2016 Halid Cisse. All rights reserved.
//

#import "AppDelegate.h"
#import <LiveAgentChat/LiveAgentChat.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    // If you've instantiated your own UIWindow use that instead.
    UIWindow *keyWindow = _window;
    
    // This code assumes you already have a rootViewController via the storyboard. If you are instantiating your
    // own programmatically; then you can skip this step and pass your viewController into the initWithViewController:
    // initializer on the LACContainerViewController.
    UIViewController *oldRoot = [keyWindow rootViewController];
    //[keyWindow setRootViewController:nil];
    
    // Instantiate the LACContainerViewController with your root view controller
    // and set it as the rootViewController of your application window.
    LACContainerViewController *newRoot = [[LACContainerViewController alloc] initWithViewController:oldRoot];
    [keyWindow setRootViewController:newRoot];
    
//    LACRootNavigationController *newRoot = [[LACRootNavigationController alloc] initWithRootViewController:oldRoot];
//    
//    [[UIApplication sharedApplication].keyWindow setRootViewController:newRoot];
//    [self.window makeKeyAndVisible];
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
