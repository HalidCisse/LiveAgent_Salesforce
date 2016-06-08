//
//  SCEdgeContainerViewController.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 8/11/15.
//  Copyright (c) 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SCAttachment;

/**
 View controller that's capable of manipulating multiple child view controllers, managed through "Attachment" views.  These view objects can be automatically positioned and manipulated according to their own internal rules, accessed by name, removed or otherwise manipulated.  It provides an abstract base for a set of controllers that can be manipulated on-screen in unconventional ways without unnecessarily complex one-off code.
 
 This controller is meant to be used as the root view controller of a UIWindow instance.  By default it doesn't present any content, and permits all touches to pass through, allowing it to safely float above other windows.  When SCAttachment instances are added using addAttachment:, the view controller represented by that attachment can be positioned on the screen in whatever way is defined by that attachment.
 
 When used in conjunction with SCFloatingRootWindow, these attachments can be visible over other view controllers, regardless of how they're presented (e.g. modally, within navigation or split view controllers, etc).  View controllers presented on-screen in such a fashion can optionally conform to SCAttachmentOverlay to control which attachments should be visible, and how those attachments may interact with those controllers.
 */
@interface SCAttachmentContainerViewController : UIViewController

/**
 Array of attachments currently within this container.  KVO notifications are sent when attachments are added or removed.
 
 @see addAttachment:
 @see removeAttachment:
 @see SCAttachment
 */
@property (nonatomic, strong, readonly) NSArray *attachments;

/**
 Adds the indicated attachment.
 
 The controller bound to the supplied attachment is automatically added as a child controller.
 
 @param attachment Attachment to add.
 @see SCAttachment
 */
- (void)addAttachment:(SCAttachment*)attachment;

/**
 Removes the supplied attachment.
 
 The controller bound to the attachment is automatically removed as a child controller.

 @param attachment Attachment to remove.
 @see SCAttachment
 */
- (void)removeAttachment:(SCAttachment*)attachment;

/**
 Returns the attachment with the given name.
 
 @param name Name to search for.
 
 @return Attachment matching this name, otherwise `nil` if no matching attachments are found.
 @see SCAttachment
 */
- (nullable SCAttachment*)attachmentWithName:(NSString*)name;

/**
 Returns the attachment bound to the supplied controller
 
 @param controller Controller to search for.
 
 @return Attachment bound to the indicated controller, otherwise `nil`.
 @see SCAttachment
 */
- (nullable SCAttachment*)attachmentForController:(UIViewController*)controller;

@end

NS_ASSUME_NONNULL_END
