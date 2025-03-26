#include "s21_string.h"

#include <stdio.h>

size_t s21_strlen(const char *str);
int s21_strcmp(const char *str1, const char *str2);
char *s21_strcpy(char *dest, const char *src);
char *s21_strcat(char *dest, const char *src);
char *s21_strchr(const char *str, int c);
char *s21_strstr(const char *str, const char *substr);
char *s21_strtok(char *str, char *delim);

size_t s21_strlen(const char *str) {
    size_t length = 0;
    if (str != NULL)
        while (str[length] != '\0') length++;
    return length;
}

int s21_strcmp(const char *str1, const char *str2) {
    int res = 0, i = 0;
    if (str1 == NULL && str2 == NULL)
        res = 0;
    else {
        if (str1 == NULL)
            res = -1;
        else if (str2 == NULL)
            res = 1;
    }
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) res = (unsigned char)str1[i] - (unsigned char)str2[i];
        i++;
    }
    res = (unsigned char)str1[i] - (unsigned char)str2[i];

    return res;
}

char *s21_strcpy(char *dest, const char *src) {
    if (dest == NULL || src == NULL) return NULL;
    char *ptr = dest;
    while ((*dest++ = *src++) != '\0');

    return ptr;
}

char *s21_strcat(char *dest, const char *src) {
    if (dest == NULL || src == NULL) return NULL;
    char *ptr = dest;
    while (*dest != '\0') dest++;

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
    return ptr;
}

char *s21_strchr(const char *str, int c) {
    for (; *str != c; ++str)
        if (*str == '\0') return 0;
    return (char *)str;
}

char *s21_strstr(const char *str, const char *substr) {
    char *result = NULL;

    if (str == NULL || substr == NULL) {
        return NULL;
    }
    if (*substr == '\0') {
        result = (char *)str;
    } else {
        while (*str != '\0' && result == NULL) {
            const char *h = str;
            const char *n = substr;
            while (*h != '\0' && *n != '\0' && *h == *n) {
                h++;
                n++;
            }
            if (*n == '\0') {
                result = (char *)str;
            }
            str++;
        }
    }
    return result;
}

char *s21_strtok(char *str, char *delim) {
    char *next;

    if (str) {
        next = str;
        while (*next && s21_strchr(delim, *next)) *next++ = '\0';
    }

    if (!*next) return NULL;

    str = next;

    while (*next && !s21_strchr(delim, *next)) ++next;
    while (*next && s21_strchr(delim, *next)) *next++ = '\0';

    return str;
}