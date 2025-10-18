#include "student.h"
#include "io.h"
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

    int check = 0;
    printf("Enter student's name please.\n");
    check = get_char_input(sizeof(Student.name), (*students + *count)->name);
    if(check == 1){
        perror("Input error.");
        return check;
    }
    
    printf("Do you want to add the subject.(Y/n)\n");

    for(;;){
        int choice = get_yes_or_no();
        if(choice == 1){
            perror("Input error.");
            return 1;
        }else if(choice == 'y'){
            check = add_subject();
        }
    }
}
