#include <stdio.h>
#include <stdlib.h>

int **input(int *m, int *n);
void output(int **matrix, int m, int n);
int **sort_horizontal(int **matrix, int m, int n);
int **sort_vertical(int **matrix, int m, int n);

int main() {
    int **result;
    int n, m;

    int **matrix = input(&m, &n);
    if (matrix != NULL) {
        // printf("\n"); //Для красоты он должен быть тут, но в условии нету...
        result = sort_vertical(matrix, n, m);
        output(result, m, n);
        printf("\n\n");
        result = sort_horizontal(matrix, m, n);
        output(result, m, n);
        for (int i = 0; i < m; i++) {
            free(matrix[i]);
            free(result[i]);
        }
        free(matrix);
        free(result);
        matrix = NULL;
        result = NULL;
    } else
        printf("n/a");
    return 0;
}

int **input(int *m, int *n) {
    int res = 0;
    int **arr = NULL;
    if (scanf("%d", m) == 1) {
        if (scanf("%d", n) == 1) {
            arr = malloc((*m) * sizeof(int *));
            for (int i = 0; i < *m; i++) arr[i] = malloc((*n) * sizeof(int));
            for (int i = 0; i < *m; i++)
                for (int j = 0; j < *n; j++)
                    if (scanf("%d", &arr[i][j]) == 1) res = 1;
        }
    }
    if (res == 0) {
        for (int i = 0; i < *m; i++) free(arr[i]);
        free(arr);
        arr = NULL;
    }
    return arr;
}

int **sort_vertical(int **matrix, int m, int n) {
    int **result_matrix = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) result_matrix[i] = malloc(n * sizeof(int));

    int f = 1, a, j = 0;
    for (int i = 0; i < m; i++) {
        a = 0;
        while (a < n) {
            result_matrix[a][i] = matrix[i][j];
            a++;
            if ((f > 0 && j == m - 1) || (f < 0 && j == 0))
                f = -f;
            else
                j = j + f;
        }
    }
    return result_matrix;
}

int **sort_horizontal(int **matrix, int m, int n) {
    int **result_matrix = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) result_matrix[i] = malloc(n * sizeof(int));
    int f = 1, a, j = 0;
    for (int i = 0; i < m; i++) {
        a = 0;
        while (a < n) {
            result_matrix[i][a] = matrix[i][j];
            a++;
            if ((f > 0 && j == m - 1) || (f < 0 && j == 0))
                f = -f;
            else
                j = j + f;
        }
    }
    return result_matrix;
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            if (j < n - 1)
                printf("%d ", matrix[i][j]);
            else
                printf("%d", matrix[i][j]);
        if (i < m - 1) printf("\n");
    }
}