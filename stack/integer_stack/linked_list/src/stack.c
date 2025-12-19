#include "stack.h"
#include "list.h"
#include <stdio.h>

void peek(node *head){
    if(is_empty){
        fprintf(stderr, "The stack is empty.\n");
        return;
    }else{
        fprintf(stdout, "Top: %d\n", head->data);
    }
}

int is_empty(node *head){
    if(head == NULL){
        return 1;
    }else{
        return 0;
    }
}

int push(int value, node **head){
    node *new = create_new_node(value);
    if(new == NULL){
        return -1;
    }

    new->next = *head;
    *head = new;
    return 0;
}
