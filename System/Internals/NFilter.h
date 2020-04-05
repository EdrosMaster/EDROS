//============================================================================//
// Title: EDROS: General purpose moving average filter (M.A. Filter)		  //
// Author: edros.master@pobox.com											  //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM 											  //
// 					   All rights reserved.									  //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:					  //
//               opensource.org/licenses/BSD-3-Clause						  //
//============================================================================//
#ifndef NFILTERH
    #define NFILTERH
    #include "stdint.h"
	#include "property.h"

namespace nfilter_space{

    //-------------------------------------------
    class NFilter{

        private:
            static const unsigned short __DEFAULT_SIZE = 10;

            //-----------------------------------
            unsigned short* samples;
            unsigned short filter_size;
            unsigned short filter_last;
            unsigned short filter_first;
            unsigned short filter_index;
            unsigned int last_filtered;

        public:
            //-----------------------------------
            // METHODS
            NFilter(void);
            NFilter(uint8_t);
            NFilter(uint8_t, uint16_t);
            ~NFilter(void);
            unsigned int Filter(unsigned int);
			unsigned int Filter(unsigned short*, unsigned int);
			unsigned int Filter(unsigned short*, unsigned int, unsigned int);
            unsigned int Filter();
			//int16_t Filter(int16_t);
            void Resize(uint32_t);
            void Flush();
			void Fill(uint16_t);
			
            //--------------------------------------
            // PROPERTIES									< DEFAULT VALUES >
            property<NFilter, unsigned int, propRead> Value;    // 0

    };
    //-------------------------------------------
}
    using namespace nfilter_space;

#endif
//==============================================================================

