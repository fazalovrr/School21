#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void sort_doors(struct door* doors);
void close_doors(struct door* doors);
void output_doors(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort_doors(doors);
    close_doors(doors);
    output_doors(doors);

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort_doors(struct door* doors) {
    int f = 1;
    while (f) {
        f = 0;
        for (int i = 0; i < DOORS_COUNT; i++)
            if (doors[i].id > doors[i + 1].id) {
                struct door temp = doors[i];
                doors[i] = doors[i + 1];
                doors[i + 1] = temp;
                f = 1;
            }
    }
}

void close_doors(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++)
        if (doors[i].status > 0) doors[i].status = 0;
}

void output_doors(struct door* doors) {
    printf("\n");
    for (int i = 0; i < DOORS_COUNT; i++) printf("%d, %d\n", doors[i].id, doors[i].status);
    printf("%d, %d", doors[DOORS_COUNT - 1].id, doors[DOORS_COUNT - 1].status);
}