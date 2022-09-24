#ifndef RCC_H
#define RCC_H

/*Includes*/
#include <stdint.h>

/*Types*/

typedef enum RccAHB1Control_e
{
    rccAHB1GpioA     = 0b00000000000000000000000000000001,
    rccAHB1GpioB     = 0b00000000000000000000000000000010,
    rccAHB1GpioC     = 0b00000000000000000000000000000100,
    rccAHB1GpioD     = 0b00000000000000000000000000001000,
    rccAHB1GpioE     = 0b00000000000000000000000000010000,
    rccAHB1GpioF     = 0b00000000000000000000000000100000,
    rccAHB1GpioG     = 0b00000000000000000000000001000000,
    rccAHB1GpioH     = 0b00000000000000000000000010000000,
    rccAHB1CRC       = 0b00000000000000000001000000000000,
    rccAHB1BkpSram   = 0b00000000000001000000000000000000,
    rccAHB1Dma1      = 0b00000000001000000000000000000000,
    rccAHB1Dma2      = 0b00000000010000000000000000000000,
    rccAHB1Otghs     = 0b00100000000000000000000000000000,
    rccAHB1OtghsUlpi = 0b01000000000000000000000000000000
} RccAHB1Control_t;

typedef enum RccAPB1Control_e
{
    RccAPB1TIM2_EN    = 1,
    RccAPB1TIM3_EN    = (1 << 1),
    RccAPB1TIM4_EN    = (1 << 2),
    RccAPB1TIM5_EN    = (1 << 3),
    RccAPB1TIM6_EN    = (1 << 4),
    RccAPB1TIM7_EN    = (1 << 5),
    RccAPB1TIM12_EN   = (1 << 6),
    RccAPB1TIM13_EN   = (1 << 7),
    RccAPB1TIM14_EN   = (1 << 8),
    RccAPB1WWDG_EN    = (1 << 11),
    RccAPB1SPI2_EN    = (1 << 14),
    RccAPB1SPI3_EN    = (1 << 15),
    RccAPB1SPDIFRX_EN = (1 << 16),
    RccAPB1USART2_EN  = (1 << 17),
    RccAPB1USART3_EN  = (1 << 18),
    RccAPB1UART4_EN   = (1 << 19),
    RccAPB1UART5_EN   = (1 << 20),
    RccAPB1I2C1_EN    = (1 << 21),
    RccAPB1I2C2_EN    = (1 << 22),
    RccAPB1I2C3_EN    = (1 << 23),
    RccAPB1FMPI2C1_EN = (1 << 24),
    RccAPB1CAN1_EN    = (1 << 25),
    RccAPB1CAN2_EN    = (1 << 26),
    RccAPB1CEC_EN     = (1 << 27),
    RccAPB1PWR_EN     = (1 << 28),
    RccAPB1DAC_EN     = (1 << 29)
} RccAPB1Control_t;

typedef enum RccAPB2Control_e
{
    RccAPB2TIM1_EN   = 1,
    RccAPB2TIM8_EN   = (1 << 1),
    RccAPB2USART1_EN = (1 << 4),
    RccAPB2USART6_EN = (1 << 5),
    RccAPB2ADC1_EN   = (1 << 8),
    RccAPB2ADC2_EN   = (1 << 9),
    RccAPB2ADC3_EN   = (1 << 10),
    RccAPB2SDIO_EN   = (1 << 11),
    RccAPB2SPI1_EN   = (1 << 12),
    RccAPB2SPI4_EN   = (1 << 13),
    RccAPB2SYSCFG_EN = (1 << 14),
    RccAPB2TIM9_EN   = (1 << 16),
    RccAPB2TIM10_EN  = (1 << 17),
    RccAPB2TIM11_EN  = (1 << 18),
    RccAPB2SAI1_EN   = (1 << 22),
    RccAPB2SAI2_EN   = (1 << 23)
} RccAPB2Control_t;


typedef enum RccClockControlHSI_e
{
    rccControlHsiOFF = 0,
    rccControlHsiON  = 1
} RccClockControlHSI_t;

typedef enum RccClockControlHSE_e
{
    rccControlHseOFF = 0,
    rccControlHseON  = 1
} RccClockControlHSE_t;

typedef enum RccClockPrescalerAHB_e
{
    rccAHBDiv1   = 0,
    rccAHBDiv2   = 0b1000,
    rccAHBDiv4   = 0b1001,
    rccAHBDiv8   = 0b1010,
    rccAHBDiv16  = 0b1011,
    rccAHBDiv64  = 0b1100,
    rccAHBDiv128 = 0b1101,
    rccAHBDiv256 = 0b1110,
    rccAHBDiv512 = 0b1111
} RccClockPrescalerAHB_t;

typedef enum RccClockPrescalerAPB1_e
{
    rccAPB1Div1  = 0,
    rccAPB1Div2  = 0b100,
    rccAPB1Div4  = 0b101,
    rccAPB1Div8  = 0b110,
    rccAPB1Div16 = 0b111
} RccClockPrescalerAPB1_t;

typedef enum RccClockPrescalerAPB2_e
{
    rccAPB2Div1  = 0,
    rccAPB2Div2  = 0b100,
    rccAPB2Div4  = 0b101,
    rccAPB2Div8  = 0b110,
    rccAPB2Div16 = 0b111
} RccClockPrescalerAPB2_t;

typedef enum RccClockPLLP_e
{
    rccPLLP2 = 0,
    rccPLLP4 = 1,
    rccPLLP6 = 2,
    rccPLLP8 = 3
} RccClockPLLP_t;

typedef struct RccClocksConfig_s
{
    RccClockControlHSI_t HSI;
    RccClockControlHSE_t HSE;
    RccClockPrescalerAHB_t AHB;
    RccClockPrescalerAPB1_t APB1;
    RccClockPrescalerAPB2_t APB2;
    RccClockPLLP_t PLLP;
    uint8_t PLLR : 3;
    uint8_t PLLQ : 4;
    uint8_t PLLSRC : 1;
    uint16_t PLLN : 9;
    uint8_t PLLM : 6;
} RccClocksConfig_t;

/*Exposed API*/
void rccEnableAHB1(RccAHB1Control_t bit);
void rccDisableAHB1(RccAHB1Control_t bit);
void rccEnableAPB1(RccAPB1Control_t bit);
void rccDisableAPB1(RccAPB1Control_t bit);
void rccEnableAPB2(RccAPB2Control_t bit);
void rccDisableAPB2(RccAPB2Control_t bit);
void rccClocksConfig(RccClocksConfig_t config);

#endif