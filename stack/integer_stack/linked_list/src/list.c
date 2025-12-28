#include "list.h"
#include <stdlib.h>
#include <stdio.h>

node *create_new_node(int data){
    node *new = malloc(sizeof(node));
    if(!new){
        perror("Memory allocation failed.");
        return NULL;
    }

    new->data = data;
    return new;
}

void free_list(node **head){
    node *tmp;
    while(*head != NULL){
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
    }
}
