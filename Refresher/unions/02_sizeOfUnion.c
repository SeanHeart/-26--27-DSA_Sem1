#include <stdio.h>
#include <stdlib.h>

union myUnion{
    int myNum;
    char myString[36];
};

int main(){
    union myUnion u1;
    printf("Size of the union: %zu bytes\n", sizeof(u1));
    
    return 0;
}