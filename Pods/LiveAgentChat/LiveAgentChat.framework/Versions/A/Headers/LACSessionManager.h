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
/// @name Initialization
///---------------------------------

/**
 *  Shared singleton instance for the LACSessionManager.
 *
 *  @warning The LACSessionManager is intended to be used as a singleton. Instantiating a
 *  standalone instance is not supported.
 *
 *  @return The singleton instance of LACSessionManager.
 */
+ (instancetype)sharedInstance;

///---------------------------------
/// @name Session Control
///---------------------------------

/**
 *  This method will begin the process for starting a Live Agent Chat session.
 *
 *  __NOTE__: Calling <[LACSessionManager stopSession]> at any point after calling <[LACSessionManager startSessionWithOptions:]>
 *  will not necessarily terminate a session in progress. Once the user has moved past the pre chat phase this will trigger a prompt
 *  asking the user if they wish to terminate the session. <br>
 *
 *  @param options The <LACOptions> object which represents the session configuration.
 */
- (void)startSessionWithOptions:(LACOptions *)options;

/**
 *  Stops an active or connecting session.
 *
 *  If the user has not moved past the pre chat phase this will immediately terminate the session and clean up all resources.
 */
- (void)stopSession;

/**
 *  Will force the Live Agent Chat interface to move to the full screen.
 */
- (void)maximize;

@end