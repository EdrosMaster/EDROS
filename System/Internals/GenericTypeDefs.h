//============================================================================//
// Title: EDROS: Global type definitions.									  //
// Author: edros.master@pobox.com											  //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM 											  //
// 					   All rights reserved.									  //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:					  //
//               opensource.org/licenses/BSD-3-Clause						  //
//============================================================================//

//------------------------------------------------------------------------------
#ifndef GENERICTYPEDEFS_H
    #define GENERICTYPEDEFS_H
    #include <stdint.h>
	#include <stdbool.h>
	
//------------------------------------------------------------------------------
#ifndef __WIN_TYPES
    #define __WIN_TYPES

#define NM_SYSHANDLE            0xFFFFFFFF

#define __SYS_MAX_OBJECTS       32L
#define __SYS_MAX_VECTORS       36L
#define __SYS_MAX_EVENTS        2L

#ifndef NULL
	#define NULL 		((void*)0)
#endif

//------------------------------------------------------------------------------
typedef bool                    BOOL;
typedef unsigned char           BYTE;
typedef unsigned char* 	        LPBYTE;
typedef unsigned short 	        WORD;
typedef unsigned short*         LPWORD;
typedef unsigned long 	        DWORD;
typedef unsigned long* 	        LPDWORD;
typedef unsigned long long      DWORD64;
typedef unsigned long long*     LPDWORD64;
typedef LPDWORD HANDLE;
typedef int32_t	FHANDLE;
typedef const unsigned int 	    NV_ID;
typedef const unsigned char     NP_ID;

//------------------------------------------------------------------------------
typedef struct NMESSAGE{
    uint32_t message;
    uint32_t lparam;
    uint32_t wparam;
	uint32_t tag;
} _NMESSAGE;

//------------------------------------------------------------------------------
typedef struct __SYS_VERSION{
    BYTE    major;
    BYTE    mid;
    BYTE    minor;
    BYTE    revision;
} _SYS_VERSION;

//------------------------------------------------------------------------------
typedef struct __ANALOG_PARAM {
    bool enabled;
    float bias;
    float scaling;
    float lower;
    float upper;
    uint16_t gain;
    uint16_t offset;
} ANALOG_PARAM;

#endif
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
