#include <stdio.h>
#include "stack.h"
#include "list.h"

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
    node *top = NULL;
    int i = 0;

    while(target[i] != '\0'){
        if(target[i] == '(' || target[i] == '[' || target[i] == '{'){
            push(&top, target[i]);
        }

        if(target[i] == ')' || target[i] == ']' || target[i] == '}'){
            pop(&top, target[i]);
        }

        i++;
    }

    if(top){
        while(top){
            free_node(&top);
        }
        return 0;
    }else{
        return 1;
    }
}
