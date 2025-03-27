#include <stdio.h>

#include "state.h"

int check_date(int day, int month, int year);
int comp_date(int day1, int month1, int year1, int day2, int month2, int year2);

int main() {
    int day1 = 0, month1 = 0, year1 = 0;
    int day2 = 0, month2 = 0, year2 = 0;
    char path[1024] = "\0";
    char temp[9] = "temp.bin";
    FILE *file = NULL, *tempfile = NULL;
    if (scanf("%1023s", path) == 1 && (file = fopen(path, "rb")) != NULL &&
        (tempfile = fopen(temp, "wb")) != NULL) {
        if (scanf("%d.%d.%d %d.%d.%d", &day1, &month1, &year1, &day2, &month2, &year2) == 6 &&
            check_date(day1, month1, year1) && check_date(day2, month2, year2)) {
            int f = 0;
            struct door_state_struct door_state;

            while (fread(&door_state, sizeof(door_state), 1, file)) {
                if (comp_date(day1, month1, year1, door_state.day, door_state.month, door_state.year) <= 0 &&
                    comp_date(day2, month2, year2, door_state.day, door_state.month, door_state.year) >= 0) {
                    fwrite(&door_state, sizeof(door_state), 1, tempfile);
                    f = 1;
                }
            }
            if (f == 0) printf("n/a");
        }
        fclose(file);
        fclose(tempfile);
        remove(path);
        rename(temp, path);
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

int comp_date(int day1, int month1, int year1, int day2, int month2, int year2) {
    int res = 0;
    if (year1 > year2)
        res = 1;
    else if (year1 < year2)
        res = -1;
    if (res == 0 && month1 > month2)
        res = 1;
    else if (res == 0 && month1 < month2)
        res = -1;
    if (res == 0 && day1 > day2)
        res = 1;
    else if (res == 0 && day1 < day2)
        res = -1;

    return res;
}