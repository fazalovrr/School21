#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct stack* init() {
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    if (s != NULL) {
        s->top = NULL;
    }
    return s;
}

void push(struct stack* s, int value) {
    if (s == NULL) return;

    struct stack_node* new_node = (struct stack_node*)malloc(sizeof(struct stack_node));
    if (new_node != NULL) {
        new_node->data = value;
        new_node->next = s->top;
        s->top = new_node;
    }
}

int pop(struct stack* s) {
    if (s == NULL || s->top == NULL) {
        return 0;
    }
    int value = s->top->data;
    struct stack_node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return value;
}

void destroy(struct stack* s) {
    if (s == NULL) return;

    struct stack_node* current = s->top;
    while (current != NULL) {
        struct stack_node* temp = current;
        current = current->next;
        free(temp);
    }
    free(s);
}