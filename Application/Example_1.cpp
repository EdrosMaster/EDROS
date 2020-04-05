//============================================================================//
// Title: Example 1 - EDROS demo application					  			  //
// Author: edros.master@pobox.com											  //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM 											  //
// 					   All rights reserved.									  //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:					  //
//               opensource.org/licenses/BSD-3-Clause						  //
//============================================================================//
#include "Example_1.h"

//------------------------------------------------------------------------------
// EDROS components declaration
NTinyOutput*	LedPin;
NTimer* Timer1;

//------------------------------------------------------------------------------
// application´s event-handlers declaration
void Timer1_OnTimer(void);

//------------------------------------------------------------------------------
// application initialization
void ApplicationCreate(void){

    //--------------------------------------------
    // instantiate components and set its properties
	LedPin = new NTinyOutput(__IO_OUT_LED);
	
	Timer1 = new NTimer();
	Timer1->OnTimer = Timer1_OnTimer;
	Timer1->Start(250);

}

//------------------------------------------------------------------------------
// event handler definition
void Timer1_OnTimer(void){
	LedPin->Toggle();
}

//==============================================================================

