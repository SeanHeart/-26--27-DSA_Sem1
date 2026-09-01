// Access and Update Members in Array of Structures
#include <stdio.h>
#include <string.h>

// Structure definition
struct A {
    int var;
    char c;
};

int main() {
    struct A arr[2] = {{1, 'a'}, {2, 'b'}};

    // Access the member c of second element of arr
    printf("%c\n", arr[1].c);

    // Update the value and access again
    arr[1].c = 'Z';
    printf("%c\n", arr[1].c);

    return 0;
}