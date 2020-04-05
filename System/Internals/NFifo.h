//============================================================================//
// Title: EDROS: NFifo - General purpose first-in first-out buffer        	  //
// Author: edros.master@pobox.com											  //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM 											  //
// 					   All rights reserved.									  //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:					  //
//               opensource.org/licenses/BSD-3-Clause						  //
//============================================================================//
#ifndef NFIFO_H
    #define NFIFO_H

    #include <string.h>
    #include <stdint.h>

namespace nfifo_space{

	//--------------------------------------------
    typedef struct __NFIFO_PARAMS{
        uint32_t head;
        uint32_t tail;
        uint32_t counter;
        uint32_t tag;
    } _NFIFO_PARAMS;

	//--------------------------------------------
    typedef struct __NFIFO_FLAGS{
        uint32_t overflow:  1;
        uint32_t reserved: 31;
    } _NFIFO_FLAGS;

    //-------------------------------------------
	class NFifo{
		private:
            //-----------------------------------
            static const uint32_t __NFIFO_BUFFER_FIRST = 0L;
            static const uint32_t __NFIFO_LINE_SIZE = 65L;
            static const uint32_t __NFIFO_LINES_NUMBER = 10L;
            static const uint32_t __NFIFO_LINE_LENGTH_MAX =	255L;
            static const uint32_t __NFIFO_LINE_NUMBER_MAX = 20L;

			//-----------------------------------
			uint8_t* data;

		protected:
			uint32_t line_size;
			uint32_t lines;
			__NFIFO_PARAMS params;
            __NFIFO_FLAGS flags;

		private:
			void LocateLineDepth();
			void AllocateMemory(uint32_t, uint32_t);

		public:
			//-----------------------------------
			// METHODS
			NFifo(void);
			NFifo(uint32_t, uint32_t);
			~NFifo(void);
			bool Put(unsigned char*, uint32_t);
			uint32_t Get(unsigned char*);
			void GetControl(__NFIFO_PARAMS*);
			void Flush();
			void ClearOverflow();
            uint32_t Counter();
            uint32_t GetSize();

            //-----------------------------------
            // PROPERTIES						< DEFAULT VALUES >
            bool LockOnOverflow;                        // false
	};
	//-------------------------------------------
}
    using namespace nfifo_space;

#endif
//==============================================================================

