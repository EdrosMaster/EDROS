//============================================================================//
// Title: EDROS: General Purpose Timer abstraction driver class               //
// Author: edros.master@pobox.com                                             //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM                                              //
//                     All rights reserved.                                   //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:                      //
//               opensource.org/licenses/BSD-3-Clause                         //
//============================================================================//
#ifndef NHARDTIMER_H
    #define NHARDTIMER_H

    #include "DRV_CPU.h"
    #include "NComponent.h"
    //#include "Priorities.h"

//------------------------------------------------------------------------------
namespace nhardtimer_space{

    //-----------------------------------
    enum htMode {htContinuous=0, htSingleRun=1};
    enum htBlockingModes {htNonBlocking=0, htNotifyBlocking=1, htFullBlocking};

    class NHardTimer: public NComponent{
        private:

            static const uint16_t DEFAULT_PRESCALER = 31L;
            static const uint16_t DEFAULT_INTERVAL  = 100L;

            //-------------------------
            unsigned short vector_index;

        //-----------------------------
        protected:
            TIM_TypeDef* TIMx;
            IRQn_Type TIM_IRQn;
            uint16_t prescaler;
            uint16_t reload;
            uint16_t config1;
            uint16_t config2;

        //-----------------------------
        private:
            void SetEnabled(bool);
            bool GetEnabled();
            void SetMode(htMode);
            htMode GetMode();
            void SetInterval(uint16_t);
            uint16_t GetInterval();
            void SetPrescaler(uint16_t);
            uint16_t GetPrescaler();
            void SetBuffered(bool);
            bool GetBuffered();

            void SaveRegisters();
            void ReloadRegisters();

        //-------------------------------
        protected:
            virtual bool ProcessEvent();

        //-----------------------------------------------
        public:
            NHardTimer();
            NHardTimer(TIM_TypeDef*);
            ~NHardTimer();

            //-------------------------------------------
            // METHODS
            void Start(unsigned short);
            void Stop();
            void Wait(unsigned short);
            uint16_t SetPrescaler1us();
            uint16_t SetPrescaler1ms();
            virtual void InterruptCallBack(NMESSAGE*);
            virtual void Notify(NMESSAGE*);

            //-------------------------------------------
            // EVENTS
            void (*OnTimer)(void);

            //-------------------------------------------
            // PROPERTIES                                               <DEFAULT VALUES>
            property<NHardTimer, bool, propReadWrite> Enabled;              // false
            property<NHardTimer, uint16_t, propReadWrite> Prescaler;        // __PRESCALER_VALUE [(SystemCoreClock/1.000.000)-1]
            property<NHardTimer, uint16_t, propReadWrite> Interval;         // __INTERVAL_VALUE (100)
            property<NHardTimer, enum htMode, propReadWrite> Mode;          // htContinuous
            property<NHardTimer, bool, propReadWrite> Buffered;             // true (Buffered Reload)
            htBlockingModes Block;                                          // htNonBlocking
            bool NotifyEvents;                                              // false
    };
};

using namespace nhardtimer_space;
#endif
//==============================================================================
