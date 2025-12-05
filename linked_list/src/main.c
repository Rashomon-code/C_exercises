#include <stddef.h>
#include <stdio.h>
#include "linked_list.h"
#include "file_io.h"
#include "io.h"
#include "menu.h"

int main(void){
    Node *head, *tail;
    int check;
    check = init_list(&head, &tail);
    if(check != 1){
        return check;
    }

    for(;;){
        main_menu();
        int choice = get_choice(0, 3);
        if(choice == -1){
            continue;
        }
        if(choice == 0){
            break;
        }
    }

    free_list(&head, &tail);
    return 0;
}
