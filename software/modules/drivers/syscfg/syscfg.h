#ifndef SYSCFG_H
#define SYSCFG_H

typedef enum Syscfg_EXTICRx_Control_e
{
    EXTI0,
    EXTI4,
    EXTI8,
    EXTI12,
    EXTI1,
    EXTI5,
    EXTI9,
    EXTI13,
    EXTI2,
    EXTI6,
    EXTI10,
    EXTI14,
    EXTI3,
    EXTI7,
    EXTI11,
    EXTI15
} Syscfg_EXTICRx_Control_t;

typedef enum Syscfg_EXTICRx_Config_e
{
    EXTIx_PAx = 0b0000,
    EXTIx_PBx = 0b0001,
    EXTIx_PCx = 0b0010,
    EXTIx_PDx = 0b0011,
    EXTIx_PEx = 0b0100,
    EXTIx_PFx = 0b0101,
    EXTIx_PGx = 0b0110,
    EXTIx_PHx = 0b0111,
} Syscfg_EXTICRx_Config_t;


void syscfgEXTI(Syscfg_EXTICRx_Control_t number, Syscfg_EXTICRx_Config_t bus);

#endif