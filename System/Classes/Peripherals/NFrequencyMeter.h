//============================================================================//
// Title: EDROS: NCapture - Timer Capture abstraction driver class            //
// Version: 1.0.0                                                             //
// Author: edros.master@pobox.com                                             //
// Date: 29/02/2020                                                           //
// Last Update: 29/02/2020                                                    //
// Compiler: Keil MDK-ARM Cortex-M0++ for ST V5.28.0.0                        //
//============================================================================//
#ifndef NFREQUENCYMETER_H
    #define NFREQUENCYMETER_H

    #include "DRV_CPU.h"
    #include "DRV_IO.h"
    #include "NComponent.h"
    #include "NFilter.h"

//------------------------------------------------------------------------------
namespace nfrequencymeter_space{
    #define LSBITS  ((uint32_t)16)
  
    #define TRIG_SAMPLES_TIMEOUT    5
  
    typedef struct NCaptureIIData {
        uint16_t duty;
        uint16_t period;
    } NCaptureIIData;
    
    enum fqChannels { fqCh1, fqCh2, fqCh3, fqCh4};
    enum fqRanges   {fq100Hz, fq1kHz, fq10kHz, fq100kHz};
    
    class NFrequencyMeter: public NComponent{
        private:

            static const uint16_t DEFAULT_INTERVAL  = 0xFFFF;

            //-------------------------
            unsigned short vector_index;
            fqChannels channel;
            NFilter* Period;
            NFilter* Duty;
            uint32_t decimation_factor;
            fqRanges range;
            uint32_t div;
        
        //-----------------------------
        protected:
            TIM_TypeDef* TIMx;
            IRQn_Type TIM_IRQn;
            uint32_t pulses;

        //-----------------------------
        private:
            void SetEnabled(bool);
            bool GetEnabled();
            void SetDecimation(uint32_t);
            uint32_t GetDecimation();
            void SetRange(fqRanges);
            fqRanges GetRange();

        //-------------------------------
        protected:
        
        //-----------------------------------------------
        public:
            NFrequencyMeter();
            NFrequencyMeter(TIM_TypeDef*, fqChannels);
            ~NFrequencyMeter();

            //-------------------------------------------
            // METHODS
            void SetPin(GPIO_TypeDef*, uint32_t, uint32_t);
            void Start();
            void Stop();
            void Restart();
            virtual void InterruptCallBack(NMESSAGE*);
            virtual void Notify(NMESSAGE*);

            //-------------------------------------------
            // EVENTS
            //void (*OnTriggered)();
            void (*OnCapture)(uint16_t, uint16_t);
            void (*OnUpdateFrequency)(uint32_t);
            void (*OnOutOfRange)();

            //-------------------------------------------
            // PROPERTIES                                           < Default Values >
            property<NFrequencyMeter, bool, propReadWrite> Enabled;         // false
            property<NFrequencyMeter, uint32_t, propReadWrite> Decimation;  // 10
            property<NFrequencyMeter, enum fqRanges, propReadWrite> Range;  // fq1kHz

    };
};

using namespace nfrequencymeter_space;
#endif
//==============================================================================
