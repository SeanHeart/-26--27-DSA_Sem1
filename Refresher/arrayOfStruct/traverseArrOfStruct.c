// Example of Traversing in Array of Stucture
#include <stdio.h>
#include <string.h>

// Structure definition
struct A {
    int var;
    char c;
};

int main(){
    struct A arr[5] = {{1, 'a'}, {2, 'b'}, {3, 'c'}, 
                        {4, 'd'}, {5, 'e'}};
    
    // Traverse arr
    for(int i = 0; i<5; i++){
        printf("%d %c\n", arr[i].var, arr[i].c);
    }

    return 0;
}