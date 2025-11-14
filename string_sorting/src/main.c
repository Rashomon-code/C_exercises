#include <stdio.h>
#include <stdlib.h>

int main(void){
    char **strings;
    int count = 0, capacity = 1;
    
    strings = malloc(capacity * sizeof(*strings));
    if(!strings){
        perror("Memory allocation failed.");
        return 1;
    }

    puts("Enter the string.");

    do{
        printf("> ");

    }while(0);
    
    return 0;
}
