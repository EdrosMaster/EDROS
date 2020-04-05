//============================================================================//
// Title: EDROS: System definitions for data communication					  //
// Author: edros.master@pobox.com											  //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM 											  //
// 					   All rights reserved.									  //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:					  //
//               opensource.org/licenses/BSD-3-Clause						  //
//============================================================================//
#ifndef COMMUNICATIONPROTOCOLDEFS_H
    #define COMMUNICATIONPROTOCOLDEFS_H
    #include <stdint.h>
    #include "NCommand.h"

    //-------------------------------------------------
    // low priority messages (application defined)
    //const uint32_t NM_APPLMSG_FIRST = 0x10000000;
    const uint32_t NM_UNICAST_PROCESS = 0x10000001;
    const uint32_t NM_SERVICE_PROCESS = 0x10000002;
    const uint32_t NM_BROADCAST_PROCESS = 0x10000003;
    const uint32_t NM_UNICAST_POSTPROCESS = 0x10000004;
    const uint32_t NM_SERVICE_POSTPROCESS = 0x10000005;
    const uint32_t NM_UNICAST_RESPONSE = 0x10000006;
    const uint32_t NM_SERVICE_RESPONSE = 0x10000007;
    const uint32_t NM_POSTPROCESS = 0x10000008;

    const uint32_t NM_ROUTING_PROCESS  = 0x10000009;
    const uint32_t NM_ROUTING_RESPONSE  = 0x1000000A;

    const uint32_t NM_SERIAL_ONINTERPRET = 0x10000021;
    const uint32_t NM_SERIAL_ONPOSTINTERPRET = 0x10000022;
    const uint32_t NM_SERIAL_ONSLAVESILENCE = 0x10000023;
    //const uint32_t NM_APPLMSG_FIRST = 0x10000000;
    const uint32_t NM_DATAGRAM_PROCESS = 0x1000000C;
    //const uint32_t NM_APPLMSG_LAST  = 0x10000100;
    //-------------------------------------------------

#endif
//==============================================================================
