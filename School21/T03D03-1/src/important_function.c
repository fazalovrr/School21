#include <math.h>
#include <stdio.h>

double fun();

int main() {
    double x;
    if (scanf("%lf", &x) == 1 && x > -10 && x != 0) {
        printf("%.1lf", fun(x));
    } else {
        printf("n/a");
    }

    return 0;
}

double fun(double x) {
    return 7e-3 * pow(x, 4) + ((22.8 * cbrt(x) - 1e3) * x + 3) / (x * x / 2) - x * pow(10 + x, 2.0 / x) -
           1.01;
}
