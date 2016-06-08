//
//  SCCDefines.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 11/4/15.
//  Copyright © 2015 Salesforce.com. All rights reserved.
//

#ifndef __SCCDefines_h__
#define __SCCDefines_h__

#import <Foundation/Foundation.h>

#ifndef SC_EXTERN
#ifdef __cplusplus
#define SC_EXTERN   extern "C" __attribute__((visibility ("default")))
#else
#define SC_EXTERN   extern __attribute__((visibility ("default")))
#endif
#endif

SC_EXTERN NSString * const SCInterfaceStyleDefault;

#endif

// Authentication
SC_EXTERN NSString * const SCServiceTypeCases;
SC_EXTERN NSString * const SCServiceTypeKnowledge;
SC_EXTERN NSString * const SCServiceCloudErrorDomain;
SC_EXTERN NSString * const SCSOAuthInvalidSessionId;

// Error Domain
SC_EXTERN NSString * const SCServiceErrorDomain;

typedef NS_ENUM(NSInteger, SCServiceErrorCode) {
    SCServiceUserAccountNilError,
    SCServiceUserSessionExpiredError,
    SCServiceUserAccountInvalidError
};