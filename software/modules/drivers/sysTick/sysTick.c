#include "sysTick.h"

#include <stdint.h>

#include "interrupt.h"
#include "sysTickRegisters.h"

#define REG_VAL(X) (*(volatile uint32_t*)X)

void sysTickInit(SysTickOptions_t interrupt, SysTickOptions_t clock, uint32_t load)
{
    REG_VAL(STK_LOAD) = load;
    REG_VAL(STK_VAL)  = (uint32_t)0;
    switch (interrupt)
    {
        case SysTickIntEnable:
            REG_VAL(STK_CTRL) |= ((1 << 0) | (1 << 1));
            break;

        default:
        case SysTickIntDisable:
            REG_VAL(STK_CTRL) |= (1 << 0);
            REG_VAL(STK_CTRL) &= ~(1 << 1);
            break;
    }

    switch (clock)
    {
        case SysTickClockAHB:
            REG_VAL(STK_CTRL) |= (1 << 2);
            break;
        default:
        case SysTickClockAHBDiv8:
            REG_VAL(STK_CTRL) &= ~(1 << 2);
            break;
    }
}