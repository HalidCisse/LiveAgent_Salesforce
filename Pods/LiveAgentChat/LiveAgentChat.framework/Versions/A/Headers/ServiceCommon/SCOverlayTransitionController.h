//
//  SCOverlayTransitionController.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 12/20/14.
//  Copyright (c) 2014 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SCOverlayPresentationControllerDelegate;
@interface SCOverlayTransitionController : NSObject <UIViewControllerTransitioningDelegate>

@property (nonatomic, weak, nullable) NSObject <SCOverlayPresentationControllerDelegate> *overlayDelegate;

- (instancetype)initWithViewController:(UIViewController*)controller NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END