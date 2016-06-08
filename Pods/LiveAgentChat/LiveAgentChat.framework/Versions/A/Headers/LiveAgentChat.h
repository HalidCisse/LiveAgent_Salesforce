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

///---------------------------------
/// @name Classes
///---------------------------------

#import <LiveAgentChat/LACSessionManager.h>
#import <LiveAgentChat/LACRootNavigationController.h>

#import <LiveAgentChat/LACCustomDetail.h>
#import <LiveAgentChat/LACOptions.h>

///---------------------------------
/// @name Constants
///---------------------------------

#import <LiveAgentChat/LACCustomDetailType.h>
#import <LiveAgentChat/LACSessionState.h>
#import <LiveAgentChat/LACStopReason.h>
#import <LiveAgentChat/LACErrorCode.h>

///---------------------------------
/// @name Delegate Protocols
///---------------------------------

#import <LiveAgentChat/LACCustomDetailDelegate.h>
#import <LiveAgentChat/LACDelegate.h>

///---------------------------------
/// @name Categories
///---------------------------------

#import <LiveAgentChat/SCServiceCloud+LACSessionManager.h>

///---------------------------------
/// @name UI Appearance
///---------------------------------

#import <LiveAgentChat/LACView.h>
#import <LiveAgentChat/LACOverlayView.h>
#import <LiveAgentChat/LACModalContainerView.h>
#import <LiveAgentChat/LACModalNavigationBar.h>
#import <LiveAgentChat/LACConnectingAnimationView.h>
#import <LiveAgentChat/LACConnectingView.h>
#import <LiveAgentChat/LACChatView.h>
