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
        printf("> ");
        int choice = get_choice();
        if(choice == -1){
            return 1;
        }

        if(choice == 0){
            puts("Bye!");
            break;
        }

        switch(choice){
            case 1:
                check = add_student(&capacity, &students);
                if(check == 1){
                    free(students);
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
                find_student();
                break;
        }
    }

    return 0;
}
