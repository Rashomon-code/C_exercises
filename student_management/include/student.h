#ifndef STUDENT_H
#define STUDENT_H

#include <stdlib.h>

typedef struct {
    char title[51];
    float score;
}Subject;

typedef struct{
    char name[51];
    Subject *subjects;
    int subject_count;
    int subject_capacity;
    int id;
}Student;

int init(Student **student, size_t *capacitya, int *count);

int add_student(int *count, size_t *capacity, Student **students);
int delete_student(void);
int edit_student(void);
int find_student(void);

Student create_student(int count);
int add_subject(Student *student);
int create_id(int count);

#endif
