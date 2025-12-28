#include "stack.h"
#include <stdio.h>

void push(char *stack, int *top, char c){
    if(*top >= SIZE){
        fprintf(stderr, "Stack Overflow\n");
        return;
    }
    stack[++*top] = c;
}

void pop(char *stack, int *top, char c){
    if(c == ')'){
        if(stack[*top] != '('){
            return;
        }
    }

    if(c == ']'){
        if(stack[*top] != '['){
            return;
        }
    }

    if(c == '}'){
        if(stack[*top] != '{'){
            return;
        }
    }

    (*top)--;
}
