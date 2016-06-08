//
//  SCFloatingRootWindow.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 8/11/15.
//  Copyright (c) 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SCFloatingRootWindow;

/**
 Definition of the style a controller's content contains, relative to other UI elements.
 */
typedef NS_ENUM(NSInteger, SCContentStyle) {
    /** Light content –- the contents of the controller is lighter relative to other view controllers. */
    SCContentStyleLightContent = 0,
    
    /** Dark content -- the contents of the controller may be darker relative to other view controllers. */
    SCContentStyleDarkContent = 1,
};

/**
 Protocol used by view controllers that would like to participate in, and coordinate their needs with, the floating root window.
 */
@protocol SCFloatingController <NSObject>

@optional

/**
 Indicates whether or not any of the floating root window attachments should be displayed above this controller.
 
 The default is assumed to be `YES`, but if you wish to disable floating attachments in your controller, implement
 this method and return `NO`.
 
 @return `YES` if floating attachments should be visible, otherwise `NO`.
 */
- (BOOL)shouldOverlayFloatingRootController;

/**
 Indicates the desired content style for attachments shown above this controller.
 @return SCContentStyle for attachments
 */
- (SCContentStyle)preferredContentStyle;

@end

/**
 Delegate protocol used to be informed of key events that occur within the floating root window's lifecycle.
 */
@protocol SCFloatingRootWindowDelegate <NSObject>

@optional

/**
 Informs the delegate when a subview is added to the window.  If the subview has been identified as belonging to a particular view controller, that controller will be supplied.

 @warning Due to implementation details within UIKit, this method may be called multiple times during an animated view controller transition, or when subviews change their order.
 @param window     The floating window instance.
 @param view       The view that was added.
 @param controller The controller this view belongs to, if found.
 */
- (void)floatingWindow:(SCFloatingRootWindow*)window didAddView:(UIView*)view forController:(nullable UIViewController*)controller;

/**
 Informs the delegate when a subview is removed from the window.  If the subview has been identified as belonging to a particular view controller, that controller will be supplied.

 @param window     The floating window instance.
 @param view       The view that was removed.
 @param controller The controller this view belongs to, if found.
 */
- (void)floatingWindow:(SCFloatingRootWindow*)window willRemoveSubview:(UIView*)view forController:(nullable UIViewController*)controller;

@end

/**
 UIWindow subclass that persistently floats above another reference window.
 */
@interface SCFloatingRootWindow : UIWindow

/**
 The base window to track, to ensure this floating window remains above it.
 */
@property (nonatomic, weak, nullable) UIWindow *baseWindow;

/**
 The content style that all visible elements should conform to.
 */
@property (nonatomic, assign) SCContentStyle contentStyle;

/**
 Delegate to receive updates about changes to this window.
 */
@property (nonatomic, weak, nullable) NSObject<SCFloatingRootWindowDelegate> *floatingDelegate;

/**
 Adjusts the contentStyle property animated.
 
 @param contentStyle New content style.
 @param animated     `YES` to animate the change, otherwise `NO`.
 */
- (void)setContentStyle:(SCContentStyle)contentStyle animated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
