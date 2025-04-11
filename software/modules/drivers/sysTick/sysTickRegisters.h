#ifndef SYS_TICK_REGISTERS_H
#define SYS_TICK_REGISTERS_H

// Base value for SysTick memory region
#define SYSTEM_TIMER_BASE 0xE000E010

// SysTick registers
#define STK_CTRL  (0x00 + SYSTEM_TIMER_BASE)
#define STK_LOAD  (0x04 + SYSTEM_TIMER_BASE)
#define STK_VAL   (0x08 + SYSTEM_TIMER_BASE)
#define STK_CALIB (0x0C + SYSTEM_TIMER_BASE)


#endif