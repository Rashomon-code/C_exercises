#ifndef IO_H
#define IO_H

#include <stddef.h>
#include "contact.h"

#define BUFFER_SIZE 1024

int get_choice(int min, int max);
int get_yes_or_no(void);
int get_string(char *string, size_t size);
void print_contact(long count, Contact *list, long num);

#endif
