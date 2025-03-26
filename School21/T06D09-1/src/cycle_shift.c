#include <stdio.h>
#define NMAX 10

int inpunt (int a[], int *len);
void output(const int arr[], const int *len);
void shift(int arr[], const int *len, const int *shift);

int main(){
    int arr[NMAX];// = {4, 3, 9, 0, 1, 2, 0, 2, 7, -1};
    int len;// = 10;
    int sh = inpunt(arr,&len); 
    if (sh > 0){
        shift(arr,&len,&sh);
        output(arr, &len);
    }
    else 
        printf("n/a");
    return 0;
}

int inpunt (int arr[], int *len){
int res=0;
    if (scanf("%d", len) != 1 || *len < 1 || *len > NMAX)
        res = -1;
    else {        
        for(int i = 0; i < *len; i++)
            if (scanf("%d", &arr[i]) != 1) res = -1;
        if (res < 0 || scanf("%d", &res) != 1) res = -1;  
    }
    return res;
}

void output(const int arr[], const int *len){
    for (int i = 0; i < *len; i++)
        if (i < *len - 1) printf("%d ", arr[i]); else printf("%d", arr[i]);
}

void shift(int arr[], const int *len, const int *sh){
    int temp;
    for (int j=0; j<*sh; j++){
        if (*sh > 0) {
            temp = arr[0];
            for(int i=0; i < *len - 1; i++){            
                arr[i] = arr[i+1];        
            }
            arr[*len-1] = temp;
        }
            if (*sh < 0) {
                temp = arr[*len-1];
                for(int i = *len - 1; i > 0; i--){                
                    arr[i] = arr[i-1];        
            }
            arr[0] = temp;
    }
    }
}