#include <stdio.h>
#include <stdbool.h>
#include "types.h"

// write your functions here
void initialize(Stack *s){
    s->top = -1;
}

bool isFull(Stack *s){
    return s->top == MAX-1;
}

bool isEmpty(Stack *s){
    return s->top == -1;
}

void push(Stack *s, int value){
    if(isFull(s)){
        return;
    }
    s->top++;
    s->items[s->top] = value;
}

int pop(Stack *s){
    if(isEmpty(s)){
        return -1;
    }
    
    return s->items[s->top--];
}

int peek(Stack *s){
    if(isEmpty(s)){
        return -1;
    }
    
    return s->items[s->top];
}

int top(Stack *s){
    return peek(s);
}

void display(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty.\n");
        return;
    }
    
    for(int i=s->top; i>=0; i--){
        printf("%d\n", s->items[i]);
    }
}