//============================================================================//
// Title: EDROS Driver: System Services Requests for STM32G0xx                //
// Author: edros.master@pobox.com											  //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM 											  //
// 					   All rights reserved.									  //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:					  //
//               opensource.org/licenses/BSD-3-Clause						  //
//============================================================================//
#ifndef DRV_SSR_H
    #define DRV_SSR_H

#ifdef __cplusplus
extern "C"{
#endif

    #include "stm32G071xx.h"

    #define LSB16   ((uint32_t)0x0000FFFF)
    #define MSB16   ((uint32_t)0xFFFF0000)
    #define MSBITS  ((uint32_t)16)
  
    //--------------------------------------------------------------------------
    void  SSR_Relocate(int);
    void SSR_Allocate(unsigned int, unsigned int);      
    void __svc(0x00) SSR_CallService0();
    void __svc(0x01) SSR_CallService1(unsigned int);
    void __svc(0x02) SSR_CallService2(unsigned int);
    void __svc(0x03) SSR_CallService3(unsigned int, unsigned int);
    void __svc(0x04) SSR_CallService4(unsigned int, unsigned int);
    unsigned int __svc(0x05) SSR_CallService5(unsigned int);
    unsigned int __svc(0x06) SSR_CallService6();
    bool __svc(0x07) SSR_CallService7(unsigned int, unsigned int);
    unsigned int __svc(0x08) SSR_CallService8();
    unsigned int __svc(0x09) SSR_CallService9(unsigned int);

#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------

#endif
//==============================================================================
