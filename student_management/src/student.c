#include "student.h"
#include "io.h"
#include <stdio.h>
#include <stdlib.h>

int init(Student **student, size_t *capacity, int *count){
    *count = 0;

    *capacity = 1;
    *student = malloc(*capacity * sizeof(Student));
    if(*student == NULL){
        perror("Memory allocation failed.");
        return 1;
    }

    return 0;
}


int add_student(int *count, size_t *capacity, Student **students){
    if(*count >= *capacity){
        *capacity *= 2;
        Student *tmp = realloc(*students, sizeof(Student) * *capacity);
        if(!tmp){
            perror("Error: Memory reallocation failed.");
            return 1;
        }else{
            *students = tmp;
        }
    }

    Student new_student;
    new_student = create_student();

    return 0;
}

int delete_student(void){
    return 0;
}
int edit_student(void){
    return 0;
}
int find_student(void){
    return 0;
}

int create_student(Student *new){

}

int add_subject(Student *student){
    return 0;
}
