#ifndef CONTACT_H
#define CONTACT_H

typedef struct{
    char name[50];
    char phone[15];
}Contact;

int add_contact(long *count, long *capacity, Contact **list);

#endif
