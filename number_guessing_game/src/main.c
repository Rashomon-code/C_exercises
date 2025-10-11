#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"

int main(void){
    srand(time(NULL));
    int num = create_num(1, 100);
    printf("%d\n", num);
    return 0;
}