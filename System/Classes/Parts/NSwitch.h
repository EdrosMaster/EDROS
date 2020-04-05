//============================================================================//
// Title: EDROS: Switch abstraction driver class                              //
// Author: edros.master@pobox.com                                             //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM                                              //
//                     All rights reserved.                                   //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:                      //
//               opensource.org/licenses/BSD-3-Clause                         //
//============================================================================//
#ifndef NSWITCH_H
    #define NSWITCH_H

    #include "NInput.h"

namespace nswitch_space{

    //-----------------------------------
    enum swStatus {swReleased=0, swOn=0, swPressed=1, swOff=1};
    enum swStyle {swButton, swSwitch};
    enum swMode {swNormal = 0, swInverted=1};

    #define INVERTED        ((bool)mode)

    //-----------------------------------
    class NSwitch : private NInput{

        private:
            static const uint32_t __STATUS_OFF = 0L;
            static const uint32_t __STATUS_ON = 1L;
            static const uint32_t __PORT_WIDTH = 16L;
            static const uint32_t __PIN_STICK = 1L;
            static const uint32_t __DEFAULT_DEBOUNCE = 2L;

            //-------------------------
            swStatus status;
            swStyle style;
            swMode mode;
            unsigned int debounce;

            //-------------------------
            unsigned int change_counter;
            swStatus pin_status;

            //-------------------------
            void SetStatus(swStatus);
            swStatus GetStatus();
            void SetStyle(swStyle);
            swStyle GetStyle();
            void SetMode(swMode);
            swMode GetMode();
            unsigned int GetDebounce();
            void SetDebounce(unsigned int);

        //-------------------------------------------
        public:
            NSwitch(GPIO_TypeDef*, unsigned int);
            ~NSwitch(void);

            //---------------------------------------
            // METHODS
            virtual void Notify(NMESSAGE*);

            //---------------------------------------
            // EVENTS
            void (*OnChange)(void);
            void (*OnPress)(void);
            void (*OnRelease)(void);

            //---------------------------------------
            // PROPERTIES                                       < DEFAULT VALUES >
            bool Enabled;                                               // true
            property<NSwitch, enum swStatus, propRead> Status;          // ?
            property<NSwitch, enum swStyle, propReadWrite> Style;       // swButton
            property<NSwitch, enum swMode, propReadWrite> Mode;         // swInverted
            property<NSwitch, unsigned int, propReadWrite> Debounce;    // 2 (20 ms)
            using NComponent::Tag;

    };
    //------------------------------------
}
    using namespace nswitch_space;
#endif
//==============================================================================
