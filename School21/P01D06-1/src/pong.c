#include <stdio.h>

#define WIDTH 80
#define HEIGHT 25
#define WINSCORE 21

void show(int up1, int up2, int score1, int score2, int ball_x, int ball_y);

int main(void) {
    int score1 = 0, score2 = 0, up1 = HEIGHT / 2 - 1, up2 = HEIGHT / 2 - 1, running = 1;
    int ball_x = WIDTH / 2 - 2, ball_y = HEIGHT / 2 - 1, ball_move_up = 1, ball_move_side = 1;
    show(up1, up2, score1, score2, ball_x, ball_y);
    while (running) {
        char move = getchar();
        if (move == 'a') {
            if (up1 > 0) up1--;  // Движение вверх левой ракетки
        } else if (move == 'z') {
            if (up1 < HEIGHT - 3) up1++;  // Движение вниз левой ракетки
        } else if (move == 'k') {
            if (up2 > 0) up2--;  // Движение вверх правой ракетки
        } else if (move == 'm') {
            if (up2 < HEIGHT - 3) up2++;  // Движение вниз правой ракетки
        } else if (move == 'q')
            running = 0;
        if (ball_x == 2 && (ball_y >= up1 && ball_y <= up1 + 2))
            ball_move_side = 1;  // Касание мяча ракетки 1/2
        if (ball_x == WIDTH - 5 && (ball_y >= up2 && ball_y <= up2 + 2)) ball_move_side = -1;
        if (ball_y == 0) ball_move_up = -1;  // Касание мяча верхней/ниженей границы
        if (ball_y == HEIGHT - 1) ball_move_up = 1;
        if (ball_x == 0) {  // Касание мяча правой/левой границы
            ball_move_side = -1;
            score2++;
            ball_x = WIDTH / 2, ball_y = HEIGHT / 2;
        }
        if (ball_x == WIDTH - 3) {
            ball_move_side = 1;
            score1++;
            ball_x = WIDTH / 2 - 2, ball_y = HEIGHT / 2 + 1;
        }
        ball_move_up > 0 ? ball_y-- : ball_y++;
        ball_move_side > 0 ? ball_x++ : ball_x--;
        show(up1, up2, score1, score2, ball_x, ball_y);
        if (score1 == WINSCORE || score2 == WINSCORE) {  // Есть победитель?
            running = 0;
            printf("\033[H\033[J");  // Очистка экрана
            if (score1 == WINSCORE)
                printf("///////// PLAYER 1 WON! /////////");
            else
                printf("///////// PLAYER 2 WON! /////////");
        }
    }
    return 0;
}

void show(int up1, int up2, int score1, int score2, int ball_x, int ball_y) {
    printf("\033[H\033[J");  // Очистка экрана
    printf("\n╔");
    for (int j = 0; j < WIDTH - 8; j++) {  // Верхняя граница
        if (j == 18)
            printf(" %02d ", score1);
        else if (j == 53)
            printf(" %02d ", score2);
        else
            printf("═");
    }
    printf("╗\n");
    for (int i = 0; i < HEIGHT; i++) {  // Поле с ракетками
        printf("║");
        for (int j = 0; j < WIDTH - 2; j++) {
            if ((i >= up1 && i < up1 + 3) && j == 1) {
                printf("▒");
                continue;
            }
            if ((i >= up2 && i < up2 + 3) && j == WIDTH - 4) {
                printf("▒");
                continue;
            }
            if (j == ball_x && i == ball_y) {
                printf("☻");
                continue;
            }
            if (j == WIDTH / 2 - 1 || j == WIDTH / 2 - 2) {
                printf("│");
                continue;
            }
            printf(" ");
        }
        printf("║\n");
    }
    printf("╚");
    for (int j = 0; j < WIDTH - 2; j++) printf("═");  // Нижняя граница
    printf("╝\n");
}