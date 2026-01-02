#include <stdio.h>
#include "io.h"

#define SIZE 1024;

void string_reverse(string);

int main(void){
    char string[SIZE];
    printf("Enter the string you want to reverse.\n");

    get_input(SIZE, string);

    string_reverse(string);
    printf("%s\n", string);

    return 0;
}

void string_reverse(string){
    char new_str[SIZE] = {0};
    int top = -1;
    while(string[i] != '\0'){
        push(string[i], new_str);
        i++;
    }
}
