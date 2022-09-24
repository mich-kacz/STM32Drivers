#ifndef SYSCFG_REGISTERS_H
#define SYSCFG_REGISTERS_H

// Address for SYSCFG clock
#define SYSCFG_BASE 0x40013800

// SYSCFG REGISTERS
#define SYSCFG_EXTICR1 (0x08 + SYSCFG_BASE)
#define SYSCFG_EXTICR2 (0x0C + SYSCFG_BASE)
#define SYSCFG_EXTICR3 (0x10 + SYSCFG_BASE)
#define SYSCFG_EXTICR4 (0x14 + SYSCFG_BASE)

#endif