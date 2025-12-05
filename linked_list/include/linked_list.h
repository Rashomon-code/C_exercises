#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node{
    int value;
    struct node *previous;
    struct node *next;
}Node;

Node* create_node(int value);
int head_insert(Node **head, Node **tail, int value);
int tail_insert(Node **head, Node **tail, int value);
void free_list(Node **head, Node **tail);

#endif
