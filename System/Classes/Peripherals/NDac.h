//============================================================================//
// Title: EDROS: DAC abstraction driver class                                 //
// Author: edros.master@pobox.com                                             //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM                                              //
//                     All rights reserved.                                   //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:                      //
//               opensource.org/licenses/BSD-3-Clause                         //
//============================================================================//
#ifndef NDAC_H
    #define NDAC_H

    #include "NLowPowerTimer.h"
    #include "NHardTimer.h"
    #include "NAdc.h"

namespace ndac_space{

    //-----------------------------------
    enum daTriggers {daTimer2=2, daTimer3=3, daTimer6=5, daTimer7=6, daTimer15=8, daLpTimer1=11, daLpTimer2=12, daSynch=1}; 
    enum daActiveChannels {daChannel1 = 1, daChannel2 = 2, daBothChannels = 3};
    enum daConvertionModes {daManual, daAutoSingle, daAutoBlock, daTriangle, daNoise};
    enum daOutputModes  {daBufferedPinOnly = 0, daBufferedPinAndFeedback = 1,
                         daOutputPinOnly = 2, daFeedbackOnly = 3};
    enum daAlignments   {daRight = 0, daLeft = 1, daByte = 2};

    #define __DEFAULT_INTERVAL  ((uint16_t) 1000)

    //-----------------------------------
    class NDac : public NComponent{
        private:

            //-------------------------
            bool enabled;
            daConvertionModes mode;
            daOutputModes output1;
            daOutputModes output2;
            daActiveChannels channels;

            uint32_t rec_rate;
            uint32_t* DataRegister;

            //-------------------------
            DAC_TypeDef*            DACx;
            NComponent*             TIMx;
            DMA_Channel_TypeDef*    DMA_DacChannel;

            uint16_t                vector_index;
            uint32_t                DMA_DacChannelFlags;
            IRQn_Type               DMA_IRQn;
            IRQn_Type               TIM_IRQn;
            
            uint32_t*               ExternalBuffer;
            uint16_t                ExternalBufferSize;

            //-------------------------
            void StartManual();
            void StartSingle();
            void StartBlock();
            void StartTriangle();
            void StartNoise();
            void StopManual();
            void StopSingle();
            void StopBlock();
            void StopTriangle();
            void StopNoise();
            
            void SetupInterrupt();
            void SetTrigger(daTriggers);
            void Timebase(FunctionalState);
            uint16_t SetPrescaler1us();
            uint16_t SetPrescaler1ms();

            //-------------------------
            void SetEnabled(bool);
            bool GetEnabled();
            void SetChannels(daActiveChannels);
            daActiveChannels GetChannels();
            void SetMode(daConvertionModes);
            daConvertionModes GetMode();
            void SetAlignment(daAlignments);
            daAlignments GetAlignment();
            void SetOutput1(daOutputModes);
            daOutputModes GetOutput1();
            void SetOutput2(daOutputModes);
            daOutputModes GetOutput2();
            
            void SetConvertionRate(uint32_t);
            uint32_t GetConvertionRate();

        //-----------------------------------------------
        public:
            NDac(DAC_TypeDef*, daTriggers);
            ~NDac(void);

            //-------------------------------------------
            // METHODS
            void SynchSource();
            void Write(uint32_t);
            void SetBlock(uint32_t*, uint16_t);
            virtual void Notify(NMESSAGE*);
            virtual void InterruptCallBack(NMESSAGE*);

            //-------------------------------------------
            // EVENTS
            void (*OnFeedNewSample)(uint32_t*);
            void (*OnFirstHalfConverted)();
            void (*OnSecondHalfConverted)();

            //-------------------------------------------
            // PROPERTIES                                               < DEFAULT VALUES >
            property<NDac, bool, propReadWrite> Enabled;                // false
            property<NDac, daActiveChannels, propReadWrite> Channels;   // daBothChannels
            property<NDac, enum daConvertionModes, propReadWrite> Mode; // daManual
            property<NDac, enum daOutputModes, propReadWrite> Output1;  // daFeedbackOnly
            property<NDac, enum daOutputModes, propReadWrite> Output2;  // daFeedbackOnly
            property<NDac, uint32_t, propReadWrite> ConvertionRate;     // 1000 (us)
            daAlignments Alignment;                                     // daRight
            
    };
    //------------------------------------
}
    using namespace ndac_space;
#endif
//==============================================================================
