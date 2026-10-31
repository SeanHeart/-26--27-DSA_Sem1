#include <stdio.h>

 char unionCh(char value, char addOn){
    return (value | addOn);

    }

char intersection(char value, char addOn){
    return (value & addOn);
}

char difference(char value, char addOn){    
    return (value & ~addOn);
}

void displayBitPattern(char value){
    int i = 1 << (sizeof(value)*8 - 1);
    while(i > 0){
        printf("%d ", (value & i)?1:0);
        i = i >> 1;
    }

}


int main(){

    char value = 'A'; // 65 - 0 1 0 0 0 0 0 1
    char addOn = 'b'; // 98 - 0 1 1 0 0 0 1 0
                        
                        // union A U a == 0 1 1 0 0 0 1 1
                        // inter A ∩ a == 0 1 0 0 0 0 0 0
                        // diff  A - a == 0 0 0 0 0 0 0 1
                        // diff  a - A == 0 0 1 0 0 0 1 0
    
    //4 functions - 1 line;
        //char unionCh(char value, char addOn);
        //char intersection(char value, char addOn);
        //char difference(char value, char addOn); //use this function twice;
        //void displayBitPattern(char);


        printf("Union:\n");
        displayBitPattern(unionCh(value, addOn));

        printf("\n\nIntersection:\n");
        displayBitPattern(intersection(value, addOn));

        printf("\n\nDiff (A - a)\n");
        displayBitPattern(difference(value, addOn));
        
        printf("\n\nDiff (a - A)\n");
        displayBitPattern(difference(addOn, value));

    return 0;
}