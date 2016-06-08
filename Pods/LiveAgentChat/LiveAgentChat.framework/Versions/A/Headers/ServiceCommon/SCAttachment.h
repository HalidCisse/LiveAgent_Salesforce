//
//  SCAttachment.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 8/12/15.
//  Copyright (c) 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Attachment animation operation types that may be supplied to [SCAttachmentController animationControllerForAttachment:forTransitionOperation:].
 */
typedef NS_ENUM(NSInteger, SCAttachmentControllerOperation) {
    /** No transition is occurring. */
    SCAttachmentControllerOperationNone,

    /** The attachment controller will be shown. */
    SCAttachmentControllerOperationShow,

    /** The attachment controller will be hidden. */
    SCAttachmentControllerOperationHide,
};

@class SCAttachment;

/**
 Protocol used to define controllers that are capable of being bound to an attachment.
 
 All methods defined within this protocol are optional, but can be adopted individually to provide the controller with more influence over how it interacts with the view controllers surrounding it.
 */
@protocol SCAttachmentController <NSObject>

@optional

/**
 If the receiver is capable of interacting with scroll views, this method should return `YES`.  Otherwise the default is to skip this controller when working with scroll views.
 
 @warning It is a programmer error if only one of interactsWithOverlayScrollViews: or setOverlayScrollView: is implemented by the receiver
 @return `YES` if this attachment should be notified when a scroll view is availabile, otherwise `NO`.
 @see -[SCAttachmentOverlay scrollViewInfluencingAttachment]
 */
- (BOOL)interactsWithOverlayScrollViews;

/**
 Message sent to the receiver when the active overlay scroll view changes.
 
 @warning It is a programmer error if only one of interactsWithOverlayScrollViews: or setOverlayScrollView: is implemented by the receiver
 @param scrollView New primary scroll view, or `nil` if no primary scroll view is present.
 @see interactsWithOverlayScrollViews
 */
- (void)setOverlayScrollView:(nullable UIScrollView*)scrollView;

/**
 Indicates which level this attachment should be shown in within the view hierarchy.
 
 If this method is not implemented, a default value of `0.0` is assumed.  Higher number values results in the attachment being placed above others with lower values.
 */
- (CGFloat)attachmentLevel;

/**
 Optional method allowing a controller to customize the appearance transition for its associated attachment.
 
 @param attachment The attachement being animated.
 @param operation  The style of transition operation being performed.
 @return Animator instance conforming to UIViewControllerAnimatedTransitioning, or `nil` for a default transition.
 @see SCAttachment
 */
- (nullable id <UIViewControllerAnimatedTransitioning>)animationControllerForAttachment:(SCAttachment*)attachment
                                                                 forTransitionOperation:(SCAttachmentControllerOperation)operation;

@end

@class SCAttachmentContainerViewController;

/**
 This class represents a view that can be attached to a SCAttachmentContainerViewController instance.  These views are the containers that manage the position and behaviors of child controllers that can be presented omnipresently over other controllers.
 
 Attachments are specialized views that represents a child controller which can be positioned at arbitrary locations on the screen, presented in an omnipresent fashion above all other controllers.  These attachments encapsulate the logic of that positioning, and has facilities to interact with the controllers around it.
 
 These attachments need to be initialized with a view controller that conforms to the SCAttachmentController protocol.  These attachments then respond and behave in different ways depending on which view controllers are presented on the screen (either modally, within navigation controllers, etc).  Those controllers may optionally conform to the SCAttachmentOverlay protocol to indicate which attachments are capable of being presented along side them.
 */
@interface SCAttachment : UIView

/**
 Access to the controller supplied to the initializer.  Setting this value will result in that new controller being presented within this attachment.
 @see SCAttachmentController
 */
@property (nonatomic, strong, nullable) UIViewController<SCAttachmentController> *controller;

/**
 Convenience property to refer to the parent attachment container controller.
 
 @see SCAttachmentContainerViewController
 */
@property (nonatomic, weak, readonly) SCAttachmentContainerViewController *attachmentContainerController;

/**
 Name to identify this attachment by.  Can be used in conjunction with [SCAttachmentContainerViewController attachmentWithName:].
 */
@property (nonatomic, copy, nullable) NSString *name;

/**
 Optional view within the view hierarchy to constrain, or align, this attachment to.  If this value is `nil`, the attachment will be positioned relative to the window.
 
 If a controller is presented that implements the [SCAttachmentOverlay viewToConstrainOverlayForAttachment:] method, it may cause this property to change, allowing attachments to be aligned relative to a different view or controller within the hierarchy.  When that happens, this value will change, and the Auto Layout constraints will be updated.
 */
@property (nonatomic, weak, nullable) UIView *alignmentView;

/**
 Boolean property indicating whether or not the controller within this attachment is dismissed.  When an attachment is dismissed, it is still present within the view hierarchy, but the controller contained within it is dismissed.  That controller's appearance methods will be called as appropriate to indicate when the views will disappear, or when they reappear.
 
 Setting this value will perform a non-animated transition.  To perform an animated transition, see the setDismissed:animated: method.
 
 This value defaults to `YES`.
 */
@property (nonatomic, assign, getter=isDismissed) BOOL dismissed;

/**
 Designated initializer.
 
 @param controller Child controller to attach to the floating root controller.  Must conform to SCAttachmentController.
 @return Initialized object
 @see SCAttachmentController
 */
- (instancetype)initWithController:(UIViewController<SCAttachmentController>*)controller NS_DESIGNATED_INITIALIZER;

/**
 Performs an animated update to hide or show the attachment; the default doesn't perform an animation.
 
 @param dismissed `YES` if the view should be hidden, otherwise `NO`
 @param animated  `YES` to animate the visibility change.
 @see dismissed
 */
- (void)setDismissed:(BOOL)dismissed animated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END

