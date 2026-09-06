// Implementation File

//stack .c
#include "stack.h"
#include <stdio.h>

struct Stack {
    int items[100];
    int top;
};

Stack* create_stack() {
    Stack *s = malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

void push(Stack *s, int value) {
    s->top++;
    s->items[s->top] = value;
}

int pop(Stack *s) {
    int value = s->items[s->top];
    s->top--;
    return value;
}