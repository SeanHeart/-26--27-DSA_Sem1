#include <stdio.h>
#include <string.h>

// Structure definition
struct A {
    int var;
    char c;
};

int main() {
    // Declaration and initialization using nested initializer list
    struct A arr1[2] = {{1, 'a'}, {2, 'b'}};

    // Declaration and initialization using non-nested initializer list
    struct A arr2[2] = {10, 'A', 20, 'B'};

    // Designated initialization
    struct A arr3[2] = {{.c = 'A', .var = 10},
                        {.var = 2, .c = 'b'}};
    
    printf("arr1\n");
    for(int i=0; i<2; i++){
        printf("%d %c\n", arr1[i].var, arr1[i].c);
    }
    printf("\n");

    printf("arr2\n");
    for(int i=0; i<2; i++){
        printf("%d %c\n", arr2[i].var, arr2[i].c);
    }
    printf("\n");

    printf("arr3\n");
    for(int i=0; i<2; i++){
        printf("%d %c\n", arr3[i].var, arr3[i].c);
    }
    printf("\n");

    return 0;
}