#include<stdio.h>

int main(){

    // int i = 0, i++; <do no do this
    //      << >>
    //     sizeof();

    char value = 'A';   // 65 <- 1 byte
    int i = 1 << (sizeof(value)*8 - 1);  // 128

    // 1 0 0 0 0 0 0 0
    // 0 0 0 0 0 0 0 0
    while(i > 0){
        printf("%d ", (value & i)?1:0);
        i = i >> 1;
    }

    // printf("%d", (value & 1 << 6)?1:0); //1    7bit
    // printf("%d", (value & 1 << 1)?1:0); //0    2ndbit

    //expected output : 0 1 0 0 0 0 0 1

    return 0;
}