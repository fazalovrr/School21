#include <math.h>
#include <stdio.h>

long double vrzr(long double x) { return 1. / (1 + x * x); }

long double bern(long double x) { return sqrt(sqrt(1 + 4 * x * x) - x * x - 1); }

long double giperb(long double x) { return 1. / (x * x); }

int main() {
    long double pi = M_PI;
    long double dx = pi * 2. / 41;
    long double x = -pi;
    for (int i = 0; i < 42; ++i) {
        if (x == 0)
            printf("%.7Lf | %.7Lf | - | -\n", x, vrzr(x));
        else if (sqrt(1 + 4 * x * x) - x * x - 1 > 0)
            printf("%.7Lf | %.7Lf | %.7Lf | %.7Lf\n", x, vrzr(x), bern(x), giperb(x));
        else
            printf("%.7Lf | %.7Lf | - | %.7Lf\n", x, vrzr(x), giperb(x));
        x += dx;
    }
}
