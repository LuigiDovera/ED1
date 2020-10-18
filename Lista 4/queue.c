#include <stdlib.h>
#include "queue.h"

typedef struct _queue_
{
    int front,
        rear;
    int maxItens;
    void **qArray;
} Queue;

/* Criar (q) - criar uma fila q vazia */
Queue *qCreate(int max)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL)
        return NULL;
    q->qArray = (void **)calloc(max,
                                sizeof(void *));
    if (q->qArray == NULL)
        return NULL;
    q->front = 0;
    q->rear = 0;
    q->maxItens = max;
    return q;
}


int qDestroy(Queue *q)
{
    if (q != NULL)
    {
        if (q->qArray != NULL)
        {
            if (q->front == q->rear)
            {
                free(q->qArray);
                free(q);
                return TRUE;
            }
        }
    }
    return FALSE;
}

/* Inserir (x, F) - insere x no fim de q */
int Enqueue(Queue *q, void *b)
{
    if (IsFull(q))
    {
        return FALSE;
    }
    else
    {
        q->qArray[q->rear] = b;
        q->rear++;
        return TRUE;
    }
}

/* Elimina (F)
** elimina o elemento do início da fila */
int Dequeue(Queue *q)
{
    if (IsEmpty(q))
    {
        return FALSE;
    }
    else
    {
        q->front++;
        return TRUE;
    }
}

/* Primeiro (q) -
** acessa o elemento do início da fila */
void *qFirst(Queue *q)
{
    void *aux;
    if (q != NULL)
    {
        if (q->front <= q->rear)
        {
            aux = q->qArray[q->front];
            return aux;
        }
    }
    return NULL;
}

int qIsFull(Queue *q)
{
    if (q->rear < q->maxItens - 1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/* Vazia (q) - testa se q está vazia */
int qIsEmpty(Queue *q)
{
    if (q->front == q->rear)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}