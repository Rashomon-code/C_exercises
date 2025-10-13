#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"
#include "io.h"

int main(void){
    srand(time(NULL));
    int user_num, count = 0;
    int num = create_num(1, 100);

    puts("Enter your number.(1-100)");
    for(;;){
        user_num = get_input();
        if(user_num == -1){
            return 1;
        }else{
            count++;
        }

        if(user_num < num){
            condition(-1);
        }else if(user_num > num){
            condition(1);
        }else{
            break;
        }
    }

    finish(count);

    return 0;
}