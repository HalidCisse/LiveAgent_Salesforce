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

#import <LiveAgentChat/LACSessionState.h>
#import <LiveAgentChat/LACStopReason.h>
#import <LiveAgentChat/LACErrorCode.h>

/**
 *  Delegate protocol for the <LACSessionManager>.
 *  Classes conforming to this protocol will be provided events detailing the
 *  status of a Live Agent Chat session.
 */
@protocol LACDelegate <NSObject>

@optional
/**
 *  Delegate method invoked when first starting a Live Agent Chat session.
 *
 *  This method will be invoked when the connection flow for a Live Agent Chat session has begun.
 *
 *  @see <[LACDelegate chatDidConnect:]> which is invoked when a session has started.
 *
 *  @param chat <LACSessionManager> instance which invoked the method.
 */
- (void)chatDidStart:(__weak LACSessionManager *)chat;

/**
 *  Delegate method invoked when first attempting to stop a Live Agent Chat session.
 *
 *  @param chat   <LACSessionManager> instance which invoked the method.
 *  @param reason <LACStopReason> describing why the session has stopped.
 *  @param error  NSError instance describing the error. Error codes can be referenced from <LACErrorCode>
 */
- (void)chatDidStop:(__weak LACSessionManager *)chat reason:(LACStopReason)reason error:(NSError *)error;

/**
 *  Delegate method invoked when the Live Agent Chat session has connected. The session at this point is fully active.
 *
 *  @param chat <LACSessionManager> instance which invoked the method.
 */
- (void)chatDidConnect:(__weak LACSessionManager *)chat;

/**
 *  Delegate method invoked when the Live Agent Chat session state changes.
 *
 *  @param chat     <LACSessionManager> instance which invoked the method.
 *  @param current  The new <LACSessionState> which has been set on the for the Live Agent Chat session.
 *  @param previous The previous <LACSessionState>.
 */
- (void)chat:(__weak LACSessionManager *)chat stateDidChange:(LACSessionState)current previous:(LACSessionState)previous;

/**
 *  Delegate method invoked if an error is raised during a Live Agent Chat session.
 *
 *  @param chat  <LACSessionManager> instance which invoked the error.
 *  @param error NSError instance describing the error. Error codes can be referenced from <LACErrorCode>
 */
- (void)chat:(__weak LACSessionManager *)chat didError:(NSError *)error;

@end