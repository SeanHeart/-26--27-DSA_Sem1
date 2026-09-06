// Main Program

#include <stdio.h>
#include "stack.h"

int main() {
    Stack *myStack = create_stack();

    // Abstraction in action:
    push(myStack, 10);
    push(myStack, 20);
    int value = pop(myStack);   // Returns 20

    return 0;
}