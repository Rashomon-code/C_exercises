#include "io.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_word(char **string, int count){
    char buffer[SIZE];

    for(;;){
        if(fgets(buffer, SIZE, stdin) == NULL){
            return 1;
        }

        if(strchr(buffer, '\n') == NULL){
            fprintf(stderr, "Input too long.\nTry again.\n");
            int ch;
            while((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }

        string[count] = malloc(strlen(buffer) * sizeof(char));
        if(string[count] == NULL){
            perror("Memory allocation failed.");
            return 1;
        }

        strcpy(string[count], buffer);

        return 0;
    }
}
