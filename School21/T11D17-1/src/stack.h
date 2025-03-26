#ifndef SRC_STACK_H_
#define SRC_STACK_H_

struct stack {
    struct stack_node* top;
};

struct stack_node {
    int data;
    struct stack_node* next;
};

struct stack* init();
void push(struct stack* s, int value);
int pop(struct stack* s);
void destroy(struct stack* s);

#endif