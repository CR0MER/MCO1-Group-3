typedef struct Stack Stack;

Stack *CREATE();
int ISFULL(Stack *s);
int ISEMPTY(Stack *s);
int PUSH(Stack *s, int elem);
int POP(Stack *s);
int TOP(Stack *s);
int NEXT_TO_TOP(Stack *s);
void FREE(Stack *s);