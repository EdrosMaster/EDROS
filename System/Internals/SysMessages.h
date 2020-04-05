//============================================================================//
// Title: EDROS - System messages definition 		  		  	  			  //
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
#ifndef SYSMESSAGES_H
    #define SYSMESSAGES_H
	#include <stdint.h>
	
//------------------------------------------------------------------------------
// high priority messages (system-defined) [> NM_HIGHEST]
const uint32_t NM_EXTINGUISH    = 0xFFFFFFFFU;

const uint32_t NM_EXTINT        = 0xFFFFFFFEU;
const uint32_t NM_EXECUTE       = 0xFFFFFFFDU;
const uint32_t NM_HARDTICK      = 0xFFFFFFFCU;
const uint32_t NM_TIMETICK      = 0xFFFFFFFBU;
const uint32_t NM_TIMESLICE     = 0xFFFFFFFAU;
const uint32_t NM_PERIPH_RESET  = 0xFFFFFFF6U;

const uint32_t NM_TIMERFAULT    = 0xFFFFFFF4U;
const uint32_t NM_TIMERTRIGGER  = 0xFFFFFFF3U;
const uint32_t NM_TIMERCAPTURE  = 0xFFFFFFF2U;
const uint32_t NM_TIMERCHANGE   = 0xFFFFFFF1U;

const uint32_t NM_CANERROR      = 0xFFFF0402U;
const uint32_t NM_CANRX         = 0xFFFF0401U;
const uint32_t NM_CANTX         = 0xFFFF0400U;

const uint32_t NM_HDTIM_UPT     = 0xFFFFF020U;
const uint32_t NM_I2CEVENT      = 0xFFFFF012U;
const uint32_t NM_SPISRXE       = 0xFFFFF010U;

// high priority messages (user-defined)
const uint32_t NM_APPHMSG_LAST  = 0xFFFF0100U;
const uint32_t NM_APPHMSG_FIRST = 0xFFFF0000U;

// low priority messages (user-defined)
const uint32_t NM_APPLMSG_LAST  = 0x10000100U;
const uint32_t NM_APPLMSG_FIRST = 0x10000000U;

// low priority messages (system-defined)
const uint32_t NM_STATE_ENTRY 	= 0x00000912;
const uint32_t NM_STATE_LEAVE 	= 0x00000910;

const uint32_t NM_ITEM_EXCLUDED = 0x00000812;
const uint32_t NM_ITEM_INCLUDED = 0x00000810;

const uint32_t NM_DAC           = 0x00000720;
const uint32_t NM_ADC_OK        = 0x00000700;

const uint32_t NM_I2CERROR      = 0x00000607;
const uint32_t NM_I2CMTCR       = 0x00000605;
const uint32_t NM_I2CMTC        = 0x00000604;
const uint32_t NM_I2CMTXE       = 0x00000603;
const uint32_t NM_I2CMRXNE      = 0x00000602;

const uint32_t NM_SPIERROR      = 0x00000507;
const uint32_t NM_SPITMOUT      = 0x00000506;
const uint32_t NM_SPISTXE       = 0x00000505;
const uint32_t NM_SPIMTXE       = 0x00000503;
const uint32_t NM_SPIMRXNE      = 0x00000502;
const uint32_t NM_SPIRX         = 0x00000501;
const uint32_t NM_SPITX         = 0x00000500;

const uint32_t NM_DMA_ERR       = 0x00000302;
const uint32_t NM_DMA_MOK       = 0x00000301;
const uint32_t NM_DMA_OK        = 0x00000300;

const uint32_t NM_UARTRXIDLE	= 0x00000204;
const uint32_t NM_UARTCTS       = 0x00000203;
const uint32_t NM_UARTERROR     = 0x00000202;
const uint32_t NM_UARTRX        = 0x00000201;
const uint32_t NM_UARTTX        = 0x00000200;

const uint32_t NM_ADCOVR        = 0x00000154;
const uint32_t NM_ADCEOSEQ      = 0x00000153;
const uint32_t NM_ADCAWD        = 0x00000152;
const uint32_t NM_ADCJEOC       = 0x00000151;
const uint32_t NM_ADCEOC        = 0x00000150;

const uint32_t NM_TIMEOUT       = 0x00000100;
const uint32_t NM_KEYS_UPDATE   = 0x000000A2;
const uint32_t NM_KEYSCAN       = 0x000000A0;
const uint32_t NM_REPAINT       = 0x00000080;
const uint32_t NM_KEYDOWN       = 0x00000090;
const uint32_t NM_KEYUP         = 0x00000092;
const uint32_t NM_NULL          = 0x00000000;

//------------------------------------------------------------------------------
#endif
//==============================================================================
