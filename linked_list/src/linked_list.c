#include "linked_list.h"
#include "menu.h"
#include <stdlib.h>
#include <stdio.h>
#include "io.h"

int init_list(Node **head, Node **tail){
    FILE *fp = fopen("data/generated/list.dat", "rb");
    if(!fp){
        init_menu();
        int choice = get_yes_or_no();
        if(choice != 1){
            return choice;
        }

        *head = NULL;
        *tail = NULL;
        return 0;
    }
}

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

int head_insert(Node **head, Node **tail){
    int value, check = 0;
    check = get_value(&value);
    if(check == -1){
        return -1;
    }

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

int tail_insert(Node **head, Node **tail){
    int value, check = 0;
    check = get_value(&value);
    if(check == -1){
        return -1;
    }

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
