#include <stdio.h>

int main(){
    char path[256]="\0";
    char full_path[512] = "\0";
    int n_menu, ch;
    FILE *file =NULL;
    if (scanf("%d %255s", &n_menu, path) == 2 && n_menu == 1 ) {
        snprintf(full_path, sizeof(full_path), "%3s%250s",  "../", path);
        if((file = fopen(path, "r")) != NULL){
        while ((ch = fgetc(file)) != EOF)
            putchar(ch);
        fclose(file); 
        } else printf("n/a");
    } else printf("n/a");

    
    return 0;   
}

