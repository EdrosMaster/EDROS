//============================================================================//
// Title: EDROS: PWM abstraction driver class                                 //
// Author: edros.master@pobox.com                                             //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM                                              //
//                     All rights reserved.                                   //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:                      //
//               opensource.org/licenses/BSD-3-Clause                         //
//============================================================================//
#ifndef NPWM_H
    #define NPWM_H

    #include "DRV_IO.h"
    #include "DRV_CPU.h"
    #include "NComponent.h"
    #include "Priorities.h"
    #include "Property.h"

//------------------------------------------------------------------------------
namespace npwm_space{

    //-----------------------------------
    enum pwResolutions { pw4Bits=16, pw8Bits=256, pw10Bits=1024, pw12Bits=4096, pw16Bits=65536};
    enum pwChannels { pwCh1, pwCh2, pwCh3, pwCh4};
    enum pwPolarities { pwDutyHigh, pwDutyLow};

    class pwChannel {
        TIM_TypeDef* TIMc;
        NComponent* owner;
        uint32_t index;
        uint32_t offset;
        float duty;
        bool active;

        private:
            void SetEnabled(bool);
            bool GetEnabled();
            void SetDuty(float);
            float GetDuty();
            void SetPolarity(pwPolarities);
            pwPolarities GetPolarity();

        public:
            pwChannel(TIM_TypeDef*, pwChannels);
            void PinSelection(GPIO_TypeDef*, uint32_t, uint32_t);
            
            property<pwChannel, bool, propReadWrite>            Enabled;
            property<pwChannel, float, propReadWrite>           Duty;
            property<pwChannel, pwPolarities, propReadWrite>    Polarity;
    };
    
    #define CR1_DEFAULT         (TIM_CR1_ARPE)
    #define CR2_DEFAULT         ((uint16_t) 0)
    
    class NPwm: public NComponent{
      
        private:
            //-------------------------
            pwResolutions resolution;
            float duty;

            //--------------------------
            void SetEnabled(bool);
            bool GetEnabled();
            pwResolutions GetResolution();
            void SetResolution(pwResolutions);
            uint32_t GetFrequency();
            void SetPrescaler(uint16_t);
            void SetDuty(float);
            float GetDuty();
            void SetPolarity(pwPolarities);
            
        //-------------------------------
        protected:
            TIM_TypeDef* TIMx;

        //-----------------------------------------------
        public:
            
            //-------------------------------------------
            // METHODS
            NPwm(TIM_TypeDef*);
            virtual void Notify(NMESSAGE*);

            //-------------------------------------------
            // EVENTS

            //-------------------------------------------
            // PROPERTIES                                           < DEFAULT VALUES >
            property<NPwm, bool, propReadWrite> Enabled;                // true
            property<NPwm, pwResolutions, propReadWrite> Resolution;    // pw8Bits
            property<NPwm, float, propReadWrite> Duty;                  // 50.0 (normalized in %)
            property<NPwm, pwPolarities, propRead> Polarity;            // pwDutyHigh
            property<NPwm, uint32_t, propRead> Frequency;               // ? (PCLK)
            property<NPwm, uint16_t, propWrite> Prescaler;              // 1 (div by 1)
            pwChannel* Channel1;
            pwChannel* Channel2;
            pwChannel* Channel3;
            pwChannel* Channel4;
    };
};
//------------------------------------------------------------------------------

using namespace npwm_space;
#endif
//==============================================================================
