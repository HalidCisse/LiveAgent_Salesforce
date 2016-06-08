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
/**
 * The `LACOptions` object allows the developer to configure the behavior of any <LACSessionManager> session.
 *
 * The options set on the `LACOptions` object determines how the Chat session will be routed.
 */
@interface LACOptions: NSObject

///---------------------------------
/// @name Initialization
///---------------------------------

/**
 *  Instantiates an `LACOptions` object for use with <[LACSessionManager startSessionWithOptions:]>
 *
 *  @param liveAgentPod The hostname for the LiveAgent endpoints that your organization has been assigned.
 *  @param orgId        The Salesforce 15 character Organization ID.
 *  @param deploymentId The unique ID for the deployment that this client will be configured to use.
 *  @param buttonId     The unique ID for the chat configuration that this client will use.
 *
 *  @return The `LACOptions` instance.
 */
+ (instancetype)optionsWithLiveAgentPod:(NSString *)liveAgentPod
                                  orgId:(NSString *)orgId
                           deploymentId:(NSString *)deploymentId
                               buttonId:(NSString *)buttonId;

///---------------------------------
/// @name Deployment Configuration
///---------------------------------

/**
 *  The hostname for the LiveAgent endpoints that your organization has been assigned.
 */
@property (nonatomic, strong) NSString *liveAgentPod;

/**
 *  The Salesforce 15 character Organization ID.
 */
@property (nonatomic, strong) NSString *organizationId;

/**
 *  The unique ID for the deployment that this client will be configured to use.
 */
@property (nonatomic, strong) NSString *deploymentId;

/**
 *  The unique ID for the chat configuration that this client will use.
 */
@property (nonatomic, strong) NSString *buttonId;

///---------------------------------
/// @name Session Behavior
///---------------------------------

/**
 *  The name of the visitor that will be displayed to an agent.
 *
 *  If this property is `nil` then the default value `Visitor` will be used.
 */
@property (nonatomic, strong) NSString *visitorName;

/**
 *  The language code that this chat will be using.
 */
@property (nonatomic, strong) NSString *language;

/**
 *  An array of <LACCustomDetail> objects defining the custom information this session will provide.
 */
@property (nonatomic, readonly, strong) NSMutableArray *prechatDetails;

/**
 *  Determines whether or not this session will receive live queue updates while connecting. Default: `YES`
 */
@property (nonatomic) BOOL receiveQueueUpdates;

/**
 *  Determines whether the session is run with modals and minimized or in a fullscreen fashion. Default: `NO`
 */
@property (nonatomic) BOOL fullscreen;

@end
