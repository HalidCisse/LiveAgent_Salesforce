/*
 * Copyright © salesforce.com, inc. 2015
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice, this
 * list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.
 *
 * Neither the name of the {organization} nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <UIKit/UIKit.h>
#import <LiveAgentChat/LiveAgentChat.h>

@class LACView;
@class LACWindow;

/**
 *  A UIViewController which is used to manage the lifetime of all views required for a Live Agent Chat session.
 *
 *  This view controller is intended to separate the UI Elements of Live Agent Chat away from the application view hierarchy your app
 *  will be using. The result is that Chat lives in a separate window outside of your application's hierarchy and allows the Chat UI to live
 *  easily across multiple view controllers seemlessly.
 */
@interface LACContainerViewController : UIViewController

///---------------------------------
/// @name Properties
///---------------------------------

/**
 *  The UIWindow in which all Live Agent Chat views are added.
 *
 *  This property is made available for debugging and introspection purposes. It is recommended that you do _not_ modify this window.
 */
@property (nonatomic, readonly, strong) LACWindow *chatWindow;

/**
 *  The parent UIView for all Live Agent Chat UI elements.
 *
 *  Like the <[LACContainerViewController chatWindow]> property. It is recommended that you do _not_ modify this view.
 */
@property (nonatomic, readonly, strong) LACView *chatView;

/**
 *  The child view controller.
 *
 *  When instantiating the `LACContainerViewController` this property will expose the UIViewController provided to
 *  <[LACContainerViewController initWithViewController:]>. In general this would be the root view controller for your application.
 */
@property (nonatomic, strong) UIViewController *childViewController;

///---------------------------------
/// @name Initialization
///---------------------------------

/**
 *  Initializes an `LACContainerViewController` instance.
 *
 *  This initializer is intended to be used if you wish to manage your view hierarchy programmatically.
 *  It is recommended that the `LACContainerViewController` is the rootViewController for your application UIWindow.
 *
 *  @warning The `LACContainerViewController` is a strict singleton. Attempting to instantiate multiple instances or
 *  calling this method if the LACContainerViewController has been added via the storyboard will raise an error.
 *
 *  @param viewController The view controller that was originally the entry view controller for your application.
 *
 *  @return `LACContainerViewController` instance.
 */
- (id)initWithViewController:(UIViewController *)viewController;

/**
 *  Shared singleton instance for the `LACContainerViewController`.
 *
 *  @warning Since this class is designed to be instantiated either programmatically or via the storyboard:
 *  The singleton instance will be available _ONLY_ after an instance of `LACContainerViewController` has been initialized normally.
 *  This method will return `nil` if no `LACContainerViewController` has been initialized.
 *
 *  @return The singleton instance of `LACContainerViewController`.
 */
+ (id)sharedInstance;

@end