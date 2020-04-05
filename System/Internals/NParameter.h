//============================================================================//
// Title: EDROS: System parameters interface class						  	  //
// Author: edros.master@pobox.com											  //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM 											  //
// 					   All rights reserved.									  //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:					  //
//               opensource.org/licenses/BSD-3-Clause						  //
//============================================================================//
#ifndef NPARAMETER_H
    #define NPARAMETER_H
    #include "Property.h"
    #include "GenericTypeDefs.h"
namespace nparameter_space{

    //-----------------------------------
    class NParameter{

        private:
            static const uint8_t __STANDARD_PARAMETER = 0x01;
            uint8_t type;
            uint8_t GetType();
            
        public:
            //-------------------------------------------
            // METHODS
            NParameter(uint8_t);
            NParameter();
            ~NParameter();

            //-------------------------------------------
            // PROPERTIES									<DEFAULT VALUES>
            HANDLE  Handle;                                     // ?
            uint32_t Id;                                        // 0x01
            uint32_t Tag;                                       // 0
            property<NParameter, uint8_t, propRead> Type;       // 0.0
    };
};
    using namespace nparameter_space;
#endif
//==============================================================================
