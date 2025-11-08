#include <stdio.h>

void hanoi(int n, char from, char to, char aux);

int main(void){
    puts("How many disk do you want to move.");
    printf("> ");
    
    int num;
    scanf("%d", &num);

    hanoi(num, 'A', 'C', 'B');
    return 0;
}

void hanoi(int n, char from, char to, char aux){
    if(n == 1){
        printf("Move disk 1 from %c to %c\n", from, to);
    }else{
        //核心：把disk當成只有n和n-1兩個碟子，移動兩個碟子的邏輯
        hanoi(n - 1, from, aux, to);
        printf("Move disk %d from %c to %c\n", n, from, to);
        hanoi(n - 1, aux, to, from);
    }
}
