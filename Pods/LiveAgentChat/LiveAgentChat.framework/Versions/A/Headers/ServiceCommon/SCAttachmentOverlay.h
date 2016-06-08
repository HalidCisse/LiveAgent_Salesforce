//
//  SCAttachmentOverlay.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 4/15/15.
//  Copyright (c) 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@class SCAttachment;

/**
 Protocol used by controllers who wish to participate in, or influence, the behavior of any attachment controllers that may be present above it.
 
 @see SCAttachmentContainerViewController
 @see SCAttachmentController
 @see SCAttachment
 */
@protocol SCAttachmentOverlay <NSObject>

@optional

/**
 Message sent to the receiver to determine if the indicated attachment should be visible.
 
 @param attachment Attachment that may, or may not, be floating above the receiver.
 
 @return `YES` if the attachment should be visible, otherwise `NO`.
 */
- (BOOL)shouldShowAttachmentOverlay:(SCAttachment*)attachment;

/**
 Provides the receiver with the opportunity to return a relevant scroll view that should influence the behavior of attachments presented above it.
 
 @param attachment The attachment to determine.
 
 @return A UIScrollView instance that the attachment may be interested in, otherwise `nil`.
 */
- (UIScrollView *)scrollViewInfluencingAttachment:(SCAttachment*)attachment;

/**
 Indicates which subview, within the presented controller, should be used to constrain the alignment of the supplied attachment.  This can be used when a particular attachment must be constrained to a particular location within the screen.
 
 @param attachment The attachment to consider.
 @return The view to constrain the supplied attachment to, or `nil` if the attachment shouldn't be constrained to anything within the current controller.
 */
- (UIView*)viewToConstrainOverlayForAttachment:(SCAttachment*)attachment;

@end
