#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

void free_memory(char **strings, int count);
void sort(char **strings, int count);

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
                free_memory(strings, count);
                return 1;
            }
        }

        printf("> ");
        int check = get_word(strings, count);
        if(check == 1){
            free_memory(strings, count);
            return check;
        }

        printf("Put 'Y/y' to continue.\n>");
        choice = getchar();
        int ch;
        while((ch = getchar()) != '\n' && ch != EOF);

        count++;
    }while(choice == 'Y' || choice == 'y');

    sort(strings, count);
    
    return 0;
}

void free_memory(char **strings, int count){
    for(int i = 0; i < count; i++){
        free(*(strings + i));
    }

    free(strings);
}

void sort(char **strings, int count){
    for(int i = 0; i < count - 1; i++){
        for(int j = i + 1; j < count; j++){
            if(strcmp(strings[i], strings[j]) > 0){
                char *buffer;
                buffer = strings[i];
                strings[i] = strings[j];
                strings[j] = buffer;
            }
        }
    }
}
