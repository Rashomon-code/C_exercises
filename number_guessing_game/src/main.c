#include <stdio.h>
#include "random.h"

int main(void){
    int num = create_num(1, 100);
    printf("%d\n", num);
    return 0;
}