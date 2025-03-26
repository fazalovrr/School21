#include <stdio.h>

#ifdef PRINT_MODULE
#include <time.h>

#include "print_module.h"
#endif

#ifdef DOC_MODULE
#include <stdlib.h>

#include "documentation_module.h"
#endif

int main() {
#ifdef PRINT_MODULE1
    print_log(print_char, Log_prefix);
    print_log(print_char, " ");

    time_t raw_time;
    struct tm *time_info;
    time(&raw_time);
    time_info = localtime(&raw_time);
    char time_buffer[9];
    strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S", time_info);
    print_log(print_char, time_buffer);

    print_log(print_char, " ");
    print_log(print_char, Module_load_success_message);
#endif

#ifdef DOC_MODULE1
    int *availability_mask = check_available_documentation_module(validate, Documents_count, Documents);
    if (availability_mask) {
        char *documents[] = {Documents};

        for (int i = 0; i < Documents_count; i++) {
            printf("%d. %-*s : %s\n", i + 1, 15, documents[i],
                   availability_mask[i] ? "available" : "unavailable");
        }
        free(availability_mask);

    } else
        printf("Memory error\n");
#endif
    return 0;
}
