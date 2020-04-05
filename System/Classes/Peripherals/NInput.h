//============================================================================//
// Title: EDROS: Input pin abstraction driver class                           //
// Author: edros.master@pobox.com                                             //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM                                              //
//                     All rights reserved.                                   //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:                      //
//               opensource.org/licenses/BSD-3-Clause                         //
//============================================================================//
#ifndef NINPUT_H
    #define NINPUT_H

    #include "DRV_IO.h"
    #include "NComponent.h"

//------------------------------------------------------------------------------
namespace ninput_space {

    //-----------------------------------
    enum inLevel        {inLow, inHigh};
    enum inAccess       {inQueued, inImmediate, inInterrupt};
    enum inEdges        {inNoEdge, inRisingEdge, inFallingEdge, inRiseAndFall};
    enum inActions      {inInterrupts=0, inEvents=4, inNoInterrupts=8};

    const int PORT_WIDTH = 16;

    //-----------------------------------
    class NInput : public NComponent{

        private:
            //-------------------------
            inLevel level;
            inAccess access;
            inEdges  edge;
            bool inverted;

            //-------------------------
            IO_Config Pino_InitStructure;
            HANDLE PreviousVector;

            //-------------------------------------------
            inLevel GetLevel();
            void SetAccess(inAccess);
            inAccess GetAccess();
            void SetEdge(inEdges);
            inEdges GetEdge();
            void SetInverted(bool);
            bool GetInverted();

        protected:
            GPIO_TypeDef* porta;

            //-------------------------
            void SetupInterrupt();
            inLevel ReadPin();
            uint32_t GetVectorIndex();

        //-----------------------------------------------
        public:
            NInput(GPIO_TypeDef*, unsigned int);
            ~NInput(void);

            //-------------------------------------------
            // METHODS
            inLevel ReadInput();
            virtual void Notify(NMESSAGE*);
            virtual void InterruptCallBack(NMESSAGE*);

            //-------------------------------------------
            // EVENTS
            void (*OnLevelChange)(void);
            void (*OnRisingEdge)(void);
            void (*OnFallingEdge)(void);

            //-------------------------------------------
            // PROPERTIES                                       < DEFAULT VALUES >
            bool Enabled;                                           // true
            property<NInput, enum inLevel, propRead> Level;         // (?)
            property<NInput, enum inAccess, propReadWrite> Access;  // inQueued
            property<NInput, enum inEdges, propReadWrite> Edge;     // inFallingEdge
            property<NInput, bool, propReadWrite> Inverted;         // false

    };
    //------------------------------------
}
    using namespace ninput_space;
#endif
//==============================================================================
