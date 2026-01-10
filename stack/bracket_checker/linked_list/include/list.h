#ifndef LIST_H
#define LIST_H

typedef struct node{
    char c;
    struct node *next;
}node;

node *create_node(char c);
void free_node(node **top);

#endif
