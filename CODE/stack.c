#include <stdio.h>
#include "stack.h"

//*s is a pointer to the stack
void CREATE(Stack *s)
{
    s->top = -1; // Initialize the stack as empty  (top == -1 inidcates an empty stack)
}

// Checks if The stack is Full (returns 1 if full, else 0)
int ISFULL(Stack *s)
{
    return s->top == MAX_COORDS - 1;
}

// Checks if The stack is Empty (returns 1 if empty, else 0)
int ISEMPTY(Stack *s)
{
    return s->top == -1;
}

void PUSH(Stack *s, Coord point)
{
    if (!ISFULL(s)) // Check if stack is not full
    {
        s->elems[++s->top] = point; // Increment top and push the new element to the top index
    }

    else
    {
        printf("Stack is full\n"); // else notify stack is already full
    }
}

// Removes the top element from the stack and returns it
Coord POP(Stack *s)
{
    if (!ISEMPTY(s)) // Check if stack is not empty
    {
        return s->elems[s->top--]; // Return the top element and decrement the top index
    }

    // In this case, this is not needed but will add it just to be safe (it may interfere with the black box though)
    else
    {
        printf("Stack is empty\n"); // else notify stack is already empty
        Coord empty_coord = {0, 0}; // initialize an empty Coordinate
        return empty_coord;         // Return the empty Coordinate
    }
}

// Returns the top of the element (Does not remove it from the stack)
Coord TOP(Stack *s)
{
    if (!ISEMPTY(s)) // Check if stack is not empty
    {
        return s->elems[s->top]; // Return the top element without removing it
    }

    // In this case, this is not needed but will add it just to be safe (it may interfere with the black box though)
    else
    {
        printf("Stack is empty\n"); // else notify stack is already empty
        Coord empty_coord = {0, 0}; // initialize an empty Coordinate
        return empty_coord;         // Return the empty Coordinate
    }
}

// Returns the second top of the element (Does not remove it from the stack)
Coord NEXT_TO_TOP(Stack *s)
{
    if (s->top > 0)
    {                                // Check if there are at least two elements in the stack
        return s->elems[s->top - 1]; // Return the second top element
    }

    // In this case, this is not needed but will add it just to be safe (it may interfere with the black box though)
    else
    {
        printf("Not enough elements in stack\n"); // else notify stack does not have enough elements
        Coord empty_coord = {0, 0};               // initialize an empty Coordinate
        return empty_coord;                       // Return the empty Coordinate
    }
}