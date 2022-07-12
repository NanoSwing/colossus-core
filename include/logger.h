#pragma once

#include "defs.h"

typedef enum {
    LOG_LEVEL_FATAL,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_WARN,
    LOG_LEVEL_INFO,
    LOG_LEVEL_DEBUG
} LogLevel;

extern void _log_message(LogLevel level, const char *file, U32 line, const char *message, ...);

/*
 * Logs a fatal level message.
 *
 * Args:
 * message - Message.
 */
#define log_fatal(message, ...) _log_message(LOG_LEVEL_FATAL, __FILE__, __LINE__, message, ##__VA_ARGS__)
/*
 * Logs an error level message.
 *
 * Args:
 * message - Message.
 */
#define log_error(message, ...) _log_message(LOG_LEVEL_ERROR, __FILE__, __LINE__, message, ##__VA_ARGS__)
/*
 * Logs a warning level message.
 *
 * Args:
 * message - Message.
 */
#define log_warn(message, ...)  _log_message(LOG_LEVEL_WARN, __FILE__, __LINE__,  message, ##__VA_ARGS__)
/*
 * Logs an info level message.
 *
 * Args:
 * message - Message.
 */
#define log_info(message, ...)  _log_message(LOG_LEVEL_INFO, __FILE__, __LINE__, message, ##__VA_ARGS__)

#ifdef COLOSSUS_RELEASE
    /*
     * Logs a debug level message.
     *
     * Args:
     * message - Message.
     */
    #define log_debug(message, ...)
#else
    /*
     * Logs a debug level message.
     *
     * Args:
     * message - Message.
     */
    #define log_debug(message, ...) _log_message(LOG_LEVEL_DEBUG, __FILE__, __LINE__, message, ##__VA_ARGS__)
#endif
