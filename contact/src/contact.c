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

    for(long i = 0; i < count; i++){
        print_contact(i, list, i);
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

    int *arr = malloc(sizeof(int) * count);
    int j;

    switch(choice){
        case 1:
            printf("Enter the name you want to search\n> ");
            j = search_by_name(count, list, arr);
            break;
        case 2:
            printf("Enter the phone number you want to search.\n> ");
            j = search_by_phone_number(count, list, arr);
            break;
    }

    if(j == 0){
        puts("No matching item found.");
    }else{
        for(int i = 0; i < j; i++){
            print_contact(arr[i], list, i);
        }
    }

    free(arr);
}

int search_by_name(long count, Contact *list, int *arr){
    char buffer[BUFFER_SIZE];
    
    int check = get_string(buffer, sizeof(list->name));
    printf("\n");
    if(check == -1){
        return -1;
    }

    int j = 0;
    for(int i = 0; i < count; i++){
        if(strstr((list + i)->name, buffer) != NULL){
            arr[j++] = i;
        }
    }

    return j;
}

int search_by_phone_number(long count, Contact *list, int *arr){
    char buffer[BUFFER_SIZE];

    int check = get_string(buffer, sizeof(list->phone));
    printf("\n");
    if(check == -1){
        return -1;
    }

    int j = 0;
    for(int i = 0; i < count; i++){
        if(strstr((list + i)->phone, buffer) != NULL){
            arr[j++] = i;
        }
    }

    return j;
}

int delete_contact(long *count, Contact *list){
    printf("Enter the name of contact you want to delete.\n> ");

    int *arr = malloc(*count * sizeof(int));
    int contact_num = search_by_name(*count, list, arr);
    if(contact_num == -1){
        free(arr);
        return -1;
    }

    if(contact_num == 0){
        puts("No matching item found.");
    }else{
        for(int i = 0; i < contact_num; i++){
            print_contact(arr[i], list, i);
        }
    }

    printf("Enter the number of the menu you want to delete.\n");
    int delete_number = get_choice(0, contact_num);

    for(int i = arr[delete_number - 1]; i < *count - 1; i++){
        list[i] = list[i + 1];
    }

    *count -= 1;
    free(arr);
    puts("Deleted.\n");
    return 0;
}
