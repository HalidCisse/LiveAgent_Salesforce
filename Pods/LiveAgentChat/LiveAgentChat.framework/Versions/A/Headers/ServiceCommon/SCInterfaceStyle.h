//
//  SSCAppearance.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 10/28/14.
//  Copyright (c) 2014 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SCCInternalDefines.h"

SC_PRIVATE_EXTERN NSString * const kSCAppearanceImageClose;
SC_PRIVATE_EXTERN NSString * const kSCAppearanceChevronArrow;
SC_PRIVATE_EXTERN NSString * const kSCAppearanceSubmitButtonChevronArrow;
SC_PRIVATE_EXTERN NSString * const kSCAppearanceSubmitButtonRotatedChevronArrow;
SC_PRIVATE_EXTERN NSString * const kSCAppearanceEmptyArticle;
SC_PRIVATE_EXTERN NSString * const kSCAppearanceEmptyCell;
SC_PRIVATE_EXTERN NSString * const kSCAppearanceNoConnection;
SC_PRIVATE_EXTERN NSString * const kSCAppearanceCaseSubmitSuccess;
SC_PRIVATE_EXTERN NSString * const kSCAppearanceDone;
SC_PRIVATE_EXTERN NSString * const kSCAppearanceSubcategoryIcon;
SC_PRIVATE_EXTERN NSString * const kSCAppearanceActionCasePublisher;
SC_PRIVATE_EXTERN NSString * const kSCAppearanceActionCaseList;
SC_PRIVATE_EXTERN NSString * const kSCAppearanceActionSearch;
SC_PRIVATE_EXTERN NSString * const kSCAppearancePicklistDropdown;
SC_PRIVATE_EXTERN NSString * const kSCAppearanceNoSearchResult;
SC_PRIVATE_EXTERN NSString * const kSCAppearanceSearchPlaceholder;

@class SCAppearanceConfiguration;

/**
 Abstract protocol defining the centralized way the application interface is constructed and managed.
 */
@protocol SCInterfaceStyle <NSObject>

@required

@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic, readonly, getter=isAppearanceApplied) BOOL appearanceApplied;

- (void)applyAppearance;
- (instancetype)initWithConfiguration:(SCAppearanceConfiguration*)configuration;

@optional

- (NSObject<UIViewControllerTransitioningDelegate>*)transitioningDelegateForController:(UIViewController*)controller;
- (void)applyStyleToPresentationController:(UIPresentationController*)presentationController;
- (UIImage*)imageForIdentifierName:(NSString *)name withTraitCollection:(UITraitCollection*)traitCollection;

@end
