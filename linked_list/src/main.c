#include <stddef.h>
#include <stdio.h>
#include "linked_list.h"
#include "file_io.h"

int main(void){
    Node *head, *tail;
    int check;
    check = init_list(&head, &tail);
    if(check != 1){
        return check;
    }

    free_list(&head, &tail);
    return 0;
}
