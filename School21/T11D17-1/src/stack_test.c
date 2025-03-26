#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

int test_push();
int test_pop();

int main() {
    printf("Тест на добавление элемента. Результат: ");
    if (test_push() == 0) {
        printf("FAIL\n");
    } else {
        printf("SUCCESS\n");
    }
    printf("Тест на извлечение элемента. Результат: ");
    if (test_pop() == 0) {
        printf("FAIL\n");
    } else {
        printf("SUCCESS\n");
    }
    return 0;
}

int test_push() {
    int result = 1;

    struct stack* s = init();
    if (s == NULL) return 0;

    push(s, 10);
    if (s->top == NULL || s->top->data != 10) {
        destroy(s);
        return 0;
    }

    push(s, 20);
    if (s->top == NULL || s->top->data != 20) {
        destroy(s);
        return 0;
    }

    destroy(s);
    return result;
}

int test_pop() {
    int result = 1;

    struct stack* s = init();
    if (s == NULL) return 0;

    push(s, 10);
    push(s, 20);

    int value = pop(s);
    if (value != 20) {
        destroy(s);
        return 0;
    }

    value = pop(s);
    if (value != 10) {
        destroy(s);
        return 0;
    }

    value = pop(s);
    if (value != 0) {
        destroy(s);
        return 0;
    }

    destroy(s);
    return result;
}