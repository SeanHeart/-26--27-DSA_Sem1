#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct{
    int items[MAX];
    int top;
}Stack;

void init(Stack *s){
    s->top = -1;
}

bool isEmpty(Stack *s){
    return s->top == -1;
}

bool isFull(Stack *s){
    return s->top == MAX-1;
}

void push(Stack *s, int v){
    if(!isFull(s)){
        s->top++;
        s->items[s->top] = v;
    }
}

int pop(Stack *s){
    return isEmpty(s) ? -1 : s->items[s->top--];
}

int peek(Stack *s){
    return isEmpty(s) ? -1 : s->items[s->top];
}

void sortStack (Stack *s){
    Stack temp;
    init(&temp);
    
    while(!isEmpty(s)){
        int x = pop(s);
        
        while(!isEmpty(&temp) && peek(&temp) < x){
            push(s, pop(&temp));
        }
        push(&temp, x);
    }
    
    while(!isEmpty(&temp)){
        push(s, pop(&temp));
    }
}


int main(){
    Stack s;
    init(&s);
    
    int n, value;
    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &value);
        push(&s, value);
    }
    
    sortStack(&s);
    
    printf("Sorted Stack:");
    while(!isEmpty(&s)){
        printf(" %d", pop(&s));
    }
    printf("\n");
    
    return 0;
}