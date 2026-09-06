// Encapsulation Example
# include <stdio.h>

// Encapsulation: Bundling the stack's data into a single struct
typedef struct {
    int items[100];
    int top;
} Stack;

// Functions designed specifically to manipulate the Stack struct
void push(Stack *s, int value){
    s->top++;
    s->items[s->top] = value;
}

int pop(Stack *s){
    int val = s->items[s->top];
    s->top--;

    return val;
}