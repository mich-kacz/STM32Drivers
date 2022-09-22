/**
 ******************************************************************************
 * @file    logger.c
 * @author  Daniel Kopiecki
 * @date    2021-08-07
 * @brief   <Provide some short description here>
 ******************************************************************************
 */


/* Includes ---------------------------------------------------------------- */
#include "logger.h"

#include <stdarg.h>
#include <stdio.h>

#include "SEGGER_RTT.h"

/* Constants and macros ---------------------------------------------------- */
// clang-format off


// clang-format on

/* Private types ----------------------------------------------------------- */


/* Private variables ------------------------------------------------------- */


/* Private functions ------------------------------------------------------- */
static uint32_t logger_getTimestamp()
{
    return 0;
}

/* Exposed API ------------------------------------------------------------- */
void logger_unused(const char* format, ...)
{
    va_list args;
    va_start(args, format);
}

void logger_hex(const char* module, uint8_t* buffer, size_t size)
{
    SEGGER_RTT_printf(
        0,
        "%lu" D_MAGENTA "|LOG HEX|%s|Addr:  0x%08X |Size: %lu",
        logger_getTimestamp(),
        module,
        buffer,
        size);

    for (size_t i = 0; i < size; ++i)
    {
        SEGGER_RTT_printf(0, "%c%02X", (i % 16 == 0) ? '\n' : ' ', buffer[i]);
    }

    SEGGER_RTT_printf(0, D_NOCOLOR "\n");
}

void logger_log(const char* format, ...)
{
    SEGGER_RTT_printf(0, "%lu", logger_getTimestamp());

    va_list args;
    va_start(args, format);
    SEGGER_RTT_vprintf(0, format, &args);
    va_end(args);
}

void logger_raw(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    SEGGER_RTT_vprintf(0, format, &args);
    va_end(args);
}

/**** END OF FILE ****/