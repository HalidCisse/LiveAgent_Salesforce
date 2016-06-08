//
//  UIViewController+ServiceCommon.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 11/4/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Convenience additions to UIViewController for Service Cloud SDK functionality.
 */
@interface UIViewController (ServiceCommon)

/**
 Convenience method that finds the tompost presented view controller
 */
@property (nonatomic, weak, readonly) UIViewController *topmostViewController;

/**
 Convenience method that finds the tompost presented view controller
 */
@property (nonatomic, assign, readonly, getter=isPresentedInFloatingRootWindow) BOOL presentedInFloatingRootWindow;

/**
 Convenience method to find the list of all presented controllers, starting from the receiver.
 */
- (NSArray*)allPresentedControllers;

/**
 Convenience method to find the list of all child controllers, starting from the receiver.
 */
- (NSArray*)allChildControllers;

/**
 Convenience method to return the view controller at, or below, the level of the receiver that conforms to the given protocol.
 
 @param protocol Protocol to validate.
 
 @return View controller conforming to the given protocol, or `nil`.
 */
- (UIViewController*)viewControllerConformingToProtocol:(Protocol*)protocol;

/**
 Internal method used to dismiss presented controllers.  This is necessary to inform the overlay attachment system when
 controllers are about to go away; not using this method will result in a degraded experience when presenting controllers.

 @param animated   Whether or not the dismissal should be animated.
 @param completion Optional completion block to trigger when the dismissal is complete.
 */
- (void)scu_dismissViewControllerAnimated:(BOOL)animated completion:(nullable void (^)(void))completion;

/**
 Internal method used to presented controllers.  This is necessary to inform the overlay attachment system when
 controllers are about to appear; not using this method will result in a degraded experience when presenting controllers.
 
 @param controller Controller to present.
 @param animated   Whether or not the presentation should be animated.
 @param completion Optional completion block to trigger when the presentation is complete.
 */
- (void)scu_presentViewController:(UIViewController *)controller animated:(BOOL)animated completion:(nullable void (^)(void))completion;

@end

NS_ASSUME_NONNULL_END