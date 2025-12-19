#ifndef LIST_H
#define LIST_H

typedef struct node{
    int data;
    struct node *next;
}node;

node *create_new_node(int data);

#endif
