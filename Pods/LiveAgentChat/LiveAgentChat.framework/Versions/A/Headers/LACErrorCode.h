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
 *  Live Agent Chat ErrorCode definitions.
 *
 *  Errors fall into one of several groups (or series) of errors.
 *
 *  If there is an error thrown by a library dependency it will be included as metadata
 *  in the userInfo of the error which is returned to the application code.
 *
 *  @see <[LACDelegate chat:didError:]>
 *  @see <[LACDelegate chatDidStop:reason:error:]>
 */
typedef NS_ENUM(NSInteger, LACErrorCode) {
    ///--------------------------------
    /// @name General Errors (1000-series)
    ///--------------------------------

    /**
     *  Unclassified error. This results from an unknown or unexpected error state.
     *
     *  Any other un-grouped errors will be added to the 1000 series error group.
     */
    LACGenericError = 1000,

    /**
     *  The <LACOptions> object provided to the <LACSessionManager> is invalid.
     */
    LACInvalidOptions = 1001,

    ///--------------------------------
    /// @name Connection Errors (2000-series)
    ///--------------------------------

    /**
     *  Standard communication error. This can be returned from operations dependent on communication
     *  between LAC or any other remote system.
     *
     *  All communication related errors will be found in the 2000 series error group.
     */
    LACCommunicationError = 2000,

    /**
     *  Returned when attempting to start a session when no agents are available to accept the request.
     */
    LACNoAgentsAvailableError = 2001
};