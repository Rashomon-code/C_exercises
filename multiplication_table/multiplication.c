#include <stdio.h>

int main(void){
    for(int x = 1; x < 10; x++){
        for(int y = 1; y < 10; y++){
            fprintf(stdout, "%2d ", x * y);
        }
        printf("\n");
    }
}