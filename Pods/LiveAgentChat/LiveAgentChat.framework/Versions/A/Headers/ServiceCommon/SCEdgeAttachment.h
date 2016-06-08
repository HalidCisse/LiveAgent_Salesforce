//
//  SCEdgeAttachmentView.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 8/12/15.
//  Copyright (c) 2015 Salesforce.com. All rights reserved.
//

#import "SCAttachment.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Instance of an SCAttachment that is intrinsically bound to a specific edge of the screen.
 */
@interface SCEdgeAttachment : SCAttachment

/**
 Edge of the screen to be attached to, defaults to CGRectMaxYEdge.
 
 Changing this value will cause the controller to reattach itself to the indicated edge.
 */
@property (nonatomic, assign) CGRectEdge edge;

/**
 Designated initializer.
 
 @param controller Child controller to attach.  Must conform to SCAttachmentController.
 @param edge       Edge to attach the controller to.
 @return Initialized object.
 */
- (instancetype)initWithController:(UIViewController<SCAttachmentController>*)controller edge:(CGRectEdge)edge NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
