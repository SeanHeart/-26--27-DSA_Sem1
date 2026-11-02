/*Date: October 31, 2026
Topic: Stack (push and pop functions)

Notes/Comments/Feedback: Done
*/

//write code here
#include <stdio.h>
#define SIZE 10

typedef struct{
    int item[SIZE];
    int top;
}Stack;

// prototype declaractions
void init(Stack *);
void push(Stack *, int);        // Returns nothing thus it is void.
int pop(Stack *);               // Return the deleted element (return the last inserted element) thus it it int. 



void push(Stack *sp, int value){
    if(sp->top == SIZE-1){
        printf("Stack Overflow\n");
        return;
    }

    sp->top++;
    sp->item[sp->top] = value;

}

int pop(Stack *sp){
    if(sp->top == -1){
        printf("Stack Underflow\n");
        return -9999;
    }
    int value;
    value = sp->item[sp->top];
    sp->top--;
    return value;

    // sp->item[sp->top]--;
    // sp->top--;

}

void init(Stack *sp){
    sp->top = -1;
}


int main(){
    Stack s1, s2;
    init(&s1);
    init(&s2);

    push(&s1, 100);
    push(&s1, 200);

    push(&s2, 10);
    push(&s2, 20);

    printf("Deleted from s1: %d\n", pop(&s1));  // 200 
    printf("Deleted from s1: %d\n", pop(&s1));  // 100 

    printf("Deleted from s2: %d\n", pop(&s2));  // 20 
    printf("Deleted from s2: %d\n", pop(&s2));  // 10

    

    return 0;
}