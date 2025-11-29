#include "menu.h"
#include <stdio.h>

void main_menu(void){
    puts("Enter the number of the menu.");
    puts("1. Add Contact");
    puts("2. Display All");
    puts("3. Search Contact");
    puts("4. Delete Contact");
    puts("5. Modify Contact");
    puts("0. Exit");
}

void search_menu(void){
    puts("Enter the number of the menu.");
    puts("1. Search by name.");
    puts("2. Search by phone number.");
    puts("0. Exit search.");
}

void modify_menu(int num, Contact *list){
    printf("Name: %s\nPhone number: %s\n\n", list[num - 1].name, list[num - 1].phone);
    puts("Enter the number of the menu.");
    puts("1. Modify the name.");
    puts("2. Modify the phone.");
    puts("0. Exit modify.");
}
