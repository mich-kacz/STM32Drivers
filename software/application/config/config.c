#include "config.h"

#include "gpio.h"
#include "interrupt.h"
#include "rcc.h"
#include "sysTick.h"

void conifg_configBoard(void)
{

    //  180 Mhz
    RccClocksConfig_t configClocks = {
        .HSI    = rccControlHsiON,
        .HSE    = rccControlHseOFF,
        .AHB    = rccAHBDiv1,
        .APB1   = rccAPB1Div4,
        .APB2   = rccAPB2Div2,
        .PLLM   = 8,
        .PLLN   = 180,
        .PLLP   = rccPLLP2,
        .PLLQ   = 2,
        .PLLR   = 2,
        .PLLSRC = 0};

    // 150 Mhz
    /*RccClocksConfig_t configClocks = {
        .HSI    = rccControlHsiON,
        .HSE    = rccControlHseOFF,
        .AHB    = rccAHBDiv1,
        .APB1   = rccAPB1Div4,
        .APB2   = rccAPB2Div2,
        .PLLM   = 8,
        .PLLN   = 150,
        .PLLP   = rccPLLP2,
        .PLLQ   = 2,
        .PLLR   = 2,
        .PLLSRC = 0};*/

    // 16 Mhz
    /*RccClocksConfig_t configClocks = {
        .HSI    = rccControlHsiON,
        .HSE    = rccControlHseOFF,
        .AHB    = rccAHBDiv4,
        .APB1   = rccAPB1Div2,
        .APB2   = rccAPB2Div1,
        .PLLM   = 8,
        .PLLN   = 64,
        .PLLP   = rccPLLP2,
        .PLLQ   = 2,
        .PLLR   = 2,
        .PLLSRC = 0};*/

    rccClocksConfig(configClocks);

    GpioConfig_t configPin = {
        .bus       = gpioBusA,
        .mode      = gpioModeOutput,
        .type      = gpioTypeOutputPushPull,
        .speed     = gpioFastSpeed,
        .pull      = gpioNoPull,
        .pinNumber = 8};

    gpioConfigPin(configPin);

    sysTickInit(SysTickIntEnable, SysTickClockAHB, 180000);

    // interruptEnableEXTI(EXTI8, EXTIx_PAx, EXTIFallingEdge, 1);
}