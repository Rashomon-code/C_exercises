#include "linked_list.h"
#include <stdlib.h>
#include "io.h"

node* create_node(int value){
    node *new;

    new->value = value;
    new->previous = NULL;
    new->next = NULL;

    return new;
}
