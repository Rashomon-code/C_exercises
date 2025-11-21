#include "contact.h"
#include <stdio.h>
#include <stdlib.h>
#include "io.h"

int add_contact(long *count, long *capacity, Contact **list){
    if(*count >= *capacity){
        *capacity *= 2;
        Contact *tmp = realloc(*list, *capacity * sizeof(Contact));
        if(!tmp){
            perror("Memory allocation failed.");
            return -1;
        }

        *list = tmp;
    }

    int check = 0;
    printf("Enter the name please.\n> ");
    check = get_string((*list)->name, sizeof((*list)->name));
    if(check == -1){
        return -1;
    }
    
    printf("Enter the phone number please.\n> ");
    check = get_string((*list)->phone, sizeof((*list)->phone));
    if(check == -1){
        return -1;
    }

    *count++;
    return 0;
}
