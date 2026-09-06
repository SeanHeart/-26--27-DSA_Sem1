// Header file
typedef struct Stack Stack; // Declarative declaration (Opaque Type)

Stack* create_stack();
void push(Stack *s, int value);
int pop(Stack *s);