#ifndef INTERRUPT_REGISTERS_H
#define INTERRUPT_REGISTERS_H


// Base value for EXTI memory region
#define EXTI_BASE 0x40013C00
// Base value for NVIC memory region
#define NVIC_BASE 0xE000E100


// EXTI registers
#define EXTI_IMR   (0x00 + EXTI_BASE)
#define EXTI_EMR   (0x04 + EXTI_BASE)
#define EXTI_RTSR  (0x08 + EXTI_BASE)
#define EXTI_FTSR  (0x0C + EXTI_BASE)
#define EXTI_SWIER (0x10 + EXTI_BASE)
#define EXTI_PR    (0x14 + EXTI_BASE)


// NVIC registers
#define NVIC_ISER (0x000 + NVIC_BASE)
#define NVIC_ICER (0x080 + NVIC_BASE)
#define NVIC_ISPR (0x100 + NVIC_BASE)
#define NVIC_ICPR (0x180 + NVIC_BASE)
#define NVIC_IABR (0x200 + NVIC_BASE)
#define NVIC_IPR  (0x300 + NVIC_BASE)
#define NVIC_STIR (0xE00 + NVIC_BASE)

#endif