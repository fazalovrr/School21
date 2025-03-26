#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 80
#define WIDTH 25

void game(int **field);
int update_field(int **field);
int check_cell(int **field, int i, int j);
int module(int coordinate, int size);
int **matrix_init(char *path);
int input_field(int **buffer);
int input_field_file(int **buffer, char *path);
void free_m(int **a);
void init_screen(int **field);
void print_field(int **field, int alive, int speed);

int main(int argc, char **argv) {
    int **field;
    if (argc > 2) {
        printf("Too many arguments.\n");
    } else if (argc == 2) {
        field = matrix_init(argv[1]);
        if (field) {
            init_screen(field);
            game(field);
            free_m(field);
        }
    } else {
        printf("Enter matrix 25*80\n");
        field = matrix_init(NULL);
        if (field) {
            game(field);
            free_m(field);
        }
    }
    endwin();
}
void game(int **field) {
    int input = 0;
    int speed = 5;
    while (input != 113) {
        int alive = update_field(field);
        print_field(field, alive, speed);
        input = getch();
        napms(500 / speed);
        if (input == 43)
            if (speed < 10) speed++;
        if (input == 45)
            if (speed > 1) speed--;
    }
}

void print_field(int **field, int alive, int speed) {
    for (int i = 1; i <= WIDTH; i++) {
        for (int j = 1; j <= LENGTH; j++) {
            if (field[i - 1][j - 1] == 1)
                mvaddch(i, j, ACS_DIAMOND);
            else
                mvaddch(i, j, ' ');
        }
    }
    move(0, 37);
    printw("Alive %d", alive);
    move(27, 40);
    printw("Speed %d, press +/- for change", speed);
    refresh();
}

int update_field(int **field) {
    int flag = 0;
    int **new_field = calloc(WIDTH, sizeof(int *));

    for (int i = 0; i < WIDTH; i++) new_field[i] = calloc(LENGTH, sizeof(int));

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            new_field[i][j] = check_cell(field, i, j);
            if (new_field[i][j] == 1) flag++;
        }
    }
    for (int i = 0; i < WIDTH; i++) {
        free(field[i]);
        field[i] = new_field[i];
    }
    free(new_field);
    return flag;
}

int check_cell(int **field, int i, int j) {
    int neighbour, ans;
    neighbour = 0;
    if (field[module(i - 1, WIDTH)][j] == 1) {
        neighbour += 1;
    }
    if (field[module(i + 1, WIDTH)][j] == 1) {
        neighbour += 1;
    }
    if (field[module(i + 1, WIDTH)][module(j + 1, LENGTH)] == 1) {
        neighbour += 1;
    }
    if (field[module(i - 1, WIDTH)][module(j - 1, LENGTH)] == 1) {
        neighbour += 1;
    }
    if (field[module(i - 1, WIDTH)][module(j + 1, LENGTH)] == 1) {
        neighbour += 1;
    }
    if (field[module(i + 1, WIDTH)][module(j - 1, LENGTH)] == 1) {
        neighbour += 1;
    }
    if (field[i][module(j + 1, LENGTH)] == 1) {
        neighbour += 1;
    }
    if (field[i][module(j - 1, LENGTH)] == 1) {
        neighbour += 1;
    }
    if ((field[i][j] == 1 && neighbour == 2) || neighbour == 3)
        ans = 1;
    else
        ans = 0;
    return ans;
}

int module(int coordinate, int size) {
    if (coordinate >= 0) {
        coordinate = coordinate % size;
    } else {
        coordinate = size + (coordinate % size);
    }
    return coordinate;
}

int **matrix_init(char *path) {
    int **pointers_matrix = NULL;

    pointers_matrix = malloc(WIDTH * sizeof(int *));

    for (int i = 0; i < WIDTH; i++) pointers_matrix[i] = malloc(LENGTH * sizeof(int));

    if (path != NULL ? input_field_file(pointers_matrix, path) : input_field(pointers_matrix) == 1) {
        free_m(pointers_matrix);
        pointers_matrix = NULL;
    }
    return pointers_matrix;
}

int input_field(int **buffer) {
    int flag, trash;

    flag = 0;

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            int temp;

            if (flag == 1) break;

            if (scanf("%d", &temp) == 0 || (temp != 1 && temp != 0)) {
                printf("Wrong format.\n");
                flag = 1;
                break;
            } else {
                buffer[i][j] = temp;
            }
        }
    }
    trash = getchar();
    while (trash == ' ' || trash == '\t') trash = getchar();
    if (trash != '\n') flag = 1;
    return flag;
}

int input_field_file(int **buffer, char *path) {
    int flag;
    FILE *file;
    flag = 0;
    file = fopen(path, "r");
    if (!file) {
        flag = 1;
        printf("Wrong path to file.\n");
    } else {
        for (int i = 0; i < WIDTH; i++) {
            if (flag == 1) break;
            for (int j = 0; j < LENGTH; j++) {
                int temp;
                if (fscanf(file, "%d", &temp) == 0 || (temp != 1 && temp != 0)) {
                    printf("Wrong format.\n");
                    flag = 1;
                    break;
                } else {
                    buffer[i][j] = temp;
                }
            }
        }
        int trash = fgetc(file);
        while (trash == ' ' || trash == '\t') trash = fgetc(file);
        if (trash != '\n' && trash != EOF) flag = 1;
        fclose(file);
    }
    return flag;
}

void free_m(int **a) {
    for (int i = 0; i < WIDTH; i++) free(a[i]);

    free(a);
}

void init_screen(int **field) {
    initscr();
    for (int i = 1; i < LENGTH + 1; i++) {
        mvaddch(0, i, ACS_HLINE);
        mvaddch(WIDTH + 1, i, ACS_HLINE);
    }
    for (int i = 1; i < WIDTH + 1; i++) {
        mvaddch(i, 0, ACS_VLINE);
        mvaddch(i, LENGTH + 1, ACS_VLINE);
    }
    mvaddch(0, 0, ACS_ULCORNER);
    mvaddch(0, LENGTH + 1, ACS_URCORNER);
    mvaddch(WIDTH + 1, 0, ACS_LLCORNER);
    mvaddch(WIDTH + 1, LENGTH + 1, ACS_LRCORNER);
    move(27, 10);
    printw("Press 'q' for exit");
    print_field(field, 0, 5);
    move(22, 24);
    printw("Press any key for start the game");
    curs_set(0);
    cbreak();
    noecho();
    refresh();
    getchar();
    nodelay(stdscr, TRUE);
}
