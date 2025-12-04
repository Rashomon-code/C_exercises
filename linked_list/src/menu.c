#include "menu.h"
#include <stdio.h>

void main_menu(void){
    puts("Enter the number of the menu.(0~3)");
    puts("1. Insert value at the beginning.");
    puts("2. Insert value at the end.");
    puts("3. Print the list.");
    puts("0. Exit.");
}

void init_menu(void){
    puts("Do you want to create a new list.(Y/N)");
}
