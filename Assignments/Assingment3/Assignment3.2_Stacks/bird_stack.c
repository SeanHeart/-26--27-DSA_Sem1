#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define String char[50]

typedef struct{
    String name;
    String specie;
    String color;
    int bread;
    int age;
}Birds;

typedef struct {
    Birds breadBirds[10];
    int top;
}Stack;

// Initializes the stack to empty
void initStack(Stack* s) {
    s->top = -1;
}

// Returns 1 if the stack is empty, 0 otherwise
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Returns 1 if the stack is full, 0 otherwise
int isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Pushes a Bird onto the top of the stack
void push(Stack* s, Birds b) {
    if (isFull(s)) {
        printf("Stack overflow. Cannot push '%s'.\n", b.name);
        return;
    }
    s->top++;
    s->breadBirds[s->top] = b;
}

// Removes the top Bird from the stack (does not return it)
void pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow. Nothing to pop.\n");
        return;
    }
    s->top--;
}

// Returns the Bird at the top of the stack without removing it
Birds peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Returning empty Bird.\n");
        Birds empty = {"", "", "", 0, 0};
        return empty;
    }
    return s->breadBirds[s->top];
}

/*
 * pushUnique
 * Pushes a Bird only if a Bird with the same name isn't already in the stack.
 * Uses ONLY push/pop/peek/isEmpty -- no direct array/top access.
 *
 * Approach: pop every Bird off into a temporary stack while checking each
 * one against the new Bird, then push everything back from the temp stack
 * to restore the original order. Finally push the new Bird if no match was found.
 */
void pushUnique(Stack* s, Birds b) {
    Stack temp;
    initStack(&temp);
    int found = 0;

    // Drain s into temp, checking for a duplicate name along the way
    while (!isEmpty(s)) {
        Birds current = peek(s);
        pop(s);
        if (strcmp(current.name, b.name) == 0) {
            found = 1;
        }
        push(&temp, current);
    }

    // Restore original order back into s
    while (!isEmpty(&temp)) {
        Birds current = peek(&temp);
        pop(&temp);
        push(s, current);
    }

    if (!found) {
        push(s, b);
    } else {
        printf("'%s' already exists in the stack. Skipped.\n", b.name);
    }
}

/*
 * countStack
 * Returns the number of Birds currently in the stack.
 * Uses ONLY push/pop/peek/isEmpty -- no direct top access.
 *
 * Approach: pop everything into a temp stack while counting, then push
 * everything back from temp to restore the original stack.
 */
int countStack(Stack* s) {
    Stack temp;
    initStack(&temp);
    int count = 0;

    while (!isEmpty(s)) {
        Birds current = peek(s);
        pop(s);
        count++;
        push(&temp, current);
    }

    while (!isEmpty(&temp)) {
        Birds current = peek(&temp);
        pop(&temp);
        push(s, current);
    }

    return count;
}

// Prints all Birds in the stack from top to bottom (for testing only)
void displayStack(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        Birds b = s->breadBirds[i];
        printf("  Name: %-10s Specie: %-10s Color: %-8s Bread: %d  Age: %d\n",
               b.name, b.specie, b.color, b.bread, b.age);
    }
}

int main() {
    Stack s;
    initStack(&s);

    Birds b1 = {"Tweety", "Canary", "Yellow", 1, 2};
    Birds b2 = {"Rio", "Macaw", "Blue", 0, 3};
    Birds b3 = {"Kevin", "Snipe", "Multicolor", 1, 5};

    printf("=== Pushing Tweety, Rio, Kevin ===\n");
    push(&s, b1);
    push(&s, b2);
    push(&s, b3);
    displayStack(&s);

    printf("\n=== Peek ===\n");
    Birds top = peek(&s);
    printf("Top of stack: %s\n", top.name);

    printf("\n=== pushUnique('Rio') -- duplicate, should be skipped ===\n");
    pushUnique(&s, b2);
    displayStack(&s);

    printf("\n=== pushUnique('Zazu') -- new, should be added ===\n");
    Birds b4 = {"Zazu", "Hornbill", "Red", 1, 4};
    pushUnique(&s, b4);
    displayStack(&s);

    printf("\n=== countStack ===\n");
    printf("Total Birds in stack: %d\n", countStack(&s));

    printf("\n=== Pop ===\n");
    pop(&s);
    displayStack(&s);

    return 0;
}
