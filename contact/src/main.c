#include <stdio.h>
#include "menu.h"
#include "io.h"
#include "contact.h"
#include "file_io.h"

int main(void){
    Contact *list;
    int count = read_data(&list);

    for(;;){
        main_menu();
        int choice = get_choice(0, 5);
        if(choice == -1){
            continue;
        }else if(choice == 0){
            return 0;
        }

        switch(choice){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
        }
    }
}
