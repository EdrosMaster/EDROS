//============================================================================//
// Title: EDROS: Output pin abstraction driver class (simplified)             //
// Author: edros.master@pobox.com                                             //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM                                              //
//                     All rights reserved.                                   //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:                      //
//               opensource.org/licenses/BSD-3-Clause                         //
//============================================================================//
#ifndef NTINYOUTPUT_H
    #define NTINYOUTPUT_H

    #include "DRV_IO.h"
    #include "Property.h"   

namespace ntinyoutput_space{

    //-----------------------------------
    enum toLevel    {toLow=0, toHigh=1, toTris=2};

    //-----------------------------------
    class NTinyOutput {

        private:
            
            static const unsigned int __PORT_WIDTH = 16L;

            //-------------------------
            toLevel  level;
           
            //-------------------------
            IO_Config Pino_InitStructure;
            GPIO_TypeDef* porta;
    
        protected:            
            bool enabled;

        //------------------------------
        private:
            void WritePin(toLevel);

            //---------------------------------------
            void SetEnabled(bool);
            bool GetEnabled();
            void SetLevel(toLevel);
            toLevel GetLevel();
            
        protected:
            void Refresh(toLevel);
            
        //------------------------------
        public:
            NTinyOutput();
            NTinyOutput(GPIO_TypeDef*, unsigned int);
            ~NTinyOutput(void);

            //---------------------------------------
            // METHODS
            void Toggle();            

            //---------------------------------------
            // EVENTS

            //---------------------------------------
            // PROPERTIES                                           < DEFAULT VALUES >
            property<NTinyOutput, bool, propReadWrite> Enabled;        // true
            property<NTinyOutput, enum toLevel, propReadWrite> Level;  // ouLow
    };
    //------------------------------------
}
    using namespace ntinyoutput_space;
#endif
//==============================================================================
