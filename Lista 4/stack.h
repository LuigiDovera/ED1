#ifndef STACK_H
#define STACK_H

#define TRUE 1
#define FALSE 0

typedef struct _stack_ Stack;


Stack *stkCreate (int max_itens);
int stkPush(Stack *s, void *item);
void *stkPop(Stack *s);
void *stkFirst(Stack *s);
int stkIsEmpty(Stack *s);
int stkDestroy(Stack *s);

#endif