// Find the Size of Array of Structures
#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float marks;
};

int main() {
    struct Student students[3] = {
        {"John", 20, 85.5},
        {"Alice", 22, 99.0},
        {"Bob", 25, 78.0}
    };

    // Printing size of students
    printf("%ld", sizeof(students));

    return 0;
}