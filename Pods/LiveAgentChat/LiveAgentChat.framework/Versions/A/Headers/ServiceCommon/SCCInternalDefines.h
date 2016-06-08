//
//  SCCInternalDefines.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 11/11/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef SC_PRIVATE_EXTERN
#ifdef __cplusplus
#define SC_PRIVATE_EXTERN   extern "C" __attribute__((visibility ("default")))
#else
#define SC_PRIVATE_EXTERN   extern __attribute__((visibility ("default")))
#endif
#endif

/// Notifications
SC_PRIVATE_EXTERN NSString * const SCUViewControllerWillAppearNotification;
SC_PRIVATE_EXTERN NSString * const SCUViewControllerDidAppearNotification;
SC_PRIVATE_EXTERN NSString * const SCUViewControllerWillDismissNotification;
SC_PRIVATE_EXTERN NSString * const SCUViewControllerDidDismissNotification;
SC_PRIVATE_EXTERN NSString * const SCContentStyleChangedNotification;
SC_PRIVATE_EXTERN NSString * const SCInterfaceStyleChangedNotification;

/**
 Notification sent when the appearance configuration is changed.

 The object included in the notification is the SCAppearanceConfiguration object.
 */
SC_PRIVATE_EXTERN NSString * const SCAppearanceConfigurationChangedNotification;

/**
 Notification sent when the appearance configuration is applied.  This may be dispatched multiple times if the appearance configuration changes.
 
 The object included in the notification is the SCAppearanceConfiguration object.
 */
SC_PRIVATE_EXTERN NSString * const SCAppearanceConfigurationAppliedNotification;

/// Interaction Events

// KnowledgeUI
SC_PRIVATE_EXTERN NSString * const SCUServiceEventCategoryListItem;
SC_PRIVATE_EXTERN NSString * const SCUServiceEventArticleListItem;
SC_PRIVATE_EXTERN NSString * const SCUServiceEventSupportHomeShowMore;
SC_PRIVATE_EXTERN NSString * const SCUServiceEventArticleList;
SC_PRIVATE_EXTERN NSString * const SCUServiceEventShowSearch;

// CaseUI
SC_PRIVATE_EXTERN NSString * const SCUServiceEventShowCasePublisher;

//User change
SC_PRIVATE_EXTERN NSString * const SCUServiceUserAccountChangedNotification;

#ifndef SCLog
#define SCLog(fmt, ...) NSLog(fmt, ##__VA_ARGS__);
#endif

SC_PRIVATE_EXTERN id SCUNibInstanceFromClass(Class callerClass);

typedef enum : NSUInteger {
    SCAnimationTypePresent,
    SCAnimationTypeDismiss,
} SCAnimationType;
