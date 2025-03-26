#include <stdio.h>
#include <unistd.h>

int main() {
    int i = 666;
    FILE *file = fopen("qwe", "rb+");
    // fseek(file, 0, 0);
    fwrite(&i, sizeof(int), 1, file);
    // write(file, i, 4);
    // f_rite()

    // fclose(file);
    // fopen("qwe", "rb");
    fseek(file, 0, 0);
    while (fread(&i, sizeof(int), 1, file)) {
        printf("%d\n", i);
    }

    fclose(file);
}