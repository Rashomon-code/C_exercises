#include "io.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int get_choice(int min, int max){
    char buffer[BUFFER_SIZE];
    long choice;
    char *end;

    for(;;){
        printf("> ");

        if(fgets(buffer, BUFFER_SIZE, stdin) == NULL){
            perror("Error!");
            return -1;
        }

        if(buffer[0] == '\n'){
            fprintf(stderr, "Empty input. Try again.\n");
            continue;
        }

        if(strchr(buffer, '\n') == NULL){
            fprintf(stderr, "Input too long. Try again.\n");
            int ch;
            while((ch = getchar()) != EOF && ch != '\n');
            continue;
        }else{
            buffer[strcspn(buffer, "\n")] = '\0';
        }

        errno = 0;
        choice = strtol(buffer, &end, 10);
        if(errno == ERANGE){
            fprintf(stderr, "Numerical result out of range.\n");
            continue;
        }

        if(*end != '\0'){
            fprintf(stderr,"Invalid input. Try again.\n");
            continue;
        }

        if(choice > max || choice < min){
            fprintf(stderr, "Input out of range (%d~%d). Try again.\n", min, max);
            continue;
        }

    return (int)choice;
    }
}
