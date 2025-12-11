#include "menu.h"
#include <stdio.h>

void main_menu(void){
    puts("Enter the number of the menu.(0~3)");
    puts("1. Insert value at the beginning.");
    puts("2. Insert value at the end.");
    puts("3. Delete the node.");
    puts("4. Print the list.");
    puts("5. Toggle cycle.");
    puts("0. Exit.");
}

void init_menu(void){
    puts("Do you want to create a new list.(Y/N)");
}

void exit_menu(void){
    puts("Do you want to save vefore exiting.(0~2)");
    puts("1. Save");
    puts("2. Don't Save");
    puts("0. Cancel");
}
