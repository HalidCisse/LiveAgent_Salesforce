//
//  SCAnimationContext.h
//  KnowledgeUI
//
//  Created by Michael Nachbaur on 10/29/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/** Private implementation of an animated transitioning between attachments.

 @warning This class is meant to be private, and should under no circumstances be exposed to customers.
 */
@interface SCAnimationContext : NSObject<UIViewControllerContextTransitioning>

@property (nonatomic, copy, nullable) void (^completionBlock)(BOOL didComplete);
@property (nonatomic, assign, getter=isAnimated) BOOL animated;
@property (nonatomic, assign, getter=isInteractive) BOOL interactive;

@property (nonatomic, weak, nullable) UIView *containerView;

- (void)setViewController:(nullable UIViewController *)controller forKey:(NSString *)key;
- (void)setInitialFrame:(CGRect)frame forViewController:(nullable UIViewController *)viewController;
- (void)setFinalFrame:(CGRect)frame forViewController:(nullable UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
