//============================================================================//
// Title: EDROS: Master-mode I2C abstraction driver class                     //
// Author: edros.master@pobox.com                                             //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM                                              //
//                     All rights reserved.                                   //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:                      //
//               opensource.org/licenses/BSD-3-Clause                         //
//============================================================================//
#ifndef NI2C_H
    #define NI2C_H

    #include "NTinyOutput.h"
    #include "DRV_DMA.h"
    #include "SysMessages.h"
    #include "NComponent.h"


//------------------------------------------------------------------------------
namespace niic_space {

    #define I2C_ISR_DISABLE         (I2Cx->CR1 &= ~(I2C_CR1_TCIE | I2C_CR1_TXIE | I2C_CR1_RXIE | I2C_CR1_ERRIE))
    #define I2C_TXDMA_ENABLE        (I2Cx->CR1 |= I2C_CR1_TXDMAEN)
    #define I2C_RXDMA_ENABLE        (I2Cx->CR1 |= I2C_CR1_RXDMAEN)
    #define I2C_TXDMA_DISABLE       (I2Cx->CR1 &= ~I2C_CR1_TXDMAEN)
    #define I2C_RXDMA_DISABLE       (I2Cx->CR1 &= ~I2C_CR1_RXDMAEN)
    #define I2C_DMA_DISABLE         (I2Cx->CR1 &= ~(I2C_CR1_TXDMAEN | I2C_CR1_RXDMAEN))

    #define I2C_ENABLE              (I2Cx->CR1 |= I2C_CR1_PE)
    #define I2C_DISABLE             (I2Cx->CR1 &= ~I2C_CR1_PE)
    #define I2C_IS_ENABLED          ((I2Cx->CR1 & I2C_CR1_PE)==I2C_CR1_PE)
    
    #define I2C_CR1_CONFIG          I2C_CR1_TXIE | I2C_CR1_RXIE | I2C_CR1_ERRIE | I2C_CR1_ANFOFF
    #define I2C_CR2_CONFIG          I2C_CR2_AUTOEND
    
    #define I2C_PACKET_SIZE_MAX     ((uint32_t) 255)
    
    #define I2C_START               (I2Cx->CR2 |= I2C_CR2_START)
    #define I2C_STOP                (I2Cx->CR2 |= I2C_CR2_STOP)

    enum iiRemapping { iiStandard, iiRemapped, iiRemapped1, iiRemapped2};
    enum iiBaudRates {  ii100kHz,  ii400kHz,   ii1000kHz};

    //----------------------------------------
    class NIic: public NComponent{
        private:
            struct{
                bool disable;
                bool MasterTxInProgress;
                bool MasterRxInProgress;
                bool MasterTxRxInProgress;
                uint32_t bytes_to_write;
                uint32_t bytes_written;
                uint32_t bytes_to_read;
                uint32_t bytes_read;
                uint8_t* bytes_pointer;
                uint8_t device_address[2];
                uint16_t device_id;
                uint8_t* external_buffer;

                I2C_TypeDef* I2Cx;
                DMA_Channel_TypeDef * DMA_TxChannel;
                DMA_Channel_TypeDef * DMA_RxChannel;
                uint16_t vector_index;
                iiBaudRates baud;
            };

        //-------------------------------------------
        private:
            I2C_TypeDef* GetPort();
            iiBaudRates GetBaudRate();
            void SetBaudRate(iiBaudRates);
            uint32_t GetDeviceId();
            void SetDeviceId(uint32_t);
            uint32_t GetDeviceId10();
            void SetDeviceId10(uint32_t);
        
        //-------------------------------------------
        protected:
            void WritePoll();
            void ReadPoll();
            void WriteISR();
            void ReadISR();
            void WriteDMA();
            void ReadDMA();
        
        //-------------------------------------------
        public:
            NIic(I2C_TypeDef*, iiRemapping);
            ~NIic(void);

            //---------------------------------------
            // METHODS
            void Open();
            void Close();
            virtual void Notify(NMESSAGE*);
            virtual void InterruptCallBack(NMESSAGE*);
            bool Write(uint8_t, uint8_t*, uint32_t);
            bool Write(uint16_t, uint8_t*, uint32_t);

            bool Read(uint8_t, uint8_t*, uint32_t);
            bool Read(uint16_t, uint8_t*, uint32_t);

            //---------------------------------------
            // EVENTS
            void (*OnError)(uint32_t);
            void (*OnReadCompleted)(uint8_t*, uint8_t);
            void (*OnWriteCompleted)(void);

            //---------------------------------------
            // PROPERTIES                                       < DEFAULT VALUES >
            bool AssistedReception;                                 // false
            bool AssistedTransmission;                              // false
            bool Blocking;                                          // true
            bool EnableDMA;                                         // false
            property<NIic, I2C_TypeDef*, propRead> Port;            // (?)
            property<NIic, iiBaudRates, propReadWrite> BaudRate;    // PCLK/32
            property<NIic, uint32_t, propReadWrite> DeviceId;       // 7-bit Id (slave)
            property<NIic, uint32_t, propReadWrite> DeviceId10;     // 10-bit Id (slave)
    };
    //-----------------------------------------------
}
    using  namespace niic_space;
#endif
//==============================================================================
