#include <stdio.h>
#include <stdlib.h>
#include "io.h"

int main(void){
    int choice;
    char **strings;
    int count = 0, capacity = 1;
    
    strings = malloc(capacity * sizeof(*strings));
    if(!strings){
        perror("Memory allocation failed.");
        return 1;
    }

    puts("Enter the string.");

    do{
        if(count >= capacity){
            capacity *= 2;
            char **tmp;
            tmp = realloc(strings, capacity * sizeof(*strings));
            if(tmp == NULL){
                perror("Memory allocation failed.");
                free(strings);
                return 1;
            }
        }

        printf("> ");
        int check = get_word(strings, count);
        if(check == 1){
            return check;
        }

        printf("Put 'Y/y' to continue.\n>");
        choice = getchar();
        int ch;
        while((ch = getchar()) != '\n' && ch != EOF);
    }while(choice == 'Y' || choice == 'y');
    
    return 0;
}
