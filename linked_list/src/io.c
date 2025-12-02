#include "io.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

int get_value(int *value){
    long vtmp;
    char buffer[BUFFER_SIZE];
    char *endptr;

    for(;;){
        if(fgets(buffer, BUFFER_SIZE, stdin) == NULL){
            return -1;
        }

        if(buffer[0] == '\n'){
            fprintf(stderr, "Empty input.\n");
            continue;
        }

        if(strchr(buffer, '\n') == NULL){
            fprintf(stderr, "Input was too long.\n");
            int ch;
            while((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }else{
            buffer[strcspn(buffer, "\n")] = '\0';
        }

        vtmp = strtol(buffer, &endptr, 10);
        if(vtmp > INT_MAX || vtmp < INT_MIN){
            fprintf(stderr, "Out of range.\n");
            continue;
        }

        if(*endptr != '\0'){
            fprintf(stderr, "Invalid input.\n");
            continue;
        }

        *value = (int)vtmp;
        return 0;
    }
}
