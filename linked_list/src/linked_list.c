#include "linked_list.h"
#include "menu.h"
#include <stdlib.h>
#include <stdio.h>
#include "io.h"

Node* create_node(int value){
    Node *new_node = malloc(sizeof(Node));
    if(!new_node){
        perror("Memory allocation failed.");
        return NULL;
    }

    new_node->value = value;
    new_node->previous = NULL;
    new_node->next = NULL;

    return new_node;
}

int head_insert(Node **head, Node **tail, int value){
    Node *new_node = create_node(value);
    if(!new_node){
        return -1;
    }

    if(*head == NULL){
        *head = new_node;
        *tail = new_node;
    }else{
        new_node->next = *head;
        (*head)->previous = new_node;
        *head = new_node;
    }

    return 0;
}

int tail_insert(Node **head, Node **tail, int value){
    Node *new_node = create_node(value);
    if(!new_node){
        return -1;
    }

    if(*head == NULL){
        *head = new_node;
        *tail = new_node;
    }else{
        new_node->previous = *tail;
        (*tail)->next = new_node;
        *tail = new_node;
    }

    return 0;
}

void free_list(Node **head, Node **tail){
    Node *current = *head;
    Node *next = NULL;

    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
    *tail = NULL;
}
