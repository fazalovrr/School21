#include <stdio.h>
#include <string.h>
#include <math.h>

#define WIDTH 80         
#define HEIGHT 25 
#define MAX_STR_LEN 256

typedef enum {
    TOK_NUMBER,       // Числовая константа
    TOK_VARIABLE,     // Переменная x
    TOK_OPERATOR,     // Оператор: +, -, *, /, ^
    TOK_FUNCTION,     // Функция: sin, cos, tan, ctg, sqrt, ln
    TOK_LEFT_PAREN,   // Левая скобка
    TOK_RIGHT_PAREN   // Правая скобка
} TokenType;

/*

Возможные операции & функции
"+"
"-" (унарный и бинарный)
"*"
"/"
"()"
sin(x)
cos(x)
tan(x)
ctg(x)
sqrt(x)
ln(x)

*/




int main(){

    char str[100], outstr[100];
    fgetc(str);

    
    


    return 0;
}
