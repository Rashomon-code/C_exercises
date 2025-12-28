#include <stdio.h>
#include "stack.h"

int bracket_check(char *target);

int main(void){
    char right[] = "([]{})";
    char wrong[] = "([)]";

    int check = bracket_check(right);
    if(check){
        printf("Brackets are balanced.\n");
    }else{
        printf("Unbalanced brackets found.\n");
    }

    check = bracket_check(wrong);
    if(check){
        printf("Brackets are balanced.\n");
    }else{
        printf("Unbalanced brackets found.\n");
    }

    return 0;
}

int bracket_check(char *target){
    char stack[SIZE];
    int top = -1;
    int i = 0;

    while(target[i] != '\0'){
        if(target[i] == '(' || target[i] == '[' || target[i] == '{'){
            push(stack, &top, target[i]);
        }

        if(target[i] == ')' || target[i] == ']' || target[i] == '}'){
            if(top > -1){
                pop(stack, &top, target[i]);
            }
        }
        i++;
    }

    if(top != -1){
        return 0;
    }else{
        return 1;
    }
}
