#include "list.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    node *head = NULL;

    peek(head);
    int check = push(10, &head);
    peek(head);
    pop(&head);
    peek(head);

    free_list(&head);

    return 0;
}
