#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int *n);
int max(int *a, int *n);
int min(int *a, int *n);
double mean(int *a, int *n);
double variance(int *a, int *n, double avr);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        output(data, &n);
        output_result(max(data, &n), min(data, &n), mean(data, &n), variance(data, &n, mean(data, &n)));
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
            printf("%d\n", a[p]);
        else
            printf("%d ", a[p]);
    }
}

int max(int *a, int *n) {
    int max_val = a[0];
    for (int p = 1; p < *n; p++) {
        if (a[p] > max_val) max_val = a[p];
    }
    return max_val;
}

int min(int *a, int *n) {
    int min_val = a[0];
    for (int p = 1; p < *n; p++) {
        if (a[p] < min_val) min_val = a[p];
    }
    return min_val;
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
};
