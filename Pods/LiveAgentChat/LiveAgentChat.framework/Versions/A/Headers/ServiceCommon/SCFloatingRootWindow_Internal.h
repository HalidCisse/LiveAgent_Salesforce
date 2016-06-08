//
//  SCFloatingRootWindow_Internal.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 8/21/15.
//  Copyright (c) 2015 Salesforce.com. All rights reserved.
//

#import "SCFloatingRootWindow.h"

@interface SCFloatingRootWindow ()

@property (nonatomic, weak) UIViewController *activeViewController;

- (void)transitionToNewViewController:(UIViewController*)newController fromViewController:(UIViewController*)oldController animated:(BOOL)animated;

@end
