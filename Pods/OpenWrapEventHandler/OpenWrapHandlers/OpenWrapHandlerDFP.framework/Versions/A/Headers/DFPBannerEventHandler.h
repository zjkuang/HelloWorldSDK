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

#import <GoogleMobileAds/GoogleMobileAds.h>
#if __has_include(<POBBannerEvent.h>)
#import <POBBannerEvent.h>
#else
#import <OpenWrapSDK/POBBannerEvent.h>
#endif

/*!
 DFP banner configuration block having DFPBannerView, request as parameters
 */
typedef void(^DFPBannerConfigBlock)(DFPBannerView *view,DFPRequest * request,POBBid * bid);

/*!
 This class is responsible for communication between OpenWrap banner view and DFP banner view.
 It implements the POBBannerEvent protocol. it notifies event back to OpenWrap SDK using POBBannerEventDelegate methods
 */
@interface DFPBannerEventHandler : NSObject <POBBannerEvent>

/*!
 Initializes and returns a event handler with the specified DFP ad unit and ad sizes
 
 @param adUnitId DFP ad unit id
 @param validSizes Array of NSValue encoded GADAdSize structs. Never create your own GADAdSize directly. Use one of the predefined
 standard ad sizes (such as kGADAdSizeBanner), or create one using the GADAdSizeFromCGSize
 method.
 Example:
 <pre>
 NSArray *validSizes = @[
 NSValueFromGADAdSize(kGADAdSizeBanner),
 NSValueFromGADAdSize(kGADAdSizeLargeBanner)
 ];
 bannerView.validAdSizes = validSizes;
 </pre>

 */
- (instancetype)initWithAdUnitId:(NSString *)adUnitId
                    andSizes:(NSArray *)validSizes;

/*!
 A configBlock that is called before event handler makes ad request call to DFP SDK. It passes DFPBannerView & DFPRequest which will be used to make ad request.
 */
@property (nonatomic, copy) DFPBannerConfigBlock configBlock;
@end
