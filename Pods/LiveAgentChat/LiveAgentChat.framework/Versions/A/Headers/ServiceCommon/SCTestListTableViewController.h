//
//  SCTestListTableViewController.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 11/5/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#ifdef DEBUG
#import <UIKit/UIKit.h>

@class SCTestListTableViewController, SCTestApplicationDelegate;
@protocol SCTestViewController <NSObject>

@optional

+ (NSString*)titleForViewInTestList:(SCTestListTableViewController*)viewController;
+ (NSInteger)orderInTestList:(SCTestListTableViewController*)viewController;
+ (void)applicationStarting:(SCTestApplicationDelegate*)appDelegate;

@end

@interface SCTestListTableViewController : UITableViewController

@property (nonatomic, weak) UINavigationController *detailNavigationController;

@end
#endif