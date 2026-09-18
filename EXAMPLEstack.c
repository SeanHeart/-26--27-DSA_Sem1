#include <stdio.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    int items[MAX];
    int top;            // index of the top element; -1 means empty
} Stack;

void init(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Push: add an element on top
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->items[++s->top] = value;
    printf("Pushed %d\n", value);
}

// Pop: remove and return the top element
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Nothing to pop\n");
        return -1;
    }
    int value = s->items[s->top--];
    printf("Popped %d\n", value);
    return value;
}

// Peek: look at the top element without removing it
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}

// Display from top to bottom
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (top -> bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main(void) {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    printf("Top element: %d\n", peek(&s));

    pop(&s);
    display(&s);

    // Fill it up to trigger overflow
    push(&s, 40);
    push(&s, 50);
    push(&s, 60);
    push(&s, 70);   // exceeds MAX (5)
    display(&s);

    // Empty it out to trigger underflow
    while (!isEmpty(&s)) {
        pop(&s);
    }
    pop(&s);        // underflow

    return 0;
}
