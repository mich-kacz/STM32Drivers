#include "config.h"

#include "gpio.h"
#include "rcc.h"

void conifg_configBoard(void)
{
    RccClocksConfig_t configClocks = {
        .HSI    = rccControlHsiON,
        .HSE    = rccControlHseOFF,
        .AHB    = rccAHBDiv1,
        .APB1   = rccAPB1Div2,
        .APB2   = rccAPB2Div2,
        .PLLM   = 8,
        .PLLN   = 80,
        .PLLP   = rccPLLP2,
        .PLLQ   = 2,
        .PLLR   = 2,
        .PLLSRC = 0};

    rccClocksConfig(configClocks);
    // SysClockConfig();

    GpioConfig_t configPin = {
        .bus       = gpioBusA,
        .mode      = gpioModeOutput,
        .type      = gpioTypeOutputPushPull,
        .speed     = gpioLowSpeed,
        .pull      = gpioNoPull,
        .pinNumber = 5};

    gpioConfigPin(configPin);

    configPin.pinNumber = 7;

    gpioConfigPin(configPin);
}