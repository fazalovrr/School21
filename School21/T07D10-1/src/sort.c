#include <stdio.h>
#include <stdlib.h>

int input_cap(int *cap);
int input_arr(int *a, const int *cap);
void output(int *a, const int *cap);
int sort(int *a, const int *cap);

int main() {
    int cap;
    if (input_cap(&cap)) {
        int *data = calloc(cap, sizeof(int));
        if (data != NULL) {
            if (input_arr(data, &cap)) {
                printf("\n");
                int f = 1;
                while (f) f = sort(data, &cap);
                output(data, &cap);
                free(data);
            } else
                printf("n/a");
        } else
            printf("n/a");
    } else
        printf("n/a");
    return 0;
}

int input_cap(int *cap) {
    int res = 0;
    if (scanf("%d", cap) == 1) res = *cap;
    return res;
}

int input_arr(int *a, const int *cap) {
    int res = 1;
    for (int *p = a; p - a < *cap; p++)
        if (scanf("%d", p) != 1) res = 0;
    if (getchar() != '\n') res = 0;
    return res;
}

int sort(int *a, const int *cap) {
    int f = 0;
    for (int *p = a; p - a < *cap - 1; p++)
        if (*p > *(p + 1)) {
            f = *p;
            *p = *(p + 1);
            *(p + 1) = f;
        }
    return f;
}

void output(int *a, const int *cap) {
    for (int p = 0; p < *cap; p++)
        if (p == *cap - 1)
            printf("%d", a[p]);
        else
            printf("%d ", a[p]);
}