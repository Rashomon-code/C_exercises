#include "file_io.h"
#include "menu.h"
#include <stdio.h>
#include "io.h"
#include "linked_list.h"

int init_list(Node **head, Node **tail, int *list_size){
    *head = NULL;
    *tail = NULL;
    *list_size = 0;
    
    FILE *fp = fopen("data/generated/list.dat", "rb");
    if(!fp){
        printf("Failed to open file.\n");
        init_menu();
        int choice = get_yes_or_no();
        return choice;
    }

    int value;
    while(fread(&value, sizeof(int), 1, fp) == 1){
        int check = tail_insert(head, tail, value, list_size);
        if(check == -1){
            fprintf(stderr, "Failed to load data.\n");
            fclose(fp);
            return -1;
        }
    }

    if(ferror(fp)){
        perror("Error reading list data.");
        fclose(fp);
        return -1;
    }

    fclose(fp);
    return 1;
}

int save_list(Node *head, Node *tail){
    FILE *fp = fopen("data/generated/list.dat", "wb");
    if(!fp){
        perror("Failed to open file for saving.");
        return -1;
    }

    Node *tmp = head;
    if(head->previous == NULL){
        while(tmp != NULL){
            if(fwrite(&tmp->value, sizeof(int), 1, fp) != 1){
                fprintf(stderr, "Failed to save data.\n");
                if(ferror(fp)){
                    perror("System error during write.");
                }
                fclose(fp);
                return -1;
            }
            tmp = tmp->next;
        }
    }else{
        do{
            if(fwrite(&tmp->value, sizeof(int), 1, fp) != 1){
                fprintf(stderr, "Failed to save data.\n");
                if(ferror(fp)){
                    perror("System error during write.");
                }
                fclose(fp);
                return -1;
            }
            tmp = tmp->next;
        }while(tmp != head);
    }

    if(fclose(fp) == EOF){
        perror("Error closing file after saving.");
    }

    return 0;
}
