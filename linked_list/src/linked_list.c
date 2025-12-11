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

int head_insert(Node **head, Node **tail, int value, int *list_size){
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

    (*list_size)++;
    return 0;
}

int tail_insert(Node **head, Node **tail, int value, int *list_size){
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

    (*list_size)++;
    return 0;
}

int delete_node(Node **head, Node **tail, int *list_size){
    puts("Enter the number of node you want to delete.(Enter '0' to exit)");
    int delete_num = get_choice(0, *list_size);
    if(delete_num == 0 || delete_num == -1){
        return delete_num;
    }
    
    Node *tmp = *head;
    for(int i = 0; i < delete_num - 1; i++){
        tmp = tmp->next;
    }
    
    if((*tail)->next == *head){
        tmp->previous->next = tmp->next;
        tmp->next->previous = tmp->previous;
        if(delete_num == 1){
            *head = tmp->next;
        }
        if(delete_num == *list_size){
            *tail = tmp->previous;
        }
    }else{
        if(tmp->next != NULL){
            tmp->next->previous = tmp->previous;
        }else{
            *tail = tmp->previous;
        }
        if(tmp->previous != NULL){
            tmp->previous->next = tmp->next;
        }else{
            *head = tmp->next;
        }
    }

    free(tmp);
    (*list_size)--;
    puts("Deleted successful.");
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

void toggle_cycle(Node *head, Node *tail){
    if(head->previous == NULL){
        head->previous = tail;
        tail->next = head;
    }else{
        head->previous = NULL;
        tail->next = NULL;
    }
}
