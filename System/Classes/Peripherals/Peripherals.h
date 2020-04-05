//============================================================================//
// Title: EDROS - Peripherals driver classes                                  //
// Author: edros.master@pobox.com                                             //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM                                              //
//                     All rights reserved.                                   //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:                      //
//               opensource.org/licenses/BSD-3-Clause                         //
//============================================================================//
#ifndef PERIPHERALS_H
    #define PERIPHERALS_H

    //--------------------------------------
    // IO peripheral drivers
    #include "NTinyOutput.h"
    #include "NOutput.h"
    #include "NInput.h"

    //--------------------------------------
    // Time/frequency peripherals drivers
    #include "NHardTimer.h"
    #include "NLowPowerTimer.h"
    
    //--------------------------------------
    // Analog peripherals drivers
    #include "NAdc.h"
    #include "NDac.h"
    #include "NPwm.h"

    //--------------------------------------
    // Communication peripherals drivers
    #include "NSerial.h"
    #include "NSpi.h"
    #include "NIic.h"

#endif
//==============================================================================
