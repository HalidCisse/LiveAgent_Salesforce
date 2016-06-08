//
//  SCFullscreenAnimationController.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 12/31/14.
//  Copyright (c) 2014 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SCCInternalDefines.h"

extern NSTimeInterval const kSCFullscreenAnimationDefaultDuration;

/**
 Animation controller used to transition between view controllers by scaling / fading the source controller to the dimensions of the target controller.
 */
@interface SCFullscreenAnimationController : NSObject <UIViewControllerAnimatedTransitioning>

/**
 Animation duration.
 */
@property (nonatomic, assign) NSTimeInterval duration;

/**
 Animation type, used to indicate whether the animation is a presentation or dismissal.
 */
@property (nonatomic, assign, readonly) SCAnimationType animationType;

/**
 Designated initializer to be used when the target controller is being presented or dismissed.
 
 This animation type behaves by animating the view from its initial frame size to the target frame
 size by scaling it.  This is only useful when the presenting view controller does not fill the full
 screen.
 
 @param animationType  Type of animation to perform
 @return Constructed instance.
 */
- (instancetype)initWithAnimationType:(SCAnimationType)animationType NS_DESIGNATED_INITIALIZER;

@end
