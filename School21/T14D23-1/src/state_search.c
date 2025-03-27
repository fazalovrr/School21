#include <stdio.h>

#include "state.h"

int check_date(int day, int month, int year);

int main() {
    int day = 0, month = 0, year = 0;
    char path[1024] = "\0";
    FILE *file = NULL;
    if (scanf("%1000s", path) == 1 && (file = fopen(path, "rb")) != NULL) {
        if (scanf("%d.%d.%d", &day, &month, &year) == 3 && check_date(day, month, year)) {
            int f = 1;
            struct door_state_struct door_state;
            while (f && fread(&door_state, sizeof(door_state), 1, file)) {
                if (door_state.year == year)
                    if (door_state.month == month)
                        if (door_state.day == day) {
                            printf("%d", door_state.code);
                            f = 0;
                        }
            }
            if (f) printf("n/a");
        } else
            printf("n/a");
        fclose(file);
    } else
        printf("n/a");

    return 0;
}

int check_date(int day, int month, int year) {
    int res = 1;
    int max_day;
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            max_day = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            max_day = 30;
            break;
        case 2:
            max_day = (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0) ? 29 : 28;
            break;
        default:
            return 0;
    }
    if (year < 1900 || year > 3000) res = 0;
    if (month < 1 || month > 12) res = 0;
    if (day < 1 || day > max_day) res = 0;

    return res;
}