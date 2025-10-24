#include <stdio.h>

#ifndef IO_H
#define IO_H

int get_choice(void);
int get_string_input(size_t size, char *sptr);
int get_yes_or_no(void);
int get_score(float *score);

#endif
