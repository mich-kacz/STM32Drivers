#ifndef SYS_TICK_H
#define SYS_TICK_H

#include <stdint.h>

typedef enum SysTickOptions_e
{
    SysTickIntEnable,
    SysTickIntDisable,
    SysTickClockAHB,
    SysTickClockAHBDiv8
} SysTickOptions_t;


void sysTickInit(SysTickOptions_t interrupt, SysTickOptions_t clock, uint32_t load);

#endif