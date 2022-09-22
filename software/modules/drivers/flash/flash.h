#ifndef FLASH_H
#define FLASH_H

typedef enum FlashPRFTEN_e
{
    FlashPRFTEN_OFF_DEFAULT = 0,
    FlashPRFTEN_ON  = 1
} FlashPRFTEN_t;

typedef enum FlashICEN_e
{
    FlashICEN_OFF_DEFAULT = 0,
    FlashICEN_ON  = 1
} FlashICEN_t;

typedef enum FlashDCEN_e
{
    FlashDCEN_OFF_DEFAULT = 0,
    FlashDCEN_ON  = 1
} FlashDCEN_t;

typedef enum FlashICRST_e
{
    FlashICRST_OFF_DEFAULT = 0,
    FlashICRST_ON  = 1
} FlashICRST_t;

typedef enum FlashDCRST_e
{
    FlashDCRST_OFF_DEFAULT = 0,
    FlashDCRST_ON  = 1
} FlashDCRST_t;

typedef struct FlashCacheConfig_s
{
    FlashPRFTEN_t PRFTEN;
    FlashICEN_t ICEN;
    FlashDCEN_t DCEN;
    FlashICRST_t ICRST;
    FlashDCRST_t DCRST;
} FlashCacheConfig_t;


int flashSetLatency(unsigned int latency);
void flashSetDataCache(FlashCacheConfig_t config);

#endif