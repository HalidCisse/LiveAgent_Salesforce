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

#import <Foundation/Foundation.h>

@class LACSession;
@class LACOptions;
@class LACSessionManager;

@protocol LACDelegate;

/**
 *  LACCompletionHandler block definition
 *
 *  @param error NSError instance describing the error. Error codes can be referenced from <LACErrorCode>
 *  @param lac   The instance of the <LACSessionManager> the block is acting on
 */
typedef void (^LACCompletionHandler)(NSError *error, __weak LACSessionManager *lac);

/**
 *  The LACSessionManager is the main interface into the LiveAgent Chat SDK.
 *
 *  The LACSessionManager is used to manage the lifetime of resources and network activity required
 *  for a Live Agent Chat session to operate properly.
 */
@interface LACSessionManager : NSObject

///---------------------------------
/// @name Properties
///---------------------------------

/**
 *  A reference to the <LACOptions> object provided to the session on start.
 */
@property (nonatomic, readonly, strong) LACOptions *options;

///---------------------------------
/// @name Session Control
///---------------------------------

/**
 *  This method will begin the process for starting a Live Agent Chat session.
 *
 *  Equivalent to invoking <[LACSessionManager startSessionWithOptions:completion:]> and providing a `nil` block.
 *
 *  @param options The <LACOptions> object which represents the session configuration.
 *
 *  @see <[LACSessionManager startSessionWithOptions:completion:]>
 */
- (void)startSessionWithOptions:(LACOptions *)options;

/**
 *  This method will begin the process for starting a Live Agent Chat session.
 *
 *  __NOTE__: Calling <[LACSessionManager stopSession]> at any point after calling <[LACSessionManager startSessionWithOptions:]>
 *  will not necessarily terminate a session in progress. Once the user has moved past the pre chat phase this will trigger a prompt
 *  asking the user if they wish to terminate the session. <br>
 *
 *  @param options The <LACOptions> object which represents the session configuration.
 *  @param block   Completion block which will be executed when the session has been fully connected to all services.<br/>
 *                __NOTE:__ when the block is executed the session is active and waiting for an agent to join.<br/>
 *                __NOTE:__ the NSError returned in the block will be `nil` on success.
 */
- (void)startSessionWithOptions:(LACOptions *)options completion:(LACCompletionHandler)block;

/**
 *  Stops an active or connecting session.
 *
 *  If the user has not moved past the pre chat phase this will immediately terminate the session and clean up all resources.
 *
 *  Equivalent to invoking <[LACSessionManager stopSessionWithCompletion:]> and providing a `nil` block.
 *
 *  @see [LACSessionManager stopSessionWithCompletion:]
 */
- (void)stopSession;

/**
 *  Stops an active or connecting session.
 *
 *  If the user has not moved past the pre chat phase this will immediately terminate the session and clean up all resources.
 *
 *  @param block Completion block which will be executed when the session has fully stopped, and all connected services have been torn down.<br/>
 *                __NOTE:__ the NSError returned in the block will be `nil` on success.
 */
- (void)stopSessionWithCompletion:(LACCompletionHandler)block;

///---------------------------------
/// @name Delegates
///---------------------------------

/**
 *  Add an instance of an NSObject implementing the <LACCustomDetailDelegate> protocol to the list of delegates to notify.
 *
 *  @param delegate NSObject instance to add.
 */
- (void)addDelegate:(id<LACDelegate>)delegate;

/**
 *  Remove an instance of an NSObject implementing the <LACCustomDetailDelegate> protocol to the list of delegates to notify.
 *
 *  @param delegate NSObject instance to remove.
 */
- (void)removeDelegate:(id<LACDelegate>)delegate;

@end