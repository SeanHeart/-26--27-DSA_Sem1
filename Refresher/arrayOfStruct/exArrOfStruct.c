#include <stdio.h>
#include <string.h>

//Structure definition
struct A {
    int var;
};

int main() {
    //Declare an array of structures
    struct A arr[2];

    arr[0].var = 10;
    arr[1].var = 20;

    for(int i=0; i<2; i++){
        printf("%d\n", arr[i].var);
    }
    
    return 0;
}