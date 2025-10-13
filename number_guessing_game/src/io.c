#include "io.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_input(void){
    char buffer[size];
    char *endptr;
    long num;

    for(;;){
        if(fgets(buffer, size, stdin) == NULL){
            fprintf(stderr, "Error.");
            return -1;
        }

        if(buffer[0] == '\n'){
            fprintf(stderr, "Empty input.");
            continue;
        }

        if(strchr(buffer, '\n') == NULL){
            fprintf(stderr, "Input too long.");
            continue;
        }else{
            buffer[strcspn(buffer, "\n")] = '\0';
        }

        num = strtol(buffer, &endptr, 10);

        if(*endptr != '\0'){
            fprintf(stderr, "Invalid input.");
            continue;
        }

        if(num > 100L || num < 1L){
            fprintf(stderr, "Enter 1-100 please.");
            continue;
        }

        return (int)num;
    }
}

void finish(int i){
    if(i == 1){
        puts("You got it on the first try.");
    }else{
        printf("You guessed it in %d tries.\n", i);
    }
}

void condition(int i){
    if(i == 1){
        puts("Too high, please try again.");
    }else{
        puts("Too low, please try again.");
    }
}