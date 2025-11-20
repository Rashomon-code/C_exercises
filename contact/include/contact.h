#ifndef CONTACT_H
#define CONTACT_H

typedef struct{
    char name[50];
    char phone[15];
}Contact;

int add_contact(int *count, int *capacity, Contact **list);

#endif
