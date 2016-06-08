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
#import <LiveAgentChat/LACCustomDetailType.h>

@class LACCustomDetail;
@protocol LACCustomDetailDelegate;

/**
 *  The `LACCustomDetail` class represents a custom field in a Live Agent session.
 *
 *  This class will allow you to configure a list of fields which can be used to provide
 *  additional context to agents when starting a support session.
 *
 *  By default all instances of `LACCustomDetail` are flagged as required. Which means that
 *  the user will not be able to move past the Pre Chat screen without setting some kind of value
 *  for these details. This behavior can be adjusted after instantiation or by using one of the
 *  provided initializers.
 *
 *  __See:__ <[LACCustomDetail required]> for further details.
 */
@interface LACCustomDetail : NSObject<UITextFieldDelegate>

///---------------------------------
/// @name Initialization
///---------------------------------

/**
 *  Initializes and populates an `LACCustomDetail` instance.
 *
 *  @param label            The Label to apply to the `LACCustomDetail in the Pre Chat screen.
 *  @param transcriptFields The fields in which the data from this object will appear in SalesCloud.
 *
 *  @return The `LACCustomDetail` instance.
 */
+ (instancetype)customDetailWithLabel:(NSString *)label
                     transcriptFields:(NSArray *)transcriptFields;

/**
 *  Initializes and populates an `LACCustomDetail` instance.
 *
 *  @param label            The Label to apply to the `LACCustomDetail in the Pre Chat screen.
 *  @param placeholder      The placeholder text to apply to the `LACCustomDetail in the Pre Chat screen.
 *  @param transcriptFields The fields in which the data from this object will appear in SalesCloud.
 *
 *  @return The `LACCustomDetail` instance.
 */
+ (instancetype)customDetailWithLabel:(NSString *)label
                          placeholder:(NSString *)placeholder
                     transcriptFields:(NSArray *)transcriptFields;

/**
 *  Initializes and populates an `LACCustomDetail` instance.
 *
 *  @param label            The Label to apply to the `LACCustomDetail in the Pre Chat screen.
 *  @param transcriptFields The fields in which the data from this object will appear in SalesCloud.
 *  @param required         Whether or not this field needs to be populated with data to start a sesion. Default: `YES`
 *
 *  @return The `LACCustomDetail` instance.
 */
+ (instancetype)customDetailWithLabel:(NSString *)label
                     transcriptFields:(NSArray *)transcriptFields
                             required:(BOOL)required;

/**
 *  Initializes and populates an `LACCustomDetail` instance.
 *
 *  @param label            The Label to apply to the `LACCustomDetail in the Pre Chat screen.
 *  @param placeholder      The placeholder text to apply to the `LACCustomDetail in the Pre Chat screen.
 *  @param transcriptFields The fields in which the data from this object will appear in SalesCloud.
 *  @param required         Whether or not this field needs to be populated with data to start a sesion. Default: `YES`
 *
 *  @return The `LACCustomDetail` instance.
 */
+ (instancetype)customDetailWithLabel:(NSString *)label
                          placeholder:(NSString *)placeholder
                     transcriptFields:(NSArray *)transcriptFields
                             required:(BOOL)required;

///---------------------------------
/// @name Properties
///---------------------------------

/**
 *  The label which is used to describe the field when presented as part of the Pre-Chat form.
 */
@property (nonatomic, strong) NSString *label;

/**
 *  The value which will be set to the field once the session begins.
 */
@property (nonatomic, strong) NSString *value;

/**
 *  Placeholder text used when the field is presented as part of the Pre-Chat form.
 */
@property (nonatomic, strong) NSString *placeHolder;

/**
 *  A list of strings that will be used to present the user with possible values when
 *  presented as part of the Pre-Chat form.
 */
@property (nonatomic, readonly, strong) NSMutableArray *pickerValues;

/**
 *  The <LACPreChatDetailType> of the field in question. This is used by the Pre-Chat form to determine
 *  how the field is displayed and behaves.
 */
@property (nonatomic) LACPreChatDetailType type;

/**
 *  Whether this field is required for a session.
 *
 *  This field is used by the Pre-Chat form to determine if all `required` fields have been satisfied
 *  before allowing a user to begin a session.<br>
 *
 *  [Default: `YES`]
 */
@property (nonatomic) BOOL required;

/**
 *  The list of transcript fields to apply this data to.
 */
@property (nonatomic, strong) NSArray *transcriptFields;

/**
 *  Whether or not to display this information to the agent on session start.
 */
@property (nonatomic) BOOL displayToAgent;

///---------------------------------
/// @name Option Resolution
///---------------------------------

/**
 *  Determines whether or not this data is satisfied. This is used by the Pre Chat screen to decide
 *  whether or not to allow a customer to start a session.
 *
 *  @return Whether this data has been satisfied. __Note__ if this field is not required this will
 *  always return `YES`.
 */
- (BOOL)satisfied;

///---------------------------------
/// @name Delegates
///---------------------------------

/**
 *  Add an instance of an NSObject implementing the <LACCustomDetailDelegate> protocol to the list of delegates to notify.
 *
 *  @param delegate NSObject instance to add.
 */
- (void)addDelegate:(id<LACCustomDetailDelegate>)delegate;

/**
 *  Remove an instance of an NSObject implementing the <LACCustomDetailDelegate> protocol to the list of delegates to notify.
 *
 *  @param delegate NSObject instance to remove.
 */
- (void)removeDelegate:(id<LACCustomDetailDelegate>)delegate;

@end