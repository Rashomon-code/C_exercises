#include "student.h"
#include <stdio.h>
#include <stdlib.h>

int add_student(size_t *capacity, int *count, Student **students){
    if(*count == 0){
        *students = malloc(sizeof(Student));
        if(!*students){
            perror("Memory allocation failed.");
            return 1;
        }
    }

    if(*count >= *capacity){
        *capacity *= 2;
        Student *tmp = realloc(*students, *capacity * sizeof(Student));
        if(!tmp){
            perror("Memory reallocation failed.");
            return 1;
        }else{
            *students = tmp;
        }
    }
}
