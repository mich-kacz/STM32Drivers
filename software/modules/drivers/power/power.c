#include "power.h"

#include <stdint.h>

#include "powerRegisters.h"

/*Constants and macros*/
#define REG_VAL(X) (*(volatile uint32_t*)X)

void powerSetVOS(PowerVOS_t mode)
{
    REG_VAL(POWER_PWR_CR) |= (mode << 14);
}