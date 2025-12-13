#include "int_stack.h"
#include <stdio.h>

void initialization(Stack *a){
    a->top = -1;
}

int is_empty(Stack a){
    if(a.top == -1){
        return 1;
    }else{
        return 0;
    }
}

void peek(Stack a){
    if(is_empty(a)){
        puts("The stack is empty.");
    }else{
        printf("Top: %d\n", a.value[a.top]);
    }
}

int is_full(Stack a){
    if(a.top == STACK_SIZE - 1){
        return 1;
    }else{
        return 0;
    }
}

int push(Stack *a, int value){
    if(is_full(*a)){
        puts("The stack is full.");
        return 1;
    }else{
        a->value[++a->top] = value;
        return 0;
    }
}

int pop(Stack *a){
    if(is_empty(*a)){
        puts("The stack is empty.");
        return 1;
    }else{
        printf("Popped value: %d\n", a->value[a->top--]);
        return 0;
    }
}
