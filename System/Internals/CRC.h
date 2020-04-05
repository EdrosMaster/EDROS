//============================================================================//
// Title: EDROS - Software CRC generation library			  		  		  //
// Author: edros.master@pobox.com											  //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM 											  //
// 					   All rights reserved.									  //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:					  //
//               opensource.org/licenses/BSD-3-Clause						  //
//============================================================================//
#ifndef CRC_H
    #define CRC_H

#include "GenericTypeDefs.h"

#define CRC8_ON
#define CRC16_ON
//#define CRC32_ON

//------------------------------------------------------------------------------
#define P_32                0xEDB88320L
#define P_CCITT             0x1021
#define P_DNP               0xA6BC
#define CRC_CCITT           0x1021

bool bit_test(uint8_t*, uint8_t);
void bit_set(uint8_t*, uint8_t);
void bit_clear(uint8_t*, uint8_t);

DWORD UpdateCrc32(DWORD, BYTE);
DWORD Crc32(LPBYTE, DWORD);
WORD Crc16(LPBYTE, DWORD);
WORD COMM_crc16(LPBYTE, DWORD);
uint8_t Crc8(uint8_t*, uint16_t, uint8_t);
uint8_t Crc_8(uint8_t*, uint16_t);

//------------------------------------------------------------------------------
#endif
//==============================================================================

