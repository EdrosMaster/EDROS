//============================================================================//
// Title: EDROS: USART abstraction driver class                               //
// Author: edros.master@pobox.com                                             //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM                                              //
//                     All rights reserved.                                   //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:                      //
//               opensource.org/licenses/BSD-3-Clause                         //
//============================================================================//
#ifndef NSERIAL_H
    #define NSERIAL_H

    #include "DRV_IO.h"
    #include "DRV_DMA.h"
    #include "DRV_CPU.h"
    #include "NComponent.h"

#include <string.h>

namespace nserial_space {

    #define USART_IS_ENABLED            (bool)(USARTx->CR1 & USART_CR1_UE)
    #define USART_ENABLE                (USARTx->CR1 |= USART_CR1_UE)
    #define USART_TX_ENABLE             (USARTx->CR1 |= USART_CR1_TE)
    #define USART_RX_ENABLE             (USARTx->CR1 |= USART_CR1_RE)
    #define USART_DISABLE               (USARTx->CR1 &= ~USART_CR1_UE)
    #define USART_TX_DISABLE            (USARTx->CR1 &= ~USART_CR1_TE)
    #define USART_RX_DISABLE            (USARTx->CR1 &= ~USART_CR1_RE)

    #define USART_TXDMA_ENABLE          (USARTx->CR3 |= USART_CR3_DMAT)
    #define USART_RXDMA_ENABLE          (USARTx->CR3 |= USART_CR3_DMAR)
    #define USART_DMA_ENABLE            (USARTx->CR3 |= (USART_CR3_DMAT | USART_CR3_DMAR))
    #define USART_TXDMA_DISABLE         (USARTx->CR3 &= ~USART_CR3_DMAT)
    #define USART_RXDMA_DISABLE         (USARTx->CR3 &= ~USART_CR3_DMAR)
    #define USART_DMA_DISABLE           (USARTx->CR3 &= ~(USART_CR3_DMAT | USART_CR3_DMAR))

    #define USART_TX_EMPTY              (USARTx->ISR & USART_ISR_TXE_TXFNF)
    #define USART_RX_FULL               (USARTx->ISR & USART_ISR_RXNE_RXFNE)
    #define USART_TX_REGISTER           (USARTx->TDR)
    #define USART_RX_REGISTER           (USARTx->RDR)
    #define USART_ISR_ERRORS            USART_ISR_ORE | USART_ISR_FE | USART_ISR_PE
    #define USART_ERROR_OCURRED         (USARTx->ISR & USART_ISR_ERRORS)
    #define USART_REGS                  USART_TypeDef

    #define USART_NUMBER(x) ((unsigned int)(x) - (unsigned int)USART0_BASE)/sizeof(x)
    
    #define USART_IT_CTS_DISABLE        (USARTx->CR3 &= ~USART_CR3_CTSIE)
    #define USART_IT_ERRORS_DISABLE     (USARTx->CR3 &= ~USART_CR3_EIE)
    #define USART_IT_RXNE_DISABLE       (USARTx->CR1 &= ~USART_CR1_RXNEIE_RXFNEIE)
    #define USART_IT_TXE_DISABLE        (USARTx->CR1 &= ~USART_CR1_TXEIE_TXFNFIE)
    #define USART_IT_TC_DISABLE         (USARTx->CR1 &= ~USART_CR1_TCIE)
    #define USART_IT_IDLE_DISABLE       (USARTx->CR1 &= ~USART_CR1_IDLEIE)

    #define USART_IT_CTS_ENABLE         (USARTx->CR3 |= USART_CR3_CTSIE)
    #define USART_IT_ERRORS_ENABLE      (USARTx->CR3 |= USART_CR3_EIE)
    #define USART_IT_RXNE_ENABLE        (USARTx->CR1 |= USART_CR1_RXNEIE_RXFNEIE)
    #define USART_IT_TXE_ENABLE         (USARTx->CR1 |= USART_CR1_TXEIE_TXFNFIE)
    #define USART_IT_TC_ENABLE          (USARTx->CR1 |= USART_CR1_TCIE)
    #define USART_IT_IDLE_ENABLE        (USARTx->CR1 |= USART_CR1_IDLEIE)

    #define USART_IT_RXNE_CLEAR (USARTx->RQR |= USART_RQR_RXFRQ)
    #define USART_IT_TC_CLEAR (USARTx->ICR = USART_ICR_TCCF)
    #define USART_IT_CTS_CLEAR (USARTx->ICR = USART_ICR_CTSCF)
    #define USART_IT_ERRORS_CLEAR (USARTx->ICR = (USART_ICR_ORECF|USART_ICR_PECF|USART_ICR_FECF))
    #define USART_IT_ALL_CLEAR (USARTx->ICR = ((uint32_t)0x121BDF))
    #define USART_IT_IDLE_CLEAR (USARTx->ICR |= USART_ICR_IDLECF)

    #define USART_IT_TXE    USART_ISR_TXE
    #define USART_IT_TC     USART_ISR_TC
    #define USART_IT_ERR    (USART_ISR_PE | USART_ISR_FE | USART_ISR_ORE)
    
    #define DMA_CSELR_USART1            ((uint32_t)0x03)
    #define DMA_CSELR_USART2            ((uint32_t)0x04)
    #define DMA_CSELR_LPUART1           ((uint32_t)0x05)
    #define DMA_CSELR_USART4            ((uint32_t)0x0C)
    #define DMA_CSELR_USART5            ((uint32_t)0x0D)

    const unsigned int NSERIAL_BUFFERSIZE_DEFAULT = 32;
    const unsigned int NSERIAL_PACKET_SIZE_MAX = 32;
    const unsigned int FLAG_HALF = ((uint32_t)0x80000000U);

    //--------------------------------------------------------------------------
    const unsigned int NM_NSERIAL_PACKET = 0x10000050;

   //--------------------------------------------------------------------------
    typedef struct NSERIAL_BUFFER {
        uint8_t  Size;
        uint8_t  Length;
        uint8_t  NextByte;
        uint8_t* Buffer;

        NSERIAL_BUFFER(){
            Resize(NSERIAL_BUFFERSIZE_DEFAULT);
            NextByte = 0; Length = 0;
        }

        void Resize(uint8_t sz){
            Size = sz;
            Buffer = new uint8_t[Size];
            NextByte = Length = 0;
        }
        
        uint8_t Put(uint8_t dat){
            Buffer[NextByte++] = dat; return(++Length);
        }

        uint8_t Get(){
            uint8_t result = 0;
            if(NextByte < Length){ result = Buffer[NextByte++];}
            return(result);
        }

        void Reset(){
            for(uint8_t c = 0; c < Size; c++){ Buffer[c]=0;}
            Length = 0; NextByte = 0;
        }

        uint8_t Import(uint8_t* ExternalBuffer, uint8_t ExternalSize){
            if(ExternalSize > Size){ ExternalSize = Size;}
            Length = ExternalSize; NextByte = 0;
            for(uint8_t c = 0; c < Length; c++){Buffer[c] = ExternalBuffer[c];}
            return(Length);
        }

        uint8_t Export(uint8_t* ExternalBuffer){
            for(uint8_t c = 0; c < Length; c++){ ExternalBuffer[c] = Buffer[c];}
            return(Length);
        }

        void Export(NSERIAL_BUFFER* Destination){
            if(Destination->Size < Length){ return;}
            for(uint8_t c = 0; c < Length; c++){ Destination->Buffer[c] = Buffer[c];}
            Destination->Length = Length; Destination->NextByte = NextByte;
        }

    } NSERIAL_BUFFER;
    
    //-----------------------------------
    enum seRemapping { seStandard, seRemapped, seRemapped1, seRemapped2};

    enum seParity {seNoParity=0, seEven=2, seOdd=3};

    enum seStopBits {seStop1 = 0, seStop05 = 1, seStop2 = 2, seStop15 = 3};

    enum seWordLen {seBits8 = 0, seBits9 = 1, seBits7 = 2};

    enum seTransferMode {seNoDMA = 0, seDMA = 1, seOff = 2};

    enum seFlowControl {seNoFlowControl = 0,
                        seOnlyRTS = 1,
                        seOnlyCTS = 2,
                        seFullFlowControl = 3,
                        seRS485 = 4,
                        seSingleWire = 5};

    //-----------------------------------
    class NSerial: public NComponent{

        static const int DEFAULT_PACKET_TIMEOUT         = 5;
        static const int MAXIMUM_PACKET_TIMEOUT         = 1000;
        static const int DEFAULT_TRANSMISSION_TIMEOUT   = 5;
        static const int MAXIMUM_TRANSMISSION_TIMEOUT   = 1000;

        protected:
            USART_TypeDef* USARTx;
            bool AssistedReception;                                         // false
            bool AssistedTransmission;                                      // false
            void RestartPacket();

        private:
            //-------------------------
            unsigned int baud;
            seWordLen wordlength;
            seStopBits stopbits;
            seParity parity;
            seTransferMode rxmode;
            seTransferMode txmode;
            seFlowControl flowcontrol;
            unsigned int packetsize;

            seRemapping remapped;
            unsigned short vector_index;
            unsigned short vector_base;

            //-------------------------
            IRQn_Type   USART_IRQn;
            DMA_Channel_TypeDef* DMAChannelTx;
            DMA_Channel_TypeDef* DMAChannelRx;

            unsigned int LastSize;
            unsigned int IRQChannelTx;
            unsigned int IRQChannelRx;

            //-------------------------
            bool flagReceiving;
            int receiving_counter;
            int reception_timeout;
            int packet_timeout;

            //-------------------------
            bool flagTransmitting;
            int transmitting_counter;
            int transmission_timeout;

            //-------------------------
            bool flagReading;
            bool flagWriting;
            
            //-------------------------
            bool pacoteInicializado;
            NSERIAL_BUFFER* PacoteLocalRx;
            NSERIAL_BUFFER* PacoteDisponivelRx;

            //-------------------------
            NSERIAL_BUFFER *PacoteLocalTx;
            NSERIAL_BUFFER* PacoteDisponivelTx;
            bool busy;
            
        //-------------------------------------------
        private:
            void SetDmaReception(unsigned char*, unsigned int);
            bool ReloadTxFifo();
            void StartTimeout(unsigned int);
            void StopTimeout();
            bool PackData(unsigned char);

            //---------------------------------------
            bool GetIsOpen();
            void SetBaudRate(unsigned int);
            unsigned int GetBaudRate();
            void SetWordLength(seWordLen);
            seWordLen GetWordLength();
            void SetParity(seParity);
            seParity GetParity();
            void SetStopBits(seStopBits);
            seStopBits GetStopBits();
            void SetRxMode(seTransferMode);
            seTransferMode GetRxMode();
            void SetTxMode(seTransferMode);
            seTransferMode GetTxMode();
            void SetFlowControl(seFlowControl);
            seFlowControl GetFlowControl();
            void SetPacketSize(unsigned int);
            unsigned int GetPacketSize();
            void SetTimeout(unsigned int);
            unsigned int GetTimeout();
            USART_REGS* GetPort();
            void SetTransmissionTimeout(int);
            int GetTransmissionTimeout();
            void SetBufferSize(int);
            int GetBufferSize();

        protected:
            virtual bool BuildDatagram(unsigned char*, unsigned char);
            virtual void DiscardDatagram(unsigned char*, unsigned char);

        //-------------------------------------------
        public:
            NSerial();
            NSerial(USART_REGS*, seRemapping);
            ~NSerial(void);
            virtual void Notify(NMESSAGE*);
            virtual void InterruptCallBack(NMESSAGE*);

            //---------------------------------------
            // METHODS
            void Open();
            void Close();
            void Flush();
            void Read(unsigned char, unsigned int);
            bool Write(unsigned char*, unsigned int);

            //--------------------------------------
            // EVENTS
            void (*OnError)(unsigned short);
            void (*OnTimeout)(void);
            void (*OnPacket)(unsigned char*, unsigned char);
            void (*OnCTS)(void);
            void (*OnIdleDetected)(void);
            void (*OnReadCompleted)(unsigned char*, unsigned char);
            void (*OnWriteCompleted)(void);
            void (*OnEnterTransmission)(void);
            void (*OnLeaveTransmission)(void);

            //--------------------------------------
            // PROPERTIES                                                   < DEFAULT VALUES >
            property<NSerial, bool, propRead> IsOpen;                       // false
            property<NSerial, USART_TypeDef*, propRead> Port;              // (?)
            property<NSerial, unsigned int, propReadWrite> BaudRate;           // 115200
            property<NSerial, enum seWordLen, propReadWrite> WordLength;       // seBits8
            property<NSerial, enum seParity, propReadWrite> Parity;            // seNoParity
            property<NSerial, enum seStopBits, propReadWrite> StopBits;        // seStop1
            property<NSerial, enum seTransferMode, propReadWrite> RxMode;      // seDMA
            property<NSerial, enum seTransferMode, propReadWrite> TxMode;      // seDMA
            property<NSerial, enum seFlowControl, propReadWrite> FlowControl;  // seNoFlowControl
            property<NSerial, unsigned int, propReadWrite> PacketSize;         // 1 (byte)
            property<NSerial, unsigned int, propReadWrite> Timeout;            // 5 (ms)
            property<NSerial, int, propReadWrite> TransmissionTimeout;          // 5 (ms)
            property<NSerial, int, propReadWrite> BufferSize;                   // NSERIAL_PACKET_SIZE_MAX
    };
    
    //--------------------------------------------
}

using  namespace nserial_space;

#endif
//==============================================================================
