#include "gpio.h"
#include "config.h"

int main(void)
{
    conifg_configBoard();
    
    unsigned int i = 0;

    while (1)
    {
        for (i = 0; i < 4000000; i++)
        {
        }
        gpioSetPin(gpioBusA, 7, GpioStateHigh);
        for (i = 0; i < 4000000; i++)
        {
        }
        gpioSetPin(gpioBusA, 7, GpioStateLow);
    }

    return 0;
}