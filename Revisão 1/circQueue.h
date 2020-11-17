#ifndef CIRCQUEUE_H
#define CIRCQUEUE_H

#define TRUE 1
#define FALSE 0

typedef struct _queue_ Queue;

Queue *qCreate(int max);
int Enqueue(Queue *q, void *b);
int Dequeue(Queue *q);
void *qFirst(Queue *q);
int qIsFull(Queue *q);
int qIsEmpty(Queue *q);
int IsFull(Queue *q);
int IsEmpty(Queue *q);

#endif