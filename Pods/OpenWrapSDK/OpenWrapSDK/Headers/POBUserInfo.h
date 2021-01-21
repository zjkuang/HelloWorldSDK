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

NS_ASSUME_NONNULL_BEGIN
/**
 ------------------------------------------------------------------------------------
 POBUserInfo Class
 ------------------------------------------------------------------------------------
 */

/*!
 Provides setters to pass user information
 */

@interface POBUserInfo : NSObject

/*!
 @abstract The year of birth in YYYY format.
 
 Example :
 birthYear = @1988;
 
 */
@property(nonatomic, strong) NSNumber *birthYear;

/*!
 Sets user gender,
 Possible options are:
 
 - POBGenderOther
 - POBGenderMale,
 - POBGenderFemale
 
 @see POBGender
 */
@property(nonatomic, assign) POBGender gender;

/*!
 @abstract Google metro code; similar to but not exactly Nielsen DMAs.
 e.g. For example, New York, NY is also known as 501. Los Angeles, CA, on the other hand has been assigned the number 803.
 */
@property(nonatomic, strong) NSString *metro;

/*! @abstract The user's zip or postal code. This may be useful in delivering geographically relevant ads
 e.g 94063 for Redwood City, CA
 */
@property(nonatomic, strong) NSString *zip;

/*! @abstract City of user
 e.g "Los Angeles"
 */
@property(nonatomic, strong) NSString *city;

/*!
 @abstract Region code using ISO-3166-2; 2-letter state code if USA
 e.g for France you can use 'FR'
 */
@property(nonatomic, strong) NSString *region;

/*!
 @abstract Country code using ISO-3166-1-alpha-3.
 e.g for United States of America you can use 'USA'
 */
@property(nonatomic, strong) NSString *country;

/*!
 @abstract A comma-separated list of keywords indicating the consumer's interests or intent.
 */
@property (nonatomic, strong) NSString *keywords;

@end

NS_ASSUME_NONNULL_END
