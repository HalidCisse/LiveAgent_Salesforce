//
//  SCUApperanceConfiguration_Internal.h
//  ServiceSDK
//
//  Created by Amit Gosar on 9/1/15.
//  Copyright (c) 2015 Salesforce.com. All rights reserved.
//

extern NSString * SCStringValueForFontWeight(NSInteger type);
extern NSInteger SCFontWeightTypeForFontWeightName(NSString *name);

@interface SCAppearanceConfiguration (FontsInternal)

// TODO: These methods will go away one I have an opportunity to clean up the CSS/font handling of articles
- (UIFont*)fontForWeight:(NSInteger)weight pointSize:(CGFloat)size;
- (NSString*)getDefaultFontFamily;

@end
