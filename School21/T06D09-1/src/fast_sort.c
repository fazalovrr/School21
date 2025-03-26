#include <stdio.h>
#define NMAX 10

int input(int *a);
void output(int *a);
void quicksort(int *a, int left, int right);
void heapsort(int arr[], int n);
void swap(int *a, int i, int j);
void heapify(int arr[], int n, int i);
void copy_arr(const int *a, int *b);

int main() {
    int data[NMAX];

    if (input(data)) {
        int data2[NMAX];
        copy_arr(data, data2);
        quicksort(data, 0, NMAX - 1);
        output(data);
        printf("\n");
        heapsort(data2, NMAX);
        output(data2);
    } else
        printf("n/a");
    return 0;
}

int input(int *a) {
    int res = 1;
    for (int *p = a; p - a < NMAX; p++) {
        res = 1;
        if (scanf("%d", p) != 1) res = 0;
    }
    return res;
}

void output(int *a) {
    for (int p = 0; p < NMAX; p++)
        if (p == NMAX - 1)
            printf("%d", a[p]);
        else
            printf("%d ", a[p]);
}

void quicksort(int *a, int left, int right) {
    // int f = 0;
    if (left <= right) {
        int p = a[(left + right) / 2];
        int i = left;
        int j = right;
        while (i <= j) {
            while (a[i] < p) i++;
            while (a[j] > p) j--;
            if (i <= j) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++;
                j--;
            }
        }
        quicksort(a, left, j);
        quicksort(a, i, right);
    }
}

void heapsort(int *a, int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    for (i = n - 1; i > 0; i--) {
        swap(a, 0, i);
        heapify(a, i, 0);
    }
}

void swap(int *a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    return;
}

void heapify(int *a, int n, int i) {
    int max = i;
    int r = 2 * i + 2;
    int l = 2 * i + 1;

    if (l < n && a[l] > a[max]) max = l;

    if (r < n && a[r] > a[max]) max = r;

    if (max != i) {
        int temp = a[i];
        a[i] = a[max];
        a[max] = temp;
        heapify(a, n, max);
    }
    return;
}

void copy_arr(const int *a, int *b) {
    for (int i = 0; i < NMAX; i++) b[i] = a[i];
}