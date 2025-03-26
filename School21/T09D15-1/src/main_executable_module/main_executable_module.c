#include <stdio.h>
#include <stdlib.h>

#define USE_DYNAMIC_LIB

#ifdef USE_DYNAMIC_LIB
#include "../data_module/data_process.h"
#else
#include "../data_module/data_process.h"
#endif

#include "../data_libs/data_io.h"
#include "../yet_another_decision_module/decision.h"

void sort(double *data, int n);

int main() {
    double *data;
    int n;

    if (scanf("%d", &n) == 1 && n > 0) {
        data = (double *)malloc(n * sizeof(double));
        if (data == NULL) {
            printf("ERROR");
        } else {
            input(data, n);

            printf("LOAD DATA...\n");
            input(data, n);

            printf("RAW DATA:\n\t");
            output(data, n);

            printf("\nNORMALIZED DATA:\n\t");
            normalization(data, n);
            output(data, n);

            printf("\nSORTED NORMALIZED DATA:\n\t");
            sort(data, n);
            output(data, n);

            printf("\nFINAL DECISION:\n\t");
            make_decision(data, n);
            output(data, n);
        }
    }
    return 0;
}

void sort(double *data, int n) {
    double temp;
    int f = 1;
    while (f) {
        f = 0;
        for (int i = 0; i < n - 1; i++)
            if (data[i] > data[i + 1]) {
                temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
                f = 1;
            }
    }
}