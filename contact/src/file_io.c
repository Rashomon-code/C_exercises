#include "file_io.h"
#include <stdio.h>
#include "io.h"
#include <stdlib.h>

long read_data(Contact **list, long *capacity){
    FILE *fp = fopen("data/generated/contact.dat", "rb");
    if(!fp){
        printf("Could not open the file.\nDo you want to create a new contact?(Y/n)\n");
        int check = get_yes_or_no();
        if(check == 1){
            *capacity = 1;
            *list = malloc(*capacity * sizeof(Contact));
            if(*list == NULL){
                perror("Memory allocation failed.");
                return -1;
            }
            return 0;
        }else{
            return -1;
        }
    }

    size_t file_size;
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    if(file_size % sizeof(Contact) != 0){
        fprintf(stderr, "File size does not match the size of the Contact structure.The file may be corrupted.\n");
        fclose(fp);
        return -1;
    }

    long count = file_size / sizeof(Contact);
    *capacity = count + 1;
    *list = malloc(*capacity * sizeof(Contact));
    if(*list == NULL){
        perror("Memory allocation failed.");
        fclose(fp);
        return -1;
    }

    size_t read_count = fread(*list, sizeof(Contact), count, fp);
    if(read_count != count){
        fprintf(stderr, "Failed to read all contacts from file.\n");
        free(*list);
        fclose(fp);
        return -1;
    }

    fclose(fp);
    return count;
}
