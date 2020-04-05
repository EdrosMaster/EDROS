//============================================================================//
// Title: EDROS Driver: Low level GPIO for STM32G0xx                          //
// Author: edros.master@pobox.com											  //
//----------------------------------------------------------------------------//
// Copyright (c) 2020 EDROS TEAM 											  //
// 					   All rights reserved.									  //
// This software component is licensed by "EDROS TEAM" under BSD 3-Clause li- //
// cense, the "License"; You may not use this file except in compliance with  //
// the License. You may obtain a copy of the License at:					  //
//               opensource.org/licenses/BSD-3-Clause						  //
//============================================================================//
#ifndef DRV_IO_H
  #define DRV_IO_H

#include "stm32G071xx.h"
#include "Priorities.h"

//------------------------------------------------------------------------------
enum io_modes { io_in=0, io_out=1, io_af=2, io_anal=3};
enum io_otypes { io_pp=0, io_od=1};
enum io_speeds { io_ls=0, io_ms=1, io_hs=2, io_vh=3};
enum io_pulls { io_none=0, io_up=1, io_down=2, io_res=3};
enum io_funcs { io_af0=0, io_af1=1, io_af2=2, io_af3=3,
                io_af4=4, io_af5=5, io_af6=6, io_af7=7};

//------------------------------------------------------------------------------
#define IO_MASK_MODE    ((uint32_t)3)
#define IO_MASK_TYPE    ((uint32_t)1)
#define IO_MASK_SPEED   ((uint32_t)3)
#define IO_MASK_PULL    ((uint32_t)3)
#define IO_MASK_FUNC    ((uint32_t)7)
#define IO_MASK_EXTI    ((uint32_t)0x000000FF)

#define IO_FIELD_MODE   ((uint32_t)2)
#define IO_FIELD_TYPE   ((uint32_t)1)
#define IO_FIELD_SPEED  ((uint32_t)2)
#define IO_FIELD_PULL   ((uint32_t)2)
#define IO_FIELD_FUNC   ((uint32_t)4)
#define IO_FIELD_INT    ((uint32_t)1)
#define IO_FIELD_RISE   ((uint32_t)1)
#define IO_FIELD_FALL   ((uint32_t)1)
#define IO_FIELD_RESERV ((uint32_t)3)
#define IO_FIELD_SEPARE ((uint32_t)8)
#define IO_FIELD_PIN    ((uint32_t)8)

//------------------------------------------------------------------------------
typedef struct {
    uint32_t Mode   :IO_FIELD_MODE;
    uint32_t Type   :IO_FIELD_TYPE;
    uint32_t Speed  :IO_FIELD_SPEED;
    uint32_t Pull   :IO_FIELD_PULL;
    uint32_t Func   :IO_FIELD_FUNC;
    uint32_t Int    :IO_FIELD_INT;
    uint32_t Rise   :IO_FIELD_RISE;
    uint32_t Fall   :IO_FIELD_FALL;
    uint32_t Reserv :IO_FIELD_RESERV;
    uint32_t Separe :IO_FIELD_SEPARE;
    uint32_t Pin    :IO_FIELD_PIN;
} IO_Config;

//------------------------------------------------------------------------------
typedef struct {
    IO_Config* Pin;
    GPIO_TypeDef* Port;
} IO_FullConfig;

//------------------------------------------------------------------------------
#define GPIO_SIZE                   0x0400

//------------------------------------------------------------------------------
#define __PINOUT_NORMAL             false
#define __PINOUT_REMAPPED           true

#define __PERIPHERAL_USART          0x00001
#define __PERIPHERAL_SPI            0x00002
#define __PERIPHERAL_I2C            0x00003
#define __PERIPHERAL_TIMER          0x00004
#define __PERIPHERAL_ADC            0x00005
#define __PERIPHERAL_DAC            0x00006
#define __PERIPHERAL_CAN            0x00007
#define __PERIPHERAL_USB            0x00008

#define __USART1_STANDARD           0x0010
#define __USART1_REMAPPED           0x8010
#define __USART1_REMAPPED1          0x8011
#define __USART1_REMAPPED2          0x8012

#define __USART2_STANDARD           0x0014
#define __USART2_REMAPPED           0x8014
#define __USART2_REMAPPED1          0x8015
#define __USART2_REMAPPED2          0x8016

#define __USART3_STANDARD           0x0018
#define __USART3_REMAPPED           0x8018
#define __USART3_REMAPPED1          0x8019
#define __USART3_REMAPPED2          0x801A

#define __UART4_STANDARD            0x001C
#define __UART4_REMAPPED            0x801C
#define __UART4_REMAPPED1           0x801D
#define __UART4_REMAPPED2           0x801E

#define __UART5_STANDARD            0x0020
#define __UART5_REMAPPED            0x8020
#define __UART5_REMAPPED1           0x8021
#define __UART5_REMAPPED2           0x8022

#define __SPI1_STANDARD             0x0030
#define __SPI1_REMAPPED             0x8030
#define __SPI1_REMAPPED1            0x8031
#define __SPI1_REMAPPED2            0x8032

#define __SPI2_STANDARD             0x0034
#define __SPI2_REMAPPED             0x8034
#define __SPI2_REMAPPED1            0x8035
#define __SPI2_REMAPPED2            0x8036

#define __I2C1_STANDARD             0x003C
#define __I2C1_REMAPPED             0x803C
#define __I2C1_REMAPPED1            0x803D
#define __I2C1_REMAPPED2            0x803E

#define __I2C2_STANDARD             0x0040
#define __I2C2_REMAPPED             0x8040
#define __I2C2_REMAPPED1            0x8041
#define __I2C2_REMAPPED2            0x8042

#define __USB_STANDARD              0x0050
#define __USB_REMAPPED              0x8050
#define __USB_REMAPPED1             0x8051
#define __USB_REMAPPED2             0x8052

#define __OUTPUT_STANDARD           0x0100
#define __OUTPUT_FAST               0x8100

#define __INPUT_STANDARD            0x0101
#define __INPUT_FAST                0x8101

#define __MASK_REMAP                ((uint32_t)0x00008000)
#define __MASK_FULL                 ((uint32_t)0x00004000)
#define __MASK_PORT                 ((uint32_t)0x000000FF)
#define __MASK_PIN                  ((uint32_t)0x0000FF00)
#define __MASK_ALTERNATE            ((uint32_t)0x00FF0000)
#define __MASK_SLAVE                __MASK_FULL

//----------------------------------------
#define __NOTAV                     0xFFFF
#define __PORTA                     0x0000
#define __PORTB                     0x0100
#define __PORTC                     0x0200
#define __PORTD                     0x0300
#define __PORTE                     0x0400
#define __PORTF                     0x0500
#define __PORTG                     0x0600
#define __PIN0                      0x0000
#define __PIN1                      0x0001
#define __PIN2                      0x0002
#define __PIN3                      0x0003
#define __PIN4                      0x0004
#define __PIN5                      0x0005
#define __PIN6                      0x0006
#define __PIN7                      0x0007
#define __PIN8                      0x0008
#define __PIN9                      0x0009
#define __PIN10                     0x000A
#define __PIN11                     0x000B
#define __PIN12                     0x000C
#define __PIN13                     0x000D
#define __PIN14                     0x000E
#define __PIN15                     0x000F

//------------------------------------------------------------------------------
#define IO_FUNC_AF0     ((uint32_t)0)
#define IO_FUNC_AF1     ((uint32_t)1)
#define IO_FUNC_AF2     ((uint32_t)2)
#define IO_FUNC_AF3     ((uint32_t)3)
#define IO_FUNC_AF4     ((uint32_t)4)
#define IO_FUNC_AF5     ((uint32_t)5)
#define IO_FUNC_AF6     ((uint32_t)6)
#define IO_FUNC_AF7     ((uint32_t)7)

#define __AF0           (IO_FUNC_AF0 << 16)
#define __AF1           (IO_FUNC_AF1 << 16)
#define __AF2           (IO_FUNC_AF2 << 16)
#define __AF3           (IO_FUNC_AF3 << 16)
#define __AF4           (IO_FUNC_AF4 << 16)
#define __AF5           (IO_FUNC_AF5 << 16)
#define __AF6           (IO_FUNC_AF6 << 16)
#define __AF7           (IO_FUNC_AF7 << 16)

//----------------------------------------
#define USART1_STANDARD_TX          (__PORTA | __PIN9  | __AF4)
#define USART1_STANDARD_RX          (__PORTA | __PIN10 | __AF4)
#define USART1_STANDARD_CTS         (__PORTA | __PIN11 | __AF4)
#define USART1_STANDARD_RTS         (__PORTA | __PIN12 | __AF4)

#define USART1_REMAPPED_TX          (__PORTB | __PIN6  | __AF0)
#define USART1_REMAPPED_RX          (__PORTB | __PIN7  | __AF0)
#define USART1_REMAPPED_CTS         (__PORTB | __PIN4  | __AF5)
#define USART1_REMAPPED_RTS         (__PORTB | __PIN3  | __AF5)

#define USART2_STANDARD_TX          (__PORTA | __PIN2  | __AF1)
#define USART2_STANDARD_RX          (__PORTA | __PIN3  | __AF1)
#define USART2_STANDARD_CTS         (__PORTA | __PIN0  | __AF1)
#define USART2_STANDARD_RTS         (__PORTA | __PIN1  | __AF1)

#define USART2_REMAPPED_TX          (__PORTD | __PIN5  | __AF0)
#define USART2_REMAPPED_RX          (__PORTD | __PIN6  | __AF0)
#define USART2_REMAPPED_CTS         (__PORTD | __PIN3  | __AF0)
#define USART2_REMAPPED_RTS         (__PORTD | __PIN4  | __AF0)

#ifdef USART3
#define USART3_STANDARD_TX          (__PORTB | __PIN10 | __AF4)
#define USART3_STANDARD_RX          (__PORTB | __PIN11 | __AF4)
#define USART3_STANDARD_CTS         (__PORTB | __PIN13 | __AF4)
#define USART3_STANDARD_RTS         (__PORTB | __PIN14 | __AF4)

#define USART3_REMAPPED_TX          (__PORTC | __PIN10 | __AF0)
#define USART3_REMAPPED_RX          (__PORTC | __PIN11 | __AF0)
#define USART3_REMAPPED_CTS         (__PORTA | __PIN6  | __AF4)
#define USART3_REMAPPED_RTS         (__PORTB | __PIN1  | __AF4)
#endif

#ifdef LPUART1
#define LPUART1_STANDARD_TX         (__PORTB | __PIN10 | __AF1)
#define LPUART1_STANDARD_RX         (__PORTB | __PIN11 | __AF1)
#define LPUART1_STANDARD_CTS        (__PORTB | __PIN13 | __AF1)
#define LPUART1_STANDARD_RTS        (__PORTB | __PIN14 | __AF1)

#define LPUART1_REMAPPED_TX         (__PORTC | __PIN1  | __AF1)
#define LPUART1_REMAPPED_RX         (__PORTC | __PIN0  | __AF1)
#define LPUART1_REMAPPED_CTS        (__PORTA | __PIN6  | __AF6)
#define LPUART1_REMAPPED_RTS        (__PORTB | __PIN1  | __AF6)
#endif

#define USART4_STANDARD_TX          (__PORTA | __PIN0  | __AF4)
#define USART4_STANDARD_RX          (__PORTA | __PIN1  | __AF4)
#define USART4_STANDARD_CTS         (__PORTB | __PIN7  | __AF4)
#define USART4_STANDARD_RTS         (__PORTA | __PIN15 | __AF4)

#define USART4_REMAPPED_TX          (__PORTC | __PIN10 | __AF6)
#define USART4_REMAPPED_RX          (__PORTC | __PIN11 | __AF6)
#define USART4_REMAPPED_CTS         (__PORTB | __PIN7  | __AF6)
#define USART4_REMAPPED_RTS         (__PORTA | __PIN15 | __AF6)

#define USART4_REMAPPED2_TX         (__PORTC | __PIN10 | __AF1)
#define USART4_REMAPPED2_RX         (__PORTC | __PIN11 | __AF1)
#define USART4_REMAPPED2_CTS        (__PORTB | __PIN7  | __AF4)
#define USART4_REMAPPED2_RTS        (__PORTA | __PIN15 | __AF4)

#define SPI1_STANDARD_NSS           (__PORTA | __PIN4  | __AF0)
#define SPI1_STANDARD_SCK           (__PORTA | __PIN5  | __AF0)
#define SPI1_STANDARD_MISO          (__PORTA | __PIN6  | __AF0)
#define SPI1_STANDARD_MOSI          (__PORTA | __PIN7  | __AF0)

#define SPI1_REMAPPED_MOSI          (__PORTB | __PIN5  | __AF0)
#define SPI1_REMAPPED_SCK           (__PORTB | __PIN3  | __AF0)
#define SPI1_REMAPPED_MISO          (__PORTB | __PIN4  | __AF0)
#define SPI1_REMAPPED_NSS           (__PORTA | __PIN15 | __AF0)

#define SPI2_STANDARD_NSS           (__PORTB | __PIN12 | __AF0)
#define SPI2_STANDARD_SCK           (__PORTB | __PIN13 | __AF0)
#define SPI2_STANDARD_MISO          (__PORTB | __PIN14 | __AF0)
#define SPI2_STANDARD_MOSI          (__PORTB | __PIN15 | __AF0)

#define SPI2_REMAPPED_NSS           (__PORTB | __PIN12 | __AF0)
#define SPI2_REMAPPED_SCK           (__PORTB | __PIN13 | __AF0)
#define SPI2_REMAPPED_MISO          (__PORTC | __PIN2  | __AF1)
#define SPI2_REMAPPED_MOSI          (__PORTC | __PIN3  | __AF1)

#define SPI2_REMAPPED2_NSS          (__PORTB | __PIN9  | __AF5)
#define SPI2_REMAPPED2_SCK          (__PORTB | __PIN10 | __AF5)
#define SPI2_REMAPPED2_MISO         (__PORTD | __PIN3  | __AF2)
#define SPI2_REMAPPED2_MOSI         (__PORTD | __PIN4  | __AF1)

#define I2C1_STANDARD_SCL           (__PORTA | __PIN9  | __AF6)
#define I2C1_STANDARD_SDA           (__PORTA | __PIN10 | __AF6)

#define I2C1_REMAPPED_SCL           (__PORTB | __PIN8  | __AF6)
#define I2C1_REMAPPED_SDA           (__PORTB | __PIN9  | __AF6)

#define I2C1_REMAPPED2_SCL          (__PORTB | __PIN6  | __AF6)
#define I2C1_REMAPPED2_SDA          (__PORTB | __PIN7  | __AF6)

#define I2C2_STANDARD_SCL           (__PORTB | __PIN13 | __AF6)
#define I2C2_STANDARD_SDA           (__PORTB | __PIN14 | __AF6)

#define I2C2_REMAPPED_SCL           (__PORTB | __PIN10 | __AF6)
#define I2C2_REMAPPED_SDA           (__PORTB | __PIN11 | __AF6)

//------------------------------------------------------------------------------
//#define PIN_RESOLVE(_pino_)    (0x0001 << (_pino_ & __MASK_PORT));

//------------------------------------------------------------------------------
#pragma anon_unions
struct __port{
    uint16_t peripheral;
    uint16_t config;
    union{
        struct {
            uint32_t tx;
            uint32_t rx;
            uint32_t rts;
            uint32_t cts;
        };
        struct{
            uint32_t mosi;
            uint32_t miso;
            uint32_t sck;
            uint32_t nss;
        };
    };
};

//------------------------------------------------------------------------------
extern __port pins;
extern uint32_t GetPortIndex(GPIO_TypeDef*p);
GPIO_TypeDef* IO_GetPort(uint32_t p);
extern uint16_t IO_PortIndex(GPIO_TypeDef*);
extern GPIO_TypeDef* IO_PortClockOn(uint32_t);
extern void IO_PortClockEnable(GPIO_TypeDef*);
extern void IO_PinInit(IO_FullConfig* PinConfig);
extern void IO_PinInit(GPIO_TypeDef*, IO_Config*);
extern __port IO_GetPinout(uint32_t);
extern void IO_PinConfig(uint32_t);
extern void IO_SetExtendedIT(GPIO_TypeDef*, IO_Config*);
extern void IO_ResetExtendedIT(GPIO_TypeDef*, IO_Config*);
extern void IO_MaskExtendedIT(IO_Config*);
extern void IO_UnmaskExtendedIT(IO_Config*);
extern void IO_ClearPendingExtendedIT(IO_Config*);

#endif
//==============================================================================
