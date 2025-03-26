#include <stdio.h>
#include <stdlib.h>

int main(){
    int n=0 ,f = 1, i =0;
    char ch=10;
    int *arr = malloc(2*sizeof(int));
    if (arr != NULL){ 
        if(scanf("%d%c", &n, &ch) == 2  && n > 0 && (ch == 10 || ch == 32)){
            while (i < n && f){
                if(scanf("%d%c", &arr[i], &ch) == 2 && (ch == 10 || ch == 32)){
                    //printf("%d is ok. Last simb '%d'", n, ch);
                    i++;
                    arr = realloc(arr,(i+1) * sizeof(int));
                } else { 
                    if (n != -1) printf("n/a"); else printf("End input.");
                    f = 0;
                }
            }
            if (f) {
                for (i=0; i<n-1;i++) printf("%d ", arr[i]);
                printf("%d", arr[n-1]);
            }
        } else printf("n/a");
        
        
        free(arr);
    } else printf("Memory error.");
    return 0;
}