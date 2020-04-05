//============================================================================//
// Title: EDROS: ADC abstraction driver class                                 //
// Author: edros.master@pobox.com                                             //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM                                              //
//                     All rights reserved.                                   //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:                      //
//               opensource.org/licenses/BSD-3-Clause                         //
//============================================================================//
#ifndef NADC_H
    #define NADC_H

    #include "DRV_IO.h"
    #include "DRV_DMA.h"
    #include "DRV_CPU.h"
    #include "NComponent.h"

    #define ADC_CHANNELS_MAX 18
    #define TEMP130_CAL_ADDR ((uint16_t*) ((uint32_t) 0x1FF8007E))
    #define TEMP30_CAL_ADDR ((uint16_t*) ((uint32_t) 0x1FF8007A))
    #define VDD_CALIB ((uint16_t) (300))
    #define VDD_APPLI ((uint16_t) (330))
    #define BLANK_UPPER ((uint32_t)0x00000FFF)
    #define BLANK_LOWER ((uint32_t)0x0FFF0000)
    #define ADC_ISR_ALL (ADC_ISR_ADRDY|ADC_ISR_EOSMP|ADC_ISR_EOC|ADC_ISR_EOSEQ|ADC_ISR_OVR|ADC_ISR_AWD1|ADC_ISR_EOCAL)

namespace nadc_space{

    //-----------------------------------------------------
    enum adModes        {adSingle, adContinuous1, adContinuous2, adContinuous3};

    enum adChannels     {adCH0,  adCH1,  adCH2,  adCH3,    adCH4,  adCH5,  adCH6,  adCH7,
                         adCH8,  adCH9,  adCH10, adCH11,   adCH12, adCH13, adCH14,
                         adCH15, adCH16, adVref, adThermo, adNoCH};

    enum adTimeTriggers {adTIM1_TRGO2, adTIM1CC4, adTIM2TRGO, adTIM3TRGO, adTIM15TRGO, adTIM6TRGO, adTIMreserved, adEXTI_11};

    //-----------------------------------------------------
    const uint16_t Channels[16]={
        (__PORTA | __PIN0), // ADC_IN0
        (__PORTA | __PIN1), // ADC_IN1
        (__PORTA | __PIN2), // ADC_IN2
        (__PORTA | __PIN3), // ADC_IN3
        (__PORTA | __PIN4), // ADC_IN4
        (__PORTA | __PIN5), // ADC_IN5
        (__PORTA | __PIN6), // ADC_IN6
        (__PORTA | __PIN7), // ADC_IN7
        (__PORTB | __PIN0), // ADC_IN8
        (__PORTB | __PIN1), // ADC_IN9
        (__PORTC | __PIN0), // ADC_IN10
        (__PORTC | __PIN1), // ADC_IN11
        (__PORTC | __PIN2), // ADC_IN12
        (__PORTC | __PIN3), // ADC_IN13
        (__PORTC | __PIN4), // ADC_IN14
        (__PORTC | __PIN5), // ADC_IN15
    };

    //-----------------------------------------------------
    const uint32_t Triggers[8][2]={
        {(uint32_t)TIM1,    (uint32_t)TIM1_BRK_UP_TRG_COM_IRQn},
        {(uint32_t)TIM1,    (uint32_t)TIM1_CC_IRQn},
        {(uint32_t)TIM2,    (uint32_t)TIM2_IRQn},
        {(uint32_t)TIM3,    (uint32_t)TIM3_IRQn},
        {(uint32_t)TIM15,   (uint32_t)TIM15_IRQn},
        {(uint32_t)TIM6,    (uint32_t)TIM6_DAC_LPTIM1_IRQn},
        {(uint32_t)NULL,    (uint32_t)0},
        {(uint32_t)EXTI,    (uint32_t)EXTI4_15_IRQn},
    };

    //-----------------------------------------------------
    struct AD_SAMPLES{
        uint16_t* data;
        uint16_t  size;
    };

    //-----------------------------------------------------
    class NAdc : public NComponent{
        private:
            static const uint32_t DEFAULT_PERIOD = 1000L;

            //--------------------------------------------
            adModes mode;
            adTimeTriggers trigger;
            uint16_t samplingrate;

            //--------------------------------------------
            TIM_TypeDef*                TIMx;
            ADC_Common_TypeDef*         ADCc;
            ADC_TypeDef*                ADCx;
            DMA_Channel_TypeDef*        DMA_AdcChannel;
            uint16_t                    vector_index;
            AD_SAMPLES buffer[2L];

            //--------------------------------------------
            uint16_t convertion_counter;
            uint16_t convertion_period;
            HANDLE PreviousVector;

            //-------------------------------------------
            void SetMode(adModes);
            adModes GetMode();
            void SetTimeTrigger(adTimeTriggers);
            adTimeTriggers GetTimeTrigger();
            void SetLowerLimit(uint16_t);
            uint16_t GetLowerLimit();
            void SetUpperLimit(uint16_t);
            uint16_t GetUpperLimit();
            uint16_t GetSamplingRate();
            void SetChannel(adChannels);
            adChannels GetChannel();

            //-------------------------------------------
            void Enable(void);
            void Disable(void);
            void SetupInterrupt();
            void SetTimebase(uint16_t);
            uint32_t CountChannels();
            uint32_t CheckSpecialChannels();

        //-----------------------------------------------
        public:

            //-------------------------------------------
            // METHODS                                              < APLICABILITY >
            NAdc(ADC_TypeDef*);                                     // all modes
            ~NAdc(void);                                            // no mode
            bool AddChannel(adChannels);                            // all modes
            void FlushChannels();                                   // all modes
            void Start();                                           // adSingle mode only
            void Start(uint16_t);                                   // adContinuousx modes
            void Stop();                                            // adContinuousx modes
            bool SetDataBuffer(uint16_t*, uint16_t);                // adContinuous3 mode only
            int32_t Temperature(uint32_t);
        
            virtual void Notify(NMESSAGE*);
            virtual void InterruptCallBack(NMESSAGE*);

            //-------------------------------------------
            // EVENTS                                               < OCCURENCE >
            void (*OnData)(uint16_t);                               // all but adContinuous3
            void (*OnDataBlock)(uint16_t*, uint16_t);               // adContinuous3 only
            void (*OnUpperThreshold)(uint16_t);                     // all modes (adBoth, adLower)
            void (*OnLowerThreshold)(uint16_t);                     // all modes (adBoth, adUpper)

            //-------------------------------------------
            // PROPERTIES                                               <DEFAULT VALUES>
            property<NAdc, enum adModes, propReadWrite> Mode;               // adSingle
            property<NAdc, enum adTimeTriggers, propReadWrite> TimeTrigger; // adTIM6OV
            property<NAdc, uint16_t, propReadWrite> LowerLimit;             // 0x0000
            property<NAdc, uint16_t, propReadWrite> UpperLimit;             // 0x0FFF
            property<NAdc, uint16_t, propRead> ActiveChannels;              // 0
            property<NAdc, uint16_t, propRead> SamplingRate;                // 1000
            property<NAdc, adChannels, propReadWrite> Channel;              // adNoCH

    };
    //-----------------------------------------------------
}
    using namespace nadc_space;
#endif
//==============================================================================

