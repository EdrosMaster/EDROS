//============================================================================//
// Title: Example 1 - EDROS demo application                                  //
// Author: edros.master@pobox.com                                             //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM                                              //
//                     All rights reserved.                                   //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:                      //
//               opensource.org/licenses/BSD-3-Clause                         //
//============================================================================//
#ifndef APPLICATION_H
    #define APPLICATION_H

    //--------------------------------------------------------------------------
    #include "Peripherals.h"
    #include "NTimer.h"
    #include "NSerial.h"

    //========================== NUCLEO-G071RB  ================================
    // application definned pinout for "STM32G071 Nucleo-64"

    // Port A: output pins
    #define __IO_OUT_LED                    GPIOA, ((uint16_t) 5)   // PA5

//------------------------------------------------------------------------------

#endif
//==============================================================================
