//
//  UIImage+ServiceCommon.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 11/18/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Service Common convenience additions to UIImage.
 */
@interface UIImage (ServiceCommon)

/**
 Returns an arbitrary image from the filesystem using the standard [UIImage imageNamed:] method, automatically adding the necessary "../" relative path prefixes to ensure images not contained in the main application's bundle can still be loaded and cached within the system UIImage cache.
 
 This significantly improves performance and memory consumption when loading images.
 @param path            Path to the desired file.
 @param traitCollection Optional trait collection to use.
 @return Cached image for the file at the given path, or `nil` if none was found.
 */
+ (nullable UIImage *)imageAtRelativePath:(nonnull NSString *)path compatibleWithTraitCollection:(nullable UITraitCollection *)traitCollection;

@end
