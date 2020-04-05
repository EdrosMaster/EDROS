//============================================================================//
// Title: EDROS: Software timer component						  	  		  //
// Author: edros.master@pobox.com											  //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM 											  //
// 					   All rights reserved.									  //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:					  //
//               opensource.org/licenses/BSD-3-Clause						  //
//============================================================================//
#ifndef NTIMER_H
    #define NTIMER_H

    #include "NComponent.h"

namespace ntimer_space{

    //-----------------------------------
    enum tmMode {tmContinuous=0, tmSingleRun=1};

    class NTimer: public NComponent{
        private:
            static const unsigned int __NTIMER_DEFAULT_TIMEOUT = 100;

            //-------------------------
            unsigned int interval;
            tmMode mode;
            bool enabled;

            //-------------------------
            unsigned int timeout_counter;
            unsigned int timeout_value;
            bool done;
            bool iDone;

            //-------------------------------------------
            void SetEnabled(bool);
            bool GetEnabled();
            void SetDone(bool);
            bool GetDone();
            void SetMode(tmMode);
            tmMode GetMode();
            void SetInterval(unsigned int);
            unsigned int GetInterval();

        //-----------------------------------------------
        public:
            NTimer();
            ~NTimer();

            //-------------------------------------------
            // METHODS
            void Start(unsigned int);
            void Stop();
            virtual void Notify(NMESSAGE*);

            //-------------------------------------------
            // EVENTS
            void (*OnTimer)(void);

            //-------------------------------------------
            // PROPERTIES										< DEFAULT PARAMETERS>
            property<NTimer, bool, propReadWrite> Enabled;          // false
            property<NTimer, unsigned int, propReadWrite> Interval; // 100 (ms)
            property<NTimer, enum tmMode, propReadWrite> Mode;      // tmContinuous
            property<NTimer, bool, propReadWrite> Done;             // false

    };
};

using namespace ntimer_space;
#endif
//==============================================================================
