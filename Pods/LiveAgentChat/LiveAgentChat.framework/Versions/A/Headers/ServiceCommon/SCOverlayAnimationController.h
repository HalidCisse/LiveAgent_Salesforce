//
//  SCOverlayAnimationController.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 12/23/14.
//  Copyright (c) 2014 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SCCInternalDefines.h"

NS_ASSUME_NONNULL_BEGIN

extern NSTimeInterval const kSCOverlayAnimationDefaultDuration;

/**
 Animation controller used by SCOverlayPresentationController to animate the presentation and dismissal of the overlay controller.
 */
@interface SCOverlayAnimationController : NSObject <UIViewControllerAnimatedTransitioning, UIViewControllerInteractiveTransitioning>

@property (nonatomic, weak, readonly, nullable) UIViewController *presentedController;
@property (nonatomic, weak, readonly, nullable) UIViewController *presentingController;
@property (nonatomic, weak, readonly, nullable) UIViewController *sourceController;
@property (nonatomic, weak, readonly, nullable) UIViewController *dismissedController;

@property (nonatomic, assign) NSTimeInterval duration;
@property (nonatomic, assign, getter = isInteractive, readonly) BOOL interactive;
@property (nonatomic, assign, readonly) SCAnimationType animationType;

/**
 Designated initializer to be used when the target controller is being presented.
 
 @param presented  Presented view controller.
 @param presenting Presenting view controller.
 @param source     Source view controller.
 
 @return Constructed instance.
 */
- (instancetype)initWithPresentedController:(UIViewController *)presented
                       presentingController:(UIViewController *)presenting
                           sourceController:(UIViewController *)source NS_DESIGNATED_INITIALIZER;

/**
 Designated initializer to be used when the target controller is being dismissed.
 
 @param dismissed The dismissed view controller.
 
 @return Constructed instance.
 */
- (instancetype)initWithDismissedController:(UIViewController*)dismissed NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END