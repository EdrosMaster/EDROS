//============================================================================//
// Title: Base class for communications commands                           	  //
// Author: edros.master@pobox.com											  //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM 											  //
// 					   All rights reserved.									  //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:					  //
//               opensource.org/licenses/BSD-3-Clause						  //
//============================================================================//
#ifndef NCOMMAND_H
    #define NCOMMAND_H

    #include "GenericTypeDefs.h"
namespace ncommand_space{

    //-----------------------------------
    class NCommand{

        public:
            HANDLE  Handle;
            unsigned int Tag;
            union {
                unsigned int ID32;
                unsigned short ID16;
                unsigned char ID;
                unsigned char IDH;
            };

        public:
            NCommand();
            ~NCommand();
            virtual void Notify(NMESSAGE*);
            virtual void InterruptCallBack(NMESSAGE*);
    };
};
    using namespace ncommand_space;
#endif
//==============================================================================
