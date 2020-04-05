//============================================================================//
// Title: EDROS: Output pin abstraction driver class                          //
// Author: edros.master@pobox.com                                             //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM                                              //
//                     All rights reserved.                                   //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:                      //
//               opensource.org/licenses/BSD-3-Clause                         //
//============================================================================//
#ifndef NOUTPUT_H
    #define NOUTPUT_H

    #include "DRV_IO.h"
    #include "NComponent.h"

namespace noutput_space{

    //-----------------------------------
    enum ouLevel    {ouLow=0, ouHigh=1, ouTris=2};
    enum ouAccess   {ouQueued, ouImmediate};

    //-----------------------------------
    class NOutput: public NComponent{

        private:
            
            static const unsigned int __PORT_WIDTH = 16L;

            //-------------------------
            ouLevel  level;
            ouAccess access;
           
            //-------------------------
            IO_Config Pino_InitStructure;
            GPIO_TypeDef* porta;
    
        protected:            
            bool enabled;

        //------------------------------
        private:
            void WritePin(ouLevel);

            //--------------------------
            void SetEnabled(bool);
            bool GetEnabled();
            void SetLevel(ouLevel);
            ouLevel GetLevel();
            void SetAccess(ouAccess);
            ouAccess GetAccess();
            
        protected:
            void Refresh(ouLevel);
            
        //------------------------------
        public:
            NOutput();
            NOutput(GPIO_TypeDef*, unsigned int);
            ~NOutput(void);

            //---------------------------------------
            // METHODS
            void Toggle();            
            virtual void Notify(NMESSAGE*);

            //---------------------------------------
            // EVENTS

            //---------------------------------------
            // PROPERTIES                                           < DEFAULT VALUES >
            property<NOutput, bool, propReadWrite> Enabled;         // true
            property<NOutput, enum ouLevel, propReadWrite> Level;   // ouLow
            property<NOutput, enum ouAccess, propReadWrite> Access; // ouQueued

    };
    //------------------------------------
}
    using namespace noutput_space;
#endif
//==============================================================================
