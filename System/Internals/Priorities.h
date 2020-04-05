//============================================================================//
// Title: EDROS - System vectors and priorities definition 		  		  	  //
// Author: edros.master@pobox.com											  //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM 											  //
// 					   All rights reserved.									  //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:					  //
//               opensource.org/licenses/BSD-3-Clause						  //
//============================================================================//
#ifndef PRIORITIES_H
    #define PRIORITIES_H

    //--------------------------------------
    #include <stdint.h>
    #include <stdio.h>
    #include "GenericTypeDefs.h"
	#include "stm32g0xx.h"

    //--------------------------------------------------------------------------
    NV_ID NV_EXCEPTION              = 0x00;
    NV_ID NV_EXTINT_0_1             = 0x01;
    NV_ID NV_EXTINT_2_3             = 0x02;
    NV_ID NV_EXTINT_4_15       		= 0x03;
    NV_ID NV_ADC1              		= 0x04;
    NV_ID NV_TIM1                   = 0x05;
    NV_ID NV_TIM2                   = 0x06;
    NV_ID NV_TIM3                   = 0x07;
    NV_ID NV_TIM6                   = 0x08;
    NV_ID NV_TIM7                   = 0x09;
    NV_ID NV_TIM14                  = 0x0A;
    NV_ID NV_TIM15                  = 0x0B;
    NV_ID NV_TIM16                  = 0x0C;
    NV_ID NV_TIM17                  = 0x0D;
	
    NV_ID NV_I2C1                   = 0x0E;
    NV_ID NV_I2C2                   = 0x0F;
    NV_ID NV_UART1                  = 0x10;
    NV_ID NV_UART2                  = 0x11;
    NV_ID NV_UART3                	= 0x12;
    NV_ID NV_UART4                  = 0x13;
    NV_ID NV_SPI1                   = 0x14;
    NV_ID NV_SPI2                   = 0x15;
    NV_ID NV_DMA1                   = 0x16;
    NV_ID NV_DMA2                   = 0x17;
    NV_ID NV_DMA3                   = 0x18;
    NV_ID NV_DMA4                   = 0x19;
    NV_ID NV_DMA5                   = 0x1A;
    NV_ID NV_DMA6                   = 0x1B;
    NV_ID NV_DMA7                   = 0x1C;
    NV_ID NV_LPUART1                = 0x1D;
	NV_ID NV_LPTIM1					= 0x1E;
	NV_ID NV_LPTIM2					= 0x1F;
	NV_ID NV_COMP1             		= 0x20;
	NV_ID NV_COMP2             		= 0x21;
	NV_ID NV_DAC1              		= 0x22;

    //--------------------------------------------------------------------------
    const uint32_t Vectors[__SYS_MAX_VECTORS] = {
        ((uint32_t)NULL),   	 	//    NV_ID NV_SYSTICK			= 0x00;
        ((uint32_t)NULL),    		//    NV_ID NV_EXTINT_0_1      	= 0x01;
        ((uint32_t)NULL),    		//    NV_ID NV_EXTINT_2_3       = 0x02;
        ((uint32_t)NULL),    		//    NV_ID NV_EXTINT_4_15 		= 0x03;
        ((uint32_t)ADC1),    		//    NV_ID NV_ADC1_COMP        = 0x04;
        ((uint32_t)TIM1),    		//    NV_ID NV_TIM1             = 0x05;
		((uint32_t)TIM2),    		//    NV_ID NV_TIM2             = 0x06;
        ((uint32_t)TIM3),    		//    NV_ID NV_TIM3             = 0x07;
        ((uint32_t)TIM6),    		//    NV_ID NV_TIM6             = 0x08;
        ((uint32_t)TIM7),    		//    NV_ID NV_TIM7             = 0x09;
        ((uint32_t)TIM14),   		//    NV_ID NV_TIM14            = 0x0A;
        ((uint32_t)TIM15),   		//    NV_ID NV_TIM15            = 0x0B;
        ((uint32_t)TIM16),   		//    NV_ID NV_TIM16            = 0x0C;
		((uint32_t)TIM17),   		//    NV_ID NV_TIM17            = 0x0D;
		
        ((uint32_t)I2C1),    		//    NV_ID NV_I2C1             = 0x0E;
        ((uint32_t)I2C2),    		//    NV_ID NV_I2C2             = 0x0F;
		
        ((uint32_t)USART1),  		//    NV_ID NV_UART1           	= 0x10;
        ((uint32_t)USART2),  		//    NV_ID NV_UART2           	= 0x11;
        ((uint32_t)USART3),  		//    NV_ID NV_UART3           	= 0x12;
        ((uint32_t)USART4),  		//    NV_ID NV_UART4           	= 0x13;
		
        ((uint32_t)SPI1),    		//    NV_ID NV_SPI1            	= 0x14;
        ((uint32_t)SPI2),    		//    NV_ID NV_SPI2           	= 0x15;
		
        ((uint32_t)DMA1_Channel1),	//    NV_ID NV_DMA1           	= 0x16;
        ((uint32_t)DMA1_Channel2),	//    NV_ID NV_DMA2           	= 0x17;
        ((uint32_t)DMA1_Channel3),	//    NV_ID NV_DMA3           	= 0x18;
        ((uint32_t)DMA1_Channel4),	//    NV_ID NV_DMA4            	= 0x19;
        ((uint32_t)DMA1_Channel5),	//    NV_ID NV_DMA5            	= 0x1A;
        ((uint32_t)DMA1_Channel6),	//    NV_ID NV_DMA6            	= 0x1B;
        ((uint32_t)DMA1_Channel7),	//    NV_ID NV_DMA7            	= 0x1C;
		((uint32_t)LPUART1), 		//    NV_ID NV_LPUART1         	= 0x1D;
		((uint32_t)LPTIM1), 		//    NV_ID NV_LPTIM1          	= 0x1E;
		((uint32_t)LPTIM2), 		//    NV_ID NV_LPTIM1          	= 0x1F;
		((uint32_t)COMP1),			//    NV_ID NV_COMP1         	= 0x20;
		((uint32_t)COMP2),			//    NV_ID NV_COMP2         	= 0x21;
		((uint32_t)DAC1), 			//    NV_ID NV_DAC1          	= 0x22;
    };

    //--------------------------------------------------------------------------
    #define NP_SYSTICK          0
    #define NP_EXTINT0_1        1
    #define NP_EXTINT2_3        2
    #define NP_EXTINT4_15       3
    #define NP_ADC1_COMP        4
    #define NP_TIM1             5
    #define NP_TIM2             6
    #define NP_TIM3             7
    #define NP_TIM6             8
    #define NP_TIM7             9
    #define NP_TIM14            10
    #define NP_TIM15            11
	#define NP_TIM16            12
	#define NP_TIM17            13
	
    #define NP_I2C1             14
    #define NP_I2C2             15

    #define NP_UART1            16
    #define NP_UART2            17
    #define NP_UART3            18
	#define NP_UART4            19	

    #define NP_SPI1             20
    #define NP_SPI2             21
	
    #define NP_DMA1             22
    #define NP_DMA2             23
    #define NP_DMA3             24
    #define NP_DMA4             25
    #define NP_DMA5             26
    #define NP_DMA6             27
    #define NP_DMA7             28
    #define NP_LPUART1          29
    #define NP_LPTIM1           30
	#define NP_LPTIM2           31
	#define NP_COMP1           	32
	#define NP_COMP2           	33
	#define NP_DAC1           	34

    //--------------------------------------------------------------------------
    const uint8_t Priorities[__SYS_MAX_VECTORS] = {
        0x03, // 00   NP_SYSTICK 
        0x01, // 01   NP_EXTINT0_1
        0x01, // 02   NP_EXTINT2_3
        0x01, // 03   NP_EXTINT4_15
        0x01, // 04   NP_ADC1_COMP
        0x01, // 05   NP_TIM1
        0x01, // 06   NP_TIM2
        0x00, // 07   NP_TIM3
        0x01, // 08   NP_TIM6
        0x01, // 09   NP_TIM7
        0x01, // 10   NP_TIM14
        0x01, // 11   NP_TIM15
		0x01, // 12   NP_TIM16
		0x01, // 13   NP_TIM17
		
        0x01, // 14   NP_I2C1
        0x01, // 15   NP_I2C2
		
        0x01, // 16   NP_USART1
        0x01, // 17   NP_USART2
        0x01, // 18   NP_USART3
		0x01, // 19   NP_USART4
		
        0x01, // 20   NP_SPI1
        0x01, // 21   NP_SPI2
		
        0x01, // 22   NP_DMA1
        0x01, // 23   NP_DMA2
        0x01, // 24   NP_DMA3
        0x01, // 25   NP_DMA4
        0x01, // 26   NP_DMA5
        0x01, // 27   NP_DMA6
        0x01, // 28   NP_DMA7
        0x01, // 29   NP_LPUART1
    };

    //--------------------------------------------------------------------------
	#define EP_HIGHESTPRIORITY	0
	#define EP_HIGHPRIORITY		1
	#define EP_LOWPRIORITY		2
	#define EP_LOWESTPRIORITY	3

    //--------------------------------------------------------------------------
    #define EP_SYSTICK          EP_LOWESTPRIORITY
    #define EP_EXTINT0_1        EP_HIGHPRIORITY
    #define EP_EXTINT2_3        EP_HIGHPRIORITY
    #define EP_EXTINT4_15       EP_HIGHPRIORITY
    #define EP_ADC1_COMP        EP_HIGHPRIORITY
    #define EP_TIM1             EP_HIGHPRIORITY
    #define EP_TIM2             EP_HIGHPRIORITY
    #define EP_TIM3             EP_HIGHPRIORITY
    #define EP_TIM6             EP_HIGHPRIORITY
    #define EP_TIM7             EP_HIGHPRIORITY
    #define EP_TIM14            EP_HIGHPRIORITY
    #define EP_TIM15            EP_HIGHPRIORITY
	#define EP_TIM16            EP_HIGHPRIORITY
	#define EP_TIM17            EP_HIGHPRIORITY
	
    #define EP_I2C1             EP_HIGHPRIORITY
    #define EP_I2C2             EP_HIGHPRIORITY

    #define EP_UART1            EP_HIGHPRIORITY
    #define EP_UART2            EP_HIGHPRIORITY
    #define EP_UART3            EP_HIGHPRIORITY
	#define EP_UART4            EP_HIGHPRIORITY	

    #define EP_SPI1             EP_HIGHPRIORITY
    #define EP_SPI2             EP_HIGHPRIORITY
	
    #define EP_DMA1             EP_HIGHPRIORITY
    #define EP_DMA2             EP_HIGHPRIORITY
    #define EP_DMA3             EP_HIGHPRIORITY
    #define EP_DMA4             EP_HIGHPRIORITY
    #define EP_DMA5             EP_HIGHPRIORITY
    #define EP_DMA6             EP_HIGHPRIORITY
    #define EP_DMA7             EP_HIGHPRIORITY
    #define EP_LPUART1          EP_HIGHPRIORITY
    #define EP_LPTIM1           EP_HIGHPRIORITY
	#define EP_LPTIM2           EP_HIGHPRIORITY
	#define EP_COMP1           	EP_HIGHPRIORITY
	#define EP_COMP2           	EP_HIGHPRIORITY
	#define EP_DAC1           	EP_HIGHPRIORITY
	
#endif 

//============================================================================//
