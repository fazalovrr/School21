#include <stdio.h>
#define NMAX 10

int input(int *a);
void output(int *a);
int sort(int *a);

int main() {
    int data[NMAX];
    if (input(data)) {
        int f = 1;
        while (f) f = sort(data);
        output(data);
    } else
        printf("n/a");
    return 0;
}

int input(int *a) {
    int res = 1;
    for (int *p = a; p - a < NMAX; p++)
        if (scanf("%d", p) != 1) res = 0;
    return res;
}

int sort(int *a) {
    int f = 0;
    for (int *p = a; p - a < NMAX - 1; p++)
        if (*p > *(p + 1)) {
            f = *p;
            *p = *(p + 1);
            *(p + 1) = f;
        }
    return f;
}

void output(int *a) {
    for (int p = 0; p < NMAX; p++)
        if (p == NMAX - 1)
            printf("%d", a[p]);
        else
            printf("%d ", a[p]);
}