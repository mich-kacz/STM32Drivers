

/*includes*/
#include "gpio.h"

#include "gpioRegisters.h"
#include "rcc.h"

/*Constant and macros*/
#define REG_VAL(X) (*(volatile uint32_t*)X)

/*Private types*/

typedef struct GpioRegisters_s
{
    uint32_t mode;
    uint32_t oType;
    uint32_t oSpeed;
    uint32_t pullUpDown;
    uint32_t outputData;
    uint32_t bitSetReset;
    uint32_t lock;
    uint32_t alternateFunctionLow;
    uint32_t alternateFuntionHigh;
} GpioRegisters_t;

/*Private variables*/


/*Private functions*/
static uintptr_t getBusReg(GpioBus_t bus)
{
    uintptr_t regTab[] = {
        GPIO_GPIOA,
        GPIO_GPIOB,
        GPIO_GPIOC,
        GPIO_GPIOD,
        GPIO_GPIOE,
        GPIO_GPIOF,
        GPIO_GPIOG,
        GPIO_GPIOH};
    return regTab[bus];
}

static void gpioInit(GpioBus_t bus)
{
    switch (bus)
    {
        case gpioBusA:
            rccEnableAHB1(rccAHB1GpioA);
            break;
        case gpioBusB:
            rccEnableAHB1(rccAHB1GpioB);
            break;
        case gpioBusC:
            rccEnableAHB1(rccAHB1GpioC);
            break;
        case gpioBusD:
            rccEnableAHB1(rccAHB1GpioD);
            break;
        case gpioBusE:
            rccEnableAHB1(rccAHB1GpioE);
            break;
        case gpioBusF:
            rccEnableAHB1(rccAHB1GpioF);
            break;
        case gpioBusG:
            rccEnableAHB1(rccAHB1GpioG);
            break;
        case gpioBusH:
            rccEnableAHB1(rccAHB1GpioH);
            break;
        default:
            break;
    }
}


/*Exposed API*/

void gpioConfigPin(GpioConfig_t config)
{
    gpioInit(config.bus);
    volatile uint32_t* regBase = (void*)getBusReg(config.bus);
    volatile uint32_t* reg     = regBase + GPIO_MODER_OFFSET;
    *reg |= (uint32_t)(config.mode << (config.pinNumber * 2));
    reg = regBase + GPIO_OTYPER_OFFSET;
    *reg |= (uint32_t)(config.type << config.pinNumber);
    reg = regBase + GPIO_OSPEEDER_OFFSET;
    *reg |= (uint32_t)(config.speed << (config.pinNumber * 2));
    reg = regBase + GPIO_PUPDR_OFFSET;
    *reg |= (uint32_t)(config.pull << (config.pinNumber * 2));
}

void gpioSetPin(GpioBus_t bus, uint8_t number, GpioPinState_t state)
{
    volatile uint32_t* reg = (void*)getBusReg(bus) + GPIO_BSRR_OFFSET;
    switch (state)
    {
        case GpioStateLow:
            *reg |= (1 << (number + 16));
            break;
        case GpioStateHigh:
            *reg |= (1 << number);
            break;
        default:
            break;
    }
}


GpioPinState_t gpioReadPin(GpioBus_t bus, uint8_t number)
{
    volatile uint16_t* reg = (void*)getBusReg(bus) + GPIO_IDR_OFFSET;
    GpioPinState_t state;
    if ((*reg & (1 << number)) == (1 << number))
    {
        state = GpioStateHigh;
    }
    else
    {
        state = GpioStateLow;
    }
    return state;
}

void gpioReset(void)
{
    GpioRegisters_t resetRegs = {
        .mode                 = 0xA8000000,
        .oType                = 0,
        .oSpeed               = 0,
        .pullUpDown           = 0x64000000,
        .outputData           = 0,
        .bitSetReset          = 0,
        .lock                 = 0,
        .alternateFunctionLow = 0,
        .alternateFuntionHigh = 0};
}