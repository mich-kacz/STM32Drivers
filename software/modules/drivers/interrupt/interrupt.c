#include "interrupt.h"

#include <stdint.h>

#include "interruptRegisters.h"
#include "rcc.h"

#define REG_VAL(X) (*(volatile uint32_t*)X)
#define NVIC       ((NVIC_Type_t*)NVIC_BASE)

typedef struct NVIC_Type_s
{
    volatile uint32_t ISER[8U]; /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
    uint32_t RESERVED0[24U];
    volatile uint32_t ICER[8U]; /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register
                                 */
    uint32_t RSERVED1[24U];
    volatile uint32_t ISPR[8U]; /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register
                                 */
    uint32_t RESERVED2[24U];
    volatile uint32_t ICPR[8U]; /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register
                                 */
    uint32_t RESERVED3[24U];
    volatile uint32_t IABR[8U]; /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
    uint32_t RESERVED4[56U];
    volatile uint8_t IP[240U]; /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit
                                  wide) */
    uint32_t RESERVED5[644U];
    volatile uint32_t STIR; /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register
                             */
} NVIC_Type_t;

static void interruptSetEdge(uint8_t pinNumber, InterruptEXITEdgeDetection_t detection)
{
    if (detection == EXTIFallingEdge)
    {
        REG_VAL(EXTI_RTSR) &= ~(1 << pinNumber);
        REG_VAL(EXTI_FTSR) |= (1 << pinNumber);
    }
    else if (detection == EXTIRisingEdge)
    {
        REG_VAL(EXTI_FTSR) &= ~(1 << pinNumber);
        REG_VAL(EXTI_RTSR) |= (1 << pinNumber);
    }
}

static void interruptNVICSetPriority(uint8_t position, uint8_t priority)
{
    if ((int32_t)(position) >= 0)
    {
        NVIC->IP[((uint32_t)position)] = (uint8_t)((priority << (4U)) & (uint32_t)0xFFUL);
    }
}

static void interruptNVICEnableIRQ(uint8_t position)
{
    if ((int32_t)(position) >= 0)
    {
        NVIC->ISER[(((uint32_t)position) >> 5UL)] =
            (uint32_t)(1UL << (((uint32_t)position) & 0x1FUL));
    }
}


void interruptEnableEXTI(
    Syscfg_EXTICRx_Control_t number,
    Syscfg_EXTICRx_Config_t bus,
    InterruptEXITEdgeDetection_t detection,
    uint8_t priority)
{
    rccEnableAPB2(RccAPB2SYSCFG_EN);
    syscfgEXTI(number, bus);

    switch (number)
    {
        case EXTI0:
            REG_VAL(EXTI_IMR) |= (1 << 0);
            interruptSetEdge(0, detection);
            interruptNVICSetPriority(6, priority);
            interruptNVICEnableIRQ(6);
            break;
        case EXTI4:
            REG_VAL(EXTI_IMR) |= (1 << 4);
            interruptSetEdge(4, detection);
            interruptNVICSetPriority(10, priority);
            interruptNVICEnableIRQ(10);
            break;
        case EXTI8:
            REG_VAL(EXTI_IMR) |= (1 << 8);
            interruptSetEdge(8, detection);
            interruptNVICSetPriority(23, priority);
            interruptNVICEnableIRQ(23);
            break;
        case EXTI12:
            REG_VAL(EXTI_IMR) |= (1 << 12);
            interruptSetEdge(12, detection);
            interruptNVICSetPriority(40, priority);
            interruptNVICEnableIRQ(40);
            break;
        case EXTI1:
            REG_VAL(EXTI_IMR) |= (1 << 1);
            interruptSetEdge(1, detection);
            interruptNVICSetPriority(7, priority);
            interruptNVICEnableIRQ(7);
            break;
        case EXTI5:
            REG_VAL(EXTI_IMR) |= (1 << 5);
            interruptSetEdge(5, detection);
            interruptNVICSetPriority(23, priority);
            interruptNVICEnableIRQ(23);
            break;
        case EXTI9:
            REG_VAL(EXTI_IMR) |= (1 << 9);
            interruptSetEdge(9, detection);
            interruptNVICSetPriority(23, priority);
            interruptNVICEnableIRQ(23);
            break;
        case EXTI13:
            REG_VAL(EXTI_IMR) |= (1 << 13);
            interruptSetEdge(13, detection);
            interruptNVICSetPriority(40, priority);
            interruptNVICEnableIRQ(40);
            break;
        case EXTI2:
            REG_VAL(EXTI_IMR) |= (1 << 2);
            interruptSetEdge(2, detection);
            interruptNVICSetPriority(8, priority);
            interruptNVICEnableIRQ(8);
            break;
        case EXTI6:
            REG_VAL(EXTI_IMR) |= (1 << 6);
            interruptSetEdge(6, detection);
            interruptNVICSetPriority(23, priority);
            interruptNVICEnableIRQ(23);
            break;
        case EXTI10:
            REG_VAL(EXTI_IMR) |= (1 << 10);
            interruptSetEdge(10, detection);
            interruptNVICSetPriority(40, priority);
            interruptNVICEnableIRQ(40);
            break;
        case EXTI14:
            REG_VAL(EXTI_IMR) |= (1 << 14);
            interruptSetEdge(14, detection);
            interruptNVICSetPriority(40, priority);
            interruptNVICEnableIRQ(40);
            break;
        case EXTI3:
            REG_VAL(EXTI_IMR) |= (1 << 3);
            interruptSetEdge(3, detection);
            interruptNVICSetPriority(9, priority);
            interruptNVICEnableIRQ(9);
            break;
        case EXTI7:
            REG_VAL(EXTI_IMR) |= (1 << 7);
            interruptSetEdge(7, detection);
            interruptNVICSetPriority(23, priority);
            interruptNVICEnableIRQ(23);
            break;
        case EXTI11:
            REG_VAL(EXTI_IMR) |= (1 << 11);
            interruptSetEdge(11, detection);
            interruptNVICSetPriority(40, priority);
            interruptNVICEnableIRQ(40);
            break;
        case EXTI15:
            REG_VAL(EXTI_IMR) |= (1 << 15);
            interruptSetEdge(15, detection);
            interruptNVICSetPriority(40, priority);
            interruptNVICEnableIRQ(40);
            break;
        default:
            break;
    }
}

void interruptEnableOthers(Syscfg_Interrupt_Control_t position, uint8_t priority)
{
    if (priority > 0)
    {
        interruptNVICSetPriority(position, priority);
    }
    interruptNVICEnableIRQ(position);
}

int interruptCheckPendingReg(void)
{
    uint8_t i;
    int ret = -1;
    for (i = 0; i < 22; i++)
    {
        if (REG_VAL(EXTI_PR) & (1 << i))
        {
            REG_VAL(EXTI_PR) |= (uint32_t)(1 << i);
            ret = i;
            break;
        }
    }
    return ret;
}