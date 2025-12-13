#ifndef INT_STACK_H
#define INT_STACK_H

#define STACK_SIZE 32

typedef struct{
    int value[STACK_SIZE];
    int top;
}Stack;

void initialization(Stack *a);
int is_empty(Stack a);
int is_full(Stack a);
void peek(Stack a);
int push(Stack *a, int value);
int pop(Stack *a);

#endif
