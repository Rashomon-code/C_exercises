#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node{
    int value;
    struct node *previous;
    struct node *next;
}Node;

int init_list(Node **head, Node **tail);
Node* create_node(int value);
int head_insert(Node **head, Node **tail);
int tail_insert(Node **head, Node **tail);

#endif
