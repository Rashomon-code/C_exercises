#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

int hash(char *key){
    int sum = 0, i = 0;
    while(key[i]){
        sum += key[i];
        i++;
    }

    return sum % TABLE_SIZE;
}

Student *create_node(char *name, int id){
    Student *new = malloc(sizeof(Student));
    if(!new){
        perror("Memory allocation.");
        return NULL;
    }

    strcpy(new->name, name);
    new->id = id;
    new->next = NULL;

    return new;
}

int insert(char *name, int id, Student **table){
    int index = hash(name);
    Student *new = create_node(name, id);
    if(!new){
        return 1;
    }
    new->next = table[index];
    table[index] = new;
    return 0;
}
