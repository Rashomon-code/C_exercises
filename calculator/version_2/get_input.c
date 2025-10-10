#include "get_input.h"
#include <stdio.h>
#include <string.h>

int get_input(double *num1, double *num2, char *op){
    char buffer[BUFFER_SIZE];
    int check = 0, check_ch = 0;
    char tmp;

    for(;;){
        fprintf(stdout, "Enter expression.\n> ");
        if(fgets(buffer, sizeof(buffer), stdin) == NULL){
            fprintf(stderr, "\nCalculator session ended.\n");
            return 1;
        }

        if(strchr(buffer, '\n') == NULL){
            int ch;
            while((ch = getchar()) != '\n' && ch != EOF);
            fprintf(stderr, "ERROR: Input too long.\n");
            continue;
        }

        if(buffer[0] == '\n'){
            fprintf(stderr, "ERROR: Empty input.\n");
            continue;
        }

        check = sscanf(buffer, "%lf %c %lf %n", num1, &tmp, num2, &check_ch);
        if(check != 3){
            fprintf(stderr, "ERROR: Invalid format.");
            continue;
        }

        if(buffer[check_ch] != '\0' && buffer[check_ch] != '\n'){
            fprintf(stderr, "ERROR: Junk characters found at the end of input.\n");
            continue;
        }

        if(tmp != '+' && tmp != '-' && tmp != '*' && tmp != '/'){
            fprintf(stderr, "ERROR: Invalid operator.");
            continue;
        }

        *op = tmp;

        return 0;
    }
}