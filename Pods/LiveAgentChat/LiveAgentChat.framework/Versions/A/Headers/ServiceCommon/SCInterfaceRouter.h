//
//  SCUAppearanceRouter.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 10/28/14.
//  Copyright (c) 2014 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SCInterfaceStyle;
@class SCServiceCloud, SCAppearanceConfiguration;

/**
 Factory container class to manage a collection of SCInterfaceStyle instances responsible for presenting and managing the display and navigation of a collection of view controllers.
 
 The router provies an abstraction layer to collect interface style instances and allows different UI components to communicate, potentially distributed across multiple sublibrary targets that may not have visibility to one-another.
 */
@interface SCInterfaceRouter : NSObject

/**
 Registers a class to respond to a given interface style.
 
 This is the primary entry point for enrolling a class to handle events, interface decisions, or other behavioral interactions to a shared interface.  No judgements are made about which classes should respond, but the various interface handler classes are collected together into the interface style router.  This router is then used by the shared interface singleton to delegate decisions about interface navigation events, UI transition controllers, and other behaviors.
 
 It is up to the implementation to determine how to access the appropriate objects.  Either directly accessing the allInterfaceStyleHandlers property to iterate through the registered handler instances, or utilizing interfaceStylesConformingToProtocol: to limit the handlers to those that are needed for a particular capability, are useful.
 @param styleClass The class to register.
 @param style      The style name to associate this class with.
 */
+ (void)registerClass:(Class)styleClass forStyle:(NSString*)style;

/**
 Readonly property returning the service cloud instance supplied to the initializer.
 @see SCServiceCloud
 */
@property (nonatomic, weak, readonly) SCServiceCloud *serviceCloud;

/**
 Readonly property to return the style name this handler instance is currently adopting.
 
 This value may change if it supports the adoptInterfaceStyle: method, and the interface style changes at runtime.
 */
@property (nonatomic, copy, readonly) NSString *interfaceStyle;

/**
 Accessor to retrieve the full list of handlers for this interface style.
 @see SCInterfaceStyle
 */
@property (nonatomic, strong, readonly) NSArray<NSObject<SCInterfaceStyle>*> *allInterfaceStyleHandlers;

/**
 Designated initializer that returns an interface style router with the given style.
 @param serviceCloud The service cloud instance constructing this router.
 @param style        Interface style to use.
 @see SCServiceCloud
 */
- (instancetype)initWithServiceCloud:(SCServiceCloud*)serviceCloud interfaceStyle:(NSString*)style NS_DESIGNATED_INITIALIZER;

/**
 Transitions to the given interface style.  If any handlers active within this interface router are capable of adapting to the new style (e.g. they respond to the [SCInterfaceStyle adoptInterfaceStyle:] method and return `YES`), they will be preserved during the transition.
 @param style New interface style to transition to.
 */
- (void)transitionToInterfaceStyle:(NSString*)style;

/**
 Returns a subset of the interface styles conforming to the given protocol.
 @param protocol The protocol members must conform to.
 @see SCInterfaceStyle
 */
- (nullable NSArray<NSObject<SCInterfaceStyle>*> *)interfaceStylesConformingToProtocol:(Protocol*)protocol;

@end

@interface SCInterfaceRouter (ViewControllerPresentation)

/**
 Requests a transitioning delegate for the given controller from the various interface style instances that conform to SCInterfacePresentation.
 @param controller View controller about to be presented
 @return Object conforming to UIViewControllerTransitioningDelegate, or `nil` if no transitioning delegate is needed.
 */
- (nullable NSObject<UIViewControllerTransitioningDelegate>*)transitioningDelegateForController:(UIViewController*)controller;

/**
 Requests the given presentation controller to be customized, as needed, prior to use.
 @param presentationController Presentation controller about to be used when presenting another controller.
 */
- (void)applyStyleToPresentationController:(UIPresentationController*)presentationController;

@end

@class SCEvent;
@interface SCInterfaceRouter (SCInterfaceEventResponder)

/**
 Sends the given event to the appropriate interface handler that supports the SCInterfaceEventResponder protocol.
 
 The appropriate handler or handlers will be given the opportunity to respond to the event.
 
 @discussion
 If no interaction responder is available for the receiver, then the event will be silently ignored.
 
 @param event Event to send.
 @return `YES` if the event has been handled, otherwise `NO` means no responder was available to handle the event.
 @see SCEvent
 */
- (BOOL)sendInteractionEvent:(SCEvent*)event;

@end

NS_ASSUME_NONNULL_END
