#include <stdio.h>

int divider(int a) {
    int b, c, d;
    b = a - 1;
    c = a;
    d = 0;
    while (c != 0 && b > 1) {
        c = a;
        while (c > 0) {
            c = c - b;
        }
        b--;
        d++;
    }
    b++;
    if (c < 0 || d == 0) b = 0;
    return b;
}

int main() {
    int a;
    char c;
    if (scanf("%d %c", &a, &c) == 1 && (a > 1 || a < -1)) {
        if (a < 0) a = -a;
        while (divider(a) > 0) a = divider(a);
    } else {
        a = 0;
    }
    a != 0 ? printf("%d", a) : printf("n/a");
    return 0;
}