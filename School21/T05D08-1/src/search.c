#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
int find_pos(int *a, int *n);
double mean(int *a, int *n);
double variance(int *a, int *n, double avr);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        printf("%d", find_pos(data, &n));
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

int find_pos(int *a, int *n) {
    int res = 0;
    for (int p = 0; p < *n; p++) {
        if (a[p] > 0)
            if (a[p] % 2 == 0)
                if (a[p] >= mean(a, n))
                    if (a[p] <= mean(a, n) + 3 * sqrt(variance(a, n, mean(a, n)))) res = p + 1;
    }
    return res;
}

double mean(int *a, int *n) {
    double avr = a[0];
    for (int i = 1; i < *n; i++) {
        avr = avr + a[i];
    }
    avr = avr / *n;
    return avr;
}

double variance(int *a, int *n, double avr) {
    double vr = 0;
    for (int p = 0; p < *n; p++) {
        vr = vr + (a[p] - avr) * (a[p] - avr);
    }
    vr = vr / *n;
    return vr;
}