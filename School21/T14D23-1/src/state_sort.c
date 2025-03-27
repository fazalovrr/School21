#include <stdio.h>

#include "state.h"

int comp(struct door_state_struct door_state1, struct door_state_struct door_state2);
int sort(FILE *file);
int swap(FILE *file, int index, struct door_state_struct door_state1, struct door_state_struct door_state2);
int output(FILE *file);
int append(FILE *file, struct door_state_struct door_state);
int check(struct door_state_struct door_state);

int main() {
    int n_menu = -1;
    FILE *file = NULL;
    char path[256] = "\0";
    if (scanf("%255s", path) == 1 && (file = fopen(path, "rb+")) != NULL) {
        if (scanf("%d", &n_menu) == 1) {
            switch (n_menu) {
                case 0:
                    if (output(file) == 0) printf("n/a");
                    break;

                case 1:
                    if (sort(file) == 0) {
                        if (output(file) == 0) printf("n/a");
                    } else
                        printf("n/a");
                    ;
                    break;

                case 2:
                    struct door_state_struct door_state1;
                    if (scanf("%d %d %d %d %d %d %d %d", &door_state1.year, &door_state1.month,
                              &door_state1.day, &door_state1.hour, &door_state1.min, &door_state1.sec,
                              &door_state1.state, &door_state1.code) == 8 &&
                        check(door_state1) && append(file, door_state1)) {
                        if (sort(file) == 0) {
                            if (output(file) == 0) printf("n/a");
                        } else
                            printf("n/a");
                    } else
                        printf("n/a");
                    break;

                default:
                    printf("n/a");
                    break;
            }
        } else
            printf("n/a");
        fclose(file);
    } else
        printf("n/a");

    return 0;
}

int comp(struct door_state_struct door_state1, struct door_state_struct door_state2) {
    int res = 0;
    if (door_state1.year > door_state2.year)
        res = 1;
    else if (door_state1.year < door_state2.year)
        res = -1;
    if (res == 0 && door_state1.month > door_state2.month)
        res = 1;
    else if (res == 0 && door_state1.month < door_state2.month)
        res = -1;
    if (res == 0 && door_state1.day > door_state2.day)
        res = 1;
    else if (res == 0 && door_state1.day < door_state2.day)
        res = -1;
    if (res == 0 && door_state1.hour > door_state2.hour)
        res = 1;
    else if (res == 0 && door_state1.hour < door_state2.hour)
        res = -1;
    if (res == 0 && door_state1.min > door_state2.min)
        res = 1;
    else if (res == 0 && door_state1.min < door_state2.min)
        res = -1;
    if (res == 0 && door_state1.sec > door_state2.sec)
        res = 1;
    else if (res == 0 && door_state1.sec < door_state2.sec)
        res = -1;

    return res;
}

int swap(FILE *file, int index, struct door_state_struct door_state1, struct door_state_struct door_state2) {
    int res = 0;
    if (fseek(file, (index) * sizeof(door_state1), SEEK_SET) == 0)
        res = 1;
    else
        res = 0;
    if (res == 1 && fwrite(&door_state2, sizeof(door_state2), 1, file) == 1)
        res = 1;
    else
        res = 0;
    if (res == 1 && fseek(file, (index + 1) * sizeof(door_state1), SEEK_SET) == 0)
        res = 1;
    else
        res = 0;
    if (res == 1 && fwrite(&door_state1, sizeof(door_state1), 1, file) == 1)
        res = 1;
    else
        res = 0;

    return res;
}

int sort(FILE *file) {
    int f = 1;
    if (file) {
        struct door_state_struct door_state1, door_state2;
        int count;
        while (f == 1) {
            f = 0;
            if (fseek(file, 0, 0) == 0) {
                count = 1;
                if (fread(&door_state1, sizeof(door_state1), 1, file))
                    while (f >= 0 && fread(&door_state2, sizeof(door_state2), 1, file)) {
                        if (comp(door_state1, door_state2) == 1) {
                            f = 1;
                            if (swap(file, count - 1, door_state1, door_state2) == 0) f = -1;
                        } else
                            door_state1 = door_state2;
                        count++;
                    }
            }
        }
    }

    return f;
}

int output(FILE *file) {
    int count = 0;
    struct door_state_struct door_state1;
    if (fseek(file, 0, SEEK_SET) == 0) {
        while (fread(&door_state1, sizeof(door_state1), 1, file) && count < 60000000) {
            printf("%d %d %d %d %d %d %d %d\n", door_state1.year, door_state1.month, door_state1.day,
                   door_state1.hour, door_state1.min, door_state1.sec, door_state1.state, door_state1.code);
            count++;
        }
    }
    return count;
}

int append(FILE *file, struct door_state_struct door_state) {
    int res = 0;
    if (file != NULL) {
        if (fseek(file, 0, SEEK_END) == 0)
            if (fwrite(&door_state, sizeof(door_state), 1, file)) res = 1;
    }
    return res;
}

int check(struct door_state_struct door_state) {
    int res = 1;
    if (door_state.year < 1900 || door_state.year > 3000) res = 0;
    if (door_state.month < 1 || door_state.month > 12) res = 0;
    int max_day;
    switch (door_state.month) {
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
            max_day = (door_state.year % 400 == 0) || (door_state.year % 100 != 0 && door_state.year % 4 == 0)
                          ? 29
                          : 28;
            break;
        default:
            return 0;
    }
    if (door_state.day < 1 || door_state.day > max_day) res = 0;
    if (door_state.hour < 0 || door_state.hour > 23) res = 0;
    if (door_state.min < 0 || door_state.min > 59) res = 0;
    if (door_state.sec < 0 || door_state.sec > 59) res = 0;
    if (door_state.state < 0 || door_state.state > 1) res = 0;
    if (door_state.code < 1) res = 0;
    return res;
}
