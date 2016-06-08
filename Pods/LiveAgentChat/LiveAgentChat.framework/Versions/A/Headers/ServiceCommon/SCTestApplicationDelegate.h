//
//  SCTestApplicationDelegate.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 11/5/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#ifdef DEBUG
#import <UIKit/UIKit.h>

@interface SCTestApplicationDelegate : NSObject<UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@end
#endif