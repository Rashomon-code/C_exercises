#include <stdio.h>
#include <string.h>

int main(void){
    char buffer[1024];
    int vowel[5] = {0};

    fgets(buffer, sizeof(buffer), stdin);
    if(strchr(buffer, '\n') == NULL){
        int ch;
        while((ch = getchar()) != '\n' && ch != EOF);
    }else{
        buffer[strcspn(buffer, "\n")] = '\0';
    }

    for(int i = 0; buffer[i] != '\0'; i++){
        switch(buffer[i]){
            case 'A':
            case 'a':
                vowel[0]++;
                break;
            case 'E':
            case 'e':
                vowel[1]++;
                break;
            case 'I':
            case 'i':
                vowel[2]++;
                break;
            case 'O':
            case 'o':
                vowel[3]++;
                break;
            case 'U':
            case 'u':
                vowel[4]++;
                break;
        }
    }

    printf("sum: %d\n", vowel[0] + vowel[1] + vowel[2] + vowel[3] + vowel[4]);
    printf("A: %d E: %d I: %d O: %d U: %d\n", vowel[0] , vowel[1] , vowel[2] , vowel[3] , vowel[4]);

    return 0;
}