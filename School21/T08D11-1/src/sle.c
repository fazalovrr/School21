#include <stdio.h>
#include <stdlib.h>



void input(int ***matrix, int *n, int *m);
void output(int **matrix, int n, int m);


void main() {
    int **matrix, n=0, m=0;
    input(matrix, &n, &m);
    output(matrix, n, m);

    // Освобождение памяти
    if (matrix != NULL) {
        for (int i = 0; i < n; i++) {
            free(matrix[i]);
        }
        free(matrix);
}


void input(int ***matrix, int *n, int *m){
    int res = 1;
    if (scanf("%d", n) == 1 && *n > 0){
        if (scanf("%d", m) == 1 && *m > 0) {
            *matrix = malloc((*n) * sizeof(int *));
            for (int i=0;i< *n;i++) *matrix[i]=(int *)malloc((*m) * sizeof(int));
            if (*matrix != NULL){
                for (int i = 0; i < *n; i++)
                    for (int j = 0; j < *m; j++)
                        if (scanf("%d", &(*matrix[i][j])!=1)) res = 0;
            }
        }
    }
    if (res == 0) {
        if (*matrix != NULL) {
            for (int i = 0; i < *n; i++) {
                if ((*matrix)[i] != NULL) {
                    free((*matrix)[i]);
                }
            }
            free(*matrix);
            *matrix = NULL;
        }
        *n = 0;
        *m = 0;
    }
}

void output(int **matrix, int n, int m){
    if (matrix == NULL || n <= 0 || m <= 0) {
        printf("Матрица не инициализирована или имеет неверные размеры.\n");
        return;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}