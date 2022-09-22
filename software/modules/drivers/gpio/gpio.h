#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

/*Types*/

typedef enum GpioMode_e
{
    gpioModeInput,
    gpioModeOutput,
    gpioModeAlternate,
    gpioModeAnalog
} GpioMode_t;

typedef enum GpioType_e
{
    gpioTypeOutputPushPull,
    gpioTypeOutputOpenDrain
} GpioType_t;

typedef enum GpioOutputSpeed_e
{
    gpioLowSpeed,
    gpioMediumSpeed,
    gpioFastSpeed,
    gpioHighSpeed
} GpioOutputSpeed_t;

typedef enum GpioOutputPull_e
{
    gpioNoPull,
    gpioPullUp,
    gpioPullDown
} GpioOutputPull_t;

typedef enum GpioPinState_e
{
    GpioStateLow,
    GpioStateHigh
} GpioPinState_t;

typedef enum GpioBus_e
{
    gpioBusA,
    gpioBusB,
    gpioBusC,
    gpioBusD,
    gpioBusE,
    gpioBusF,
    gpioBusG,
    gpioBusH
} GpioBus_t;


typedef struct GpioConfig_s
{
    GpioBus_t bus;
    GpioMode_t mode;
    GpioType_t type;
    GpioOutputSpeed_t speed;
    GpioOutputPull_t pull;
    uint8_t pinNumber : 4;
} GpioConfig_t;


/*Exposed API*/

void gpioConfigPin(GpioConfig_t config);
void gpioSetPin(GpioBus_t bus, uint8_t number, GpioPinState_t state);
GpioPinState_t gpioReadPin(GpioBus_t bus, uint8_t number);
void gpioReset(void);

#endif