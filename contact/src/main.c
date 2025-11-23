#include <stdio.h>
#include "menu.h"
#include "io.h"
#include "contact.h"
#include "file_io.h"
#include <stdlib.h>

int main(void){
    Contact *list = NULL;
    long capacity;
    long count = read_data(&list, &capacity);
    if(count == -1){
        return 1;
    }
    int check;

    for(;;){
        main_menu();
        int choice = get_choice(0, 5);
        printf("\n");
        if(choice == -1){
            continue;
        }else if(choice == 0){
            free(list);
            puts("Bye.");
            return 0;
        }

        switch(choice){
            case 1:
                check = add_contact(&count, &capacity, &list);
                if(check == -1){
                    return -1;
                }
                break;
            case 2:
                display_contact(count, list);
                break;
            case 3:
                search_contact(count, list);
                break;
            case 4:
                break;
            case 5:
                break;
        }
    }
}
