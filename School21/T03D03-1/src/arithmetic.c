#include <stdio.h>

int sum(int a, int b);
int mi(int a, int b);
int mu(int a, int b);
int di(int a, int b);

int main() {
    double ad, bd;
    int a, b;
    int in = scanf("%lf %lf", &ad, &bd);
    a = ad;
    b = bd;
    if (a + b == ad + bd && in == 2) {
        if (b > 0) {
            printf("%d %d %d %d", sum(a, b), mi(a, b), mu(a, b), di(a, b));
        } else {
            printf("%d %d %d n/a", sum(a, b), mi(a, b), mu(a, b));
        }
    } else {
        printf("n/a");
    }

    return 0;
}

int sum(int a, int b) { return (a + b); }
int mi(int a, int b) { return (a - b); }
int mu(int a, int b) { return (a * b); }
int di(int a, int b) { return (a / b); }