#include <stdio.h>

int max();

int main() {
    double ad, bd;
    long a, b;
    int in = scanf("%lf %lf", &ad, &bd);
    a = ad;
    b = bd;
    if (a + b == ad + bd && in == 2) {
        printf("%d", max(a, b));
    } else {
        printf("n/a");
    }

    return 0;
}

int max(int a, int b) {
    if (a < b) {
        a = b;
    }

    return a;
}