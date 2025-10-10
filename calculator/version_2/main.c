#include <stdio.h>
#include "get_input.h"
#include "calculator.h"

int main(void){
    double num1, num2, result;
    char operator;
    int check;

    for(;;){
        check = get_input(&num1, &num2, &operator);
        if(check == 1){
            return 1;
        }

        switch(operator){
            case '+':
            result = num1 + num2;
            break;
            case '-':
            result = num1 - num2;
            break;
            case '*':
            result = num1 * num2;
            break;
            case '/':
            result = num1 / num2;
        }

        printf(" = %lf\n", result);
    }

    return 0;
}