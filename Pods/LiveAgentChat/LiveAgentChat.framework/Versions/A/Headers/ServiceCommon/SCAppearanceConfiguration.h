//
//  SCApperanceConfiguration.h
//  ServiceSDK
//
//  Created by Amit Gosar on 9/1/15.
//  Copyright (c) 2015 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SCCDefines.h"

NS_ASSUME_NONNULL_BEGIN

/// The primary brand color key, used for primary visual elements such as header colors.
SC_EXTERN NSString * const SCAppearancePrimaryBrandColor;

/// The secondary brand color key, used for action button colors.
SC_EXTERN NSString * const SCAppearanceSecondaryBrandColor;

/// The primary text color key, used for the majority of text.
SC_EXTERN NSString * const SCAppearancePrimaryTextColor;

/// The secondary text color key, used for sub category header text.
SC_EXTERN NSString * const SCAppearanceSecondaryTextColor;

/// The background brand color key, used for primary visual elements such as header colors.
SC_EXTERN NSString * const SCAppearanceBackgroundColor;

/// The overlay background brand color key, used for semi-transparent overlay colors.
SC_EXTERN NSString * const SCAppearanceOverlayColor;

/// The main background color key.
SC_EXTERN NSString * const SCAppearanceInputErrorTextColor;

/// The navigation background color key.
SC_EXTERN NSString * const SCAppearanceNavbarBackgroundColor;

/// The text color key used for header text.
SC_EXTERN NSString * const SCAppearanceTitleTextColor;

/// The text color key used for actionable labels, such as action buttons and case submit buttons.
SC_EXTERN NSString * const SCAppearanceCTAButtonForegroundColor;

/// The tertiary color key is a calculated value used for unselected article backgrounds, footer backgrounds, and other secondary areas.
/// The value is calculated by SCAppearanceBackgroundColor mixed with the SCAppearanceSecondaryTextColor with a 10% alpha applied.
SC_EXTERN NSString * const SCAppearanceTertiaryColor;

/// The quaternary color key is a calculated value used for the tint coloring of accessory images.
/// This value is calculated by SCAppearanceBackgroundColor mixed with the SCAppearanceSecondaryTextColor with a 50% alpha applied.
SC_EXTERN NSString * const SCAppearanceQuaternaryColor;

@class SCAppearanceConfiguration;

/* SCFontWeight */
SC_EXTERN NSInteger const SCFontWeightLight;
SC_EXTERN NSInteger const SCFontWeightRegular;
SC_EXTERN NSInteger const SCFontWeightBold;

/**
 Delegate protocol for responding to style and branding customization requests at runtime.
 */
@protocol SCAppearanceConfigurationDelegate <NSObject>

@optional

/**
 Informs the receiver when appearance configuration updates will be applied.
 @param configuration The appearance configuration to be applied.
 */
- (void)appearanceConfigurationWillApplyUpdates:(SCAppearanceConfiguration*)configuration;

/**
 Informs the receiver when appearance configuration updates have been applied.
 @param configuration The appearance configuration that was applied.
 */
- (void)appearanceConfigurationDidApplyUpdates:(SCAppearanceConfiguration*)configuration;

@end

/**
 Configuration class used to customize the various settings that influences the branding and coloring of the various UI elements used in Service Cloud Kit.
 */
@interface SCAppearanceConfiguration : NSObject

/**
 The appearance delegate, used for branding customization
 @see SCAppearanceConfigurationDelegate
 */
@property (nonatomic, weak, nullable) NSObject<SCAppearanceConfigurationDelegate> *delegate;

/**
 Property indicating whether or not any UIAppearance settings have been applied from this configuration instance.
 */
@property (nonatomic, readonly, getter=isAppearanceApplied) BOOL appearanceApplied;

/**
 Controls whether or not the UIAppearance selectors need to be updated.

 @see applyAppearanceUpdatesIfNeeded
 */
- (void)setNeedsAppearanceUpdates;

/**
 Updates the UIAppearance selectors to reflect the current state of the configuration object.
 
 This method can be used to force appearance updates to occur at a particular time, or if there is cause for some branding changes to be reapplied.  Note that updates will only be applied if the appearance settings have indeed changed.
 
 @see setNeedsAppearanceUpdates
 */
- (void)applyAppearanceUpdatesIfNeeded;

@end

@interface SCAppearanceConfiguration (Colors)

/**
 Sets the color for one of the name from SCAppearanceConfiguration constants.

 @param color The color to set.
 @param name  The branding token name to set the color for.
 */
- (void)setColor:(UIColor*)color forName:(NSString*)name;

/**
 Returns the color set by `setColor:forName:` method or default for the specified name from SCAppearanceConfiguration constants.
 
 If no color was explicitly assigned, a default color will be provided, if applicable for the given branding token.
 
 @param name The branding token name to retrieve a color for.
 @return The color associated with that branding token, or `nil` if the branding token name was invalid.
 */
- (nullable UIColor*)colorForName:(NSString*)name;

@end

@interface SCAppearanceConfiguration (Images)

/**
 Sets the image for one of the name from SCAppearanceConfiguration constants
 
 @param image           The image to set.
 @param traitCollection The trait collection the image will be used for, if applicable.
 @param name            The branding token name to set the image for.
 */
- (void)setImage:(UIImage*)image compatibleWithTraitCollection:(nullable UITraitCollection *)traitCollection forName:(NSString*)name;

/**
 Returns the image set by `setImage:forName:` method or default for the specified name from SCAppearanceConfiguration constants.
 
 If no image was explicitly assigned, a default image will be provided, if applicable for the given branding token.
 
 @param name            The image name to retrieve an image for.
 @param traitCollection The trait collection the image will be used for, if applicable.
 */
- (nullable UIImage*)imageForName:(NSString*)name compatibleWithTraitCollection:(nullable UITraitCollection *)traitCollection;

@end

@interface SCAppearanceConfiguration (Fonts)

/**
 Sets fontDescriptor for specified weight which will be used to create and set UIFont on the labels.
 If UIFontDescriptorSizeAttribute is set on the fontDescriptor, it will be used to set the font size.
 If not, ServiceSDK will set the font size appropriately.
 
 @param fontDescriptor UIFontDescriptor instance to be used for creating UIFont.
 @param fileName Name of the font file contained in the Bundle.
 @param weight A value from SCFontWeight enum.
 */
- (void)setFontDescriptor:(UIFontDescriptor*)fontDescriptor fontFileName:(nullable NSString*)fileName forWeight:(NSInteger)weight;

/**
 Returns the fontDescriptor for the weight if one was set by the host application.
 Otherwise it returns the default:
 'Helvetica Neue - Light' for SCFontWeightLight,
 'Helvetica Neue' for SCFontWeightRegular,
 'Helvetica Neue - Semibold' for SCFontWeightBold.

 @param weight A value from SCFontWeight enum.
 */
- (UIFontDescriptor*)getFontDescriptorForWeight:(NSInteger)weight;

- (nullable NSString*)getFontFileNameForWeight:(NSInteger)weight;

@end

NS_ASSUME_NONNULL_END

