#include "io.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_choice(int min, int max){
    char *endptr;
    char buffer[8];
    long num;

    for(;;){
        if(fgets(buffer, sizeof(buffer), stdin) == NULL){
            fprintf(stderr, "ERROR.\n");
            return -1;
        }

        if(buffer[0] == '\n'){
            fprintf(stderr, "Empty input.\n> ");
            continue;
        }

        if(strchr(buffer, '\n') == NULL){
            fprintf(stderr, "Input too long.\n> ");
            int ch;
            while((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }else{
            buffer[strcspn(buffer, "\n")] = '\0';
        }

        num = strtol(buffer, &endptr, 10);

        if(*endptr != '\0'){
            fprintf(stderr, "Invalid input.\n> ");
            continue;
        }

        if(num > max || num < min){
            fprintf(stderr, "Enter %d-%d please.\n> ", min, max);
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
    char buffer[8];
    char *endptr;
    float scr;

    for(;;){
        if(fgets(buffer, 8, stdin) == NULL){
            perror("Could not get score.");
            return 1;
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

        scr = strtof(buffer, &endptr);
        if(*endptr != '\0'){
            fprintf(stderr, "Invalid input.\n");
            continue;
        }

        if(scr > 100.0F || scr < 0.0F){
            fprintf(stderr, "Invalid input.\n");
            continue;
        }
        
        break;
    }

    *score = scr;
    return 0;
}

void print_subject(Subject *subject, int count){
    for(int i = 0; i < count; i++){
        printf("Subject %d: %s\nScore: %.1f\n", i + 1, (subject + i)->title, (subject + i)->score);
    }
}

void print_student(Student *sarr, int num){
    printf("ID: %d\n", (sarr + num)->id);
    printf("Name: %s\n", (sarr + num)->name);
    print_subject((sarr + num)->subjects, (sarr + num)->subject_count);
}

void print_all_students(Student *sarr, int count){
    if(count == 0){
        puts("No student.\n");
    }else{
        for(int i = 0; i < count; i++){
            print_student(sarr, i);
        }
    }
}
