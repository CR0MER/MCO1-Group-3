#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX_STACK_SIZE 32768

struct Stack
{
    int data[MAX_STACK_SIZE];
    int top;
};

Stack *CREATE()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s)
        s->top = -1;
    return s;
}

int ISFULL(Stack *s)
{
    return s->top == MAX_STACK_SIZE - 1;
}

int ISEMPTY(Stack *s)
{
    return s->top == -1;
}

int PUSH(Stack *s, int elem)
{
    if (ISFULL(s))
        return 0;
    s->data[++(s->top)] = elem;
    return 1;
}

int POP(Stack *s)
{
    if (ISEMPTY(s))
        return -1; // or handle error
    return s->data[(s->top)--];
}

int TOP(Stack *s)
{
    if (ISEMPTY(s))
        return -1; // or handle error
    return s->data[s->top];
}

int NEXT_TO_TOP(Stack *s)
{
    if (s->top < 1)
        return -1; // or handle error
    return s->data[s->top - 1];
}

void FREE(Stack *s)
{
    free(s);
}