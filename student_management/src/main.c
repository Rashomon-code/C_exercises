#include <stdio.h>
#include "io.h"
#include "student.h"
#include <stdlib.h>
#include "io.h"

int main(void){
    int choice, check = 0, count = 0;
    size_t capacity = 1;
    Student *students;

    for(;;){
        put_menu();
        choice = get_choice();
        if(choice == -1){
            return 1;
        }

        if(choice == 0){
            puts("Bye!");
            break;
        }

        switch(choice){
            case 1:
                add_student();
                break;
            case 2:
                delete_student();
                break;
            case 3:
                exit_student();
                break;
            case 4:
                find_student();
                break;
        }
    }

    return 0;
}
