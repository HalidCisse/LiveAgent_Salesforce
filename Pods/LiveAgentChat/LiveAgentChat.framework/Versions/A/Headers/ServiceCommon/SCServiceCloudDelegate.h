//
//  SCServiceCloudDelegate.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 11/20/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SCServiceCloud;
/**
 The delegate protocol to interact with the Service Cloud SDK, and to make decisions on behalf of the SDK.
 */
@protocol SCServiceCloudDelegate <NSObject>

@optional

/**
 Message sent to the receiver when the interface is about to be displayed.

 @param serviceCloud  Service Cloud interface instance.
 @param controller View controller being displayed.
 @param animated   `YES` if the presentation is animated.
 */
- (void)serviceCloud:(SCServiceCloud *)serviceCloud willDisplayViewController:(UIViewController*)controller animated:(BOOL)animated;

/**
 Message sent to the receiver after the interface was displayed.

 @param serviceCloud  Service Cloud interface instance.
 @param controller View controller being displayed.
 @param animated   `YES` if the presentation was animated.
 */
- (void)serviceCloud:(SCServiceCloud *)serviceCloud didDisplayViewController:(UIViewController*)controller animated:(BOOL)animated;

/**
 Message sent to the receiver when the interface is about to be hidden.

 @param serviceCloud  Service Cloud interface instance.
 @param controller View controller being hidden.
 @param animated   `YES` if the dismissal is animated.
 */
- (void)serviceCloud:(SCServiceCloud *)serviceCloud willHideViewController:(UIViewController*)controller animated:(BOOL)animated;

/**
 Message sent to the receiver after the interface was hidden.

 @param serviceCloud  Service Cloud interface instance.
 @param controller View controller being hidden.
 @param animated   `YES` if the dismissal was animated.
 */
- (void)serviceCloud:(SCServiceCloud *)serviceCloud didHideViewController:(UIViewController*)controller animated:(BOOL)animated;

/**
 Allows the receiver to customize the transitioning delegate used when a view controller is about to be presented.
 
 By default, the Service Cloud SDK uses custom controllers for presentation and for transition animations. If you wish to customize the default behavior, implement this method and return an object conforming to UIViewControllerTransitioningDelegate.
 
 @param serviceCloud Service Cloud interface instance.
 @param controller   View controller about to be presented.

 @return Transitioning delegate that should control the controller presentation, or `nil` to to accept the system defaults.
 */
- (nullable NSObject<UIViewControllerTransitioningDelegate>*)serviceCloud:(SCServiceCloud *)serviceCloud transitioningDelegateForViewController:(UIViewController*)controller;

/**
 Use this method to configure which action buttons should be present.

 @param serviceCloud Service Cloud interface instance.
 @param name Name representing the action in question.
 @return `YES` if the action should be visible, otherwise `NO` if the button should be omitted for the action.
 */
- (BOOL)serviceCloud:(SCServiceCloud *)serviceCloud shouldShowActionWithName:(NSString*)name;

/**
 Message sent to the receiver when Cases/KB is about to be displayed.
 @param service  string to notify if case or knowledge is being launched.
 */
- (BOOL)serviceCloud:(SCServiceCloud*)serviceCloud shouldAuthenticateService:(NSString*)service;

/**
 Message sent to the receiver when there is an error in authenticating cases or knowledge.
 @param error  NSError denotes the reason for failure.
 @param service string denotes if authentication failed for knowledge or cases.
 */
- (void)serviceCloud:(SCServiceCloud*)serviceCloud serviceAuthenticationFailedWithError:(NSError*)error forService:(NSString*)service;

@end

NS_ASSUME_NONNULL_END