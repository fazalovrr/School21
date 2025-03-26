#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int *n);
void squaring(int *a, int *n);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        squaring(data, &n);
        output(data, &n);
    } else
        printf("n/a");
    return 0;
}

int input(int *a, int *n) {
    int res = 1;

    if (scanf("%d", n) != 1 || *n < 1 || *n > NMAX)
        res = 0;
    else
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d", p) != 1) res = 0;
        }
    return res;
}

void output(int *a, int *n) {
    for (int p = 0; p < *n; p++) {
        if (p == *n - 1)
            printf("%d", a[p]);
        else
            printf("%d ", a[p]);
    }
}

void squaring(int *a, int *n) {
    for (int p = 0; p < *n; p++) {
        a[p] = a[p] * a[p];
    }
}
