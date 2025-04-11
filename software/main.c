#include "config.h"
#include "gpio.h"
#include "interrupt.h"


void SysTick_Handler(void)
{
    gpioTogglePin(gpioBusA, 8);
}

int main(void)
{
    conifg_configBoard();

    while (1)
    {
        /*gpioSetPin(gpioBusA, 5, GpioStateHigh);

        while (zmiennaGlobalna < 499)
        {
        }
        zmiennaGlobalna = 0;
        gpioSetPin(gpioBusA, 5, GpioStateLow);

        while (zmiennaGlobalna < 499)
        {
        }
        zmiennaGlobalna = 0;*/
    }

    return 0;
}