//============================================================================//
// Title: EDROS: Master-mode SPI abstraction driver class                     //
// Author: edros.master@pobox.com                                             //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM                                              //
//                     All rights reserved.                                   //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:                      //
//               opensource.org/licenses/BSD-3-Clause                         //
//============================================================================//
#ifndef NSPI_H
    #define NSPI_H

    #include "NTinyOutput.h"
    #include "DRV_DMA.h"
    #include "SysMessages.h"
    #include "NComponent.h"

//------------------------------------------------------------------------------
namespace nspi_space {

    #define SPI_ISR_DISABLE         (SPIx->CR2 &= ~(SPI_CR2_TXEIE | SPI_CR2_RXNEIE | SPI_CR2_ERRIE))
    #define SPI_TXDMA_ENABLE        (SPIx->CR2 |= SPI_CR2_TXDMAEN)
    #define SPI_RXDMA_ENABLE        (SPIx->CR2 |= SPI_CR2_RXDMAEN)
    #define SPI_TXDMA_DISABLE       (SPIx->CR2 &= ~SPI_CR2_TXDMAEN)
    #define SPI_RXDMA_DISABLE       (SPIx->CR2 &= ~SPI_CR2_RXDMAEN)
    #define SPI_DMA_DISABLE         (SPIx->CR2 &= ~(SPI_CR2_TXDMAEN | SPI_CR2_RXDMAEN))
    #define SPI_ENABLE              (SPIx->CR1 |= SPI_CR1_SPE)
    #define SPI_DISABLE             (SPIx->CR1 &= ~SPI_CR1_SPE)
    #define SPI_IS_ENABLED          (SPIx->CR1 & SPI_CR1_SPE)
    #define SPI_CR1_CONFIG          (SPI_CR1_CPHA|SPI_CR1_CPOL|SPI_CR1_MSTR | SPI_CR1_SSM | SPI_CR1_SSI)
    #define SPI_CR2_CONFIG          (SPI_CR2_DS_0 | SPI_CR2_DS_1 | SPI_CR2_DS_2)<<SPI_CR2_DS_Pos | SPI_CR2_FRXTH
    
    #define MAX_SPI_PACKET_SIZE     ((uint32_t) 1024)

    enum spRemapping { spStandard, spRemapped, spRemapped1, spRemapped2};
    enum spBaudRates {  spPCLK_2,  spPCLK_4,   spPCLK_8,   spPCLK_16,  spPCLK_32,
                        spPCLK_64, spPCLK_128, spPCLK_256};

    //----------------------------------------
    class NSpi: public NComponent{
        private:
            struct{
                bool MasterTxInProgress;
                bool MasterRxInProgress;
                uint32_t ControlRegister1;
                uint32_t ControlRegister2;
                uint32_t bytes_to_write;
                uint32_t bytes_written;
                uint32_t bytes_read;
                uint8_t* bytes_pointer;
            };

            SPI_TypeDef* SPIx;
            DMA_Channel_TypeDef * DMA_TxChannel;
            DMA_Channel_TypeDef * DMA_RxChannel;
            uint16_t vector_index;
            spBaudRates baud;

        //-------------------------------------------
        private:
            SPI_TypeDef* GetPort();
            spBaudRates GetBaudRate();
            void SetBaudRate(spBaudRates);

        //-------------------------------------------
        protected:
            bool WritePoll(uint8_t*, uint32_t wlen);
            bool ReadPoll(uint8_t*, uint32_t wlen);
            bool WriteISR(uint8_t*, uint32_t wlen);
            bool ReadISR(uint8_t*, uint32_t wlen);
            bool WriteDMA(uint8_t*, uint32_t);
            bool ReadDMA(uint8_t*, uint32_t);
            void StartFrame();
            void StopFrame();
        
        //-------------------------------------------
        public:
            NSpi(SPI_TypeDef*, spRemapping);
            ~NSpi(void);

            //---------------------------------------
            // METHODS
            void Open();
            void Close();
            virtual void Notify(NMESSAGE*);
            virtual void InterruptCallBack(NMESSAGE*);
            bool Write(uint8_t*, uint32_t);
            bool Read(uint8_t*, uint32_t);

            //---------------------------------------
            // EVENTS
            void (*OnError)(uint32_t);
            void (*OnReadCompleted)(void);
            void (*OnWriteCompleted)(void);

            //---------------------------------------
            // PROPERTIES                                       < DEFAULT VALUES >
            bool AssistedReception;                                 // false
            bool AssistedTransmission;                              // false
            bool Blocking;                                          // true
            bool SingleStart;                                       // false
            bool EnableDMA;                                         // false
            NComponent* ChipSelect;                                 // NULL
            property<NSpi, SPI_TypeDef*, propRead> Port;            // (?)
            property<NSpi, spBaudRates, propReadWrite> BaudRate;    // PCLK/32
    };
    //-----------------------------------------------
}
    using  namespace nspi_space;
#endif
//==============================================================================
