#include <stdio.h>

long fibonacci(int i);

int main(void){
    long result = fibonacci(5);
    printf("%ld", result);

    return 0;
}

long fibonacci(int i){
    if(i == 0){
        return 0;
    }
    if(i == 1){
        return 1;
    }
    return fibonacci(i - 1) + fibonacci(i - 2);
}
