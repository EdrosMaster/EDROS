//============================================================================//
// Title: EDROS: System components interface class						  	  //
// Author: edros.master@pobox.com											  //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM 											  //
// 					   All rights reserved.									  //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:					  //
//               opensource.org/licenses/BSD-3-Clause						  //
//============================================================================//
#ifndef NCOMPONENT_H
    #define NCOMPONENT_H
	
    #include "DRV_SSR.h"
    #include "GenericTypeDefs.h"
    #include "SysMessages.h"
    #include "Priorities.h"
    #include "Property.h"

namespace ncomponent_space{
	
  	enum nPriorities {nTimeCritical=0, nNormal=1, nRelaxed=2};
	
    //-----------------------------------
    class NComponent{

        private:

        protected:

        public:
            HANDLE  Handle;
            uint32_t Tag;

        public:
            NComponent();
            ~NComponent();
            virtual void Notify(NMESSAGE*);
            virtual void InterruptCallBack(NMESSAGE*);
			nPriorities Priority;
    };
};
    using namespace ncomponent_space;
#endif
//==============================================================================
