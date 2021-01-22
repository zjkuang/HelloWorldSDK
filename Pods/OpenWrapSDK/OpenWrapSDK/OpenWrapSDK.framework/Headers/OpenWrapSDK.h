/*
* PubMatic Inc. ("PubMatic") CONFIDENTIAL
* Unpublished Copyright (c) 2006-2020 PubMatic, All Rights Reserved.
*
* NOTICE:  All information contained herein is, and remains the property of PubMatic. The intellectual and technical concepts contained
* herein are proprietary to PubMatic and may be covered by U.S. and Foreign Patents, patents in process, and are protected by trade secret or copyright law.
* Dissemination of this information or reproduction of this material is strictly forbidden unless prior written permission is obtained
* from PubMatic.  Access to the source code contained herein is hereby forbidden to anyone except current PubMatic employees, managers or contractors who have executed
* Confidentiality and Non-disclosure agreements explicitly covering such access or to such other persons whom are directly authorized by PubMatic to access the source code and are subject to confidentiality and nondisclosure obligations with respect to the source code.
*
* The copyright notice above does not evidence any actual or intended publication or disclosure  of  this source code, which includes
* information that is confidential and/or proprietary, and is a trade secret, of  PubMatic.   ANY REPRODUCTION, MODIFICATION, DISTRIBUTION, PUBLIC  PERFORMANCE,
* OR PUBLIC DISPLAY OF OR THROUGH USE  OF THIS  SOURCE CODE  WITHOUT  THE EXPRESS WRITTEN CONSENT OF PUBMATIC IS STRICTLY PROHIBITED, AND IN VIOLATION OF APPLICABLE
* LAWS AND INTERNATIONAL TREATIES.  THE RECEIPT OR POSSESSION OF  THIS SOURCE CODE AND/OR RELATED INFORMATION DOES NOT CONVEY OR IMPLY ANY RIGHTS
* TO REPRODUCE, DISCLOSE OR DISTRIBUTE ITS CONTENTS, OR TO MANUFACTURE, USE, OR SELL ANYTHING THAT IT  MAY DESCRIBE, IN WHOLE OR IN PART.
*/

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "POBAdRendering.h"
#import "POBApplicationInfo.h"
#import "POBAuctioning.h"
#import "POBBannerEvent.h"
#import "POBBannerView.h"
#import "POBBid.h"
#import "POBBidderProvider.h"
#import "POBBidding.h"
#import "POBBiddingPartnerService.h"
#import "POBBidEvent.h"
#import "POBCustomRendererProvider.h"
#import "POBDataTypes.h"
#import "POBImpression.h"
#import "POBInterstitial.h"
#import "POBInterstitialEvent.h"
#import "POBRequest.h"
#import "POBReward.h"
#import "POBRewardedAd.h"
#import "POBRewardedAdEvent.h"
#import "POBRewardedAdEventDelegate.h"
#import "POBUserInfo.h"

//! Project version number for OpenWrapSDK.
FOUNDATION_EXPORT double OpenWrapSDKVersionNumber;

//! Project version string for OpenWrapSDK.
FOUNDATION_EXPORT const unsigned char OpenWrapSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <OpenWrapSDK/PublicHeader.h>

/*!
 *  Log levels to filter logs.
 */
typedef NS_ENUM(NSUInteger, POBSDKLogLevel){
    /**
     *  No logs
     */
    POBSDKLogLevelOff       = 0,
    
    /**
     *  Error logs only
     */
    POBSDKLogLevelError,
    
    /**
     *  Error and warning logs
     */
    POBSDKLogLevelWarning,
    
    /**
     *  Error, warning and info logs
     */
    POBSDKLogLevelInfo,
    
    /**
     *  Error, warning, info and debug logs
     */
    POBSDKLogLevelDebug,
    
    /**
     *  Error, warning, info, debug and verbose logs
     */
    POBSDKLogLevelVerbose,
    
    /**
     *  All logs
     */
    POBSDKLogLevelAll,
};

/*!
Location source
*/
typedef NS_ENUM(NSInteger, POBLocSource)  {
    
    /// Location is determined from GPS
    POBLocSourceGPS = 1,
    /// Location is determined from IP address
    POBLocSourceIPAddress,
    /// Location is provided by user
    POBLocSourceUserProvided
    
};

/*!
 ------------------------------------------------------------------------------------
 OpenWrapSDK Class
 ------------------------------------------------------------------------------------
 */

/*!
 Provides global configurations for the OpenWrap SDK, e.g. enabling logging, location access, GDPR, etc. These configurations are globally applicable for OpenWrap SDK; you don't have to set these for every ad request.
 */
@interface OpenWrapSDK : NSObject


/**
 ------------------------------------------------------------------------------------
 @name Instance Methods
 ------------------------------------------------------------------------------------
 */

/*!
 @abstract Returns the OpenWrap SDK's version.
 */
+ (NSString*)version;

/*!
 @abstract Sets log level across all ad formats. Default log level is POBSDKLogLevelWarn
 @param logLevel log level to set.
 @see POBSDKLogLevel
 */
+ (void)setLogLevel:(POBSDKLogLevel)logLevel;

/*!
 
 @abstract Sets GDPR compliance, it indicates whether or not the ad request is GDPR(General Data Protection Regulation) compliant.
 @param gdprEnabled boolean value
 - YES : indicates GDPR compliant requests
 - NO : indicates that the request is not GDPR compliant
 
 By default, this parameter is omitted in the ad request, indicating Unknown.
 */
+ (void)setGDPREnabled:(BOOL)gdprEnabled;

/*!
 @abstract Sets GDPR consent string, A valid Base64 encoded consent string as per https://github.com/InteractiveAdvertisingBureau/GDPR-Transparency-and-Consent-Framework.
 @discussion The user consent string is optional, but highly recommended if the request is subject to GDPR regulations (i.e. gdpr = YES). The default sense of consent under GDPR is “opt-out” and as such, an omitted consent string in a request subject to GDPR would be interpreted as equivalent to the user fully opting out of all defined purposes for data use by all parties.
 @param gdprConsent consent string to convey user consent when GDPR regulations are in effect.
 */
+ (void)setGDPRConsent:(NSString *)gdprConsent;

/*!
 @abstract Used to enable/disable location access.
 @discussion This value decides whether the OpenWrap SDK should access device location usings Core Location APIs to serve location-based ads. When set to NO, the SDK will not attempt to access device location. When set to YES, the SDK will periodically try to fetch location efficiently.
 Note that, this only occurs if location services are enabled and the user has already authorized the use of location services for the application. The OpenWrap SDK never asks permission to use location services by itself.
 
 The default value is YES.
 
 @param allow YES/NO value
 */
+ (void)allowLocationAccess:(BOOL)allow;

/*!
 @abstract Tells OpenWrap SDK to use internal SDK browser, instead of the default device browser, for opening landing pages when the user clicks on an ad.
 By default, use of internal browser is enabled.
 @param use BOOL value that enables/disables the use of internal browser.
 */
+ (void)useInternalBrowser:(BOOL)use;

/*!
 @abstract Sets user's location and its source. It is useful in delivering geographically relevant ads.
 @discussion
 If your application is already accessing the device location, it is highly recommended to set the location coordinates inferred from the device GPS. If you are inferring location from any other source, make sure you set the appropriate location source.
 
 @see POBLocSource
 @param location User's current location
 @param source Source of user's location.
 */
+ (void)setLocation:(CLLocation *)location source:(POBLocSource)source;

/*!
 @abstract Indicates whether the visitor is COPPA-specific or not. For COPPA (Children's Online Privacy Protection Act) compliance, if the visitor's age is below 13, then such visitors should not be served targeted ads.

 @param enable boolean value

 - No : Indicates that the visitor is not COPPA-specific and can be served targeted ads.
 - Yes : Indicates that the visitor is COPPA-specific and should be served only COPPA-compliant ads.
 */
+ (void)setCoppaEnabled:(BOOL)enable;

/*!
 @abstract Enable/disable secure ad calls.
 @discussion By default, OpenWrap SDK initiates secure ad calls from an application to the ad server and delivers only secure ads. You can allow non secure ads by passing NO to this method.
 
 @param enable boolean value
 */
+ (void)setSSLEnabled:(BOOL)enable;

/*!
 @abstract Indicates whether Advertisment ID(IDFA) should be sent in the request. 
 
 @param allow boolean value

 - YES : Advertising Identifier will be sent in the request.
 - NO : Advertising Identifier will be masked in the request.
 
 */
+ (void)allowAdvertisingId:(BOOL)allow;

/*!
 @abstract Sets Application information, which contains various attributes about app, such as application category, store URL, domain, etc, for more relevant ads.
 @param appInfo Appication object having user related information
 @see POBApplicationInfo
 */
+ (void)setApplicationInfo:(POBApplicationInfo *)appInfo;

/*!
 @abstract Sets user information, such as birth year, gender, region, etc, for more relevant ads.
 @param userInfo User object having user related information
 @see POBUserInfo
 */
+ (void)setUserInfo:(POBUserInfo *)userInfo;

/*!
@abstract Set the CCPA compliant string, it helps publisher toward compliance with the California Consumer Privacy Act (CCPA).

@discussion For more details refer https://www.iab.com/guidelines/ccpa-framework/

Make sure that the string value you use is compliant with the IAB Specification, refer https://iabtechlab.com/wp-content/uploads/2019/11/U.S.-Privacy-String-v1.0-IAB-Tech-Lab.pdf

If this is not set, SDK looks for app's NSUserDefault with key 'IABUSPrivacy_String'
If CCPA is applied through both options, the SDK will honour only API property.
If both are not set then CCPA parameter is omitted from an ad request.
 
@param ccpaString is the CCPA compliant string
*/
+ (void)setCCPA:(NSString *)ccpaString;

@end
