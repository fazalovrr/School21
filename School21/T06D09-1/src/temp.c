#include <stdio.h>

int main(){
int a;
int f=1;
    do{        
        f=0;
        if (scanf("%d", &a)==1) f=1;
        if (getchar()==10) f=0;
        if (getchar()==32) f=0;
       // printf(" %d ", (int)ch);

    }while(f==1);
       
       printf("%d", a);
   // printf("%d", getchar());

return 0;
}