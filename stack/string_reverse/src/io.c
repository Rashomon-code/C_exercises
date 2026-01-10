#include "io.h"
#include <stdio.h>
#include <string.h>

int get_input(size_t size, char *string){
    for(;;){
        if(fgets(string, size, stdin) == NULL){
            fprintf(stderr, "Can not get input.");
            return -1;
        }

        if(strchr(string, '\n') == NULL){
            fprintf(stderr, "Input too long.\n");
            int ch;
            while((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }else{
            string[strcspn(string, "\n")] = '\0';
            return 0;
        }
    }
}
