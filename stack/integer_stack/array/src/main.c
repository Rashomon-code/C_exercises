#include <stdio.h>
#include "int_stack.h"

int main(void){
    Stack a;
    int check;
    int value = 1;

    initialization(&a);
    peek(a);
    for(int i = 0; i < STACK_SIZE; i++){
        check = push(&a, value++);
        if(check == 1){
            break;
        }
    }

    peek(a);

    return 0;
}
