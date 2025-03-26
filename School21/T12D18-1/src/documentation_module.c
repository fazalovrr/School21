#include "documentation_module.h"

#include <stdarg.h>
#include <stdlib.h>

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int* check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    if (document_count > 15) document_count = 15;

    int* availability = (int*)malloc(sizeof(int) * document_count);
    if (availability) {
        va_list args;
        va_start(args, document_count);
        for (int i = 0; i < document_count; i++) {
            char* doc = va_arg(args, char*);
            availability[i] = validate(doc);
        }
        va_end(args);
    }
    return availability;
}