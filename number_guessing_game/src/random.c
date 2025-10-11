#include "random.h"
#include <time.h>
#include <stdlib.h>

int create_num(int min, int max){
    return rand() / (RAND_MAX / (max - min +1)) + min;
}