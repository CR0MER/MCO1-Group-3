#ifndef STACK_H
#define STACK_H

#include "coord.h"

#define MAX_COORDS 32768

typedef struct
{
    Coord elems[MAX_COORDS];
    int top;
} Stack;

void CREATE(Stack *s);
void PUSH(Stack *s, Coord p);
Coord POP(Stack *s);
Coord TOP(Stack *s);
int ISFULL(Stack *s);
int ISEMPTY(Stack *s);
Coord NEXT_TO_TOP(Stack *s);

#endif