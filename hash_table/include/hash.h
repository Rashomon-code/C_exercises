#pragma once

#define TABLE_SIZE 1024

typedef struct student{
    char name[40];
    int id;
    struct student *next;
}Student;

int hash(char *key);
Student *create_node(char *name, int id);
int insert(char *name, int id);
