#include "io.h"
#include "linked_list.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

int get_value(int *value){
    long vtmp;
    char buffer[BUFFER_SIZE];
    char *endptr;

    for(;;){
        printf("Enter the value: ");
        if(fgets(buffer, BUFFER_SIZE, stdin) == NULL){
            fprintf(stderr, "Error reading input.\n");
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

int get_yes_or_no(void){
    char buffer[BUFFER_SIZE];
    
    for(;;){
        printf("> ");
        if(fgets(buffer, BUFFER_SIZE, stdin) == NULL){
            fprintf(stderr, "Error reading input.\n");
            return -1;
        }

        if(buffer[0] == '\n'){
            fprintf(stderr, "Empty input.\n");
            continue;
        }

        if(buffer[1] != '\n'){
            fprintf(stderr, "Input too long.\n");
            continue;
        }

        if(tolower(buffer[0]) == 'n'){
            return 0;
        }else if(tolower(buffer[0]) == 'y'){
            return 1;
        }else{
            fprintf(stderr, "Invalid input.\n");
            continue;
        }
    }
}

int get_choice(int min, int max){
    char buffer[BUFFER_SIZE];
    char *endptr;
    long choice;

    for(;;){
        printf("> ");
        if(fgets(buffer, BUFFER_SIZE, stdin) == NULL){
            perror("fgets failed");
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

        choice = strtol(buffer, &endptr, 10);
        if(*endptr != '\0' || choice < min || choice > max){
            fprintf(stderr, "Invalid input.\n");
            continue;
        }

        return (int)choice;
    }
}

void print_list(Node *head){
    Node *tmp = head;
    int i = 1;
    if(head->previous == NULL){
        while(tmp != NULL){
            printf("%d. %d ->\n", i, tmp->value);
            tmp = tmp->next;
            i++;
        }
        printf("NULL\n");
    }else{
        i = 1;
        do{
            printf("%d. %d ->\n", i, tmp->value);
            tmp = tmp->next;
            i++;
        }while(tmp != head);
        printf("1. %d\n", tmp->value);
    }
}
