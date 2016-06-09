//
//  ViewController.m
//  LiveAgent
//
//  Created by Halid Cisse on 6/9/16.
//  Copyright © 2016 Halid Cisse. All rights reserved.
//

#import "ViewController.h"
#import <LiveAgentChat/LiveAgentChat.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    //[super viewDidLoad];
    // LACSessionManager is a singleton, the behavior of a session can be configured using an
    // LACOptions object you pass into the startSessionWithOptions: method.
    
    LACOptions *opts = [LACOptions
                        optionsWithLiveAgentPod:@"d.la1-c1-frf.salesforceliveagent.com/"
                        orgId:@"00D58000000OwMB"
                        deploymentId:@"57258000000L1mj"
                        buttonId:@"57358000000L24F"];
    
                        [[opts prechatDetails] addObject:[LACCustomDetail customDetailWithLabel:@"Email" placeholder:@"Please enter your email" transcriptFields:@[@"c.__email"]]];
                        
                        [[opts prechatDetails] addObject:[LACCustomDetail customDetailWithLabel:@"Name" placeholder:@"Please enter your full name" transcriptFields:@[@"c.__filler"] required:NO]];
                        
                        // Start the session
                        [[LACSessionManager sharedInstance] startSessionWithOptions:opts];
    //LACSessionManager *session = [[LACSessionManager alloc] init];
    
    //[session startSessionWithOptions: opts];
    //[session stopSession];
    
//    [session startSessionWithOptions:opts
//             completion:^(NSError *error, LACSessionManager *__weak lac)
//    {
//        
//    }];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
