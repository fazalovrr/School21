/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

void input(int *buffer, int *length);
void output(int *buffer, int length);
int find_numbers(const int *buffer, int length, int number, int *numbers);
int sum_numbers(const int *buffer, int length);
int find_numbers(const int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int length = 10, buffer[NMAX];
    input(buffer, &length);
    if (length > 0) {
        int sum = sum_numbers(buffer, length);
        if (sum>0)printf("%d\n", sum); else printf("n/a");
        int numbers[NMAX];
        int num = find_numbers(buffer, length, sum, numbers);

        if (num > 0) {
            for (int i = 0; i < num; i++) {
                if (i < num - 1)
                    printf("%d ", numbers[i]);
                else
                    printf("%d", numbers[i]);
            }
        }
    } else
        printf("n/a");
    return 0;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(const int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0 && buffer[i] != 0) {
            sum = sum + buffer[i];
        }
    }
    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(const int *buffer, int length, int number, int *numbers) {
    int num = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[num] = buffer[i];
            num++;
        }
    }
    return num;
}

void input(int *buffer, int *length) {
    if (scanf("%d", length) != 1 || *length < 1 || *length > NMAX)
        *length = -1;
    else
        for (int *p = buffer; p - buffer < *length; p++) {
            if (scanf("%d", p) != 1) *length = -1;
        }
}