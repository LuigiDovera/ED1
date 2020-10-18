#ifndef QUEUE_H
#define QUEUE_H

#define TRUE 1
#define FALSE 0

typedef struct _queue_ Queue;

Queue *qCreate(int max);
int Enqueue(Queue *q, void *b);
int Dequeue(Queue *q);
void *qFirst(Queue *q);
int qIsFull(Queue *q);
int qIsEmpty(Queue *q);

#endif