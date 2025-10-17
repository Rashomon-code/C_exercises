#include "io.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_choice(void){
    char *endptr;
    char buffer[8];
    long num;

    for(;;){
        if(fgets(buffer, sizeof(buffer), stdin) == NULL){
            fprintf(stderr, "ERROR.\n");
            return -1;
        }

        if(buffer[0] == '\n'){
            fprintf(stderr, "Empty input.\n");
            continue;
        }

        if(strchr(buffer, '\n') == NULL){
            fprintf(stderr, "Input too long.\n");
            continue;
        }else{
            buffer[strcspn(buffer, "\n")] = '\0';
        }

        num = strtol(buffer, &endptr, 10);

        if(*endptr != '\0'){
            fprintf(stderr, "Invalid input.\n");
            continue;
        }

        if(num > 4L || num < 0L){
            fprintf(stderr, "Enter 0-4 please.\n");
            continue;
        }
        
        return (int)num;
    }
}
