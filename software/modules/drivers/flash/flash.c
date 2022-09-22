#include "flash.h"

#include <stdint.h>

#include "flashRegisters.h"


#define REG_VAL(X) (*(volatile uint32_t*)X)


int flashSetLatency(unsigned int latency)
{
    int error = -1;
    if (latency > 15)
    {
        error = -1;
    }
    else
    {
        REG_VAL(FLASH_FLASH_ACR) |= (uint8_t)latency;
        error = 1;
    }
    return error;
}

void flashSetDataCache(FlashCacheConfig_t config)
{
    REG_VAL(FLASH_FLASH_ACR) |=
        ((config.PRFTEN << 8) | (config.ICEN << 9) | (config.DCEN << 10)
         | (config.ICRST << 11) | (config.DCRST << 12));
}