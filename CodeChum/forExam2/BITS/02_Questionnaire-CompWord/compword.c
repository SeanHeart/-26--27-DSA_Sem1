#include <stdio.h>
#include <stdbool.h>
#include "compword.h"

// write your functions here...
void setAnswer(CompWord* profile, int index, int value){
    if(value){
        *profile |= (1 << index);
    }else{
        *profile &= ~(1 << index);
    }
}

void printAnswers(CompWord profile){
    for (int i = 9; i >= 0; i--) {
        printf("%d", (profile >> i) & 1);
    }
    printf("\n");
}

int compareProfiles(CompWord a, CompWord b){
    int matches = 0;

    for(int i=0; i<10; i++){
        int bitA = (a >> i) & 1;
        int bitB = (b >> i) & 1;
        if(bitA == bitB){
            matches++;
        }
    }

    return matches;
}
