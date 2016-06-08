//
//  SCAttachment_Internal.h
//  KnowledgeUI
//
//  Created by Michael Nachbaur on 10/29/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#import "SCAttachment.h"
#import "SCAnimationContext.h"

static const void * kAssociatedParentAttachment;

@interface SCAttachment ()

@property (nonatomic, weak, readwrite) SCAttachmentContainerViewController *attachmentContainerController;

- (id <UIViewControllerAnimatedTransitioning>)defaultAnimationControllerForAttachmentForTransitionOperation:(SCAttachmentControllerOperation)operation;
- (SCAnimationContext*)animationContextForTransitionOperation:(SCAttachmentControllerOperation)operation;
- (CGFloat)_attachmentLevel;

@end
