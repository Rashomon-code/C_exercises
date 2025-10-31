#include <stddef.h>

#ifndef IO_H
#define IO_H

#include "student.h"

int get_choice(int min, int max);
int get_string_input(size_t size, char *sptr);
int get_yes_or_no(void);
int get_score(float *score);
int get_id(void);

void print_subject(Subject *subject, int count);
void print_student(Student *sarr, int num);
void print_all_students(Student *sarr, int count);

#endif
