//
//  SCOverlayOverlayPresentationController.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 12/20/14.
//  Copyright (c) 2014 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SCOverlayPresentationController;
@protocol SCOverlayPresentationControllerDelegate;

@interface SCOverlayPresentationView : UIView @end

/**
 Presentation controller for displaying a semi-opaque background behind the presented controller.
 */
@interface SCOverlayPresentationController : UIPresentationController

/**
 The delegate to control interactions with the presentation controller.
 
 @discussion
 If the presented, or presenting, view controllers conform to this protocol, they will automatically be used
 as the default for this property.
 */
@property (nonatomic, weak, nullable) NSObject<SCOverlayPresentationControllerDelegate> *overlayDelegate;

/**
 The insets to apply to the child view controller, to adjust its margins from the edge of the presenting controller.
 */
@property (nonatomic, assign) UIEdgeInsets marginInsets;

/**
 The corner radius to apply to the overlaid controller.
 */
@property (nonatomic, assign) CGFloat cornerRadius;

/**
 The background view that will be displayed between the presented and presenting view controllers.
 */
@property (nonatomic, strong, readonly) UIView *backgroundView;

- (void)transitionToFullScreenView:(BOOL)fullScreen;

@end

NS_ASSUME_NONNULL_END