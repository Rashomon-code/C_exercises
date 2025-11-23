#ifndef CONTACT_H
#define CONTACT_H

typedef struct{
    char name[50];
    char phone[15];
}Contact;

int add_contact(long *count, long *capacity, Contact **list);
void display_contact(long count, Contact *list);
void search_contact(long count, Contact *list);
void search_by_name(long count, Contact *list);
void search_by_phone_number(long count, Contact *list);
int delete_contact(long *count, Contact *list);

#endif
