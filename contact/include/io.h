#ifndef IO_H
#define IO_H

#include <stddef.h>

#define BUFFER_SIZE 1024

int get_choice(int min, int max);
int get_yes_or_no(void);
int get_string(char *string, size_t size);

#endif
