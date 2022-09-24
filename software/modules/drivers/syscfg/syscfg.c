#include "syscfg.h"

#include <stdint.h>

#include "syscfgRegisters.h"

#define REG_VAL(X) (*(volatile uint32_t*)X)

void syscfgEXTI(Syscfg_EXTICRx_Control_t number, Syscfg_EXTICRx_Config_t bus)
{
    switch (number)
    {
        case EXTI0:
            REG_VAL(SYSCFG_EXTICR1) |= bus;
            break;
        case EXTI4:
            REG_VAL(SYSCFG_EXTICR2) |= bus;
            break;
        case EXTI8:
            REG_VAL(SYSCFG_EXTICR3) |= bus;
            break;
        case EXTI12:
            REG_VAL(SYSCFG_EXTICR4) |= bus;
            break;
        case EXTI1:
            REG_VAL(SYSCFG_EXTICR1) |= (bus << 4);
            break;
        case EXTI5:
            REG_VAL(SYSCFG_EXTICR2) |= (bus << 4);
            break;
        case EXTI9:
            REG_VAL(SYSCFG_EXTICR3) |= (bus << 4);
            break;
        case EXTI13:
            REG_VAL(SYSCFG_EXTICR4) |= (bus << 4);
            break;
        case EXTI2:
            REG_VAL(SYSCFG_EXTICR1) |= (bus << 8);
            break;
        case EXTI6:
            REG_VAL(SYSCFG_EXTICR2) |= (bus << 8);
            break;
        case EXTI10:
            REG_VAL(SYSCFG_EXTICR3) |= (bus << 8);
            break;
        case EXTI14:
            REG_VAL(SYSCFG_EXTICR4) |= (bus << 8);
            break;
        case EXTI3:
            REG_VAL(SYSCFG_EXTICR1) |= (bus << 12);
            break;
        case EXTI7:
            REG_VAL(SYSCFG_EXTICR2) |= (bus << 12);
            break;
        case EXTI11:
            REG_VAL(SYSCFG_EXTICR3) |= (bus << 12);
            break;
        case EXTI15:
            REG_VAL(SYSCFG_EXTICR4) |= (bus << 12);
            break;
        default:
            break;
    }
}