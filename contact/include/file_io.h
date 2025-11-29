#ifndef FILE_IO_H
#define FILE_IO_H

#include "contact.h"

long read_data(Contact **list, long *capacity);
int write_data(int count, Contact **list);

#endif
