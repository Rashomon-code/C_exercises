#include "student.h"
#include <string.h>
#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"

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
    new_student = create_student(*count);
    if(new_student.id == 1){
        return 1;
    }else{
        *(*students + *count) = new_student;
        (*count)++;
    }

    return 0;
}

int delete_student(Student *sptr, int *count){
    printf("Enter the ID you want to delete.\n> ");
    int target;
    target = search_by_id(sptr, *count);
    if(target == -1){
        return 1;
    }
    
    for(int i = target; i < *count - 1; i++){
        sptr[i] = sptr[i + 1];
    }

    (*count)--;
    puts("Successful.");

    return 0;
}

int edit_student(Student *sptr, int count){
    printf("Enter the ID you want to edit.\n> ");
    int target;
    target = search_by_id(sptr, count);
    if(target == -1){
        return 1;
    }

    for(;;){
        edit_menu();
        int choice = get_choice(0, 3);
        if(choice == -1){
            return 1;
        }
        if(choice == 0){
            return 0;
        }

        switch(choice){
            case 1:
                break;
            case 2:
                break;
            case 3:
                print_student(sptr, target);
                break;
        }
    }
}

void find_student(Student *sptr, int count){
    search_menu();
    int choice = get_choice(0, 2);
    if(choice == 0){
        return;
    }
    int target;
    switch(choice){
        case 1: 
            target = search_by_name(sptr, count);
            break;
        case 2:
            target = search_by_id(sptr,count);
            break;
    }

    if(target >= 0){
        print_student(sptr, target);
    }
}

Student create_student(int count){
    Student stu;
    stu.subject_count = 0;
    int check;
    int choice;
    
    printf("Enter student name: ");
    check = get_string_input(sizeof(stu.name), stu.name);
    if(check == 1){
        fprintf(stderr, "Coult not get name input.\n");
        stu.id = 1;
        return stu;
    }

    puts("Add the subject.");
    do{
        check = add_subject(&stu);
        if(check == 1){
            fprintf(stderr, "Coult not add subjects.\n");
            stu.id = 1;
            return stu;
        }

        puts("Do you want to continue?(Y/n)");
        choice = get_yes_or_no();
    }while(choice == 'y' || choice == 'Y');

    stu.id = create_id(count);
    
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
    check = get_score(&((student->subjects + student->subject_count)->score));
    if(check == 1){
        return 1;
    }

    student->subject_count++;
    
    return 0;
}

int create_id(int count){
    time_t now;
    struct tm *info;
    long id;
    char buffer[16];

    time(&now);
    info = localtime(&now);
    sprintf(buffer, "%d%05d", info->tm_year + 1900, count);
    id = strtol(buffer, NULL, 10);

    return (int)id;
}

int search_by_name(Student *sptr, int count){
    char target[51];
    printf("Enter the name: ");
    int check = get_string_input(sizeof(sptr->name), target);
    if(check == 1){
        return -1;
    }

    for(int i = 0; i < count; i++){
        if(strcmp(target, (sptr + i)->name) == 0){
            return i;
        }
    }

    puts("Could not find the student.");
    return -1;
}

int search_by_id(Student *sptr, int count){
    int target;
    printf("Enter the ID: ");
    target = get_id();
    if(target == -1){
        return -1;
    }

    for(int i = 0; i < count; i++){
        if((sptr + i)->id == target){
            return i;
        }
    }
    
    puts("Could not find the student.");
    return -1;
}

void free_memory(Student **students, int count){
    for(int i = 0; i < count; i++){
        free((*students + i)->subjects);
    }
    free(*students);
    *students = NULL;
}
