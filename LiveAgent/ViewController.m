//
//  ViewController.m
//  LiveAgent
//
//  Created by Halid Cisse on 6/8/16.
//  Copyright © 2016 Halid Cisse. All rights reserved.
//

#import "ViewController.h"
#import <LiveAgentChat/LiveAgentChat.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    // LACSessionManager is a singleton, the behavior of a session can be configured using an
    // LACOptions object you pass into the startSessionWithOptions: method.
    
    LACOptions *opts = [LACOptions optionsWithLiveAgentPod:@"https://d.la1-c1-frf.salesforceliveagent.com" // the hostname for the LiveAgent pod that your organization has been assigned.
                                                     orgId:@"00D58000000OwMB" // the Salesforce organization id.
                                              deploymentId:@"57258000000L1mj" // the unique id of the deployment for this session.
                                                  buttonId:@"57358000000L24F"]; // The unique id represent a chat configuration.
                        
                        
                        // You can configure the options object to take any number of Pre Chat fields. Pre Chat fields are required by default but can be set to optional.
                        // Required email field
                        [[opts prechatDetails] addObject:[LACCustomDetail customDetailWithLabel:@"Email" placeholder:@"Please enter your email" transcriptFields:@[@"c.__email"]]];
                        
                        // Optional name field.
                        [[opts prechatDetails] addObject:[LACCustomDetail customDetailWithLabel:@"Name" placeholder:@"Please enter your full name" transcriptFields:@[@"c.__filler"] required:NO]];
                        
                        // Start the session
 [[LACSessionManager sharedInstance] startSessionWithOptions:opts];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
