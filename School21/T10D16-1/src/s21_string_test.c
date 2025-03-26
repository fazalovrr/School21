#include "s21_string.h"

size_t s21_strlen_test(const char *str);
int s21_strcmp_test(const char *str1, const char *str2);
char *s21_strcpy_test(char *dest, const char *src);
char *s21_strcat_test(char *dest, const char *scr);
char *s21_strchr_test(const char *str, int c);
char *s21_strstr_test(const char *str, const char *substr);
char *s21_strtok_test(char *str, char *delim);

int main() {
#ifdef STRLN_TEST
    const char str1[] = "School21";
    size_t len = s21_strlen_test(str1);
    printf("Input string - 'School21'. Output string - '%s'. Print len - 8. Calc len - %zu. Result: %s\n",
           str1, len, len == 8 ? "SUCCESS" : "FAIL");
    const char str2[] = "";
    len = s21_strlen_test(str2);
    printf("Input string - ''. Output string - '%s'. Print len - 0. Calc len - %zu. Result: %s\n", str2, len,
           len == 0 ? "SUCCESS" : "FAIL");
    const char str3[] = "School\021";
    len = s21_strlen_test(str3);
    printf("Input string - 'School\021'. Output string - '%s'. Print len - 11. Calc len - %zu. Result: %s\n",
           str3, len, len == 11 ? "SUCCESS" : "FAIL");
#endif

#ifdef STRCMP_TEST
    const char str1[] = "School21";
    const char str3[] = "School\021";
    printf("Compare strings. Input string1 - 'School21', Input string2 - 'School\\021'. ");
    printf("Output string1 - '%s', Output string2 - '%s'. Result: %s\n", str1, str3,
           s21_strcmp_test(str1, str3) == 0 ? "SUCCESS" : "FAIL");
#endif

#ifdef STRCPY_TEST
    char src1[20] = "School21";
    char dest1[20];
    printf("Copy strings 1. Input string1 - 'School21', Input string2 - ''.  ");
    printf("Result: %s. Output string1 - '%s', Output string2 - '%s'. \n",
           s21_strcpy_test(dest1, src1) != NULL ? "SUCCESS" : "FAIL", src1, dest1);

    char src2[20] = "School21";
    char dest2[20] = "School22";
    printf("Copy strings 2. Input string1 - 'School21', Input string2 - 'School22'.  ");
    printf("Result: %s. Output string1 - '%s', Output string2 - '%s'. \n",
           s21_strcpy_test(dest2, src2) != NULL ? "SUCCESS" : "FAIL", src2, dest2);

    char src3[20];
    char dest3[20];
    printf("Copy strings 3. Input string1 - '', Input string2 - ''.  ");
    printf("Result: %s. Output string1 - '%s', Output string2 - '%s'. \n",
           s21_strcpy_test(dest3, src3) != NULL ? "SUCCESS" : "FAIL", src3, dest3);
#endif

#ifdef STRCAT_TEST
    char src1[20] = "School21";
    char dest1[20];
    printf("Copy strings 1. Input string1 - '', Input string2 - 'School21'.  ");
    printf("Result: %s. Output string1 - '%s', Output string2 - '%s'. \n",
           s21_strcat_test(dest1, src1) != NULL ? "SUCCESS" : "FAIL", src1, dest1);

    char src2[20] = "School21";
    char dest2[20] = "School22";
    printf("Copy strings 2. Input string1 - 'School21', Input string2 - 'School22'.  ");
    printf("Result: %s. Output string1 - '%s', Output string2 - '%s'. \n",
           s21_strcat_test(dest2, src2) != NULL ? "SUCCESS" : "FAIL", src2, dest2);

    char src3[20];
    char dest3[20];
    printf("Copy strings 3. Input string1 - '', Input string2 - ''.  ");
    printf("Result: %s. Output string1 - '%s', Output string2 - '%s'. \n",
           s21_strcat_test(dest3, src3) != NULL ? "SUCCESS" : "FAIL", src3, dest3);
#endif

#ifdef STRCHR_TEST
    const char *str1 = "School21";
    char ch = 'o';
    printf("String 1: '%s'. ", str1);
    char *result = s21_strchr(str1, ch);
    if (result != NULL) {
        printf("SUCCESS! Symbol '%c' found at position: %ld\n", ch, result - str1);
    } else {
        printf("FAIL! Symbol '%c' not found.\n", ch);
    }

    const char *str2 = "School21";
    ch = '3';
    printf("String 2: '%s'. ", str2);
    result = s21_strchr(str2, ch);
    if (result != NULL) {
        printf("SUCCESS! Symbol '%c' found at position: %ld\n", ch, result - str1);
    } else {
        printf("FAIL! Symbol '%c' not found.\n", ch);
    }

    const char *str3 = "";
    ch = '1';

    printf("String 3: '%s'. ", str3);
    result = s21_strchr(str3, ch);
    if (result != NULL && s21_strlen_test(str3) > 0) {
        printf("SUCCESS! Symbol '%c' found at position: %ld\n", ch, result - str3);
    } else {
        printf("FAIL! Symbol '%c' not found.\n", ch);
    }
#endif

#ifdef STRSTR_TEST
    const char *str1 = "School21";
    const char *substr1 = "ool";
    printf("String 1: '%s'. ", str1);
    char *result = s21_strstr(str1, substr1);
    if (result != NULL) {
        printf("SUCCESS! Substring '%s' found at position: %ld\n", substr1, result - str1);
    } else {
        printf("FAIL! Substring '%s' not found.\n", substr1);
    }

    const char *str2 = "School21";
    const char *substr2 = "Cool";
    printf("String 2: '%s'. ", str2);
    result = s21_strstr(str2, substr2);
    if (result != NULL) {
        printf("SUCCESS! Substring '%s' found at position: %ld\n", substr2, result - str2);
    } else {
        printf("FAIL! Substring '%s' not found.\n", substr2);
    }

    const char *str3 = "";
    const char *substr3 = "ool";
    printf("String 3: '%s'. ", str3);
    result = s21_strstr(str3, substr3);
    if (result != NULL) {
        printf("SUCCESS! Substring '%s' found at position: %ld\n", substr3, result - str3);
    } else {
        printf("FAIL! Substring '%s' not found.\n", substr3);
    }

#endif

#ifdef STRTOK_TEST

    char *token;
    char str1[] = "School-21";
    char delim[] = "-";
    printf("String 1: '%s'. Delim: '-'. ", str1);
    token = s21_strtok(str1, delim);
    if (!s21_strcmp(token, "School")) {
        printf("SUCCESS! Token 1: '%s'\n", token);
    } else {
        printf("FAIL\n");
    }
    char str2[] = "School21";
    printf("String 2: '%s'. Delim: '-'. ", str2);
    token = s21_strtok(str2, delim);
    if (!s21_strcmp(token, "School")) {
        printf("SUCCESS! Token 1: '%s'\n", token);
    } else {
        printf("FAIL\n");
    }
    char str3[] = "";
    token = s21_strtok(str2, delim);
    printf("String 3: '%s'. Delim: '-'. ", str3);
    if (!s21_strcmp(token, "School")) {
        printf("SUCCESS! Token 1: '%s'", token);
    } else {
        printf("FAIL");
    }

#endif

    return 0;
}
size_t s21_strlen_test(const char *str) { return s21_strlen(str); }

int s21_strcmp_test(const char *str1, const char *str2) { return s21_strcmp(str1, str2); }

char *s21_strcpy_test(char *dest, const char *src) { return s21_strcpy(dest, src); }

char *s21_strcat_test(char *dest, const char *src) { return s21_strcat(dest, src); }

char *s21_strchr_test(const char *str, int c) { return s21_strchr(str, c); }

char *s21_strstr_test(const char *str, const char *substr) { return s21_strstr(str, substr); }

char *s21_strtok_test(char *str, char *delim) { return s21_strtok(str, delim); }