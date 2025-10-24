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
    if(new_student.id == 1){
        return 1;
    }else{
        *(*students + *count) = new_student;
        (*count)++;
    }

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

Student create_student(void){
    Student stu;
    stu.subject_count = 0;
    int check;
    int choice;
    
    printf("Enter student name: ");
    check = get_string_input(sizeof(stu.name), stu.name);
    if(check == 1){
        fprintf(stderr, "Count not get name input.\n");
        stu.id = 1;
        return stu;
    }

    puts("Add the subject.");
    do{
        check = add_subject(&stu);
        if(check == 1){
            fprintf(stderr, "Count not add subjects.\n");
            stu.id = 1;
            return stu;
        }

        puts("Do you want to continue?(Y/n)");
        choice = get_yes_or_no();
    }while(choice == 'y' || choice == 'Y');
    
    return stu;
}

int add_subject(Student *student){
    if(student->subject_count == 0){
        student->subject_capacity = 1;
        student->subjects = malloc(sizeof(Subject));
        if(!student->subjects){
            perror("Memory allocation failed.");
            return 1;
        }
    }else{
        if(student->subject_count >= student->subject_capacity){
            student->subject_capacity *= 2;
            Subject *new = realloc(student->subjects, student->subject_capacity * sizeof(Subject));
            if(!new){
                perror("Memory reallocation failed.");
                return 1;
            }else{
                student->subjects = new;
            }
        }
    }

    printf("Enter subject title: ");
    int check = get_string_input(sizeof((student->subjects + student->subject_count)->title), (student->subjects + student->subject_count)->title);
    if(check == 1){
        return 1;
    }

    printf("Enter the score: ");
    
    return 0;
}
