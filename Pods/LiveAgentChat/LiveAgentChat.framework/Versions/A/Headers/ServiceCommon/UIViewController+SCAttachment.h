//
//  UIViewController+SCAttachment.h
//  KnowledgeUI
//
//  Created by Michael Nachbaur on 10/30/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@class SCAttachment;

/** Category that adds some convenience methods for view controllers that interact with SCAttachment instances
 */
@interface UIViewController (SCAttachment)

/** Convenience reference to a view controller's parent attachment instance, if it is currently assigned to one.
 */
@property (nonatomic, weak, readonly, nullable) SCAttachment *parentAttachment;

@end
