#include "file_io.h"
#include <stdio.h>

int read_data(Contact **list){
    FILE *fp = fopen("data/generated/contact.dat", "rb");
    if(!fp){
        return 0;
    }

    return 0;
}
