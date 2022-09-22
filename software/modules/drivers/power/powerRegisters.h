#ifndef POWER_REGISTERS_H
#define POWER_REGISTERS_H

// Base value for power memory region
#define POWER_BASE (0x40007000)

// Power registers
#define POWER_PWR_CR  (0x00 + POWER_BASE)
#define POWER_PWR_CSR (0x04 + POWER_BASE)

#endif