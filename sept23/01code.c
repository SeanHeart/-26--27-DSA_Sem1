#include<stdio.h>

int main(){

    // char value = 'A';   // 65
    // 128 64 32 16 8 4 2 1
    // 7 6 5 4 3 2 1 0
    // 0 1 0 0 0 0 0 1

    // value << 1
    // 1 0 0 0 0 0 1 0 == 130 == 65 * 2

    // value >> 1
    // 0 0 1 0 0 0 0 0 == 32 == 65 / 2

    // int i = 1;
    // 0 0 0 0 0 0 0 1;

    // 0 1 0 0 0 0 0 1          //1
    // 0 0 0 0 0 0 0 1  |       //65
    // 0 1 0 0 0 0 1 1

    // 0 1 0 0 0 0 0 1          //1
    // 0 0 0 0 0 0 0 1         //65
    // 0 0 0 0 0 0 0 1  ^       //wa pa

    // 0 1 0 0 0 0 0 1   == A       //1
    // 0 0 0 0 0 0 0 1         //65
    // 0 0 0 0 0 0 0 0  &       

    // printf("%d", (value & 1 << 1)?1:0); //0    2ndbit
    // printf("%d", (value & 1 << 6)?1:0); //1    7bit



    //////////////////ANSWER
    // int i = 0, i++; <do no do this
    //      << >>
    //     sizeof();

    char value = 'A';   // 65
    // printf("%d", (value & 1 << 1)?1:0); //0    2ndbit
    // printf("%d", (value & 1 << 6)?1:0); //1    7bit

    //expected output : 0 1 0 0 0 0 0 1

    return 0;
}