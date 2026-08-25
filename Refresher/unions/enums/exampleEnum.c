#include <stdio.h>
#include <stdlib.h>

enum Level {
    LOW = 25,
    MEDIUM,
    HIGH
};

int main(){
    //Create an enum variable and assign a value to it
    enum Level myVar = MEDIUM;
    
    //Print the enum variable
    printf("%d", myVar);
    
    return 0;
}