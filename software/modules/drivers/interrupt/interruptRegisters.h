#ifndef INTERRUPT_REGISTERS_H
#define INTERRUPT_REGISTERS_H


// Base value for EXTI memory region
#define EXTI_BASE 0x40013C00


// EXTI registers
#define EXTI_IMR   (0x00 + EXTI_BASE)
#define EXTI_EMR   (0x04 + EXTI_BASE)
#define EXTI_RTSR  (0x08 + EXTI_BASE)
#define EXTI_FTSR  (0x0C + EXTI_BASE)
#define EXTI_SWIER (0x10 + EXTI_BASE)
#define EXTI_PR    (0x14 + EXTI_BASE)

#endif