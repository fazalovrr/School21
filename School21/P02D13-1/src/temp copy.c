
#include <stdio.h>
#include <stdlib.h>

void add_spaces(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");

    if (input_file == NULL || output_file == NULL) {
        perror("Ошибка открытия файла");
        exit(EXIT_FAILURE);
    }

    int ch;
    int next_ch;

    while ((ch = fgetc(input_file)) != EOF) {
        fputc(ch, output_file);

        next_ch = fgetc(input_file);
        if (next_ch != EOF) {
            fputc(' ', output_file);
            ungetc(next_ch, input_file);  // Возвращаем символ обратно в поток
        }
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    const char *input_filename = "../datasets/1.txt";
    const char *output_filename = "../datasets/11.txt";

    add_spaces(input_filename, output_filename);

    printf("Пробелы успешно добавлены в файл %s\n", output_filename);

    return 0;
}