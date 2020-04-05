//============================================================================//
// Title: EDROS Driver - Core resources driver for STM32G0xx                  //
// Author: edros.master@pobox.com											  //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM 											  //
// 					   All rights reserved.									  //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:					  //
//               opensource.org/licenses/BSD-3-Clause						  //
//============================================================================//
#ifndef DRV_CPU_H
    #define DRV_CPU_H

#ifdef __cplusplus
extern "C"{
#endif
#include <stdint.h>
#include "stm32G0xx.h"

#define IWDG_ENABLE                     ((uint32_t)0x0000CCCC)
#define IWDG_WRITE_ACCESS               ((uint32_t)0x00005555)
#define IWDG_REFRESH                    ((uint32_t)0x0000AAAA)
#define IWDG_RELOAD                     ((uint32_t)100)

#define WATCHDOG_FLAG_SET               0x20000000
#define WATCHDOG_FLAG_REMOVER           0x00800000
#define SOFTRESET_FLAG_SET              0x10000000
#define SOFTRESET_FLAG_REMOVER          0x00800000

#define HSI_FREQUENCY                   16000000
//------------------------------------------------------------------------------
enum cpuRanges { 
    cpuRange2Low    = 8000000,      // PWR: Vcore = 1.0V, FLASH: 0 WS  (PCLK <= 8MHz)
    cpuRange2High   = 16000000,     // PWR: Vcore = 1.0V, FLASH: 1 WS  (PCLK <= 16MHz) 
    cpuRange1Low    = 24000000,     // PWR: Vcore = 1.2V, FLASH: 0 WS  (PCLK <= 24MHz) 
    cpuRange1Mid    = 48000000,     // PWR: Vcore = 1.2V, FLASH: 1 WS  (PCLK <= 48MHz) 
    cpuRange1High   = 64000000      // PWR: Vcore = 1.2V, FLASH: 2 WS  (PCLK <= 64MHz) 
};

//------------------------------------------------------------------------------
enum HsiFrequencies { Hsi16MHz, Hsi08MHz, Hsi04MHz, Hsi02MHz, Hsi01MHz, Hsi500kHz, Hsi250kHz, Hsi125kHz};   
enum hsePllFrequencies { hsePll16MHz, hsePll32MHz, hsePll64MHz};
enum hsiPllFrequencies { hsiPll32MHz, hsiPll64MHz};

//------------------------------------------------------------------------------
// PLL Parameters: M, N, P, Q, R
// Fvco = HSE / M * N: must be in the range of 64MHz to 344MHz
// Constraints: 8 <= N <= 85, 1 <= M <= 8, 1 <= R <=7 
// PLL Parameters: M, N, P, Q, R
// HSE = Xtal: 8MHz
const uint32_t hsePllFactors[3][5] = {
    {0, 16, 7, 7, 7},   // PCLK = 16MHz
    {0, 16, 3, 3, 3},   // PCLK = 32MHz
    {0, 16, 1, 1, 1},   // PCLK = 64MHz
};

//------------------------------------------------------------------------------
// PLL Parameters: M, N, P, Q, R
// Fvco = HSI / M * N: must be in the range of 64MHz to 344MHz
// Constraints: 8 <= N <= 85, 1 <= M <= 8, 1 <= R <=7 
// HSI: 16MHz
const uint32_t hsiPllFactors[2][5] = {
    {0, 8, 3, 3, 3},    // PCLK = 32MHz
    {0, 8, 1, 1, 1},    // PCLK = 64MHz
};

// core clock control
void CPU_StartHSE(void);
void CPU_StartHsePll(hsePllFrequencies CpuSpeed);
void CPU_StartHSI(HsiFrequencies NewFreq);
void CPU_StartHsiPll(hsiPllFrequencies CpuSpeed);

bool CPU_PeripheralClockEnable(void*);
bool CPU_PeripheralClockDisable(void*);

// watchdog
void CPU_InitializeWatchdog(uint16_t);
bool CPU_CheckWatchdog();
void CPU_KickWatchdog();

// core functions
void CPU_Reset();
uint32_t CPU_Crc32(uint8_t*, uint16_t);
void CPU_RelocateVectors(int);
void CPU_AllocateVector(unsigned int, unsigned int);
void CPU_RelocateVectos();

#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------

#endif
//==============================================================================

