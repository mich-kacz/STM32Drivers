/*Includes*/

#include "rcc.h"

#include <stdint.h>

#include "flash.h"
#include "power.h"
#include "rccRegisters.h"

/*Constants and macros*/
#define REG_VAL(X) (*(volatile uint32_t*)X)

/*Types*/

/*Private functions*/

/*Exposed API*/

void rccEnableAHB1(RccAHB1Control_t bit)
{
    REG_VAL(RCC_RCC_CONTROL_AHB1_ENABLE) |= bit;
}

void DisableAHB1(RccAHB1Control_t bit)
{
    REG_VAL(RCC_RCC_CONTROL_AHB1_ENABLE) &= ~bit;
}

void rccClocksConfig(RccClocksConfig_t config)
{
    REG_VAL(RCC_RCC_CONTROL_CLOCK) &= ~(1 << 24);
    while ((REG_VAL(RCC_RCC_CONTROL_CLOCK) & 1 << 25))
        ;

    if (config.HSE == rccControlHseON)
    {
        REG_VAL(RCC_RCC_CONTROL_CLOCK) |= (uint32_t)(config.HSE << 16);
        while (!(REG_VAL(RCC_RCC_CONTROL_CLOCK) & (1 << 17)))
            ;
    }
    else
    {
        REG_VAL(RCC_RCC_CONTROL_CLOCK) |= (uint32_t)config.HSI;
        while (!(REG_VAL(RCC_RCC_CONTROL_CLOCK) & (1 << 1)))
            ;
    }

    REG_VAL(RCC_RCC_CONTROL_APB1_ENABLE) |= (uint32_t)(1 << 28);

    powerSetVOS(PowerVOS_mode1_Default); // POWERPowerVOS

    // FLASH
    FlashCacheConfig_t cacheConfig = {
        .DCEN   = FlashDCEN_ON,
        .DCRST  = FlashDCRST_OFF_DEFAULT,
        .ICEN   = FlashICEN_ON,
        .ICRST  = FlashICRST_OFF_DEFAULT,
        .PRFTEN = FlashPRFTEN_ON};
    flashSetDataCache(cacheConfig);
    flashSetLatency(5);

    REG_VAL(RCC_RCC_CONTROL_CLOCK_CONFIG) |=
        (uint32_t)((config.AHB << 4) | (config.APB1 << 10) | (config.APB2 << 13));

    REG_VAL(RCC_RCC_CONTROL_PLL_CONFIG) |= (uint32_t)(
        (config.PLLM) | (config.PLLN << 6) | (config.PLLP << 16) | (config.PLLSRC << 22)
        | (config.PLLQ << 24) | (config.PLLR << 28));

    REG_VAL(RCC_RCC_CONTROL_CLOCK) |= (1 << 24);
    while (!(REG_VAL(RCC_RCC_CONTROL_CLOCK) & (1 << 25)))
        ;


    REG_VAL(RCC_RCC_CONTROL_CLOCK_CONFIG) |= (uint32_t)0b10;
    while (!(REG_VAL(RCC_RCC_CONTROL_CLOCK_CONFIG) & 0b1000))
        ;
}