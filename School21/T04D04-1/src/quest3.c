#include <stdio.h>

int fib_num(int n) { return (n == 0 || n == 1) ? n : (fib_num(n - 1) + fib_num(n - 2)); }

int main() {
    int n, b;
    char ch;
    scanf("%d%c", &n, &ch);
    b = ch;
    if (b == 10 && n >= 0)
        printf("%d", fib_num(n));
    else
        printf("n/a");
    return 0;
}