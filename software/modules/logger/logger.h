/**
 ******************************************************************************
 * @file    logger.h
 * @author  Daniel Kopiecki
 * @date    2021-08-07
 * @brief   <Provide some short description here>
 ******************************************************************************
 */

/* Define to prevent recursive inclusion ----------------------------------- */
#ifndef LOGGER_H_
#define LOGGER_H_

/* Includes ---------------------------------------------------------------- */
#include <stdint.h>

#include "SEGGER_RTT.h"

/* Constants and macros ---------------------------------------------------- */
// clang-format off

#define LOGGER_DEBUG_SEVERITY_LOG_DISABLED      -1
#define LOGGER_DEBUG_SEVERITY_ERROR              0
#define LOGGER_DEBUG_SEVERITY_WARNING            1
#define LOGGER_DEBUG_SEVERITY_INFO               2
#define LOGGER_DEBUG_SEVERITY_DEBUG              3
#define LOGGER_DEBUG_SEVERITY_LOG                4
#define LOGGER_DEBUG_SEVERITY_TRACE              5

#define LOGGER_INIT()                   SEGGER_RTT_Init();
#define LOGGER_DEINIT()         

#ifdef __FORCE_DEBUG_SEVERITY
#undef _DEBUG_SEVERITY
#define _DEBUG_SEVERITY             __FORCE_DEBUG_SEVERITY
#endif

#ifdef DEBUG
    #ifndef _DEBUG_SEVERITY
        #define _DEBUG_SEVERITY             LOGGER_DEBUG_SEVERITY_TRACE
    #endif
#else
    #ifndef _DEBUG_SEVERITY
        #define _DEBUG_SEVERITY             LOGGER_DEBUG_SEVERITY_ERROR
    #endif
#endif

#define DBG_NL                      "\r\n"
#define DBG_EMPTY                   ""

#define D_COLORDEF(_num)			"\033[1;" #_num "m"
#define D_NOCOLOR 					"\033[0m"

#define D_DARK_GRAY                 D_COLORDEF(30)
#define D_RED                       D_COLORDEF(31)
#define D_GREEN                     D_COLORDEF(32)
#define D_YELLOW                    D_COLORDEF(33)
#define D_BLUE                      D_COLORDEF(34)
#define D_MAGENTA                   D_COLORDEF(35)
#define D_CYAN                      D_COLORDEF(36)
#define D_LIGHT_GRAY                D_COLORDEF(37)
#define D_LIGHT_RED                 D_COLORDEF(91)
#define D_LIGHT_GREEN               D_COLORDEF(92)
#define D_LIGHT_YELLOW              D_COLORDEF(93)
#define D_LIGHT_BLUE                D_COLORDEF(94)
#define D_LIGHT_MAGENTA             D_COLORDEF(95)
#define D_LIGHT_CYAN                D_COLORDEF(96)
#define D_WHITE                     D_COLORDEF(97)

#define DBG_SEVERITY_MASK           ((1 << (5 + 1u)) - 1)

#define MODULE_NAME_LOG             __func__

#if DBG_SEVERITY_MASK & 0x0001
#define LOG_ERROR(format, ...)      logger_log(D_RED "|ERR|%s| " format D_NOCOLOR DBG_NL, MODULE_NAME_LOG, ## __VA_ARGS__)
#else
#define LOG_ERROR(format, ...)      logger_unused(format, ## __VA_ARGS__)
#endif

#if DBG_SEVERITY_MASK & 0x0002
#define LOG_WARNING(format, ...)    logger_log(D_YELLOW "|WRN|%s| " format D_NOCOLOR DBG_NL, MODULE_NAME_LOG, ## __VA_ARGS__)
#else
#define LOG_WARNING(format, ...)      logger_unused(format, ## __VA_ARGS__)
#endif

#if DBG_SEVERITY_MASK & 0x0004
#define LOG_INFO(format, ...)      logger_log(D_CYAN "|INF|%s| " format D_NOCOLOR DBG_NL, MODULE_NAME_LOG, ## __VA_ARGS__)
#else
#define LOG_INFO(format, ...)      logger_unused(format, ## __VA_ARGS__)
#endif

#if DBG_SEVERITY_MASK & 0x0008
#define LOG_DEBUG(format, ...)      logger_log(D_LIGHT_GRAY "|DBG|%s| " format D_NOCOLOR DBG_NL, MODULE_NAME_LOG, ## __VA_ARGS__)
#else
#define LOG_DEBUG(format, ...)      logger_unused(format, ## __VA_ARGS__)
#endif

#if DBG_SEVERITY_MASK & 0x0010
#define LOG_TRACE(format, ...)      logger_log(D_LIGHT_GREEN "|TRC|%s| " format D_NOCOLOR DBG_NL, MODULE_NAME_LOG, ## __VA_ARGS__)
#else
#define LOG_TRACE(format, ...)      logger_unused(format, ## __VA_ARGS__)
#endif

#if DBG_SEVERITY_MASK & 0x0020
#define LOG_LOG(format, ...)      logger_log(D_LIGHT_MAGENTA "|LOG|%s| " format D_NOCOLOR DBG_EMPTY, MODULE_NAME_LOG, ## __VA_ARGS__)
#else
#define LOG_LOG(format, ...)      logger_unused(format, ## __VA_ARGS__)
#endif

#define LOG_HEX(buffer, size)     logger_hex(MODULE_NAME_LOG, (uint8_t*)buffer, size)

// clang-format on

/* Types ------------------------------------------------------------------- */


/* Exposed API ------------------------------------------------------------- */

void logger_log(const char* format, ...);
void logger_raw(const char* format, ...);
void logger_hex(const char* module, uint8_t* buffer, size_t size);
void logger_unused(const char* format, ...);

#endif /* LOGGER_H_ */

/**** END OF FILE ****/