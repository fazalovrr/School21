#include "data_io.h"

#include <stdio.h>

void input(double *data, int n) {
    double *p = data;
    while (p - data < n && scanf("%lf", p) == 1) p++;
}

void output(double *data, int n) {
    for (int i = 1; i < n; i++)
        if (i < n - 1)
            printf("%.2lf ", data[i]);
        else
            printf("%.2lf", data[i]);
}