#include "contact.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "menu.h"

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
    check = get_string(((*list) + *count)->name, sizeof(((*list) + *count)->name));
    if(check == -1){
        return -1;
    }
    
    printf("Enter the phone number please.\n> ");
    check = get_string(((*list) + *count)->phone, sizeof(((*list) + *count)->phone));
    if(check == -1){
        return -1;
    }

    return ++*count;
}

void display_contact(long count, Contact *list){
    if(count == 0){
        puts("No contacts.\n");
        return;
    }

    for(int i = 0; i < count; i++){
        print_contact(i, list);
    }
}

void search_contact(long count, Contact *list){
    if(count == 0){
        puts("No contacts.");
        return;
    }

    search_menu();
    int choice = get_choice(0, 2);
    if(choice == 0){
        return;
    }

    switch(choice){
        case 1:
            search_by_name(count, list);
            break;
        case 2:
            search_by_phone_number(count, list);
            break;
    }
}

void search_by_name(long count, Contact *list){
    char buffer[BUFFER_SIZE];
    
    printf("Enter the name you want to search\n> ");
    int check = get_string(buffer, sizeof(list->name));
    printf("\n");
    if(check == -1){
        return;
    }

    int arr[count];
    int j = 0;
    int i;
    for(i = 0; i < count; i++){
        if(strstr(list->name, buffer) != NULL){
            arr[j++] = i;
        }
    }

    if(j == 0){
        puts("No matching item found.");
        return;
    }
    
    for(i = 0; i < j; i++){
        print_contact(i, list);
    }
}

void search_by_phone_number(long count, Contact *list){
    char buffer[BUFFER_SIZE];

    printf("Enter the phone number you want to search.\n> ");
    int check = get_string(buffer, sizeof(list->phone));
    printf("\n");
    if(check == -1){
        return;
    }

    int arr[count];
    int j = 0;
    int i;
    for(i = 0; i < count; i++){
        if(strstr(list->phone, buffer) != NULL){
            arr[j++] = i;
        }
    }

    if(j == 0){
        puts("No matching item found.");
        return;
    }
    
    for(i = 0; i < j; i++){
        print_contact(i, list);
    }
    
    return;
}

int delete_contact(long *count, Contact *list){
    char buffer[BUFFER_SIZE];
    printf("Enter the name of contact you want to delete.\n> ");
    int check = get_string(buffer, sizeof(list->name));
    if(check == -1){
        return -1;
    }
    
    
}
