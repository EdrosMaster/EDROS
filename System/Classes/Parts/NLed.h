//============================================================================//
// Title: EDROS: Led abstraction driver class                                 //
// Author: edros.master@pobox.com                                             //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM                                              //
//                     All rights reserved.                                   //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:                      //
//               opensource.org/licenses/BSD-3-Clause                         //
//============================================================================//
#ifndef NLED_H
    #define NLED_H

    #include "NOutput.h"

namespace nled_space{

    enum ldStatus { ldOff, ldOn, ldOpen, ldBlinking, ldSignaling, ldPrevious};
    enum ldAccess { ldQueued, ldImmediate};
    enum ldDriver { ldNormal, ldInverted};

    static const int LED_INTERVAL_FAST      = 50;   //ms
    static const int LED_INTERVAL_MID       = 300;  //ms
    static const int LED_INTERVAL_SLOW      = 1000; //ms
    static const int LED_INTERVAL_DEFAULT   = 500;  //ms

    //-----------------------------------
    class NLed: public NOutput{

        private:
            //-------------------------
            static const unsigned int __PORT_WIDTH = 16L;
            
            //-------------------------
            ldStatus status;
            ldAccess access;
            ldDriver driver;
            uint32_t interval;
            uint32_t burst;

            //-------------------------
            ldStatus previous_status;
            uint8_t pin_status;
            uint32_t counter;

        //-------------------------------------------------
        private:
            void Repaint(ldStatus);
            
            //---------------------------------------------
            void SetStatus(ldStatus);
            ldStatus GetStatus();
            void SetAccess(ldAccess);
            ldAccess GetAccess();
            void SetDriver(ldDriver);
            ldDriver GetDriver();
            void SetInterval(uint32_t);
            uint32_t GetInterval();
            void SetBurst(uint32_t);
            uint32_t GetBurst();

        //------------------------------------------------
        public:
            NLed(GPIO_TypeDef*, unsigned int);
            ~NLed(void);

            //--------------------------------------------
            // METHODS
            void Toggle();
            virtual void Notify(NMESSAGE*);

            //--------------------------------------------
            // EVENTS
            void (*OnBurstFinished)(void);
                
            //--------------------------------------------
            // PROPERTIES                                   < DEFAULT VALUES >
            property<NLed, enum ldStatus, propReadWrite> Status;   // ldOff
            property<NLed, enum ldAccess, propReadWrite> Access;   // ldQueued 
            property<NLed, enum ldDriver, propReadWrite> Driver;   // ldNormal
            property<NLed, uint32_t, propReadWrite>      Interval; // 100 (ms)
            property<NLed, uint32_t, propReadWrite>      Burst;    // 0
            using NComponent::Tag;
            
    };
    //----------------------------------------------------
}
    using namespace nled_space;
#endif
//==============================================================================
