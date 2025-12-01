#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct list{
    int value;
    struct list *previous;
    struct list *next;
}list;

int create_node(void);

#endif
