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

int get_yes_or_no(void){
    char buffer[BUFFER_SIZE];
    
    for(;;){
        if(fgets(buffer, BUFFER_SIZE, stdin) == NULL){
            perror("Error!");
            return -1;
        }

        if(buffer[1] != '\n'){
            fprintf(stderr, "Invalid input. Try again.\n");
            int ch;
            while((ch = getchar()) != EOF && ch != '\n');
            continue;
        }

        if(buffer[0] == 'y' || buffer[0] == 'Y'){
            return 1;
        }else if(buffer[0] == 'n' || buffer[0] == 'N'){
            return 0;
        }else{
            fprintf(stderr, "Enter 'Y/n' please. Try again.\n");
            continue;
        }
    }
}

int get_string(char *string, size_t size){
    char buffer[size];
    for(;;){
        printf("> ");
        if(fgets(buffer, size, stdin) == NULL){
            perror("Could not get input.");
            return -1;
        }

        if(strchr(buffer, '\n') == NULL){
            fprintf(stderr, "Input too long. Try again.\n");
            int ch;
            while((ch = getchar()) != EOF && ch != '\n');
            continue;
        }else{
            buffer[strcspn(buffer, "\n")] = '\0';
        }

        strcpy(string, buffer);
        printf("\n");
        return 0;
    }
}

void print_contact(long count, Contact *list, long num){
    printf("%ld.\nName: %s\nPhone number: %s\n\n", num + 1, (list + count)->name, (list + count)->phone);
}
