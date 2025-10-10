#include <stdio.h>
#include "calculator.h"
#include "get_input.h"

int main(void){
    double num1, num2, result;
    char operator;

    for(;;){
        int check = 0;
        check = get_num(&num1);
        if(check == 1){
            puts("Error.");
            return 1;
        }

        operator = get_operator();
        if(operator == '\0'){
            puts("Error.");
            return 1;
        }

        check = get_num(&num2);
        if(check == 1){
            puts("Error.");
            return 1;
        }

        switch(operator){
            case '\0':
                return 1;
            case '+':
                result = add(num1, num2);
                break;
            case '-':
                result = subtract(num1, num2);
                break;
            case '*':
                result = multiply(num1, num2);
                break;
            case '/':
                result = divide(num1, num2);
                break;
        }

        printf("%f\n", result);
    }
    
    return 0;
}