#include <stdio.h>
#include "menu.h"

void put_menu(void){
    printf("Enter the number of the menu.\n");
    printf("1. Add new student.\n");
    printf("2. Delete the student.\n");
    printf("3. Exit the student.\n");
    printf("4. Find the student.\n");
    printf("5. Print out all students.\n");
    printf("0. Exit.\n");
    printf("> ");
}

void search_menu(void){
    printf("Enter the number of the menu.\n");
    printf("1. Search by name.\n");
    printf("2. Search by ID.\n");
    printf("0. Exit search.\n");
    printf("> ");
}

void edit_menu(void){
    printf("Enter the number of the menu.\n");
    printf("1. Edit the name.\n");
    printf("2. Edit the subject.\n");
    printf("3. Check.\n");
    printf("0. Exit edit.\n");
    printf("> ");
}
