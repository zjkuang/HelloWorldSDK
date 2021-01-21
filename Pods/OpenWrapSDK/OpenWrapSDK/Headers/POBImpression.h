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
#import "POBDataTypes.h"

extern NSString *const kImpressionSecureParam;
extern NSString *const kImpressionIDParam;
extern NSString *const kRTBBannerParam;
extern NSString *const kRTBVideoParam;
extern NSString *const kPositionParam;
extern NSString *const kRTBInstlParam;
extern NSString *const kRTBFormatParam;
extern NSString *const kRTBWidthParam;
extern NSString *const kRTBHeightParam;
extern NSString *const kRTBAPIParam;
extern NSString *const kRTBImpExtBidderParam;
extern NSString *const kRTBImpExtParam;
extern NSString *const kPMZoneIdParam;
extern NSString *const kKeyParam;
extern NSString *const kValueParam;
extern NSString *const kExtPubParam;
extern NSString *const kKeywordParam;
extern NSString *const kRTBDisplayManagerVerParam;
extern NSString *const kRTBDisplayManagerParam;
extern NSString *const kRTBTagIdParam;

//Video obj params
extern NSString *const kRTBMIMETypesParam;
extern NSString *const kRTBProtocolsParam;
extern NSString *const kRTBPlacementParam;
extern NSString *const kRTBminBitRateParam;
extern NSString *const kRTBLinearityParam;
extern NSString *const kRTBBoxingAllowedParam;
extern NSString *const kRTBDeliveryParam;
extern NSString *const kRTBCompanionAdParam;
extern NSString *const kRTBCompanionTypeParam;
extern NSString *const kRTBPlaybackEndParam;
extern NSString *const kRTBStartDelay;

@class POBBanner, POBVideo;
/*!
 Fold placement of the ad to be served.
 */
typedef NS_ENUM(NSInteger, POBAdPosition) {
    
    /**
     * Unable to determine the ad position, use this value
     */
    POBAdPositionUnKnown,
    
    /**
     * Ad position is visible
     */
    POBAdPositionAboveFold,
    
    /**
     * Ad position is not visible & it needs user to scroll the page to make it visible
     */
    POBAdPositionBelowFold = 3,
    
    /**
     * Header position
     */
    POBAdPositionHeader,
    
    /**
     * Footer position
     */
    POBAdPositionFooter,
    
    /**
     * In side menu
     */
    POBAdPositionSidebar,
    
    /**
     * Ad is in full screen
     */
    POBAdPositionFullscreen
};

/*!
 ------------------------------------------------------------------------------------
 POBImpression Class
 ------------------------------------------------------------------------------------
 */

/*!
 Holds the general information about an ad impression. Use this class setters to pass impression level information in bid request.
 */
@interface POBImpression : NSObject

/**
 ------------------------------------------------------------------------------------
 @name Instance Methods
 ------------------------------------------------------------------------------------
 */

/*!
 @abstract Initializes POBImpression object with given impression details
 @param impId Unique identifier of the impression
 @param adUnitId The unique identifier which represents an ad placement on the app screen. This is the one you defined while creating profile mappings on the OpenWrap dashboard.
 @result Instance of POBImpression
 @warning This class serves as base for other concrete impression classes, do not directly create an instance of this class
 */
- (instancetype)initWithImpressionId:(NSString *)impId
                            adUnitId:(NSString *)adUnitId;

/*!
 @abstract Checks if the impression is valid
 @result YES/NO value
 */
- (BOOL)isValid;

@property(nonatomic, strong) POBBanner *banner;

@property(nonatomic, assign, getter=isInterstitial) BOOL interstitial;

@property(nonatomic, strong) POBVideo *video;

/**
 ------------------------------------------------------------------------------------
 @name Properties
 ------------------------------------------------------------------------------------
 */

/*!
 @abstract This parameter is used to hold impression identifier
 */
@property(nonatomic, readonly) NSString *impressionId;

/*!
 @abstract The unique identifier which represents an ad placement on the app screen. This is the one you defined while creating profile mappings on the OpenWrap dashboard.
 */
@property(nonatomic, readonly) NSString *adUnitId;

/*!
 @abstract This parameter is used to pass a zone ID for reporting.
 */
@property(nonatomic, strong) NSString *pmZoneId;

/*!
 @abstract This parameter is used to request a test creative.
 */
@property(nonatomic, strong) NSString *testCreativeId;

/*!
 @abstract Fold placement of the ad to be served.
 Note: If you are unable to determine it, you can set the default value as Unknown in
 this parameter.
 @see POBAdPosition
 */
@property(nonatomic, assign) POBAdPosition adPosition;

/*!
 @abstract Sets custom parameters in the form of a dictionary, to set multiple values against same key, use array.
 
 @warning Only use string or array of string as values
 
 Exmaple :
 
 customParams = @{@"hobbies":@[@"sports",@"reading"],@"age":@"22"};
 
 */
@property(nonatomic, strong) NSDictionary *customParams;

@end
