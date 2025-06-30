// stack.h
// Stack for integer indices (used in Graham scan)
// Programmers: <Your Names>
#ifndef STACK_H
#define STACK_H

#define MAX_STACK_SIZE 32768

typedef struct Stack {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

Stack *CREATE();
int ISFULL(Stack *s);
int ISEMPTY(Stack *s);
int PUSH(Stack *s, int elem);
int POP(Stack *s);
int TOP(Stack *s);
int NEXT_TO_TOP(Stack *s);
void FREE(Stack *s);

#endif // STACK_H