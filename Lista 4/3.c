#include <stdlib.h>
#include "queue.h"


//A função também se encontra em Queue.c, logo abaixo da função qCreate.
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
