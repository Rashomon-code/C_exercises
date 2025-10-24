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
            int ch;
            while((ch = getchar()) != '\n' && ch != EOF);
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

int get_string_input(size_t size, char *sptr){
    for(;;){
        if(fgets(sptr, size, stdin) == NULL){
            perror("Error.");
            return 1;
        }

        if(strchr(sptr, '\n') == NULL){
            fprintf(stderr, "Input too long.\n");
            int c;
            while((c = getchar()) != '\n' && c != EOF);
            continue;
        }else{
            sptr[strcspn(sptr, "\n")] = '\0';
        }

        return 0;
    }
}

int get_yes_or_no(void){
    int ch;

    for(;;){
        ch = getchar();
        if(ch == EOF){
            perror("Error.");
            return '\0';
        }
        
        if(ch == '\n'){
            fprintf(stderr, "Invalid input.\n");
            continue;
        }

        int p, count = 0;;
        while((p = getchar()) != '\n' && p != EOF){
            count++;
        }

        if(count >= 1){
            fprintf(stderr, "Invalid input.\n");
            continue;
        }

        if(ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N'){
            break;
        }else{
            printf("(Y/n): ");
        }
    }

    return ch;
}

int get_score(float *score){
    return 0;
}
