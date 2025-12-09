#ifndef IO_H
#define IO_H

#include "linked_list.h"

#define BUFFER_SIZE 32

int get_value(int *value);
int get_yes_or_no(void);
int get_choice(int min, int max);
void print_list(Node *head);

#endif
