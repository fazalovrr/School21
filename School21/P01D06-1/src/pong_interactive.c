#include <fcntl.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 23

void show(int up1, int up2, int ball_x, int ball_y);
void header(int score1, int score2);
void rocketMove(int up1, int up2, int ball_x, int ball_y);
int ballmoveX(int ball_x, int side);
int ballmoveY(int ball_y, int down);
char getch(void);
int winchek(int score1, int score2);

int main(void) {
    int score1 = 0;
    int score2 = 0;
    int up1 = 11;
    int up2 = 11;
    int ball_x = WIDTH / 2;
    int ball_y = HEIGHT / 2;
    int down = 1;
    int side = 1;
    int f = 1;

    struct termios oldt, newt;
    // Получаем текущие настройки терминала
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    // Отключаем эхо и канонический режим
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);

    while (f) {
        header(score1, score2);
        show(up1, up2, ball_x, ball_y);

        usleep(90000);

        if (ball_x == 3) {
            if (ball_y >= up1 && ball_y <= up1 + 2) {
                side = 1;  // Отскок от левой ракетки
            } else {
                score2++;  // Очко правому игроку
                ball_x = WIDTH / 2;
                ball_y = HEIGHT / 2;
                side = 1;
                down = 1;  // Перезапуск мяча
            }
        }

        if (ball_x == WIDTH - 4) {
            if (ball_y >= up2 && ball_y <= up2 + 2) {
                side = -1;  // Отскок от правой ракетки
            } else {
                score1++;  // Очко левому игроку
                ball_x = WIDTH / 2;
                ball_y = HEIGHT / 2;
                side = -1;
                down = -1;  // Перезапуск мяча
            }
        }

        if (ball_y == 0) {
            down = -1;
        }
        if (ball_y == HEIGHT - 1) {
            down = 1;
        }

        ball_y = ballmoveY(ball_y, down);
        ball_x = ballmoveX(ball_x, side);

        char move = getch();  // move = getchar(); in basic version
        switch (move) {
            case 'a':
                if (up1 > 0) up1--;  // Движение вверх левой ракетки
                break;
            case 'z':
                if (up1 < HEIGHT - 3) up1++;  // Движение вниз левой ракетки
                break;
            case 'k':
                if (up2 > 0) up2--;  // Движение вверх правой ракетки
                break;
            case 'm':
                if (up2 < HEIGHT - 3) up2++;  // Движение вниз правой ракетки
                break;
            case 'q':
                f = 0;
                break;
        }

        if (winchek(score1, score2)) {
            printf("\033[H\033[J");
            if (score1 == 21) {
                printf("///////// PLAYER 1 WON! /////////");
            } else {
                printf("///////// PLAYER 2 WON! /////////");
            }
            f = 0;
        }
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return 0;
}

void header(int score1, int score2) {
    printf("\033[H\033[J");  // Очистка экрана
    printf("\n");
    printf("╔");
    for (int j = 0; j < WIDTH - 8; j++) {  // Верхняя граница
        if (j == 18)
            printf(" %02d ", score1);
        else if (j == 53)
            printf(" %02d ", score2);
        else
            printf("═");
    }
    printf("╗\n");
}

void show(int up1, int up2, int ball_x, int ball_y) {
    for (int i = 0; i < HEIGHT; i++) {  // Поле с ракетками
        printf("║");
        for (int j = 0; j < WIDTH - 2; j++) {
            if ((i >= up1 && i < up1 + 3) && j == 1) {
                printf("┃");
                continue;
            }
            if ((i >= up2 && i < up2 + 3) && j == WIDTH - 4) {
                printf("┃");
                continue;
            }
            if (j == ball_x && i == ball_y) {
                printf("֍");
                continue;
            }
            if (j == WIDTH / 2 - 1 || j == WIDTH / 2 - 2) {
                printf("┊");
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

char getch(void) {
    char ch = getchar();  // Читаем символ
    return ch;
}

int winchek(int score1, int score2) {
    int leave = 0;
    if (score1 == 21 || score2 == 21) {
        leave = 1;
    }
    return leave;
}

int ballmoveX(int ball_x, int side) {
    if (side > 0) {
        ball_x++;
    } else {
        ball_x--;
    }
    return ball_x;
}

int ballmoveY(int ball_y, int down) {
    if (down > 0) {
        ball_y--;
    } else {
        ball_y++;
    }
    return ball_y;
}
