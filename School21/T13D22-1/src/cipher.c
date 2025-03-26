#include <dirent.h>
#include <stdio.h>
#include <string.h>

#include "logger.h"

void craete_txt_files();
char cesar_cod(char ch, int key);

int main() {
    char path[256] = "\0";
    char message[1024] = "\0";
    int n_menu = 0;
    FILE *file = NULL;
    while (n_menu != -1) {
        // fflush(stdin);
        int ch = 0;

        if (scanf("%d", &n_menu) == 1) switch (n_menu) {
                case -1:
                    break;

                case 1:
                    if (scanf("%255s", path) == 1 && (file = fopen(path, "r")) != NULL) {
                        int size = 0;

                        snprintf(message, sizeof(message), "The file '%s' opened successfully", path);
                        logcat(log_init("logger.log"), message, info);

                        while ((ch = fgetc(file)) != EOF) {
                            putchar(ch);
                            size++;
                        }

                        fclose(file);
                        snprintf(message, sizeof(message), "The file '%s'readding successfully", path);
                        logcat(log_init("logger.log"), message, trace);

                        snprintf(message, sizeof(message), "The file '%s'closed successfully", path);
                        logcat(log_init("logger.log"), message, info);

                        if (size)
                            printf("\n");
                        else {
                            printf("n/a\n");
                            snprintf(message, sizeof(message), "The file '%s' is empty", path);
                            logcat(log_init("logger.log"), message, warning);
                        }
                    } else {
                        printf("n/a\n");
                        snprintf(message, sizeof(message), "'%s' invalid file name", path);
                        path[0] = '\0';
                        logcat(log_init("logger.log"), message, error);
                    }
                    break;

                case 2:
                    if ((file = fopen(path, "a")) != NULL) {
                        snprintf(message, sizeof(message), "The file '%s' was opened successfully", path);
                        logcat(log_init("logger.log"), message, info);

                        while ((ch = fgetc(stdin)) != '\n') fprintf(file, "%c", ch);
                        fprintf(file, "%c", '\n');

                        snprintf(message, sizeof(message), "A new string has been added to the file '%s'",
                                 path);
                        logcat(log_init("logger.log"), message, debug);

                        fclose(file);
                        file = fopen(path, "r");
                        while ((ch = fgetc(file)) != EOF) putchar(ch);

                        snprintf(message, sizeof(message), "File '%s'closed successfully", path);
                        logcat(log_init("logger.log"), message, info);

                        fclose(file);
                    } else {
                        printf("n/a\n");

                        snprintf(message, sizeof(message), "'%s' is wrong file name", path);
                        logcat(log_init("logger.log"), message, error);
                    }
                    break;

                case 3:
                    int n=0;
                    if (scanf("%d", &n) == 1 && scanf("%255s", path) == 1) {
                        DIR *dp = opendir(path);
                        if (dp != NULL) {
                            struct dirent *ep;
                            char file_path[256];
                            while ((ep = readdir(dp))) {
                                strcpy(file_path, path);
                                strcat(file_path, "/");
                                strcat(file_path, ep->d_name);
                                if (strstr(ep->d_name, ".c") != NULL) {
                                    file = fopen(file_path, "r+");
                                    while ((ch = fgetc(file)) != EOF) {
                                        fseek(file, -1, SEEK_CUR);
                                        fputc(cesar_cod(ch, n), file);
                                    }
                                    fclose(file);
                                }
                                if (strstr(ep->d_name, ".h") != NULL) {
                                    file = fopen(file_path, "w");
                                    fclose(file);
                                }
                            }
                            closedir(dp);
                        } else
                            printf("n/a\n");
                    } else
                        printf("n/a\n");
                    break;

                default:
                    printf("n/a\n");
                    break;
            }
        else {
            printf("n/a\n");
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
    }
    return 0;
}

char cesar_cod(char ch, int key) {
    if (ch >= 'A' && ch <= 'Z') ch = 'A' + (ch - 'A' + key) % 26;
    if (ch >= 'a' && ch <= 'z') ch = 'a' + (ch - 'a' + key) % 26;
    return ch;
}

// void craete_txt_files(){
//     FILE *file = fopen("abc.txt", "w");
//     if (file != NULL) {
//         fprintf(file, "Hihi_haha\n");
//         fclose(file);
//     }

//     file = fopen("love.txt", "w");
//     if (file != NULL) {
//         fprintf(file, "i_love_sh21");
//         fclose(file);
//     }

//     file = fopen("text.txt", "w");
//     if (file != NULL) {
//         fprintf(file, "Aloha!");
//         fclose(file);
//     }
// }