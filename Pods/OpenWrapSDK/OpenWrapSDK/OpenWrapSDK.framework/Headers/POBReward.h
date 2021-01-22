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

#define NO_REWARD_TYPE_LABEL @""
#define NO_REWARD_AMOUNT_VALUE @0

NS_ASSUME_NONNULL_BEGIN
/*!
 ------------------------------------------------------------------------------------
 POBReward Class
 ------------------------------------------------------------------------------------
 */

/*!
 Holds the general information about Reward to be provided to user.
 */
@interface POBReward : NSObject
/*!
 @abstract Currency for the reward, e.g. coin, life, etc.
 */
@property (nonatomic, strong, readonly) NSString * currencyType;

/*!
@abstract Reward amount to offer to the user
*/
@property (nonatomic, readonly) NSNumber *amount;

/*!
 @abstract Initializes & returns a newly initialized Reward object with the specified currency type and amount
 @param currencyType Type of currency
 @param amount amount of currency
 */
- (instancetype) initWithCurrencyType:(NSString *)currencyType withAmount:(NSNumber*)amount;

@end

NS_ASSUME_NONNULL_END
