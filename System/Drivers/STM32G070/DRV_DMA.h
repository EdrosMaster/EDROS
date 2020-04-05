//============================================================================//
// Title: EDROS Driver - DMA engine driver for STM32G0xx                      //
// Author: edros.master@pobox.com											  //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM 											  //
// 					   All rights reserved.									  //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:					  //
//               opensource.org/licenses/BSD-3-Clause						  //
//============================================================================//
#ifndef DRV_DMA_H
    #define DRV_DMA_H

    #include "stm32G0xx.h"
    #include "DRV_CPU.h"
    #include "Priorities.h"

    //--------------------------------------------------------------------------
    enum DMA_CHANNEL {
        DMA_CHANNEL_1=0, DMA_CHANNEL_2=1, DMA_CHANNEL_3=2, DMA_CHANNEL_4=3,
        DMA_CHANNEL_5=4, DMA_CHANNEL_6=5, DMA_CHANNEL_7=6};

    enum DMA_PRIORITIES {
        DMA_PRIORITY_LOW=0, DMA_PRIORITY_MEDIUM=1,
        DMA_PRIORITY_HIGH=2, DMA_PRIORITY_HIGHEST=3
    };

    enum DMA_OPERATIONS {
        DMA_NONE=0,  DMA_TX = 1,   DMA_RX = 2,       DMA_CH1 = 3,  DMA_CH2 =4,  DMA_CH3 = 5,
        DMA_CH4 = 6, DMA_TRIG = 7, DMA_TRIG_COM = 8, DMA_UP = 9, DMA_IN, DMA_OUT 
    };

    //--------------------------------------------------------------------------
    #define DMA1_CHANNELS           7
    #define DMA1_REQUESTS           64
    #define DMA1_OPERATIONS         10
                
    //--------------------------------------------------------------------------
    #ifndef AES
        #define AES                 ((uint32_t) 0)
    #endif
    #ifndef DAC
        #define DAC                 ((uint32_t) 0)
    #endif
    #ifndef I2C1
        #define I2C1                 ((uint32_t) 0)
    #endif
    #ifndef I2C2
        #define I2C2                 ((uint32_t) 0)
    #endif
    #ifndef LPUART
        #define LPUART              ((uint32_t) 0)
    #endif
    #ifndef SPI1
        #define SPI1                 ((uint32_t) 0)
    #endif
    #ifndef SPI2
        #define SPI2                 ((uint32_t) 0)
    #endif
    #ifndef TIM1
        #define TIM1                 ((uint32_t) 0)
    #endif
    #ifndef TIM15
        #define TIM15                ((uint32_t) 0)
    #endif
    #ifndef TIM16
        #define TIM16                ((uint32_t) 0)
    #endif
    #ifndef TIM17
        #define TIM17                ((uint32_t) 0)
    #endif
    #ifndef USART3
        #define USART3                 ((uint32_t) 0)
    #endif
    #ifndef USART4
        #define USART4                 ((uint32_t) 0)
    #endif
    #ifndef UCPD1
        #define UCPD1                 ((uint32_t) 0)
    #endif
    #ifndef UCPD2
        #define UCPD2                 ((uint32_t) 0)
    #endif
    
    #ifndef DMAMUX
        #define DMAMUX  0
        #define DMAMUX_BASE 0
        #define DMAMUX_CHANNEL_SIZE 0
        #define DMAMUX_REQINDEX_MASK 0
        #define DMAMUX_CCR_DMAREQ_ID 0
    #endif
    
    //--------------------------------------------------------------------------
    // DMAMUX    
    static const uint32_t DMA1_REQUEST[DMA1_REQUESTS][2] = {
        ((uint32_t) 0),     ((uint32_t) DMA_NONE),      // 1
        ((uint32_t) 0),     ((uint32_t) DMA_NONE),      // 2
        ((uint32_t) 0),     ((uint32_t) DMA_NONE),      // 3
        ((uint32_t) 0),     ((uint32_t) DMA_NONE),      // 4
        ((uint32_t) ADC1),  ((uint32_t) DMA_IN),        // 5
        ((uint32_t) AES),   ((uint32_t) DMA_IN),        // 6
        ((uint32_t) AES),   ((uint32_t) DMA_OUT),       // 7
        ((uint32_t) DAC),   ((uint32_t) DMA_CH1),       // 8 CH1
        ((uint32_t) DAC),   ((uint32_t) DMA_CH2),       // 9 CH2
        
        ((uint32_t) I2C1),  ((uint32_t) DMA_RX),        // 10 RX
        ((uint32_t) I2C1),  ((uint32_t) DMA_TX),        // 11 TX
        ((uint32_t) I2C2),  ((uint32_t) DMA_RX),        // 12 RX
        ((uint32_t) I2C2),  ((uint32_t) DMA_TX),        // 13 TX

        ((uint32_t) LPUART),((uint32_t) DMA_RX),        // 14 RX
        ((uint32_t) LPUART),((uint32_t) DMA_TX),        // 15 TX
        
        ((uint32_t) SPI1),  ((uint32_t) DMA_RX),        // 16 RX
        ((uint32_t) SPI1),  ((uint32_t) DMA_TX),        // 17 TX
        ((uint32_t) SPI2),  ((uint32_t) DMA_RX),        // 18 RX
        ((uint32_t) SPI2),  ((uint32_t) DMA_TX),        // 19 TX
        
        ((uint32_t) TIM1),  ((uint32_t) DMA_CH1),       // 20 CH1
        ((uint32_t) TIM1),  ((uint32_t) DMA_CH2),       // 21 CH2
        ((uint32_t) TIM1),  ((uint32_t) DMA_CH3),       // 22 CH3
        ((uint32_t) TIM1),  ((uint32_t) DMA_CH4),       // 23 CH4
        ((uint32_t) TIM1),  ((uint32_t) DMA_TRIG_COM),  // 24 TRIG_COM
        ((uint32_t) TIM1),  ((uint32_t) DMA_UP),        // 25 UP

        ((uint32_t) TIM2),  ((uint32_t) DMA_CH1),       // 26 CH1
        ((uint32_t) TIM2),  ((uint32_t) DMA_CH2),       // 27 CH2
        ((uint32_t) TIM2),  ((uint32_t) DMA_CH3),       // 28 CH3
        ((uint32_t) TIM2),  ((uint32_t) DMA_CH4),       // 29 CH4
        ((uint32_t) TIM2),  ((uint32_t) DMA_TRIG_COM),  // 30 TRIG
        ((uint32_t) TIM2),  ((uint32_t) DMA_UP),        // 31 UP
        
        ((uint32_t) TIM3),  ((uint32_t) DMA_CH1),       // 32 CH1
        ((uint32_t) TIM3),  ((uint32_t) DMA_CH2),       // 33 CH2
        ((uint32_t) TIM3),  ((uint32_t) DMA_CH3),       // 34 CH3
        ((uint32_t) TIM3),  ((uint32_t) DMA_CH4),       // 35 CH4
        ((uint32_t) TIM3),  ((uint32_t) DMA_TRIG),      // 36 TRIG
        ((uint32_t) TIM3),  ((uint32_t) DMA_UP),        // 37 UP
        
        ((uint32_t) TIM6),  ((uint32_t) DMA_UP),        // 38 UP
        ((uint32_t) TIM7),  ((uint32_t) DMA_UP),        // 39 UP
        
        ((uint32_t) TIM15), ((uint32_t) DMA_CH1),       // 40 CH1
        ((uint32_t) TIM15), ((uint32_t) DMA_CH2),       // 41 CH2
        ((uint32_t) TIM15), ((uint32_t) DMA_TRIG_COM),  // 42 TRIG_COM
        ((uint32_t) TIM15), ((uint32_t) DMA_UP),        // 43 UP
        
        ((uint32_t) TIM16), ((uint32_t) DMA_CH1),       // 44 CH1
        ((uint32_t) TIM16), ((uint32_t) DMA_TRIG_COM),  // 45 TRIG_COM
        ((uint32_t) TIM16), ((uint32_t) DMA_UP),        // 46 UP
        
        ((uint32_t) TIM17), ((uint32_t) DMA_CH1),       // 47 CH1
        ((uint32_t) TIM17), ((uint32_t) DMA_TRIG_COM),  // 48 TRIG_COM
        ((uint32_t) TIM17), ((uint32_t) DMA_UP),        // 49 UP
        
        ((uint32_t) USART1), ((uint32_t) DMA_RX),       // 50 RX
        ((uint32_t) USART1), ((uint32_t) DMA_TX),       // 51 TX
        ((uint32_t) USART2), ((uint32_t) DMA_RX),       // 52 RX
        ((uint32_t) USART2), ((uint32_t) DMA_TX),       // 53 TX
        ((uint32_t) USART3), ((uint32_t) DMA_RX),       // 54 RX
        ((uint32_t) USART3), ((uint32_t) DMA_TX),       // 55 TX
        ((uint32_t) USART4), ((uint32_t) DMA_RX),       // 56 RX
        ((uint32_t) USART4), ((uint32_t) DMA_TX),       // 57 TX
        
        ((uint32_t) UCPD1),  ((uint32_t) DMA_RX),       // 58 RX
        ((uint32_t) UCPD1),  ((uint32_t) DMA_TX),       // 59 TX
        ((uint32_t) UCPD2),  ((uint32_t) DMA_RX),       // 60 RX
        ((uint32_t) UCPD2),  ((uint32_t) DMA_TX),       // 61 TX
        
        ((uint32_t) 0),      ((uint32_t) DMA_NONE),     // 62
        ((uint32_t) 0),      ((uint32_t) DMA_NONE)      // 63
    };
    
    //--------------------------------------------------------------------------
    static const uint32_t DMA_Channel_IRQn[DMA1_CHANNELS] = {
        ((uint32_t) DMA1_Channel1_IRQn),
        ((uint32_t) DMA1_Channel2_3_IRQn),
        ((uint32_t) DMA1_Channel2_3_IRQn),
        ((uint32_t) DMA1_Ch4_7_DMAMUX1_OVR_IRQn),
        ((uint32_t) DMA1_Ch4_7_DMAMUX1_OVR_IRQn),
        ((uint32_t) DMA1_Ch4_7_DMAMUX1_OVR_IRQn),
        ((uint32_t) DMA1_Ch4_7_DMAMUX1_OVR_IRQn),
    };
    
    //--------------------------------------------------------------------------
    #define DMA_CCR_OFFSET              ((uint32_t)0x08)
    #define DMA_CCR_OFFSET_EN           0
    #define DMA_CCR_OFFSET_DIR          4
    #define DMA_CCR_OFFSET_CIRC         5
    #define DMA_CCR_OFFSET_PINC         6
    #define DMA_CCR_OFFSET_MINC         7
    #define DMA_CCR_OFFSET_PSIZE        8
    #define DMA_CCR_OFFSET_MSIZE        10
    #define DMA_CCR_OFFSET_PL           12
    #define DMA_CCR_OFFSET_M2M          14
    #define DMA_SIZE                    ((uint32_t)0x0D20)
    #define DMA_CHANNEL_SIZE            ((uint32_t)0x14)
    #define DMA_ISR_TC                  DMA_ISR_TCIF
    #define DMA_ISR_HT                  DMA_ISR_HTIF
    #define DMA_ISR_TE                  DMA_CCR_TEIE
    #define DMA_ISR_ALL                 (DMA_ISR_TCIF1 | DMA_ISR_HTIF1 | DMA_ISR_TEIF1| DMA_ISR_GIF1)
    #define DMA_CCR_ISR_COM             (DMA_CCR_TCIE | DMA_CCR_TEIE)
    #define DMA_CCR_ISR_ALL             (DMA_CCR_TCIE | DMA_CCR_HTIE | DMA_CCR_TEIE)
    #define DMA_CCR_BYTES               0
    #define DMA_CCR_WORDS               (DMA_CCR_PSIZE_0 | DMA_CCR_MSIZE_0)
    #define DMA_CCR_DWORDS              (DMA_CCR_PSIZE_1 | DMA_CCR_MSIZE_1)
    #define DMA_CCR_SEND_BYTES          (DMA_CCR_ISR_COM | DMA_CCR_DIR | DMA_CCR_MINC | DMA_CCR_BYTES)
    #define DMA_CCR_BLK_SEND_BYTES      (DMA_CCR_DIR | DMA_CCR_MINC | DMA_CCR_BYTES)
    #define DMA_CCR_RECEIVE_BYTES       (DMA_CCR_ISR_COM | DMA_CCR_MINC | DMA_CCR_BYTES)
    #define DMA_CCR_BLK_RECEIVE_BYTES   (DMA_CCR_ISR_COM | DMA_CCR_MINC | DMA_CCR_BYTES)
    #define DMA_CCR_PUSH_BYTES          (DMA_CCR_ISR_COM | DMA_CCR_DIR | DMA_CCR_BYTES)
    #define DMA_CCR_MOVE_BYTES          (DMA_CCR_PINC | DMA_CCR_MINC | DMA_CCR_BYTES | DMA_CCR_MEM2MEM)
    #define DMA_CCR_RECEIVE_WORDS       (DMA_CCR_ISR_COM | DMA_CCR_MINC | DMA_CCR_WORDS)
    #define DMA_CCR_RECEIVE_ADC         (DMA_CCR_ISR_ALL | DMA_CCR_CIRC | DMA_CCR_MINC | DMA_CCR_WORDS)
    #define DMA_CCR_SEND_DAC            (DMA_CCR_ISR_ALL | DMA_CCR_CIRC | DMA_CCR_MINC | DMA_CCR_DWORDS | DMA_CCR_DIR)
    #define CHANNEL_DEFAULT_PROFILE     DMA_CCR_SEND_BYTES
    #define DMA_IFCR_ALL                (DMA_IFCR_CGIF1|DMA_IFCR_CTCIF1|DMA_IFCR_CHTIF1|DMA_IFCR_CTEIF1)

    //-----------------------------------
    static const uint32_t DMA_FLAGS_WIDTH = 4;
    static const uint32_t DMA_ISR_FLAGS = 0x0000000F;
      
#ifdef __cplusplus
extern "C"{
#endif
  
    //---------------------------------------
    // funções básicas 
    DMA_Channel_TypeDef* DMA_GetFreeChannel();                                  // 1: New
    void DMA_ReleaseChannel(DMA_Channel_TypeDef*);                              // 2: New
    IRQn_Type DMA_GetChannelIRQn(DMA_Channel_TypeDef*h);                        // 3: New
    void DMA_SetPriority(DMA_Channel_TypeDef*, DMA_PRIORITIES);                 // 4: 
    DMA_PRIORITIES DMA_GetPriority(DMA_Channel_TypeDef*);                       // 5: 
    
    uint32_t DMA_ChannelIndex(DMA_Channel_TypeDef*);                            // 6:
    DMA_Channel_TypeDef* DMA_ChannelHandler(DMA_CHANNEL);                       // 7:

    // channel related
    bool DMA_SetChannel(DMA_Channel_TypeDef*);                                  // 8: NAdc, NSpi
    void DMA_ClearChannelInterrupts(DMA_Channel_TypeDef*);                      // 9: NAdc
    void DMA_EnableChannelInterrupts(DMA_Channel_TypeDef*);                     // 10:
    void DMA_DisableChannelInterrupts(DMA_Channel_TypeDef*);                    // 11: NAdc, NSpi
    bool DMA_CheckChannelInterrupts(DMA_Channel_TypeDef* CH, uint32_t);         // 12: NSpi
    
    // funções envolvendo DMA request (periféricos)
    uint32_t DMA_GetChannelRequest(uint32_t);   
    uint32_t DMA_GetPeripheralRequestNumber(uint32_t , DMA_OPERATIONS);         // 14:
    bool DMA_SetChannelRequest(DMA_Channel_TypeDef*, void*, DMA_OPERATIONS);    // 15:  

    // funções de transferência
    bool DMA_Send(void*, uint8_t*, uint8_t*, uint16_t);                         // 16: NSpi
    bool DMA_SendBytes(void*, uint8_t*, uint8_t*, uint16_t);                    // 17:
    bool DMA_Receive(void*, uint8_t*, uint8_t*, uint16_t);                      // 18: NSpi
    bool DMA_ReceiveBytes(void*, uint8_t*, uint8_t*, uint16_t);                 // 19:
    bool DMA_Move(uint8_t*, uint8_t*, uint16_t);                                // 20:
    bool DMA_CheckChannelTransferCompleted(DMA_Channel_TypeDef*);               // 21: NSpi    

#ifdef __cplusplus
}
#endif

#endif
//==============================================================================
