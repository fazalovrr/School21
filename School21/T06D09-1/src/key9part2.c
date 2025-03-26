#include <stdio.h>

#define LEN 100

void sum(const int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length);
void sub(const int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length);
int input(int arr[], int *len);
void output(const int arr[], const int *len);
int comp(int *buff1, int len1, int *buff2, int len2);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main() {
    int arr[LEN];
    int arr2[LEN];
    int result[LEN];
    int result_length = 0;
    int len = 0;
    int len2 = 0;
    input(arr, &len);

    input(arr2, &len2);

    sum(arr, len - 1, arr2, len2 - 1, result, &result_length);
    output(result, &result_length);
    printf("\n");

    sub(arr, len - 1, arr2, len2 - 1, result, &result_length);
    output(result, &result_length);
}

int input(int arr[], int *len) {
    while (scanf("%d", &arr[*len]) == 1 && getchar() == 32) {
        (*len)++;
    }
    (*len)++;
    return 0;
}

void output(const int arr[], const int *len) {
    if (*len >= 0) {
        int res = 0;
        for (int i = 0; i < *len + 1; i++) {
            if (arr[i] > 0) res = 1;
            if (res) printf("%d ", arr[i]);
        }
        if (res == 0) printf("0");
    } else
        printf("n/a");
}

void sum(const int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length) {
    int per = 0;
    if (len1 >= len2)
        *result_length = len1;
    else
        *result_length = len2;
    int res = *result_length;

    while (res > -1) {
        int b1 = 0;
        int b2 = 0;
        if (len1 >= 0) {
            b1 = buff1[len1];
        }
        if (len2 >= 0) {
            b2 = buff2[len2];
        }
        result[res] = (per + b1 + b2) % 10;
        per = (per + b1 + b2) / 10;
        len1--;
        len2--;
        res--;
    }
    if (per > 0) {
        for (int i = *result_length + 1; i > 0; i--) {
            result[i] = result[i - 1];
        }
        result[0] = 1;
        (*result_length)++;
    }
}

void sub(const int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length) {
    int per = 0;
    if (len1 > len2)
        *result_length = len1;
    else
        *result_length = len2;
    int res = *result_length;
    int r = 1;
    while (r > 0) {
        r = 0;
        int b1 = 0;
        int b2 = 0;
        if (len1 >= 0) {
            b1 = buff1[len1];
            r = 1;
        }
        if (len2 >= 0) {
            b2 = buff2[len2];
            r = 1;
        }
        if (r > 0) {
            if (b1 - b2 - per < 0) {
                result[res] = 10 + b1 - b2 - per;
                per = 1;
            } else {
                result[res] = b1 - b2 - per;
                per = 0;
            }
        }
        len1--;
        len2--;
        res--;
    }
    if (per > 0) *result_length = -1;
}