//============================================================================//
// Title: EDROS: Low Power Timer abstraction driver class                     //
// Author: edros.master@pobox.com                                             //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM                                              //
//                     All rights reserved.                                   //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:                      //
//               opensource.org/licenses/BSD-3-Clause                         //
//============================================================================//
#ifndef NLOWPOWERTIMER_H
    #define NLOWPOWERTIMER_H

    #include "DRV_CPU.h"
    #include "NComponent.h"
    #include "Priorities.h"
    #include "Property.h"


//------------------------------------------------------------------------------
namespace nlowpowertimer_space{

    //-----------------------------------
    enum ltMode {ltContinuous=0, ltSingleRun=1};
    enum ltBlockingModes {ltNonBlocking=0, ltNotifyBlocking=1, ltFullBlocking};

    class NLowPowerTimer: public NComponent{
        private:

            static const uint16_t DEFAULT_PRESCALER = 31L;
            static const uint16_t DEFAULT_INTERVAL  = 100L;
            static const uint32_t LPTIM_ICR_ALL     = 0x7F;

            //-------------------------
            unsigned short vector_index;
            uint32_t arr;
            uint32_t cr;
            uint32_t cfgr;

        //-----------------------------
        protected:
            LPTIM_TypeDef*      TIMx;
            IRQn_Type           TIM_IRQn;

        //-----------------------------
        private:
            void SetEnabled(bool);
            bool GetEnabled();
            void SetInterval(unsigned short);
            unsigned short GetInterval();
            void SetPrescaler(uint8_t);
            uint8_t GetPrescaler();

            void SaveRegisters();
            void ReloadRegisters();

        //-------------------------------
        protected:
            virtual bool ProcessEvent();

        //-----------------------------------------------
        public:
            NLowPowerTimer();
            NLowPowerTimer(LPTIM_TypeDef*);
            ~NLowPowerTimer();

            //-------------------------------------------
            // METHODS
            void Start(unsigned short);
            void Stop();
            void Wait(unsigned short);
            uint32_t SetPrescaler1us();
            virtual void InterruptCallBack(NMESSAGE*);
            virtual void Notify(NMESSAGE*);

            //-------------------------------------------
            // EVENTS
            void (*OnTimer)(void);

            //-------------------------------------------
            // PROPERTIES                                                   < Default Values >
            property<NLowPowerTimer, bool, propReadWrite> Enabled;              // false
            property<NLowPowerTimer, uint8_t, propReadWrite> Prescaler;         // __PRESCALER_VALUE [(SystemCoreClock/1.000.000)-1]
            property<NLowPowerTimer, unsigned short, propReadWrite> Interval;   // __INTERVAL_VALUE (100)
            ltBlockingModes Block;                                              // ltNonBlocking
            ltMode Mode;
    };
};

using namespace nlowpowertimer_space;
#endif
//==============================================================================
