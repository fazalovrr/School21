#include "logger.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

#include "log_levels.h"

FILE* log_init(char* filename) { return fopen(filename, "a+"); }

int logcat(FILE* log_file, char* message, enum log_level level) {
    char str[10] = "\0";
    time_t raw_time;
    struct tm* time_info;
    time(&raw_time);
    time_info = localtime(&raw_time);
    char time_buffer[20];
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", time_info);

    switch (level) {
        case debug:
            strcat(str, "DEBUG ");
            break;
        case trace:
            strcat(str, "TRACE ");
            break;
        case info:
            strcat(str, "INFO ");
            break;
        case warning:
            strcat(str, "WARNING ");
            break;
        case error:
            strcat(str, "ERROR ");
            break;
        default:
            break;
    }

    fprintf(log_file, "%-8s %-20s %s\n", str, time_buffer, message);

    log_close(log_file);

    return 0;
}

int log_close(FILE* log_file) { return fclose(log_file); }
