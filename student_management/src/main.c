#include <stdio.h>
#include "io.h"
#include "student.h"
#include <stdlib.h>
#include "menu.h"

int main(void){
    int count, check;
    size_t capacity;
    Student *students = NULL;

    check = init(&students, &capacity, &count);
    if(check == 1){
        return 1;
    }

    for(;;){
        put_menu();
        int choice = get_choice(0, 5);
        if(choice == -1){
            return 1;
        }

        if(choice == 0){
            puts("Bye!");
            break;
        }

        switch(choice){
            case 1:
                check = add_student(&count, &capacity, &students);
                if(check == 1){
                    free_memory(&students, count);
                    return 1;
                }
                break;
            case 2:
                delete_student();
                break;
            case 3:
                edit_student();
                break;
            case 4:
                find_student(students, count);
                break;
            case 5:
                print_all_students(students, count);
        }
    }

    free_memory(&students, count);
    return 0;
}
