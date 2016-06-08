//
//  SCServiceCloud.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 11/12/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SCServiceCloudDelegate;
@class SCAppearanceConfiguration;


/**
 Shared singleton class used as the primary access point for developers to interact with Service Cloud Kit.
 
 This is used to configure the interface elements, and visual customization of the interface.
 */
@interface SCServiceCloud : NSObject

/**
 Returns the shared service cloud manager for this process.
 
 @return Initialized shared instace.
 */
+ (instancetype)sharedInstance;

/**
 Identifies the primary window where view controllers should be placed when presented.
 
 @discussion
 This value will automatically be determined under most circumstances, but in the event that a custom value needs to be set, the primaryWindow property can be set to a specific window that should be used.
 */
@property (nonatomic, strong) UIWindow *primaryWindow;

/**
 The delegate of the service interface manager.
 @see SCServiceCloudDelegate
 */
@property (nonatomic, weak, nullable) NSObject<SCServiceCloudDelegate> *delegate;

/**
 The appearance style to use in presented views and view controllers.
 
 @discussion
 The default value for this is `SCInterfaceStyleDefault`.  If this value is set after the interface has already been presented, it will result in the service interface being dismissed.
 
 @warning
 It is recommended that you only assign this property once in the lifetime of an application.  Changing interface styles at runtime may have unpredictable results, and the behavior is undefined.
 */
@property (nonatomic, copy) NSString *interfaceStyle;

/**
 Sets the apperance configuration for the service interface. If not specified, this value falls back to default values.
 @see SCAppearanceConfiguration
 */
@property (nonatomic, strong) SCAppearanceConfiguration *appearanceConfiguration;

@end

NS_ASSUME_NONNULL_END