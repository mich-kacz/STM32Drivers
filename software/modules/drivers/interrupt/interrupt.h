#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <stdint.h>

#include "syscfg.h"


typedef enum InterruptEXITEdgeDetection_e
{
    EXTIFallingEdge,
    EXTIRisingEdge
} InterruptEXITEdgeDetection_t;

void interruptEnableEXTI(
    Syscfg_EXTICRx_Control_t number,
    Syscfg_EXTICRx_Config_t bus,
    InterruptEXITEdgeDetection_t detection,
    uint8_t priority);
int interruptCheckPendingReg(void);
void interruptEnableOthers(Syscfg_Interrupt_Control_t position, uint8_t priority);

#endif