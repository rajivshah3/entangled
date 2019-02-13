//
//  Interface.h
//  EntangledKit
//
//
//  Copyright © 2019 IOTA Foundation. All rights reserved.
//

#ifndef __MOBILE__IOS_INTERFACE_H_
#define __MOBILE__IOS_INTERFACE_H_

#include <stddef.h>

char* iota_ios_checksum(const char* input, const size_t input_length,
                        const size_t checksum_length);
char* iota_ios_digest(char const* const trytes);
char* iota_ios_pow(const char* trytes, int mwm);
char* iota_ios_sign_address_gen(const char* seed, const int index,
                                const int security);
char* iota_ios_sign_signature_gen(const char* seed, const int index,
                                  const int security, const char* bundleHash);
NSArray* iota_ios_pow_bundle(NSArray* txsTrytes, NSString* trunk,
                             NSString* branch, int mwm);

#endif  // __MOBILE__IOS_INTERFACE_H_
