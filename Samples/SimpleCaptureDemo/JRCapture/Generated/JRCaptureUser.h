/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Copyright (c) 2012, Janrain, Inc.

 All rights reserved.

 Redistribution and use in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation and/or
   other materials provided with the distribution.
 * Neither the name of the Janrain, Inc. nor the names of its
   contributors may be used to endorse or promote products derived from this
   software without specific prior written permission.


 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#import <Foundation/Foundation.h>
#import "JRCaptureObject.h"
#import "JRCaptureTypes.h"
#import "JRNSDate+ISO8601_CaptureDateTimeString.h"
#import "JRBestHand.h"
#import "JRGamesElement.h"
#import "JRObjectLevelOne.h"
#import "JROnipLevelOneElement.h"
#import "JRPhotosElement.h"
#import "JRPinoLevelOne.h"
#import "JRPluralLevelOneElement.h"
#import "JRPrimaryAddress.h"
#import "JRProfilesElement.h"
#import "JRStatusesElement.h"
#import "JRTournamentsPlayedElement.h"

/**
 * @brief A JRCaptureUser object
 **/
@interface JRCaptureUser : JRCaptureObject
@property (nonatomic, readonly) JRObjectId *captureUserId; /**< Simple identifier for this entity @note The \e id of the object should not be set. */ 
@property (nonatomic, readonly) JRUuid *uuid; /**< Globally unique indentifier for this entity @note A ::JRUuid property is a property of type \ref typesTable "uuid" and a typedef of \e NSString */ 
@property (nonatomic, readonly) JRDateTime *created; /**< When this entity was created @note A ::JRDateTime property is a property of type \ref typesTable "dateTime" and a typedef of \e NSDate. The accepted format should be an ISO 8601 dateTime string (e.g., <code>yyyy-MM-dd HH:mm:ss.SSSSSS ZZZ</code>) */ 
@property (nonatomic, readonly) JRDateTime *lastUpdated; /**< When this entity was last updated @note A ::JRDateTime property is a property of type \ref typesTable "dateTime" and a typedef of \e NSDate. The accepted format should be an ISO 8601 dateTime string (e.g., <code>yyyy-MM-dd HH:mm:ss.SSSSSS ZZZ</code>) */ 
@property (nonatomic, copy)     NSString *aboutMe; /**< The object's \e aboutMe property */ 
@property (nonatomic, copy)     NSString *avatar; /**< The name of the avatar which is used to represent the player at tournament tables */ 
@property (nonatomic, copy)     JRDecimal *bankroll; /**< The player’s current in-game bankroll @note A ::JRDecimal property is a property of type \ref typesTable "decimal" and a typedef of \e NSNumber. Accepted values can be, for example, <code>[NSNumber numberWithNumber:<em>myDecimal</em>]</code>, <code>nil</code>, etc. */ 
@property (nonatomic, retain)   JRBestHand *bestHand; /**< The best hand your player has ever had in a tournament */ 
@property (nonatomic, copy)     JRDate *birthday; /**< The object's \e birthday property @note A ::JRDate property is a property of type \ref typesTable "date" and a typedef of \e NSDate. The accepted format should be an ISO 8601 date string (e.g., <code>yyyy-MM-dd</code>) */ 
@property (nonatomic, copy)     NSString *currentLocation; /**< The object's \e currentLocation property */ 
@property (nonatomic, copy)     JRJsonObject *display; /**< The object's \e display property @note A ::JRJsonObject property is a property of type \ref typesTable "json", which can be an \e NSDictionary, \e NSArray, \e NSString, etc., and is therefore is a typedef of \e NSObject */ 
@property (nonatomic, copy)     NSString *displayName; /**< The name of this Contact, suitable for display to end-users. */ 
@property (nonatomic, copy)     NSString *email; /**< The object's \e email property */ 
@property (nonatomic, copy)     JRDateTime *emailVerified; /**< The object's \e emailVerified property @note A ::JRDateTime property is a property of type \ref typesTable "dateTime" and a typedef of \e NSDate. The accepted format should be an ISO 8601 dateTime string (e.g., <code>yyyy-MM-dd HH:mm:ss.SSSSSS ZZZ</code>) */ 
@property (nonatomic, copy)     JRBoolean *exampleBoolean; /**< Example of a basic string property @note A ::JRBoolean property is a property of type \ref typesTable "boolean" and a typedef of \e NSNumber. The accepted values can only be <code>[NSNumber numberWithBool:<em>myBool</em>]</code> or <code>nil</code> */ 
@property (nonatomic, copy)     JRDate *exampleDate; /**< Example of a basic date property @note A ::JRDate property is a property of type \ref typesTable "date" and a typedef of \e NSDate. The accepted format should be an ISO 8601 date string (e.g., <code>yyyy-MM-dd</code>) */ 
@property (nonatomic, copy)     JRDateTime *exampleDateTime; /**< Example of a basic dateTime property @note A ::JRDateTime property is a property of type \ref typesTable "dateTime" and a typedef of \e NSDate. The accepted format should be an ISO 8601 dateTime string (e.g., <code>yyyy-MM-dd HH:mm:ss.SSSSSS ZZZ</code>) */ 
@property (nonatomic, copy)     JRDecimal *exampleDecimal; /**< Example of a basic decimal property @note A ::JRDecimal property is a property of type \ref typesTable "decimal" and a typedef of \e NSNumber. Accepted values can be, for example, <code>[NSNumber numberWithNumber:<em>myDecimal</em>]</code>, <code>nil</code>, etc. */ 
@property (nonatomic, copy)     JRInteger *exampleInteger; /**< Example of a basic integer property @note A ::JRInteger property is a property of type ef typesTable "integer" and a typedef of \e NSNumber. The accepted values can only be <code>[NSNumber numberWithInteger:<em>myInteger</em>]</code>, <code>[NSNumber numberWithInt:<em>myInt</em>]</code>, or <code>nil</code> */ 
@property (nonatomic, copy)     JRIpAddress *exampleIpAddress; /**< Example of a basic ipAddress property @note A ::JRIpAddress property is a property of type \ref typesTable "ipAddress" and a typedef of \e NSString. */ 
@property (nonatomic, copy)     JRJsonObject *exampleJson; /**< Example of a basic ipAddress property @note A ::JRJsonObject property is a property of type \ref typesTable "json", which can be an \e NSDictionary, \e NSArray, \e NSString, etc., and is therefore is a typedef of \e NSObject */ 
@property (nonatomic, copy)     NSString *exampleString; /**< Example of a basic string property */ 
@property (nonatomic, copy)     JRStringArray *exampleStringPlural; /**< The object's \e exampleStringPlural property @note  A ::JRStringArray property is a plural (array) that holds a list of \e NSStrings. As it is an array, it is therefore a typedef of \e NSArray. This array of \c NSStrings represents a list of \c stringPluralItem */ 
@property (nonatomic, copy)     NSString *exampleUniqueString; /**< The object's \e exampleUniqueString property */ 
@property (nonatomic, copy)     NSString *familyName; /**< The object's \e familyName property */ 
@property (nonatomic, copy)     JRStringArray *favoriteHands; /**< The player’s favorite hands @note  A ::JRStringArray property is a plural (array) that holds a list of \e NSStrings. As it is an array, it is therefore a typedef of \e NSArray. This array of \c NSStrings represents a list of \c hand */ 
@property (nonatomic, copy)     NSArray *games; /**< The object's \e games property @note This is an array of JRGamesElement objects */ 
@property (nonatomic, copy)     NSString *gender; /**< The object's \e gender property */ 
@property (nonatomic, copy)     NSString *givenName; /**< The object's \e givenName property */ 
@property (nonatomic, copy)     JRDateTime *lastLogin; /**< The object's \e lastLogin property @note A ::JRDateTime property is a property of type \ref typesTable "dateTime" and a typedef of \e NSDate. The accepted format should be an ISO 8601 dateTime string (e.g., <code>yyyy-MM-dd HH:mm:ss.SSSSSS ZZZ</code>) */ 
@property (nonatomic, copy)     NSString *middleName; /**< The object's \e middleName property */ 
@property (nonatomic, retain)   JRObjectLevelOne *objectLevelOne; /**< An example of objects nested in objects, level 1 */ 
@property (nonatomic, copy)     NSArray *onipLevelOne; /**< An example of objects nested in plurals, level 1, plural @note This is an array of JROnipLevelOneElement objects */ 
@property (nonatomic, copy)     JRPassword *password; /**< The object's \e password property @note A ::JRPassword property is a property of type \ref typesTable "password", which can be either an \e NSString or \e NSDictionary, and is therefore is a typedef of \e NSObject */ 
@property (nonatomic, copy)     NSArray *photos; /**< The object's \e photos property @note This is an array of JRPhotosElement objects */ 
@property (nonatomic, retain)   JRPinoLevelOne *pinoLevelOne; /**< An example of plurals nested in objects, level 1, object */ 
@property (nonatomic, copy)     NSString *playerName; /**< The name that is displayed below the player’s avatar */ 
@property (nonatomic, copy)     NSArray *pluralLevelOne; /**< An example of plurals nested in plurals, level 1 @note This is an array of JRPluralLevelOneElement objects */ 
@property (nonatomic, retain)   JRPrimaryAddress *primaryAddress; /**< The object's \e primaryAddress property */ 
@property (nonatomic, copy)     NSArray *profiles; /**< The object's \e profiles property @note This is an array of JRProfilesElement objects */ 
@property (nonatomic, copy)     NSArray *statuses; /**< The object's \e statuses property @note This is an array of JRStatusesElement objects */ 
@property (nonatomic, copy)     NSArray *tournamentsPlayed; /**< A list of the tournaments in which the player has competed @note This is an array of JRTournamentsPlayedElement objects */ 

/**
 * @name Constructors
 **/
/*@{*/
/**
 * Default instance constructor. Returns an empty JRCaptureUser object
 *
 * @return
 *   A JRCaptureUser object
 *
 * @note 
 * Method creates a object without the required properties: \e email.
 * These properties are required when updating the object on Capture. That is, you must set them before calling
 * updateOnCaptureForDelegate:context:().
 **/
- (id)init;

/**
 * Default class constructor. Returns an empty JRCaptureUser object
 *
 * @return
 *   A JRCaptureUser object
 *
 * @note 
 * Method creates a object without the required properties: \e email.
 * These properties are required when updating the object on Capture. That is, you must set them before calling
 * updateOnCaptureForDelegate:context:().
 **/
+ (id)captureUser;

/**
 * Returns a JRCaptureUser object initialized with the given required properties: \c newEmail
 *
 * @param newEmail
 *   The object's \e email property
 * 
 * @return
 *   A JRCaptureUser object initialized with the given required properties: \e newEmail.
 *   If the required arguments are \e nil or \e [NSNull null], returns \e nil
 **/
- (id)initWithEmail:(NSString *)newEmail;

/**
 * Returns a JRCaptureUser object initialized with the given required properties: \c email
 *
 * @param email
 *   The object's \e email property
 * 
 * @return
 *   A JRCaptureUser object initialized with the given required properties: \e email.
 *   If the required arguments are \e nil or \e [NSNull null], returns \e nil
 **/
+ (id)captureUserWithEmail:(NSString *)email;

/*@}*/

/**
 * @name Manage Remotely 
 **/
/*@{*/
/**
 * TODO: DOXYGEN DOCS
 **/
- (void)replaceExampleStringPluralArrayOnCaptureForDelegate:(id<JRCaptureObjectDelegate>)delegate context:(NSObject *)context;

/**
 * TODO: DOXYGEN DOCS
 **/
- (void)replaceFavoriteHandsArrayOnCaptureForDelegate:(id<JRCaptureObjectDelegate>)delegate context:(NSObject *)context;

/**
 * TODO: DOXYGEN DOCS
 **/
- (void)replaceGamesArrayOnCaptureForDelegate:(id<JRCaptureObjectDelegate>)delegate context:(NSObject *)context;

/**
 * TODO: DOXYGEN DOCS
 **/
- (void)replaceOnipLevelOneArrayOnCaptureForDelegate:(id<JRCaptureObjectDelegate>)delegate context:(NSObject *)context;

/**
 * TODO: DOXYGEN DOCS
 **/
- (void)replacePhotosArrayOnCaptureForDelegate:(id<JRCaptureObjectDelegate>)delegate context:(NSObject *)context;

/**
 * TODO: DOXYGEN DOCS
 **/
- (void)replacePluralLevelOneArrayOnCaptureForDelegate:(id<JRCaptureObjectDelegate>)delegate context:(NSObject *)context;

/**
 * TODO: DOXYGEN DOCS
 **/
- (void)replaceProfilesArrayOnCaptureForDelegate:(id<JRCaptureObjectDelegate>)delegate context:(NSObject *)context;

/**
 * TODO: DOXYGEN DOCS
 **/
- (void)replaceStatusesArrayOnCaptureForDelegate:(id<JRCaptureObjectDelegate>)delegate context:(NSObject *)context;

/**
 * TODO: DOXYGEN DOCS
 **/
- (void)replaceTournamentsPlayedArrayOnCaptureForDelegate:(id<JRCaptureObjectDelegate>)delegate context:(NSObject *)context;

/**
 * TODO: Doxygen doc
 **/
- (BOOL)needsUpdate;

/**
 * TODO: Doxygen doc
 **/
- (void)updateOnCaptureForDelegate:(id<JRCaptureObjectDelegate>)delegate context:(NSObject *)context;
/*@}*/

/**
 * @name Primitive Getters/Setters 
 **/
/*@{*/
/**
 * TODO
 **/
- (BOOL)getExampleBooleanBoolValue;

/**
 * TODO
 **/
- (void)setExampleBooleanWithBool:(BOOL)boolVal;

/**
 * TODO
 **/
- (NSInteger)getExampleIntegerIntegerValue;

/**
 * TODO
 **/
- (void)setExampleIntegerWithInteger:(NSInteger)integerVal;
/*@}*/

@end
