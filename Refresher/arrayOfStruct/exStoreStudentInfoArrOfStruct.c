// Example of Array of Structure - Store Student Information
#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float marks;
};

int main() {
    // Declaration and initialization of an array of structures
    struct Student students[3] ={
        {"Nikhil", 20, 85.5},
        {"Shubham", 22, 90.0},
        {"Vivek", 25, 78.0}
    };

    // Traversing through the array of structures and displaying the data
    for(int i=0; i<3; i++){
        printf("Student %d:\n", i+1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %.2f\n\n", students[i].marks);
    }

    return 0;
}