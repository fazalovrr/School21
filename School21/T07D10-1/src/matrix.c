#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int input_cap(int *cap, int *col);
int input_arr1(int *a, const int row, const int col);
int **input_arr2(const int row, const int col);
int **input_arr3(const int row, const int col);
int **input_arr4(const int row, const int col);
void s_output(const int *a, const int row, const int col);
void d_output(int **a, const int row, const int col);

int main() {
    int row, col;
    // printf("Выберите метод создания массива:\n1. Статический\n2. Динамический 1\n3. Динамический 2\n4.
    // Динамический 3\n");
    int num = input_cap(&row, &col);
    if (num > 0) {
        int s_arr[row][col];
        int **d_arr;
        switch (num) {
            case 1:
                if (input_arr1((int *)s_arr, row, col) > 0)
                    s_output((int *)s_arr, row, col);
                else
                    printf("n/a");
                break;
            case 2:
                d_arr = input_arr2(row, col);
                if (d_arr != NULL) {
                    d_output(d_arr, row, col);
                    free(d_arr);
                } else
                    printf("n/a");
                break;
            case 3:
                d_arr = input_arr3(row, col);
                if (d_arr != NULL) {
                    d_output(d_arr, row, col);
                    for (int i = 0; i < row; i++) free(d_arr[i]);
                    free(d_arr);
                } else
                    printf("n/a");
                break;
            case 4:
                d_arr = input_arr4(row, col);
                if (d_arr != NULL) {
                    d_output(d_arr, row, col);
                    free(d_arr[0]);
                    free(d_arr);
                } else
                    printf("n/a");
                break;
            default:
                printf("n/a");
                break;
        }
    } else
        printf("n/a");
    return 0;
}

int input_cap(int *row, int *col) {
    int res = 0;
    if (scanf("%d", &res) == 1 && res > 0 && res < 5) {
        if (scanf("%d", row) != 1) res = 0;
        if (scanf("%d", col) != 1) res = 0;
    } else
        res = 0;
    return res;
}

int input_arr1(int *a, const int row, const int col) {  // static
    int res = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            if (res && scanf("%d", a + i * col + j) != 1) res = 0;
        // if (getchar() != '\n') res = 0;
    }
    return res;
}

int **input_arr2(const int row, const int col) {  // single
    int res = 1;
    int **a = (int **)malloc(row * col * sizeof(int) + row * sizeof(int *));
    int *ptr = (int *)(a + row);

    for (int i = 0; i < row; i++) a[i] = ptr + col * i;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            if (res && scanf("%d", &a[i][j]) != 1) res = 0;
        // if (getchar() != '\n') res = 0;
    }
    if (!res) {
        free(a);
        a = NULL;
    }
    return a;
}

int **input_arr3(const int row, const int col) {
    int res = 1;
    int **a = malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) a[i] = malloc(col * sizeof(int));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            if (res && scanf("%d", &a[i][j]) != 1) res = 0;
        // if (getchar() != '\n') res = 0;
    }
    if (!res) {
        for (int i = 0; i < row; i++) free(a[i]);
        free(a);
        a = NULL;
    }
    return a;
}

int **input_arr4(const int row, const int col) {
    int res = 1;
    int **a = malloc(row * sizeof(int *));
    int *ptr = malloc(row * col * sizeof(int));

    for (int i = 0; i < row; i++) a[i] = ptr + col * i;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            if (res && scanf("%d", &a[i][j]) != 1) res = 0;
        if (getchar() != '\n') res = 0;
    }
    if (!res) {
        free(a[0]);
        free(a);
        a = NULL;
    }
    return a;
}

void s_output(const int *a, const int row, const int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            if (j < col - 1)
                printf("%d ", *(a + i * col + j));
            else
                printf("%d", *(a + i * col + j));
        if (i < row - 1) printf("\n");
    }
}

void d_output(int **a, const int row, const int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            if (j < col - 1)
                printf("%d ", a[i][j]);
            else
                printf("%d", a[i][j]);
        if (i < row - 1) printf("\n");
    }
}