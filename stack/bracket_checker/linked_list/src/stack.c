#include "stack.h"
#include <stddef.h>
#include "list.h"

void push(node **top, char c){
    node *new = create_node(c);
    if(!new){
        return;
    }

    new->next = *top;
    *top = new;
}

void pop(node **top, char c){
    if((c == ')' && (*top)->c != '(') || (c == ']' && (*top)->c != '[') || (c == '}' && (*top)->c != '{')){
        return;
    }

    if(*top == NULL){
        return;
    }

    free_node(top);
}
