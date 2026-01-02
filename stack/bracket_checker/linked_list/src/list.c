#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node *create_node(char c){
    node *new_node = malloc(sizeof(node));
    if(!new_node){
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    new_node->c = c;
    new_node->next = NULL;
    return new_node;
}

void free_node(node **top){
    node *tmp = *top;
    *top = (*top)->next;
    free(tmp);
}
