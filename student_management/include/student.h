#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    char title[51];
    float score;
}Subject;

typedef struct{
    char name[51];
    Subject *subjects;
}Student;

int add_student(int *capacity);
int delete_student(void);
int edit_student(void);
int find_student(void);

#endif