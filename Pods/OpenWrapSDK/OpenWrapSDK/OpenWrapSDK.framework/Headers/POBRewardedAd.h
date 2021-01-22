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

#import "POBReward.h"
#import "POBRewardedAdEvent.h"
#import "POBBidEvent.h"
#import "POBRequest.h"


@class POBRewardedAd;
NS_ASSUME_NONNULL_BEGIN

/**
 ------------------------------------------------------------------------------------
 POBRewardedAdDelegate Protocol
 ------------------------------------------------------------------------------------
 */

/*!
 Protocol for interaction with the POBRewardedAd instance.
 
 All messages are guaranteed to occur on the main thread.
 */
@protocol POBRewardedAdDelegate <NSObject>

@optional

/*!
@abstract Notifies the delegate that an rewarded ad has been received successfully.
@param rewardedAd The POBRewardedAd instance sending the message.
*/
-(void) rewardedAdDidReceiveAd:(POBRewardedAd *)rewardedAd;

/*!
@abstract Notifies the delegate of an error encountered while loading or rendering an ad.
@param rewardedAd The POBRewardedAd instance sending the message.
@param error The error encountered while attempting to receive or render the ad.
*/
-(void) rewardedAd:(POBRewardedAd *)rewardedAd didFailToReceiveAdWithError:(NSError *)error;

/*!
@abstract Notifies the delegate that the rewarded ad will be presented as a modal on top of the current view controller.
@param rewardedAd The POBRewardedAd instance sending the message.
*/
-(void) rewardedAdWillPresentAd:(POBRewardedAd *)rewardedAd;

/*!
@abstract Notifies the delegate that the rewarded ad has been animated off the screen.
@param rewardedAd The POBRewardedAd instance sending the message.
*/
-(void) rewardedAdDidDismissAd:(POBRewardedAd *)rewardedAd;

/*!
@abstract Notifies the delegate of ad click
@param rewardedAd The POBRewardedAd instance sending the message.
*/
-(void) rewardedAdDidClickAd:(POBRewardedAd *)rewardedAd;

/*!
@abstract Notifies the delegate that a user interaction will open another app (e.g. App Store), leaving the current app. To handle user clicks that open the
landing page URL in the internal browser, use 'RewardedAdDidClickAd:'
instead.
@param rewardedAd The POBRewardedAd instance sending the message.
*/
-(void) rewardedAdWillLeaveApplication:(POBRewardedAd *)rewardedAd;

/*!
@abstract Notifies the delegate of an ad expiration. After this callback, this 'POBRewardedAd' instance is marked as invalid & will not be shown.
@param rewardedAd The POBRewardedAd instance sending the message.
*/
-(void) rewardedAdDidExpireAd:(POBRewardedAd *)rewardedAd;

/*!
@abstract Notifies the delegate that a user will be rewarded once the ad is completely viewed.
@param rewardedAd The POBRewardedAd instance sending the message.
@param reward The POBReward instance to reward.
*/
-(void) rewardedAd:(POBRewardedAd *)rewardedAd shouldReward:(POBReward *)reward;

@end

/**
 ------------------------------------------------------------------------------------
 POBRewardedAd Class
 ------------------------------------------------------------------------------------
 */

/*!
 Displays Rewarded Ads.
 */
@interface POBRewardedAd : NSObject<POBBidEvent>

/*!
@abstract Initializes & returns a newly initialized Rewarded ad object with the specified POBRewardedAdEvent implementaion and other details.
@param publisherId Unique identifier assigned at the time of publisher onboarding.
@param profileId Profile id.
@param adUnitId Ad unit id used to identify unique placement on screen.
@param eventHandler Object conforming to POBRewardedAdEvent protocol
@result Instance of POBRewardedAd
*/
- (instancetype)initWithPublisherId:(NSString *)publisherId
                        profileId:(NSNumber *)profileId
                         adUnitId:(NSString *)adUnitId
                        eventHandler: (id<POBRewardedAdEvent>)eventHandler;

/*!
 @abstract Initializes & returns a newly initialized Rewarded ad object for supporting 'No Ad Server Configuration'.
 @param publisherId Unique identifier assigned at the time of publisher onboarding.
 @param profileId Profile id.
 @param adUnitId Ad unit id used to identify unique placement on screen.
 @result Instance of POBRewardedAd
*/
- (instancetype)initWithPublisherId:(NSString *)publisherId
                                profileId:(NSNumber *)profileId
                                 adUnitId:(NSString *)adUnitId;

/*!
@abstract Initiates the loading of an rewarded ad
*/
- (void)loadAd NS_SWIFT_NAME(loadAd());

/*!
 @abstract Returns the winning bid that will be used to render the ad
 */
- (POBBid *)bid;

/*!
 @abstract Sets title, message & button texts to be used while showing the skip alert.
 @discussion If any of the parameters is empty the SDK discards all the values & shows a default skip alert.
 @param title alert title
 @param message alert message
 @param closeTitle title of the close button
 @param resumeTitle title of the resume button
 */
- (void)setSkipAlertInfoWithTitle:(NSString*)title
                  message:(NSString*)message
         closeButtonTitle:(NSString*)closeTitle
        resumeButtonTitle:(NSString*)resumeTitle;

/*!
@abstract Presents an rewarded ad in full screen view until the user dismisses it. Calling this method has no effect until the ad is received(rewardedAdDidReceiveAd:) and is ready to show, i.e. 'isReady' flag is true.
@param controller UIViewController to be used for presenting the rewarded ad.
*/
- (void)showFromViewController:(UIViewController *)controller;

/*!
@abstract Sets the POBRewardedAdDelegate delegate receiver for the rewarded ad
@warning Proper reference management practices should be observed when using delegates.
@warning Ensure that the delegate is set to nil prior to setting nil to POBRewardedAd's object reference.
*/
@property (nonatomic, weak) id<POBRewardedAdDelegate> delegate;

/*!
 @abstract Object representing bid request
 @discussion You may set some additional targeting parameters on this object
 */
@property (nonatomic, readonly) POBRequest *request;

/*!
 @abstract Managed impression object created internally. It provides APIs to set PubMatic zone id and other custom parameterss
 */
@property (nonatomic, readonly) POBImpression *impression;

/*!
 @abstract Returns YES if the rewarded ad is ready to be displayed. The delegate’s rewardedAdDidReceiveAd: will be called after this property switches from NO to YES.
 */
@property (nonatomic, assign, readonly) BOOL isReady;

@end

NS_ASSUME_NONNULL_END
