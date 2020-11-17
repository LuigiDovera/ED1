#include <stdlib.h>
#include "circQueue.h"

typedef struct _queue_
{
    int front,
        rear;
    int maxItens;
    int numItens;
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
        if (q->rear == (q->maxItens - 1))
        {
            q->qArray[q->rear] = b;
            q->rear = 0;
        }
        else
        {   
            q->qArray[q->rear] = b;
            q->rear = q->rear + 1;
        }
        q->numItens++;
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
        q->front = (q->front + 1) % q->maxItens;
        q->numItens--;
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

int IsFull(Queue *q)
{
    if (q->numItens < q->maxItens)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}
int IsEmpty(Queue *q)
{
    if (q->numItens == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}