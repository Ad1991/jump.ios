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

/**
 * @brief Object for testing getting/setting, updating, and replacing properties when the properties have the constraints of being required and unique
 **/
@interface JRObjectTestRequiredUnique : JRCaptureObject
@property (nonatomic, copy)     NSString *requiredString; /**< The object's \e requiredString property */ 
@property (nonatomic, copy)     NSString *uniqueString; /**< The object's \e uniqueString property */ 
@property (nonatomic, copy)     NSString *requiredUniqueString; /**< The object's \e requiredUniqueString property */ 

/**
 * @name Constructors
 **/
/*@{*/
/**
 * Default instance constructor. Returns an empty JRObjectTestRequiredUnique object
 *
 * @return
 *   A JRObjectTestRequiredUnique object
 *
 * @note 
 * Method creates a object without the required properties: \e requiredString, \e requiredUniqueString.
 * These properties are required when updating the object on Capture. That is, you must set them before calling
 * updateOnCaptureForDelegate:context:().
 **/
- (id)init;

/**
 * Default class constructor. Returns an empty JRObjectTestRequiredUnique object
 *
 * @return
 *   A JRObjectTestRequiredUnique object
 *
 * @note 
 * Method creates a object without the required properties: \e requiredString, \e requiredUniqueString.
 * These properties are required when updating the object on Capture. That is, you must set them before calling
 * updateOnCaptureForDelegate:context:().
 **/
+ (id)objectTestRequiredUnique;

/**
 * Returns a JRObjectTestRequiredUnique object initialized with the given required properties: \c newRequiredString, \c newRequiredUniqueString
 *
 * @param newRequiredString
 *   The object's \e requiredString property
 *
 * @param newRequiredUniqueString
 *   The object's \e requiredUniqueString property
 * 
 * @return
 *   A JRObjectTestRequiredUnique object initialized with the given required properties: \e newRequiredString, \e newRequiredUniqueString.
 *   If the required arguments are \e nil or \e [NSNull null], returns \e nil
 **/
- (id)initWithRequiredString:(NSString *)newRequiredString andRequiredUniqueString:(NSString *)newRequiredUniqueString;

/**
 * Returns a JRObjectTestRequiredUnique object initialized with the given required properties: \c requiredString, \c requiredUniqueString
 *
 * @param requiredString
 *   The object's \e requiredString property
 *
 * @param requiredUniqueString
 *   The object's \e requiredUniqueString property
 * 
 * @return
 *   A JRObjectTestRequiredUnique object initialized with the given required properties: \e requiredString, \e requiredUniqueString.
 *   If the required arguments are \e nil or \e [NSNull null], returns \e nil
 **/
+ (id)objectTestRequiredUniqueWithRequiredString:(NSString *)requiredString andRequiredUniqueString:(NSString *)requiredUniqueString;

/*@}*/

/**
 * @name Manage Remotely 
 **/
/*@{*/
/**
 * TODO: Doxygen doc
 **/
- (BOOL)needsUpdate;

/**
 * TODO: Doxygen doc
 **/
- (void)updateOnCaptureForDelegate:(id<JRCaptureObjectDelegate>)delegate context:(NSObject *)context;
/*@}*/

@end
