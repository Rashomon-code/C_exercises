#include <stddef.h>
#include <stdio.h>
#include "linked_list.h"
#include "file_io.h"
#include "io.h"
#include "menu.h"

int main(void){
    Node *head, *tail;
    int list_size;
    int check;
    check = init_list(&head, &tail, &list_size);
    if(check != 1){
        return check;
    }

    for(;;){
        main_menu();
        int choice = get_choice(0, 5);
        if(choice == -1){
            continue;
        }
        if(choice == 0){
            exit_menu();
            int exit_choice = get_choice(0, 2);
            if(exit_choice == 1){
                check = save_list(head, tail);
                if(check == 0){
                    puts("Saved successful.");
                    break;
                }
            }else if(exit_choice == 2){
                break;
            }
        }

        switch(choice){
            int value;
            case 1:
                check = get_value(&value);
                if(check == 0){
                    head_insert(&head, &tail, value, &list_size);
                }
                break;
            case 2:
                check = get_value(&value);
                if(check == 0){
                    tail_insert(&head, &tail, value, &list_size);
                }
                break;
            case 3:
                check = delete_node(&head, &tail, &list_size);
                break;
            case 4:
                print_list(head);
                break;
            case 5:
                toggle_cycle(head, tail);
                break;
        }
    }

    free_list(&head, &tail);
    return 0;
}
