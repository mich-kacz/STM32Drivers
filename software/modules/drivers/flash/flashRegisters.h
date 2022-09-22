#ifndef FLASH_REG_H
#define FLASH_REG_H

// Base value for flash memory region
#define FLASH_BASE 0x40023C00

// Flash registers
#define FLASH_FLASH_ACR     (0x00 + FLASH_BASE)
#define FLASH_FLASH_KEYR    (0x04 + FLASH_BASE)
#define FLASH_FLASH_OPTKEYR (0x08 + FLASH_BASE)
#define FLASH_FLASH_SR      (0x0C + FLASH_BASE)
#define FLASH_FLASH_CR      (0x10 + FLASH_BASE)
#define FLASH_FLASH_OPTCR   (0x14 + FLASH_BASE)


#endif