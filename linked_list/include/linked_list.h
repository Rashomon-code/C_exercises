#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node{
    int value;
    struct list *previous;
    struct list *next;
}node;

node* create_node(int value);

#endif
